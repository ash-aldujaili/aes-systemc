#include <systemc.h>

#ifndef RCON_H
#define RCON_H

SC_MODULE(RconUnit)
{
	//I/O
	sc_in<sc_lv<4>>	encr_round;
	sc_out<sc_biguint<32>> byte_out;

	//process
	void rcon_lut()
	{
		switch(sc_uint<4>(encr_round.read()))
		{
		case 0x1: byte_out.write(0x01000000);break;
		case 0x2: byte_out.write(0x02000000);break;
		case 0x3: byte_out.write(0x04000000);break;
		case 0x4: byte_out.write(0x08000000);break;
		case 0x5: byte_out.write(0x010000000);break;
		case 0x6: byte_out.write(0x020000000);break;
		case 0x7: byte_out.write(0x040000000);break;
		case 0x8: byte_out.write(0x080000000);break;
		case 0x9: byte_out.write(0x1b000000);break;
		case 0xa: byte_out.write(0x36000000);break;
		default: byte_out.write(0x00000000);break;
		}

	}

	SC_CTOR(RconUnit)
	{
		SC_METHOD(rcon_lut);
		sensitive<<encr_round;
	}


};
#endif