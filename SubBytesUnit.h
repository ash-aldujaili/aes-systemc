#include <systemc.h>
#include "sub_byte_unit.h"

#ifndef SUBBYTESUNIT_H
#define SUBBYTESUNIT_H

SC_MODULE(SubBytesUnit)
{

	//I/O signals
	sc_in <sc_biguint<128> > data_in;
	sc_out<sc_biguint<128>	> data_out;



	// internal Signals:
	sc_signal<sc_biguint<8> > byte_in[16],byte_out[16];
	// process
	// This process just rename the signals to make it easier to mix the columns:
	void signal_rename_in ()
	{
		int i;
		for(i=0;i<16;i++)
		{
			byte_in[i].write(sc_biguint<8>(data_in.read().range(8*(i+1)-1,8*i)));
		}
	}
	//-----------
	void signal_rename_out()
	{
		data_out.write((byte_out[15],byte_out[14],byte_out[13],byte_out[12],byte_out[11],byte_out[10],byte_out[9] ,byte_out[8],
						byte_out[7] ,byte_out[6] ,byte_out[5] ,byte_out[4] ,byte_out[3] ,byte_out[2] ,byte_out[1] ,byte_out[0]));
	}
	//-- Instantiate the sboxes
	sub_byte_unit *sb_0;
	sub_byte_unit *sb_1;
	sub_byte_unit *sb_2;
	sub_byte_unit *sb_3;
	sub_byte_unit *sb_4;
	sub_byte_unit *sb_5;
	sub_byte_unit *sb_6;
	sub_byte_unit *sb_7;
	sub_byte_unit *sb_8;
	sub_byte_unit *sb_9;
	sub_byte_unit *sb_10;
	sub_byte_unit *sb_11;
	sub_byte_unit *sb_12;
	sub_byte_unit *sb_13;
	sub_byte_unit *sb_14;
	sub_byte_unit *sb_15;
	// Register Process, sensitivity list
	SC_CTOR(SubBytesUnit)
	{
		int j;
		// Signal renaming:
		SC_METHOD(signal_rename_in)
		sensitive<<data_in;
		// 
		SC_METHOD(signal_rename_out)
		for(j=0;j<16;j++)
				sensitive<<byte_out[j];
		// Substituting Bytes
		//instantiate sbox:
        sb_0= new sub_byte_unit ("sb_0");
		sb_0->byte_in(byte_in[0]);
		sb_0->byte_out(byte_out[0]);

		sb_1= new sub_byte_unit ("sb_1");
		sb_1->byte_in(byte_in[1]);
		sb_1->byte_out(byte_out[1]);

		sb_2= new sub_byte_unit ("sb_2");
		sb_2->byte_in(byte_in[2]);
		sb_2->byte_out(byte_out[2]);

		sb_3= new sub_byte_unit ("sb_3");
		sb_3->byte_in(byte_in[3]);
		sb_3->byte_out(byte_out[3]);


		sb_4= new sub_byte_unit ("sb_4");
		sb_4->byte_in(byte_in[4]);
		sb_4->byte_out(byte_out[4]);

		sb_5= new sub_byte_unit ("sb_5");
		sb_5->byte_in(byte_in[5]);
		sb_5->byte_out(byte_out[5]);

		sb_6= new sub_byte_unit ("sb_6");
		sb_6->byte_in(byte_in[6]);
		sb_6->byte_out(byte_out[6]);

		sb_7= new sub_byte_unit ("sb_7");
		sb_7->byte_in(byte_in[7]);
		sb_7->byte_out(byte_out[7]);

		sb_8= new sub_byte_unit ("sb_8");
		sb_8->byte_in(byte_in[8]);
		sb_8->byte_out(byte_out[8]);

		sb_9= new sub_byte_unit ("sb_9");
		sb_9->byte_in(byte_in[9]);
		sb_9->byte_out(byte_out[9]);

		sb_10= new sub_byte_unit ("sb_10");
		sb_10->byte_in(byte_in[10]);
		sb_10->byte_out(byte_out[10]);

		sb_11= new sub_byte_unit ("sb_11");
		sb_11->byte_in(byte_in[11]);
		sb_11->byte_out(byte_out[11]);

		sb_12= new sub_byte_unit ("sb_12");
		sb_12->byte_in(byte_in[12]);
		sb_12->byte_out(byte_out[12]);

		sb_13= new sub_byte_unit ("sb_13");
		sb_13->byte_in(byte_in[13]);
		sb_13->byte_out(byte_out[13]);

		sb_14= new sub_byte_unit ("sb_14");
		sb_14->byte_in(byte_in[14]);
		sb_14->byte_out(byte_out[14]);

		sb_15= new sub_byte_unit ("sb_15");
		sb_15->byte_in(byte_in[15]);
		sb_15->byte_out(byte_out[15]);
	}



};


#endif