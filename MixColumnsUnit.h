#include <systemc.h>
#include "mix_column_unit.h"

#ifndef MIX_COL_UNIT_H
#define MIX_COL_UNIT_H

SC_MODULE(MixColumnsUnit)
{

	// I/O signal declaration
	sc_in <sc_biguint<128> > data_in;
	sc_out<sc_biguint<128>	> data_out;
	
	// internal Signals:
	sc_signal<sc_biguint<32>> word_in[4],word_out[4];
	// process
	// This process just rename the signals to make it easier to mix the columns:
	void signal_rename_in ()
	{
		int i;
		for(i=0;i<4;i++)
		{
			word_in[i].write(sc_biguint<32>(data_in.read().range(32*(i+1)-1,32*i)));
		}
	}
	//-----------
	void signal_rename_out()
	{
		data_out.write((word_out[3],word_out[2],word_out[1],word_out[0]));
	}
	//-- Instantiate the mixers
	mix_column_unit *mc_0;
	mix_column_unit *mc_1;
	mix_column_unit *mc_2;
	mix_column_unit *mc_3;
	// Register Process, sensitivity list
	SC_CTOR(MixColumnsUnit)
	{
		
		// Signal renaming:
		SC_METHOD(signal_rename_in)
		sensitive<<data_in;

		SC_METHOD(signal_rename_out)
		sensitive<<word_out[0]<<word_out[1]<<word_out[2]<<word_out[3];
		// Mixing Columns
		//instantiate Mixer:
        mc_0= new mix_column_unit ("mc_0");
		mc_0->data_in(word_in[0]);
		mc_0->data_out(word_out[0]);

		mc_1= new mix_column_unit ("mc_1");
		mc_1->data_in(word_in[1]);
		mc_1->data_out(word_out[1]);

		mc_2= new mix_column_unit ("mc_2");
		mc_2->data_in(word_in[2]);
		mc_2->data_out(word_out[2]);

		mc_3= new mix_column_unit ("mc_3");
		mc_3->data_in(word_in[3]);
		mc_3->data_out(word_out[3]);

	}

};

#endif