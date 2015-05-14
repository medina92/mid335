//CMPS 335
//mid335.cpp
//
//
//
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

//frequency definitions
#define A4 440.0
#define F0 A4
#define F0_note A
#define F0_octave 4

typedef enum {
    C = 1,
    Cs,
    D,
    Ds,
    E,
    F,
    Fs,
    G,
    Gs,
    A,
    As,
    B,
    Z,
    END = B,
    HALF_STEPS_PER_OCTAVE = B 
} note_t;

double freq(note_t note, int octave_delta);

int main(int argc, char *argv[])
{
    note_t note;
    int octave_delta;

    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <NOTE>  <OCTAVE_DELTA>" << endl;
        return 0;
    }
    //
    note = (note_t)(toupper(argv[1][0]) - 64);
    switch(toupper(argv[1][0])) {
        case 'A': note = A; break;
        case 'B': note = B; break;
        case 'C': note = C; break;
        case 'D': note = D; break;
        case 'E': note = E; break;
        case 'F': note = F; break;
        case 'Z': note = Z; break;
    }
    //You may call your unit test here...
    cout << "freq function unit-test\n" << endl;    
    cout << "note octave value   diff" << endl;
    cout << "---- ------ ------- ----------" << endl;
    octave_delta = atoi(argv[2]);

    if(note == Z && octave_delta == 0) {
        for (int i = 0; i <= 8; i++) {
            for(int j = 1; j <= 12; j++) {
                
                if(j >= 10)
                    cout << " " << j << "    " << i << "    "; 
                if(j < 10) { 
                    cout << " " << j << "     " << i << "    "; 
                }
                cout << freq((note_t)j, i) << endl;
            }
        }
    }
    cout << "unit test complete" << endl;
    
    if (note > END && note != Z) {
        cout << "Invalid note!" << endl;
        return 1;
    }
    if(note != Z) {
        cout << HALF_STEPS_PER_OCTAVE << endl;
        cout << freq(note, octave_delta) << endl;
    }
    return 0;
}

//-----------------------------------------------------------
//Generate a frequency in hz that is half_steps away from C_4
//Do not modify this function.
//-----------------------------------------------------------
double freq(note_t note, int octave_delta)
{
    double freq;
    double factor;
    double a;
    int n;
    int octave = octave_delta - F0_octave;

    a = pow(2.0, 1.0/(double)HALF_STEPS_PER_OCTAVE);
    n = note - F0_note;
    freq = F0 * pow(a, (double)n);
    factor = pow(2.0, (double)octave);
    freq = freq * factor;
    return freq;
}