#include "KeyGenUnit.h"
#include <systemc.h>
int sc_main(int argc, char* argv[]) {

    //sc_signal<bool> reset,req;   // Local signals

	sc_signal<sc_biguint<128>> key_in; // plain text
	sc_signal<sc_biguint<128>> key_out; // encrypted text
	sc_signal<sc_lv<4>> encr_round;
	sc_signal<sc_biguint<32>> word_out_3,word_out_2,word_out_1,word_out_0;
	sc_signal<sc_biguint<32>> rcon_byte;


	sc_lv<4> encr_round_val = "0001";
	sc_biguint<8> key_byte[16] = {0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};

    sc_clock clk("clk",10,SC_NS);       // Create a 10ns period clock signal

	KeyGenUnit UUT1("KeyGenUnit");
	UUT1.key_in(key_in);
	UUT1.key_out(key_out);
	UUT1.encr_round(encr_round);
	UUT1.word_out_3(word_out_3);
	UUT1.word_out_2(word_out_2);
	UUT1.word_out_1(word_out_1);
	UUT1.word_out_0(word_out_0);
	UUT1.rcon_byte(rcon_byte);
	

    sc_trace_file *fp;                  // VCD filepointer
    fp=sc_create_vcd_trace_file("wave");// Create wave.vcd file
	sc_trace(fp,key_in,"key_in");
	sc_trace(fp,key_out,"key_out");
	sc_trace(fp,clk,"clk");
	sc_trace(fp,encr_round,"encr_round");
	sc_trace(fp,word_out_3,"word_out_3");
	sc_trace(fp,word_out_2,"word_out_2");
	sc_trace(fp,word_out_1,"word_out_1");
	sc_trace(fp,word_out_0,"word_out_0");
	sc_trace(fp,rcon_byte,"rcon_byte");

	
	
	sc_start(7.5, SC_NS);				// just so that data changes 25% * duty cycle before ACT
	encr_round.write(encr_round_val);
	key_in.write((key_byte[0],key_byte[1],key_byte[2],key_byte[3],key_byte[4],key_byte[5],key_byte[6],key_byte[7],key_byte[8],key_byte[9],key_byte[10],key_byte[11],key_byte[12],key_byte[13],key_byte[14],key_byte[15]));
    
	
	
	sc_start(20, SC_NS);               // Run simulation for 100 ns
    sc_start(20, SC_NS);

   
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
