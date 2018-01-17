#include <systemc.h>

#ifndef SHIFT_ROW_H
#define SHIFT_ROW_H

SC_MODULE(ShiftRowsUnit)
{
	// I/O signals:
	sc_in <sc_biguint<128> > data_in;
	sc_out<sc_biguint<128> > data_out;
	// internal Signals:
	sc_signal<sc_biguint<8>> byte[16];
	// process
	// This process just rename the signals to make it easier to shift the rows:
	void signal_rename ()
	{
		int i;
		for(i=0;i<16;i++)
		{
			//byte[i]=data_in.read()(8*(i+1)-1,8*i);
			byte[i].write(sc_biguint<8>(data_in.read().range(8*(i+1)-1,8*i)));
		}
	}
	//-----------
	void shift_rows()
	{
		data_out.write((byte[15],byte[10],byte[5],byte[0],byte[11],byte[6],byte[1],byte[12],byte[7],byte[2],byte[13],byte[8],byte[3],byte[14],byte[9],byte[4]));
	}
	//----------

	//REGISTERING PROCESS, SENSITIVITY:
	SC_CTOR(ShiftRowsUnit)
	{	
		int j;
		// Signal renaming:
		SC_METHOD(signal_rename);
		sensitive<<data_in;
		//Shifting Rows
		SC_METHOD(shift_rows);
		for(j=0;j<16;j++)
				sensitive<<byte[j];
			
	}
};

#endif