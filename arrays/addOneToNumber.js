/*
 * - Problem:
 * InterviewBit - Add One to Number
 *
 * - Problem description:
 * Given a non-negative number represented as an array of digits, add 1 to the number (increment the number represented
 * by the digits). The digits are stored such that the most significant digit is at the head of the list.
 */

function removeLeadingZeros(array) {
    while (array[0] === 0)
        array.shift();
}

function addOneToNumber(digits) {
    removeLeadingZeros(digits);
    digits.reverse();

    let carryOne = true; // means that we want to add one to the number
    for (let i = 0; i < digits.length; i++) { // goes from the least to the most significant digit
        let currDigit = digits[i];

        if (carryOne)
            currDigit++;

        if (currDigit < 10) {
            digits[i] = currDigit;
            carryOne = false;
        } else {
            digits[i] = 0;
            carryOne = true;
        }
    }

    // after covering all the digits, if carry one is still true, we need to add one in the most significant place
    if (carryOne)
        digits.push(1);

    return digits.reverse();
}

function addOneToNumberTester() {
    console.log(addOneToNumber([0, 0, 1, 0, 0, 0]));
}

addOneToNumberTester();
