#include <systemc.h>

#include "InitialRoundUnit.h"
#include "MiddleRoundUnit.h"
#include "FinalRoundUnit.h"

#ifndef ENCRYPT_H
#define ENCRYPT_H

SC_MODULE(EncryptUnit)
{
	//I/O signals:
	sc_in<bool> clk;
	sc_in<sc_biguint<128>> data_in; // plain text
	sc_in<sc_biguint<128>> key_0,key_1,key_2,key_3,key_4,key_5,key_6,key_7,key_8,key_9,key_10; // ten 10 keys
	sc_out<sc_biguint<128>> data_out; // encrypted text

	// internal signals
	sc_signal<sc_biguint<128>> data_reg[11], data_next[11];
	sc_signal<sc_biguint<128>> data_out_init_round, data_out_final_round,data_out_middle_round[9];
	// Process
	void comb_logic()
	{
		int i;
		data_next[0]=data_out_init_round;
		data_next[10]=data_out_final_round;
		for(i=0;i<9;i++)
			data_next[i+1]=data_out_middle_round[i];
		data_out.write(data_reg[10]);
	}
	//
	void seq_logic()
	{
		int i;
		for (i=0;i<11;i++)
			data_reg[i]=data_next[i];
	}
	// Instantiation

	InitialRoundUnit *init_rnd_u;
	MiddleRoundUnit	 *mid_rnd_u_0;
	MiddleRoundUnit	 *mid_rnd_u_1;
	MiddleRoundUnit	 *mid_rnd_u_2;
	MiddleRoundUnit	 *mid_rnd_u_3;
	MiddleRoundUnit	 *mid_rnd_u_4;
	MiddleRoundUnit	 *mid_rnd_u_5;
	MiddleRoundUnit	 *mid_rnd_u_6;
	MiddleRoundUnit	 *mid_rnd_u_7;
	MiddleRoundUnit	 *mid_rnd_u_8;
	MiddleRoundUnit	 *mid_rnd_u_9;
	FinalRoundUnit	 *fin_rnd_u;


	SC_CTOR(EncryptUnit)
	{
		int i,j;
		// seq_logic process
		SC_METHOD(seq_logic);
		sensitive<<clk.pos();
		// comb_logic process
		SC_METHOD(comb_logic);
		sensitive<<data_out_init_round<<data_out_final_round<<data_reg[10];
		for(i=0;i<9;i++)
			sensitive<<data_out_middle_round[i];

		// Binding
		init_rnd_u = new InitialRoundUnit("init_round");
		init_rnd_u->data_in(data_in);
		init_rnd_u->key(key_0);
		init_rnd_u->data_out(data_out_init_round);

		
			mid_rnd_u_0= new MiddleRoundUnit("mid_round0");
			mid_rnd_u_0->data_in(data_reg[0]);
			mid_rnd_u_0->key(key_1);
			mid_rnd_u_0->data_out(data_out_middle_round[0]);

			mid_rnd_u_1= new MiddleRoundUnit("mid_round1");
			mid_rnd_u_1->data_in(data_reg[1]);
			mid_rnd_u_1->key(key_2);
			mid_rnd_u_1->data_out(data_out_middle_round[1]);

			mid_rnd_u_2= new MiddleRoundUnit("mid_round2");
			mid_rnd_u_2->data_in(data_reg[2]);
			mid_rnd_u_2->key(key_3);
			mid_rnd_u_2->data_out(data_out_middle_round[2]);

			mid_rnd_u_3= new MiddleRoundUnit("mid_round3");
			mid_rnd_u_3->data_in(data_reg[3]);
			mid_rnd_u_3->key(key_4);
			mid_rnd_u_3->data_out(data_out_middle_round[3]);

			mid_rnd_u_4= new MiddleRoundUnit("mid_round4");
			mid_rnd_u_4->data_in(data_reg[4]);
			mid_rnd_u_4->key(key_5);
			mid_rnd_u_4->data_out(data_out_middle_round[4]);

			mid_rnd_u_5= new MiddleRoundUnit("mid_round5");
			mid_rnd_u_5->data_in(data_reg[5]);
			mid_rnd_u_5->key(key_6);
			mid_rnd_u_5->data_out(data_out_middle_round[5]);

			mid_rnd_u_6= new MiddleRoundUnit("mid_round6");
			mid_rnd_u_6->data_in(data_reg[6]);
			mid_rnd_u_6->key(key_7);
			mid_rnd_u_6->data_out(data_out_middle_round[6]);

			mid_rnd_u_7= new MiddleRoundUnit("mid_round7");
			mid_rnd_u_7->data_in(data_reg[7]);
			mid_rnd_u_7->key(key_8);
			mid_rnd_u_7->data_out(data_out_middle_round[7]);

			mid_rnd_u_8= new MiddleRoundUnit("mid_round8");
			mid_rnd_u_8->data_in(data_reg[8]);
			mid_rnd_u_8->key(key_9);
			mid_rnd_u_8->data_out(data_out_middle_round[8]);

		

		fin_rnd_u = new FinalRoundUnit("fin_round");
		fin_rnd_u->data_in(data_reg[9]);
		fin_rnd_u->key(key_10);
		fin_rnd_u->data_out(data_out_final_round);





	}

};

#endif