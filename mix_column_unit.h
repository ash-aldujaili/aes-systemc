#include <systemc.h>

#ifndef MIX_COL_H
#define MIX_COL_H

SC_MODULE(mix_column_unit)
{
	//I/O signal
	sc_in<sc_biguint<32> > data_in;
	sc_out<sc_biguint<32>> data_out;

	// Internal Signal declaration
	sc_signal <sc_biguint<8>> in_0,in_1,in_2,in_3,x_in_0,x_in_1,x_in_2,x_in_3;

	//signal rename:
	void sig_rename()
	{
		in_0.write(sc_biguint<8>(data_in.read()(7,0)));
		in_1.write(sc_biguint<8>(data_in.read()(15,8)));
		in_2.write(sc_biguint<8>(data_in.read()(23,16)));
		in_3.write(sc_biguint<8>(data_in.read()(31,24)));
	}

	void check_msb()
	{

		x_in_0=(in_0.read()[7] )? ((in_0.read()<<1)^(sc_biguint<8>(0x1b))):(in_0.read()<<1);
		x_in_1=(in_1.read()[7] )? ((in_1.read()<<1)^(sc_biguint<8>(0x1b))):(in_1.read()<<1);
		x_in_2=(in_2.read()[7] )? ((in_2.read()<<1)^(sc_biguint<8>(0x1b))):(in_2.read()<<1);
		x_in_3=(in_3.read()[7] )? ((in_3.read()<<1)^(sc_biguint<8>(0x1b))):(in_3.read()<<1);
	}

	void mix ()
	{
		data_out.write((x_in_3.read() ^ x_in_2.read() ^ in_2.read()     ^ in_1.read()   ^ in_0.read(),
						in_3.read()   ^ x_in_2.read() ^ x_in_1.read()   ^ in_1.read()   ^ in_0.read(),
						in_3.read()   ^ in_2.read()   ^ x_in_1.read()   ^ x_in_0.read() ^ in_0.read(),
						x_in_3.read() ^ in_3.read()   ^ in_2.read()     ^ in_1.read()   ^ x_in_0.read()));
	}


	SC_CTOR(mix_column_unit)
	{
		SC_METHOD(sig_rename)
			sensitive<<data_in;

		SC_METHOD(check_msb)
			sensitive<<in_0<<in_1<<in_2<<in_3;
		
		SC_METHOD(mix)
			sensitive<<in_0<<in_1<<in_2<<in_3<<x_in_0<<x_in_1<<x_in_2<<x_in_3;;
	}



};

#endif
