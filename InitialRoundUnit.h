#include <systemc.h>

#include "AddKeyUnit.h"

#ifndef INIT_ROUND_H
#define INIT_ROUND_H
SC_MODULE(InitialRoundUnit)

{
	//I/O signals:
	sc_in	<sc_biguint<128> > data_in;
	sc_in	<sc_biguint<128> > key;
	sc_out	<sc_biguint<128> > data_out;

	// Data member to point to low leve modules:
	AddKeyUnit *add_key_u;

	//Register process
	SC_CTOR(InitialRoundUnit)
	{
		add_key_u = new AddKeyUnit("add_key_u");
		add_key_u->data_in(data_in);
		add_key_u->key(key);
		add_key_u->data_out(data_out);
	}
};


#endif