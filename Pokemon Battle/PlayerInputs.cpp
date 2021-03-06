/* PlayerInputs.cpp
   Jay-Mark Pascua
   CS 201
   04/10/2020
   Handles player inputs
*/

#include "Pokemon.h"


int selectOption() {
    Sleep(200); // Delays input so return ints don't carry into the next selectOption() call
    while (true) {
        if (GetAsyncKeyState('1') < 0) { // Return ints start at 0 to accomodate vector indexes
                return 0;
        }
        if (GetAsyncKeyState('2') < 0) {
                return 1;
        }
        if (GetAsyncKeyState('3') < 0) {
                return 2;
        }
        if (GetAsyncKeyState('4') < 0) {
                return 3;
        }
        if (GetAsyncKeyState('5') < 0) {
                return 4;
        }
    }
}