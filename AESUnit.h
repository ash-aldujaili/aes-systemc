#include <systemc.h>


#include "EncryptUnit.h"
#include "KeyExpansionUnit.h"

#ifndef AES_H
#define AES_H

SC_MODULE(AESUnit)
{
	//i/o signals:
	sc_in<bool> clk;
	sc_in<sc_biguint<128>> data_in;
	sc_in<sc_biguint<128>> key_0;
	sc_out<sc_biguint<128>> data_out;


	//internal signals
	sc_out<sc_biguint<128>> key_1,key_2,key_3,key_4,key_5,key_6,key_7,key_8,key_9,key_10;
    sc_out<sc_biguint<32>> word_out_3_1, word_out_2_1, word_out_1_1, word_out_0_1;
	sc_out<sc_biguint<32>> word_out_3_2, word_out_2_2, word_out_1_2, word_out_0_2;
	sc_out<sc_biguint<32>> word_out_3_3, word_out_2_3, word_out_1_3, word_out_0_3;
	sc_out<sc_biguint<32>> word_out_3_4, word_out_2_4, word_out_1_4, word_out_0_4;
	sc_out<sc_biguint<32>> word_out_3_5, word_out_2_5, word_out_1_5, word_out_0_5;
	sc_out<sc_biguint<32>> word_out_3_6, word_out_2_6, word_out_1_6, word_out_0_6;
	sc_out<sc_biguint<32>> word_out_3_7, word_out_2_7, word_out_1_7, word_out_0_7;
	sc_out<sc_biguint<32>> word_out_3_8, word_out_2_8, word_out_1_8, word_out_0_8;
	sc_out<sc_biguint<32>> word_out_3_9, word_out_2_9, word_out_1_9, word_out_0_9;
	sc_out<sc_biguint<32>> word_out_3_10, word_out_2_10, word_out_1_10, word_out_0_10;

	//instantiate the units:
	KeyExpansionUnit *key_exp_u;
	EncryptUnit		 *encr_u;


	SC_CTOR(AESUnit)
	{
		key_exp_u = new KeyExpansionUnit ("key_expansion_unit");
		key_exp_u->clk(clk);
		key_exp_u->key_0(key_0);
		key_exp_u->key_1(key_1);
		key_exp_u->key_2(key_2);
		key_exp_u->key_3(key_3);
		key_exp_u->key_4(key_4);
		key_exp_u->key_5(key_5);
		key_exp_u->key_6(key_6);
		key_exp_u->key_7(key_7);
		key_exp_u->key_8(key_8);
		key_exp_u->key_9(key_9);
		key_exp_u->key_10(key_10);
		key_exp_u->word_out_3_1(word_out_3_1);key_exp_u->word_out_2_1(word_out_2_1);key_exp_u->word_out_1_1(word_out_1_1);key_exp_u->word_out_0_1(word_out_0_1);
		key_exp_u->word_out_3_2(word_out_3_2);key_exp_u->word_out_2_2(word_out_2_2);key_exp_u->word_out_1_2(word_out_1_2);key_exp_u->word_out_0_2(word_out_0_2);
		key_exp_u->word_out_3_3(word_out_3_3);key_exp_u->word_out_2_3(word_out_2_3);key_exp_u->word_out_1_3(word_out_1_3);key_exp_u->word_out_0_3(word_out_0_3);
		key_exp_u->word_out_3_4(word_out_3_4);key_exp_u->word_out_2_4(word_out_2_4);key_exp_u->word_out_1_4(word_out_1_4);key_exp_u->word_out_0_4(word_out_0_4);
		key_exp_u->word_out_3_5(word_out_3_5);key_exp_u->word_out_2_5(word_out_2_5);key_exp_u->word_out_1_5(word_out_1_5);key_exp_u->word_out_0_5(word_out_0_5);
		key_exp_u->word_out_3_6(word_out_3_6);key_exp_u->word_out_2_6(word_out_2_6);key_exp_u->word_out_1_6(word_out_1_6);key_exp_u->word_out_0_6(word_out_0_6);
		key_exp_u->word_out_3_7(word_out_3_7);key_exp_u->word_out_2_7(word_out_2_7);key_exp_u->word_out_1_7(word_out_1_7);key_exp_u->word_out_0_7(word_out_0_7);
		key_exp_u->word_out_3_8(word_out_3_8);key_exp_u->word_out_2_8(word_out_2_8);key_exp_u->word_out_1_8(word_out_1_8);key_exp_u->word_out_0_8(word_out_0_8);
		key_exp_u->word_out_3_9(word_out_3_9);key_exp_u->word_out_2_9(word_out_2_9);key_exp_u->word_out_1_9(word_out_1_9);key_exp_u->word_out_0_9(word_out_0_9);
		key_exp_u->word_out_3_10(word_out_3_10);key_exp_u->word_out_2_10(word_out_2_10);key_exp_u->word_out_1_10(word_out_1_10);key_exp_u->word_out_0_10(word_out_0_10);
		
		encr_u = new EncryptUnit("encrypt_unit");
		encr_u->clk(clk);
		encr_u->key_0(key_0);
		encr_u->key_1(key_1);
		encr_u->key_2(key_2);
		encr_u->key_3(key_3);
		encr_u->key_4(key_4);
		encr_u->key_5(key_5);
		encr_u->key_6(key_6);
		encr_u->key_7(key_7);
		encr_u->key_8(key_8);
		encr_u->key_9(key_9);
		encr_u->key_10(key_10);
		encr_u->data_in(data_in);
		encr_u->data_out(data_out);

		
	}

};
#endif