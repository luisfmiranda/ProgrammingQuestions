#include <iostream>

using namespace std;

/*
 * - Problem:
 * Reverse bits
 *
 * - Problem description:
 * Reverse bits of an 32 bit unsigned integer
 */

unsigned swapBits(unsigned n, unsigned leftOffset, unsigned rightOffset) {
    unsigned leftBit = ((n >> leftOffset) & 1);
    unsigned rightBit = ((n >> rightOffset) & 1);

    if (leftBit ^ rightBit) { // if the value of the bits are different
        n ^= ((1U << leftOffset) | (1U << rightOffset)); // swap the bits
    }

    return n;
}

unsigned reverseBits(unsigned n) {
    unsigned numBits = sizeof(n) * 8;

    // will go from the borders to the center
    for (unsigned i = 0; i < (numBits / 2); i++) {
        n = swapBits(n, i, numBits - i - 1);
    }

    return n;
}

void reverseBitsTester() {
    cout << reverseBits(3);
}
