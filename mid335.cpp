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
    double tol = 0.0;

    if (argc != 4) {
        cout << "Usage: " << argv[0] << " <NOTE>  <OCTAVE_DELTA> <TOLERANCE>" << endl;
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
    tol = atof(argv[3]);
    int badElem = 0;
    double diff = 0.0;
    double C = 16.35;
    double C_sharp = 17.32;
    double D = 18.35;
    double D_sharp = 19.45;
    double E = 20.60;
    double F = 21.83;
    double F_sharp = 23.12;
    double G = 24.50;
    double G_sharp = 25.96;
    double A = 27.50;
    double A_sharp = 29.14;
    double B = 30.87;
    
    if(note == Z && octave_delta == 0) {
        for (int i = 0; i <= 8; i++) {
            for(int j = 1; j <= 12; j++) {
                
                if(j >= 10)
                    cout << " " << j << "    " << i << "    "; 
                if(j < 10) { 
                    cout << " " << j << "     " << i << "    "; 
                }
                cout << freq((note_t)j, i);
                
                if(j == 1) {
                    diff = fabs(freq((note_t)j, i) - C);
                    cout << " " << diff;
                    if(diff > tol) {
                        cout << "  <------bad" << endl;
                        badElem++;
                    } else {
                        cout << "     good" << endl;
                    }
                } else if( j == 2) {
                    diff = fabs(freq((note_t)j, i) - C_sharp);
                    cout << " " << diff;
                    if(diff > tol) {
                        cout << "  <------bad" << endl;
                        badElem++;
                    } else {
                        cout << "     good" << endl;
                    }
                } else if(j == 3) {
                    diff = fabs(freq((note_t)j, i) - D);
                    cout << " " << diff;
                    if(diff > tol) {
                        cout << "  <------bad" << endl;
                        badElem++;
                    } else {
                        cout << "     good" << endl;
                    }
                } else if(j == 4) {
                    diff = fabs(freq((note_t)j, i) - D_sharp);
                    cout << " " << diff;
                    if(diff > tol) {
                        cout << "  <------bad" << endl;
                        badElem++;
                    } else {
                        cout << "     good" << endl;
                    }
                } else if(j == 5) {
                    diff = fabs(freq((note_t)j, i) - E);
                    cout << " " << diff;
                    if(diff > tol) {
                        cout << "  <------bad" << endl;
                        badElem++;
                    } else {
                        cout << "     good" << endl;
                    }
                } else if(j == 6) {
                    diff = fabs(freq((note_t)j, i) - F);
                    cout << " " << diff;
                    if(diff > tol) {
                        cout << "  <------bad" << endl;
                        badElem++;
                    } else {
                        cout << "     good" << endl;
                    }
                } else if(j == 7) {
                    diff = fabs(freq((note_t)j, i) - F_sharp);
                    cout << " " << diff;
                    if(diff > tol) {
                        cout << "  <------bad" << endl;
                        badElem++;
                    } else {
                        cout << "     good" << endl;
                    }
                } else if(j == 8) {
                    diff = fabs(freq((note_t)j, i) - G);
                    cout << " " << diff;
                    if(diff > tol) {
                        cout << "  <------bad" << endl;
                        badElem++;
                    } else {
                        cout << "     good" << endl;
                    }
                } else if(j == 9) {
                    diff = fabs(freq((note_t)j, i) - G_sharp);
                    cout << " " << diff;
                    if(diff > tol) {
                        cout << "  <------bad" << endl;
                        badElem++;
                    } else {
                        cout << "     good" << endl;
                    }
                } else if(j == 10) {
                    diff = fabs(freq((note_t)j, i) - A);
                    cout << " " << diff;
                    if(diff > tol) {
                        cout << "  <------bad" << endl;
                        badElem++;
                    } else {
                        cout << "     good" << endl;
                    }
                } else if(j == 11) {
                    diff = fabs(freq((note_t)j, i) - A_sharp);
                    cout << " " << diff;
                    if(diff > tol) {
                        cout << "  <------bad" << endl;
                        badElem++;
                    } else {
                        cout << "     good" << endl;
                    }
                } else if(j == 12) {
                    diff = fabs(freq((note_t)j, i) - B);
                    cout << " " << diff;
                    if(diff > tol) {
                        cout << "  <------bad" << endl;
                        badElem++;
                    } else {
                        cout << "     good" << endl;
                    }
                }
            }
            C *= 2.0;
            C_sharp *= 2.0;
            D *= 2.0;
            D_sharp *= 2.0;
            E *= 2.0;
            F *= 2.0;
            F_sharp *= 2.0;
            G *= 2.0;
            G_sharp *= 2.0;
            A *= 2.0;
            A_sharp *= 2.0;
            B *= 2.0;
        }
    }
    cout << "bad element count: " << badElem << endl;
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
