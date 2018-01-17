#include "AESUnit.h"
#include <systemc.h>
int sc_main(int argc, char* argv[]) {

    //sc_signal<bool> reset,req;   // Local signals

	sc_signal<sc_biguint<128>> data_in; // plain text
	sc_signal<sc_biguint<128>> key_0,key_1,key_2,key_3,key_4,key_5,key_6,key_7,key_8,key_9,key_10; // ten 10 keys
	sc_signal<sc_biguint<128>> data_out; // encrypted text
	sc_signal<sc_biguint<32>> word_out_3_1, word_out_2_1, word_out_1_1, word_out_0_1;
	sc_signal<sc_biguint<32>> word_out_3_2, word_out_2_2, word_out_1_2, word_out_0_2;
	sc_signal<sc_biguint<32>> word_out_3_3, word_out_2_3, word_out_1_3, word_out_0_3;
	sc_signal<sc_biguint<32>> word_out_3_4, word_out_2_4, word_out_1_4, word_out_0_4;
	sc_signal<sc_biguint<32>> word_out_3_5, word_out_2_5, word_out_1_5, word_out_0_5;
	sc_signal<sc_biguint<32>> word_out_3_6, word_out_2_6, word_out_1_6, word_out_0_6;
	sc_signal<sc_biguint<32>> word_out_3_7, word_out_2_7, word_out_1_7, word_out_0_7;
	sc_signal<sc_biguint<32>> word_out_3_8, word_out_2_8, word_out_1_8, word_out_0_8;
	sc_signal<sc_biguint<32>> word_out_3_9, word_out_2_9, word_out_1_9, word_out_0_9;
	sc_signal<sc_biguint<32>> word_out_3_10, word_out_2_10, word_out_1_10, word_out_0_10;

	sc_biguint<8> data_byte[16] = {0x32,0x43,0xf6,0xa8,0x88,0x5a,0x30,0x8d,0x31,0x31,0x98,0xa2,0xe0,0x37,0x07,0x34};
	sc_biguint<8> key_byte[16] = {0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};
	

	//sc_biguint<8> data_byte[16] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
	//sc_biguint<8> key_byte[16] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f};

    //sc_signal< sc_uint<3> > plane_number;	
    //sc_signal<bool> granted,denied;

	//unsigned int delay=100;
	//unsigned int plane=7;

    sc_clock clk("clk",10,SC_NS);       // Create a 10ns period clock signal
    /*
	// sc_clock signal( label, period, dutycycle, start_time, posedge_first);
    atc UUT("atc");           // Instantiate Device Under Test
    UUT.clk(clk);                       // Connect ports
    UUT.reset(reset); 
    UUT.req(req);
    UUT.plane_number(plane_number);
    UUT.granted(granted);
    UUT.denied(denied);
	*/
	AESUnit UUT1("AES");
	UUT1.clk(clk);
	UUT1.data_in(data_in);
	UUT1.key_0(key_0);
	UUT1.data_out(data_out);
	UUT1.key_1(key_1);
	UUT1.key_2(key_2);
	UUT1.key_3(key_3);
	UUT1.key_4(key_4);
	UUT1.key_5(key_5);
	UUT1.key_6(key_6);
	UUT1.key_7(key_7);
	UUT1.key_8(key_8);
	UUT1.key_9(key_9);
	UUT1.key_10(key_10);
	UUT1.word_out_3_1(word_out_3_1);UUT1.word_out_2_1(word_out_2_1);UUT1.word_out_1_1(word_out_1_1);UUT1.word_out_0_1(word_out_0_1);
	UUT1.word_out_3_2(word_out_3_2);UUT1.word_out_2_2(word_out_2_2);UUT1.word_out_1_2(word_out_1_2);UUT1.word_out_0_2(word_out_0_2);
	UUT1.word_out_3_3(word_out_3_3);UUT1.word_out_2_3(word_out_2_3);UUT1.word_out_1_3(word_out_1_3);UUT1.word_out_0_3(word_out_0_3);
	UUT1.word_out_3_4(word_out_3_4);UUT1.word_out_2_4(word_out_2_4);UUT1.word_out_1_4(word_out_1_4);UUT1.word_out_0_4(word_out_0_4);
	UUT1.word_out_3_5(word_out_3_5);UUT1.word_out_2_5(word_out_2_5);UUT1.word_out_1_5(word_out_1_5);UUT1.word_out_0_5(word_out_0_5);
	UUT1.word_out_3_6(word_out_3_6);UUT1.word_out_2_6(word_out_2_6);UUT1.word_out_1_6(word_out_1_6);UUT1.word_out_0_6(word_out_0_6);
	UUT1.word_out_3_7(word_out_3_7);UUT1.word_out_2_7(word_out_2_7);UUT1.word_out_1_7(word_out_1_7);UUT1.word_out_0_7(word_out_0_7);
	UUT1.word_out_3_8(word_out_3_8);UUT1.word_out_2_8(word_out_2_8);UUT1.word_out_1_8(word_out_1_8);UUT1.word_out_0_8(word_out_0_8);
	UUT1.word_out_3_9(word_out_3_9);UUT1.word_out_2_9(word_out_2_9);UUT1.word_out_1_9(word_out_1_9);UUT1.word_out_0_9(word_out_0_9);
	UUT1.word_out_3_10(word_out_3_10);UUT1.word_out_2_10(word_out_2_10);UUT1.word_out_1_10(word_out_1_10);UUT1.word_out_0_10(word_out_0_10);


    sc_trace_file *fp;                  // VCD filepointer
    fp=sc_create_vcd_trace_file("wave");// Create wave.vcd file
	sc_trace(fp,data_in,"data_in");
	sc_trace(fp,data_out,"data_out");
	sc_trace(fp,key_0,"key");
	sc_trace(fp,clk,"clk");
	sc_trace(fp,key_1,"key_1");
	sc_trace(fp,key_2,"key_2");
	sc_trace(fp,key_3,"key_3");
	sc_trace(fp,key_4,"key_4");
	sc_trace(fp,key_5,"key_5");
	sc_trace(fp,key_6,"key_6");
	sc_trace(fp,key_7,"key_7");
	sc_trace(fp,key_8,"key_8");
	sc_trace(fp,key_9,"key_9");
	sc_trace(fp,key_10,"key_10");
	sc_trace(fp,word_out_3_1,"word_out_3_1");sc_trace(fp,word_out_2_1,"word_out_2_1");sc_trace(fp,word_out_1_1,"word_out_1_1");sc_trace(fp,word_out_0_1,"word_out_0_1");
	sc_trace(fp,word_out_3_2,"word_out_3_2");sc_trace(fp,word_out_2_2,"word_out_2_2");sc_trace(fp,word_out_1_2,"word_out_1_2");sc_trace(fp,word_out_0_2,"word_out_0_2");
	sc_trace(fp,word_out_3_3,"word_out_3_3");sc_trace(fp,word_out_2_3,"word_out_2_3");sc_trace(fp,word_out_1_3,"word_out_1_3");sc_trace(fp,word_out_0_3,"word_out_0_3");
	sc_trace(fp,word_out_3_4,"word_out_3_4");sc_trace(fp,word_out_2_4,"word_out_2_4");sc_trace(fp,word_out_1_4,"word_out_1_4");sc_trace(fp,word_out_0_4,"word_out_0_4");
	sc_trace(fp,word_out_3_5,"word_out_3_5");sc_trace(fp,word_out_2_5,"word_out_2_5");sc_trace(fp,word_out_1_5,"word_out_1_5");sc_trace(fp,word_out_0_5,"word_out_0_5");
	sc_trace(fp,word_out_3_6,"word_out_3_6");sc_trace(fp,word_out_2_6,"word_out_2_6");sc_trace(fp,word_out_1_6,"word_out_1_6");sc_trace(fp,word_out_0_6,"word_out_0_6");
	sc_trace(fp,word_out_3_7,"word_out_3_7");sc_trace(fp,word_out_2_7,"word_out_2_7");sc_trace(fp,word_out_1_7,"word_out_1_7");sc_trace(fp,word_out_0_7,"word_out_0_7");
	sc_trace(fp,word_out_3_8,"word_out_3_8");sc_trace(fp,word_out_2_8,"word_out_2_8");sc_trace(fp,word_out_1_8,"word_out_1_8");sc_trace(fp,word_out_0_8,"word_out_0_8");
	sc_trace(fp,word_out_3_9,"word_out_3_9");sc_trace(fp,word_out_2_9,"word_out_2_9");sc_trace(fp,word_out_1_9,"word_out_1_9");sc_trace(fp,word_out_0_9,"word_out_0_9");
	sc_trace(fp,word_out_3_10,"word_out_3_10");sc_trace(fp,word_out_2_10,"word_out_2_10");sc_trace(fp,word_out_1_10,"word_out_1_10");sc_trace(fp,word_out_0_10,"word_out_0_10");
	
	
	sc_start(7.5, SC_NS);				// just so that data changes 25% * duty cycle before ACT
	data_in.write((data_byte[0],data_byte[1],data_byte[2],data_byte[3],data_byte[4],data_byte[5],data_byte[6],data_byte[7],data_byte[8],data_byte[9],data_byte[10],data_byte[11],data_byte[12],data_byte[13],data_byte[14],data_byte[15]));
	key_0.write((key_byte[0],key_byte[1],key_byte[2],key_byte[3],key_byte[4],key_byte[5],key_byte[6],key_byte[7],key_byte[8],key_byte[9],key_byte[10],key_byte[11],key_byte[12],key_byte[13],key_byte[14],key_byte[15]));
    
	
	
	sc_start(20, SC_NS);               // Run simulation for 100 ns
	cout<<"data "<<data_in.read()<<"\n";
	cout<<"Key "<<key_0.read()<<"\n";
    sc_start(20, SC_NS);
	cout<<"data "<<data_in.read()<<"\n";
	cout<<"Key "<<key_0.read()<<"\n";
   
   sc_start(200, SC_NS);
   sc_start(200, SC_NS);
   sc_start(200, SC_NS);
   sc_start(200, SC_NS);
   sc_start(200, SC_NS);
   sc_start(200, SC_NS);

	
    sc_close_vcd_trace_file(fp);        // close wave.vcd
	system("..\\..\\..\\..\\GTKWave\\bin\\gtkwave.exe wave.vcd");
    return 0;                           
}            
