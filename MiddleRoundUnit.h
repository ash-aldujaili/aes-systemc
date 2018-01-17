#include <systemc.h>


#include "SubBytesUnit.h"
#include "ShiftRowsUnit.h"
#include "MixColumnsUnit.h"
#include "AddKeyUnit.h"

#ifndef MIDDLE_RND_H
#define MIDDLE_RND_H

SC_MODULE(MiddleRoundUnit)

{
	//I/O signals:
	sc_in	<sc_biguint<128> > data_in;
	sc_in	<sc_biguint<128> > key;
	sc_out	<sc_biguint<128> > data_out;

	// internal signal
	sc_signal	<sc_biguint<128> > data_sub_shift, data_shift_mix, data_mix_add;
	// Data member to point to low leve modules:
	SubBytesUnit	*sub_byte_u;
	ShiftRowsUnit	*sft_row_u;
	MixColumnsUnit	*mix_col_u;
	AddKeyUnit *add_key_u;

	//Register process, binding:
	SC_CTOR(MiddleRoundUnit)
	{	
		// Sub byte:
		sub_byte_u = new SubBytesUnit("sub_byte_u");
		sub_byte_u->data_in(data_in);
		sub_byte_u->data_out(data_sub_shift);

		//Shfit
		sft_row_u = new ShiftRowsUnit("sft_row_u");
		sft_row_u->data_in(data_sub_shift);
		sft_row_u->data_out(data_shift_mix);

		//Mix
		mix_col_u = new MixColumnsUnit("mix_col_u");
		mix_col_u->data_in(data_shift_mix);
		mix_col_u->data_out(data_mix_add);


		// Add key:
		add_key_u = new AddKeyUnit("add_key_u");
		add_key_u->data_in(data_mix_add);
		add_key_u->key(key);
		add_key_u->data_out(data_out);
	}
};

#endif