#include <systemc.h>

#ifndef ADDKEYUNIT_H
#define ADDKEYUNIT_H

SC_MODULE(AddKeyUnit)
{
	// I/O signals:
	sc_in<sc_biguint<128>> data_in;
	sc_in<sc_biguint<128>> key;
	sc_out<sc_biguint<128>> data_out;


	void add_round_key()
	{
		data_out.write((data_in.read()^key.read()));
	}


	SC_CTOR(AddKeyUnit)
	{
		SC_METHOD(add_round_key);
		sensitive<<key<<data_in;
	}

};


#endif