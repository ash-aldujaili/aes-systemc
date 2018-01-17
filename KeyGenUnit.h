#include <systemc.h>

#include "RconUnit.h"
#include "sub_byte_unit.h"


#ifndef KEY_GEN_H
#define KEY_GEN_H

SC_MODULE(KeyGenUnit)
{
	sc_in<sc_biguint<128>> key_in;
	sc_in<sc_lv<4>> encr_round;
	sc_out<sc_biguint<128>> key_out;
	//sc_out<sc_biguint<32>> rcon_byte;            use it when doing debugging for KeyGen
	sc_signal<sc_biguint<32>> rcon_byte;


	// internal Signals:
	// bytes for breaking the input word and for generate the sbytes , rconbye
	sc_signal<sc_biguint<8>> byte[16],sbyte_out[4];
	// for breaking the key into words and generate the rotate after sub word
	sc_signal<sc_biguint<32>> word[4],rot_word;
	// the so- called generate key words:
	sc_out<sc_biguint<32>> word_out_3,word_out_2,word_out_1,word_out_0;
	// process
	// This process just rename the signals to make it easier to shift the rows:
	void byte_rename ()
	{
		int i;
		for(i=0;i<16;i++)
		{
			//byte[i]=data_in.read()(8*(i+1)-1,8*i);
			byte[i].write(sc_biguint<8>(key_in.read().range(8*(i+1)-1,8*i)));
		}
	}
	//----------- performs rotation and sb operation on the LSB word
	void word_rotate ()
	{
		word[0].write(sc_biguint<32>((byte[3],byte[2],byte[1],byte[0])));
		rot_word.write(sc_biguint<32>((sbyte_out[2],sbyte_out[1],sbyte_out[0],sbyte_out[3])));
		word[1].write(sc_biguint<32>((byte[7],byte[6],byte[5],byte[4])));
		word[2].write(sc_biguint<32>((byte[11],byte[10],byte[9],byte[8])));
		word[3].write(sc_biguint<32>((byte[15],byte[14],byte[13],byte[12])));
	}
	// generate the 1st word of the key
	void first_word_key()
	{
		word_out_3.write((rot_word ^ rcon_byte) ^ word[3]);
	}

	void second_word_key()
	{
		word_out_2.write(word_out_3 ^ word[2]);
	}

	void third_word_key()
	{
		word_out_1.write(word_out_2 ^ word[1]);
	}

	void fourth_word_key()
	{
		word_out_0.write(word_out_1 ^ word[0]);
	}
	//
	void out_logic()
	{
		key_out.write(sc_biguint<128>((word_out_3,word_out_2,word_out_1,word_out_0)));

	}



	// instantiate the sbox
	sub_byte_unit *sb_0;
	sub_byte_unit *sb_1;
	sub_byte_unit *sb_2;
	sub_byte_unit *sb_3;
	//instantiate Rcon
	RconUnit *rc_u;
	
	SC_CTOR(KeyGenUnit)
	{
		SC_METHOD(byte_rename);
		sensitive<<key_in;
		
		int j;
		SC_METHOD(word_rotate);
		for(j=0;j<16;j++)
			sensitive<<byte[j];
			sensitive<<sbyte_out[0]<<sbyte_out[1]<<sbyte_out[2]<<sbyte_out[3];

		SC_METHOD(first_word_key)
		sensitive<<rot_word<<word[3]<<rcon_byte;

		SC_METHOD(second_word_key)
		sensitive<<word_out_3<<word[2];

		SC_METHOD(third_word_key)
		sensitive<<word_out_2<<word[1];

		SC_METHOD(fourth_word_key)
		sensitive<<word_out_1<<word[0];

		// out logic
		SC_METHOD(out_logic)
		sensitive<<word_out_0<<word_out_1<<word_out_2<<word_out_3;
		// Substituting Bytes
		//instantiate sbox:
        sb_0= new sub_byte_unit ("sb_0");
		sb_0->byte_in(byte[0]);
		sb_0->byte_out(sbyte_out[0]);

		sb_1= new sub_byte_unit ("sb_1");
		sb_1->byte_in(byte[1]);
		sb_1->byte_out(sbyte_out[1]);

		sb_2= new sub_byte_unit ("sb_2");
		sb_2->byte_in(byte[2]);
		sb_2->byte_out(sbyte_out[2]);

		sb_3= new sub_byte_unit ("sb_3");
		sb_3->byte_in(byte[3]);
		sb_3->byte_out(sbyte_out[3]);

		// instantiate Rcong
		rc_u = new RconUnit("RconUnit");
		rc_u->byte_out(rcon_byte);
		rc_u->encr_round(encr_round);


	}


};

#endif
