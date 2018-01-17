#include <systemc.h>

#include "KeyGenUnit.h"

#ifndef KEY_EXPAND_H
#define KEY_EXPAND_H

SC_MODULE(KeyExpansionUnit)
{
	//I/O signals
	sc_in<bool> clk;
	sc_in<sc_biguint<128>> key_0;
	sc_out<sc_biguint<128>> key_1,key_2,key_3,key_4,key_5,key_6,key_7,key_8,key_9,key_10;
	sc_out<sc_biguint<32>> word_out_3_1, word_out_2_1, word_out_1_1, word_out_0_1;
	sc_out<sc_biguint<32>> word_out_3_2, word_out_2_2, word_out_1_2, word_out_0_2;
	sc_out<sc_biguint<32>> word_out_3_3, word_out_2_3, word_out_1_3, word_out_0_3;
	sc_out<sc_biguint<32>> word_out_3_4, word_out_2_4, word_out_1_4, word_out_0_4;
	sc_out<sc_biguint<32>> word_out_3_5, word_out_2_5, word_out_1_5, word_out_0_5;
	sc_out<sc_biguint<32>> word_out_3_6, word_out_2_6, word_out_1_6, word_out_0_6;
	sc_out<sc_biguint<32>> word_out_3_7, word_out_2_7, word_out_1_7, word_out_0_7;
	sc_out<sc_biguint<32>> word_out_3_8, word_out_2_8, word_out_1_8, word_out_0_8;
	sc_out<sc_biguint<32>> word_out_3_9, word_out_2_9, word_out_1_9, word_out_0_9;
	sc_out<sc_biguint<32>> word_out_3_10, word_out_2_10, word_out_1_10, word_out_0_10;


	//Internal Signals:
	sc_signal<sc_biguint<128>> key_1_reg,key_2_reg,key_3_reg,key_4_reg,key_5_reg,key_6_reg,key_7_reg,key_8_reg,key_9_reg,key_10_reg;
	sc_signal<sc_biguint<128>> key_1_next,key_2_next,key_3_next,key_4_next,key_5_next,key_6_next,key_7_next,key_8_next,key_9_next,key_10_next;
	sc_signal<sc_lv<4>> rnd1,rnd2,rnd3,rnd4,rnd5,rnd6,rnd7,rnd8,rnd9,rnd10;
	//Process:
	void seq_logic()
	{
		key_1_reg=key_1_next;
		key_2_reg=key_2_next;
		key_3_reg=key_3_next;
		key_4_reg=key_4_next;
		key_5_reg=key_5_next;
		key_6_reg=key_6_next;
		key_7_reg=key_7_next;
		key_8_reg=key_8_next;
		key_9_reg=key_9_next;
		key_10_reg=key_10_next;
		cout<<"Key 1"<<key_2_reg.read()<<"\n";

	}
	//
	//
	void out_logic()
	{
		key_1.write(key_1_reg);
		key_2.write(key_2_reg);
		key_3.write(key_3_reg);
		key_4.write(key_4_reg);
		key_5.write(key_5_reg);
		key_6.write(key_6_reg);
		key_7.write(key_7_reg);
		key_8.write(key_8_reg);
		key_9.write(key_9_reg);
		key_10.write(key_10_reg);	
	}
	//
	void rnd_sig ()
	{
		rnd1.write("0001");
		rnd2.write("0010");
		rnd3.write("0011");
		rnd4.write("0100");
		rnd5.write("0101");
		rnd6.write("0110");
		rnd7.write("0111");
		rnd8.write("1000");
		rnd9.write("1001");
		rnd10.write("1010");
	}

	// Instantiate the key generator
	KeyGenUnit *key_gen_u1;
	KeyGenUnit *key_gen_u2;
	KeyGenUnit *key_gen_u3;
	KeyGenUnit *key_gen_u4;
	KeyGenUnit *key_gen_u5;
	KeyGenUnit *key_gen_u6;
	KeyGenUnit *key_gen_u7;
	KeyGenUnit *key_gen_u8;
	KeyGenUnit *key_gen_u9;
	KeyGenUnit *key_gen_u10;

	SC_CTOR(KeyExpansionUnit)
	{
		SC_METHOD(seq_logic);
		sensitive<<clk.pos();


		SC_METHOD(out_logic);
		sensitive<<key_1_reg<<key_2_reg<<key_3_reg<<key_4_reg<<key_5_reg<<key_6_reg<<key_7_reg<<key_8_reg<<key_9_reg<<key_10_reg;

		SC_METHOD(rnd_sig);

		//bind:
		key_gen_u1 = new KeyGenUnit("key_gen_u1");
		key_gen_u1->encr_round(rnd1);
		key_gen_u1->key_in(key_0);
		key_gen_u1->key_out(key_1_next);
		key_gen_u1->word_out_3(word_out_3_1);
		key_gen_u1->word_out_2(word_out_2_1);
		key_gen_u1->word_out_1(word_out_1_1);
		key_gen_u1->word_out_0(word_out_0_1);

		key_gen_u2 = new KeyGenUnit("key_gen_u2");
		key_gen_u2->encr_round(rnd2);
		key_gen_u2->key_in(key_1_reg);
		key_gen_u2->key_out(key_2_next);
		key_gen_u2->word_out_3(word_out_3_2);
		key_gen_u2->word_out_2(word_out_2_2);
		key_gen_u2->word_out_1(word_out_1_2);
		key_gen_u2->word_out_0(word_out_0_2);

		key_gen_u3 = new KeyGenUnit("key_gen_u3");
		key_gen_u3->encr_round(rnd3);
		key_gen_u3->key_in(key_2_reg);
		key_gen_u3->key_out(key_3_next);
		key_gen_u3->word_out_3(word_out_3_3);
		key_gen_u3->word_out_2(word_out_2_3);
		key_gen_u3->word_out_1(word_out_1_3);
		key_gen_u3->word_out_0(word_out_0_3);

		key_gen_u4 = new KeyGenUnit("key_gen_u4");
		key_gen_u4->encr_round(rnd4);
		key_gen_u4->key_in(key_3_reg);
		key_gen_u4->key_out(key_4_next);
		key_gen_u4->word_out_3(word_out_3_4);
		key_gen_u4->word_out_2(word_out_2_4);
		key_gen_u4->word_out_1(word_out_1_4);
		key_gen_u4->word_out_0(word_out_0_4);

		key_gen_u5 = new KeyGenUnit("key_gen_u5");
		key_gen_u5->encr_round(rnd5);
		key_gen_u5->key_in(key_4_reg);
		key_gen_u5->key_out(key_5_next);
		key_gen_u5->word_out_3(word_out_3_5);
		key_gen_u5->word_out_2(word_out_2_5);
		key_gen_u5->word_out_1(word_out_1_5);
		key_gen_u5->word_out_0(word_out_0_5);

		key_gen_u6 = new KeyGenUnit("key_gen_u6");
		key_gen_u6->encr_round(rnd6);
		key_gen_u6->key_in(key_5_reg);
		key_gen_u6->key_out(key_6_next);
		key_gen_u6->word_out_3(word_out_3_6);
		key_gen_u6->word_out_2(word_out_2_6);
		key_gen_u6->word_out_1(word_out_1_6);
		key_gen_u6->word_out_0(word_out_0_6);

		key_gen_u7 = new KeyGenUnit("key_gen_u7");
		key_gen_u7->encr_round(rnd7);
		key_gen_u7->key_in(key_6_reg);
		key_gen_u7->key_out(key_7_next);
		key_gen_u7->word_out_3(word_out_3_7);
		key_gen_u7->word_out_2(word_out_2_7);
		key_gen_u7->word_out_1(word_out_1_7);
		key_gen_u7->word_out_0(word_out_0_7);

		key_gen_u8 = new KeyGenUnit("key_gen_u8");
		key_gen_u8->encr_round(rnd8);
		key_gen_u8->key_in(key_7_reg);
		key_gen_u8->key_out(key_8_next);
		key_gen_u8->word_out_3(word_out_3_8);
		key_gen_u8->word_out_2(word_out_2_8);
		key_gen_u8->word_out_1(word_out_1_8);
		key_gen_u8->word_out_0(word_out_0_8);

		key_gen_u9 = new KeyGenUnit("key_gen_u9");
		key_gen_u9->encr_round(rnd9);
		key_gen_u9->key_in(key_8_reg);
		key_gen_u9->key_out(key_9_next);
		key_gen_u9->word_out_3(word_out_3_9);
		key_gen_u9->word_out_2(word_out_2_9);
		key_gen_u9->word_out_1(word_out_1_9);
		key_gen_u9->word_out_0(word_out_0_9);

		key_gen_u10 = new KeyGenUnit("key_gen_u10");
		key_gen_u10->encr_round(rnd10);
		key_gen_u10->key_in(key_9_reg);
		key_gen_u10->key_out(key_10_next);
		key_gen_u10->word_out_3(word_out_3_10);
		key_gen_u10->word_out_2(word_out_2_10);
		key_gen_u10->word_out_1(word_out_1_10);
		key_gen_u10->word_out_0(word_out_0_10);

	}

};






#endif