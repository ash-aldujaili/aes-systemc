
#include <systemc.h>

// DFF using SC_METHOD – dff.h
SC_MODULE(dff) {
    sc_in<bool > clk;
    sc_in<bool > din;
    sc_out<bool > dout;
 
    void tff_proc() {
        dout.write(din.read());
    } 

    SC_CTOR(dff) {
        SC_METHOD(tff_proc);
           sensitive << clk.pos();
    }

};