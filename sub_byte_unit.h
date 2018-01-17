#include<systemc.h>


#ifndef SUBBYTEUNIT_H
#define SUBBYTEUNIT_H

SC_MODULE(sub_byte_unit)
{
	// I/O signals:
	sc_in<sc_biguint<8> > byte_in;
	sc_out<sc_biguint<8> > byte_out;

	// Process, Member Function Declaration and Definition
	void s_box_lut ()
	{
	  switch(sc_uint<8>(byte_in.read()))
	 {
	  case 0x00: byte_out.write(0x63);break;
	  case 0x01: byte_out.write(0x7c);break;
	  case 0x02: byte_out.write(0x77);break;
	  case 0x03: byte_out.write(0x7b);break;
	  case 0x04: byte_out.write(0xf2);break;
	  case 0x05: byte_out.write(0x6b);break;
	  case 0x06: byte_out.write(0x6f);break;
	  case 0x07: byte_out.write(0xc5);break;
	  case 0x08: byte_out.write(0x30);break;
	  case 0x09: byte_out.write(0x01);break;
      case 0x0a: byte_out.write(0x67);break;
	  case 0x0b: byte_out.write(0x2b);break;
	  case 0x0c: byte_out.write(0xfe);break;
	  case 0x0d: byte_out.write(0xd7);break;
	  case 0x0e: byte_out.write(0xab);break;
	  case 0x0f: byte_out.write(0x76);break;
	  case 0x10: byte_out.write(0xca);break;
	  case 0x11: byte_out.write(0x82);break;
	  case 0x12: byte_out.write(0xc9);break;
	  case 0x13: byte_out.write(0x7d);break;
	  case 0x14: byte_out.write(0xfa);break;
	  case 0x15: byte_out.write(0x59);break;
	  case 0x16: byte_out.write(0x47);break;
	  case 0x17: byte_out.write(0xf0);break;
	  case 0x18: byte_out.write(0xad);break;
	  case 0x19: byte_out.write(0xd4);break;
      case 0x1a: byte_out.write(0xa2);break;
	  case 0x1b: byte_out.write(0xaf);break;
	  case 0x1c: byte_out.write(0x9c);break;
	  case 0x1d: byte_out.write(0xa4);break;
	  case 0x1e: byte_out.write(0x72);break;
	  case 0x1f: byte_out.write(0xc0);break;
	  case 0x20: byte_out.write(0xb7);break;
	  case 0x21: byte_out.write(0xfd);break;
	  case 0x22: byte_out.write(0x93);break;
	  case 0x23: byte_out.write(0x26);break;
	  case 0x24: byte_out.write(0x36);break;
	  case 0x25: byte_out.write(0x3f);break;
	  case 0x26: byte_out.write(0xf7);break;
	  case 0x27: byte_out.write(0xcc);break;
	  case 0x28: byte_out.write(0x34);break;
	  case 0x29: byte_out.write(0xa5);break;
	  case 0x2a: byte_out.write(0xe5);break;
	  case 0x2b: byte_out.write(0xf1);break;
	  case 0x2c: byte_out.write(0x71);break;
	  case 0x2d: byte_out.write(0xd8);break;
	  case 0x2e: byte_out.write(0x31);break;
	  case 0x2f: byte_out.write(0x15);break;
	  case 0x30: byte_out.write(0x04);break;
	  case 0x31: byte_out.write(0xc7);break;
	  case 0x32: byte_out.write(0x23);break;
	  case 0x33: byte_out.write(0xc3);break;
	  case 0x34: byte_out.write(0x18);break;
      case 0x35: byte_out.write(0x96);break;
	  case 0x36: byte_out.write(0x05);break;
	  case 0x37: byte_out.write(0x9a);break;
	  case 0x38: byte_out.write(0x07);break;
	  case 0x39: byte_out.write(0x12);break;
	  case 0x3a: byte_out.write(0x80);break;
	  case 0x3b: byte_out.write(0xe2);break;
	  case 0x3c: byte_out.write(0xeb);break;
	  case 0x3d: byte_out.write(0x27);break;
	  case 0x3e: byte_out.write(0xb2);break;
	  case 0x3f: byte_out.write(0x75);break;
	  case 0x40: byte_out.write(0x09);break;
	  case 0x41: byte_out.write(0x83);break;
	  case 0x42: byte_out.write(0x2c);break;
	  case 0x43: byte_out.write(0x1a);break;
	  case 0x44: byte_out.write(0x1b);break;
	  case 0x45: byte_out.write(0x6e);break;
	  case 0x46: byte_out.write(0x5a);break;
	  case 0x47: byte_out.write(0xa0);break;
	  case 0x48: byte_out.write(0x52);break;
	  case 0x49: byte_out.write(0x3b);break;
	  case 0x4a: byte_out.write(0xd6);break;
	  case 0x4b: byte_out.write(0xb3);break;
	  case 0x4c: byte_out.write(0x29);break;
	  case 0x4d: byte_out.write(0xe3);break;
	  case 0x4e: byte_out.write(0x2f);break;
	  case 0x4f: byte_out.write(0x84);break;
	  case 0x50: byte_out.write(0x53);break;
	  case 0x51: byte_out.write(0xd1);break;
	  case 0x52: byte_out.write(0x00);break;
	  case 0x53: byte_out.write(0xed);break;
	  case 0x54: byte_out.write(0x20);break;
	  case 0x55: byte_out.write(0xfc);break;
	  case 0x56: byte_out.write(0xb1);break;
	  case 0x57: byte_out.write(0x5b);break;
	  case 0x58: byte_out.write(0x6a);break;
	  case 0x59: byte_out.write(0xcb);break;
	  case 0x5a: byte_out.write(0xbe);break;
	  case 0x5b: byte_out.write(0x39);break;
	  case 0x5c: byte_out.write(0x4a);break;
	  case 0x5d: byte_out.write(0x4c);break;
	  case 0x5e: byte_out.write(0x58);break;
	  case 0x5f: byte_out.write(0xcf);break;
	  case 0x60: byte_out.write(0xd0);break;
	  case 0x61: byte_out.write(0xef);break;
	  case 0x62: byte_out.write(0xaa);break;
	  case 0x63: byte_out.write(0xfb);break;
	  case 0x64: byte_out.write(0x43);break;
	  case 0x65: byte_out.write(0x4d);break;
	  case 0x66: byte_out.write(0x33);break;
	  case 0x67: byte_out.write(0x85);break;
	  case 0x68: byte_out.write(0x45);break;
	  case 0x69: byte_out.write(0xf9);break;
	  case 0x6a: byte_out.write(0x02);break;
	  case 0x6b: byte_out.write(0x7f);break;
	  case 0x6c: byte_out.write(0x50);break;
	  case 0x6d: byte_out.write(0x3c);break;
	  case 0x6e: byte_out.write(0x9f);break;
	  case 0x6f: byte_out.write(0xa8);break;
	  case 0x70: byte_out.write(0x51);break;
	  case 0x71: byte_out.write(0xa3);break;
	  case 0x72: byte_out.write(0x40);break;
	  case 0x73: byte_out.write(0x8f);break;
	  case 0x74: byte_out.write(0x92);break;
	  case 0x75: byte_out.write(0x9d);break;
	  case 0x76: byte_out.write(0x38);break;
	  case 0x77: byte_out.write(0xf5);break;
	  case 0x78: byte_out.write(0xbc);break;
	  case 0x79: byte_out.write(0xb6);break;
	  case 0x7a: byte_out.write(0xda);break;
	  case 0x7b: byte_out.write(0x21);break;
	  case 0x7c: byte_out.write(0x10);break;
	  case 0x7d: byte_out.write(0xff);break;
	  case 0x7e: byte_out.write(0xf3);break;
	  case 0x7f: byte_out.write(0xd2);break;
	  case 0x80: byte_out.write(0xcd);break;
	  case 0x81: byte_out.write(0x0c);break;
	  case 0x82: byte_out.write(0x13);break;
	  case 0x83: byte_out.write(0xec);break;
	  case 0x84: byte_out.write(0x5f);break;
	  case 0x85: byte_out.write(0x97);break;
	  case 0x86: byte_out.write(0x44);break;
	  case 0x87: byte_out.write(0x17);break;
	  case 0x88: byte_out.write(0xc4);break;
	  case 0x89: byte_out.write(0xa7);break;
	  case 0x8a: byte_out.write(0x7e);break;
	  case 0x8b: byte_out.write(0x3d);break;
	  case 0x8c: byte_out.write(0x64);break;
	  case 0x8d: byte_out.write(0x5d);break;
	  case 0x8e: byte_out.write(0x19);break;
	  case 0x8f: byte_out.write(0x73);break;
	  case 0x90: byte_out.write(0x60);break;
	  case 0x91: byte_out.write(0x81);break;
	  case 0x92: byte_out.write(0x4f);break;
	  case 0x93: byte_out.write(0xdc);break;
	  case 0x94: byte_out.write(0x22);break;
	  case 0x95: byte_out.write(0x2a);break;
	  case 0x96: byte_out.write(0x90);break;
	  case 0x97: byte_out.write(0x88);break;
	  case 0x98: byte_out.write(0x46);break;
	  case 0x99: byte_out.write(0xee);break;
	  case 0x9a: byte_out.write(0xb8);break;
	  case 0x9b: byte_out.write(0x14);break;
	  case 0x9c: byte_out.write(0xde);break;
	  case 0x9d: byte_out.write(0x5e);break;
	  case 0x9e: byte_out.write(0x0b);break;
	  case 0x9f: byte_out.write(0xdb);break;
	  case 0xa0: byte_out.write(0xe0);break;
	  case 0xa1: byte_out.write(0x32);break;
	  case 0xa2: byte_out.write(0x3a);break;
	  case 0xa3: byte_out.write(0x0a);break;
	  case 0xa4: byte_out.write(0x49);break;
	  case 0xa5: byte_out.write(0x06);break;
	  case 0xa6: byte_out.write(0x24);break;
	  case 0xa7: byte_out.write(0x5c);break;
	  case 0xa8: byte_out.write(0xc2);break;
	  case 0xa9: byte_out.write(0xd3);break;
	  case 0xaa: byte_out.write(0xac);break;
	  case 0xab: byte_out.write(0x62);break;
	  case 0xac: byte_out.write(0x91);break;
	  case 0xad: byte_out.write(0x95);break;
	  case 0xae: byte_out.write(0xe4);break;
	  case 0xaf: byte_out.write(0x79);break;
	  case 0xb0: byte_out.write(0xe7);break;
	  case 0xb1: byte_out.write(0xc8);break;
	  case 0xb2: byte_out.write(0x37);break;
	  case 0xb3: byte_out.write(0x6d);break;
	  case 0xb4: byte_out.write(0x8d);break;
	  case 0xb5: byte_out.write(0xd5);break;
	  case 0xb6: byte_out.write(0x4e);break;
	  case 0xb7: byte_out.write(0xa9);break;
	  case 0xb8: byte_out.write(0x6c);break;
	  case 0xb9: byte_out.write(0x56);break;
	  case 0xba: byte_out.write(0xf4);break;
	  case 0xbb: byte_out.write(0xea);break;
	  case 0xbc: byte_out.write(0x65);break;
	  case 0xbd: byte_out.write(0x7a);break;
	  case 0xbe: byte_out.write(0xae);break;
	  case 0xbf: byte_out.write(0x08);break;
	  case 0xc0: byte_out.write(0xba);break;
	  case 0xc1: byte_out.write(0x78);break;
	  case 0xc2: byte_out.write(0x25);break;
	  case 0xc3: byte_out.write(0x2e);break;
	  case 0xc4: byte_out.write(0x1c);break;
	  case 0xc5: byte_out.write(0xa6);break;
	  case 0xc6: byte_out.write(0xb4);break;
	  case 0xc7: byte_out.write(0xc6);break;
	  case 0xc8: byte_out.write(0xe8);break;
	  case 0xc9: byte_out.write(0xdd);break;
	  case 0xca: byte_out.write(0x74);break;
	  case 0xcb: byte_out.write(0x1f);break;
	  case 0xcc: byte_out.write(0x4b);break;
	  case 0xcd: byte_out.write(0xbd);break;
	  case 0xce: byte_out.write(0x8b);break;
	  case 0xcf: byte_out.write(0x8a);break;
	  case 0xd0: byte_out.write(0x70);break;
	  case 0xd1: byte_out.write(0x3e);break;
	  case 0xd2: byte_out.write(0xb5);break;
	  case 0xd3: byte_out.write(0x66);break;
	  case 0xd4: byte_out.write(0x48);break;
	  case 0xd5: byte_out.write(0x03);break;
	  case 0xd6: byte_out.write(0xf6);break;
	  case 0xd7: byte_out.write(0x0e);break;
	  case 0xd8: byte_out.write(0x61);break;
	  case 0xd9: byte_out.write(0x35);break;
	  case 0xda: byte_out.write(0x57);break;
	  case 0xdb: byte_out.write(0xb9);break;
	  case 0xdc: byte_out.write(0x86);break;
	  case 0xdd: byte_out.write(0xc1);break;
	  case 0xde: byte_out.write(0x1d);break;
	  case 0xdf: byte_out.write(0x9e);break;
	  case 0xe0: byte_out.write(0xe1);break;
	  case 0xe1: byte_out.write(0xf8);break;
	  case 0xe2: byte_out.write(0x98);break;
	  case 0xe3: byte_out.write(0x11);break;
	  case 0xe4: byte_out.write(0x69);break;
	  case 0xe5: byte_out.write(0xd9);break;
	  case 0xe6: byte_out.write(0x8e);break;
	  case 0xe7: byte_out.write(0x94);break;
	  case 0xe8: byte_out.write(0x9b);break;
	  case 0xe9: byte_out.write(0x1e);break;
	  case 0xea: byte_out.write(0x87);break;
	  case 0xeb: byte_out.write(0xe9);break;
	  case 0xec: byte_out.write(0xce);break;
	  case 0xed: byte_out.write(0x55);break;
	  case 0xee: byte_out.write(0x28);break;
	  case 0xef: byte_out.write(0xdf);break;
	  case 0xf0: byte_out.write(0x8c);break;
	  case 0xf1: byte_out.write(0xa1);break;
	  case 0xf2: byte_out.write(0x89);break;
	  case 0xf3: byte_out.write(0x0d);break;
	  case 0xf4: byte_out.write(0xbf);break;
	  case 0xf5: byte_out.write(0xe6);break;
	  case 0xf6: byte_out.write(0x42);break;
	  case 0xf7: byte_out.write(0x68);break;
	  case 0xf8: byte_out.write(0x41);break;
	  case 0xf9: byte_out.write(0x99);break;
	  case 0xfa: byte_out.write(0x2d);break;
	  case 0xfb: byte_out.write(0x0f);break;
	  case 0xfc: byte_out.write(0xb0);break;
	  case 0xfd: byte_out.write(0x54);break;
	  case 0xfe: byte_out.write(0xbb);break;
	  case 0xff: byte_out.write(0x16);break;
	 }

	}


	// Process registration, sensitivity list
	SC_CTOR(sub_byte_unit)
	{
		SC_METHOD(s_box_lut);	
		sensitive<<byte_in;
	}


};

#endif