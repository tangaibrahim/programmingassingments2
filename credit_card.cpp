#include <iostream>

using namespace std;

// Function declarations
bool isValid(long long number);
int sumOfDoubleEvenPlace(long long number);
int getDigit(int number);
int sumOfOddPlace(long long number);
bool prefixMatched(long long number, int d);
int getSize(long long d);
long long getPrefix(long long number, int k);

int main() {
    long long cardNumber;
    cout << "Enter a credit card number as a long integer: ";
    cin >> cardNumber;

    if (isValid(cardNumber)) {
        cout << cardNumber << " is valid" << endl;
    } else {
        cout << cardNumber << " is invalid" << endl;
    }

    return 0;
}

// Return true if the card number is valid
bool isValid(long long number) {
    int size = getSize(number);
    bool validSize = (size >= 13 && size <= 16);
    
    // Check valid card vendor prefixes: 4 (Visa), 5 (MasterCard), 37 (Amex), 6 (Discover)
    bool validPrefix = prefixMatched(number, 4) || 
                       prefixMatched(number, 5) || 
                       prefixMatched(number, 37) || 
                       prefixMatched(number, 6);

    int totalSum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);

    return validSize && validPrefix && (totalSum % 10 == 0);
}

// Get the result from Step 2 (doubling even-placed digits from right to left)
int sumOfDoubleEvenPlace(long long number) {
    int sum = 0;
    number /= 10; // Shift to start at the 2nd digit from the right
    while (number > 0) {
        int doubledDigit = (number % 10) * 2;
        sum += getDigit(doubledDigit);
        number /= 100; // Skip to the next even-placed digit
    }
    return sum;
}

// Return this number if it is a single digit, otherwise return the sum of the two digits
int getDigit(int number) {
    if (number < 10) {
        return number;
    }
    return (number / 10) + (number % 10);
}

// Return sum of odd-placed digits in number from right to left
int sumOfOddPlace(long long number) {
    int sum = 0;
    while (number > 0) {
        sum += (number % 10);
        number /= 100; // Skip to the next odd-placed digit
    }
    return sum;
}

// Return true if digit d is a prefix for number
bool prefixMatched(long long number, int d) {
    int dSize = getSize(d);
    return getPrefix(number, dSize) == d;
}

// Return the number of digits in d
int getSize(long long d) {
    if (d == 0) return 1;
    int count = 0;
    while (d > 0) {
        count++;
        d /= 10;
    }
    return count;
}

// Return the first k digits from number. If number has fewer than k digits, return number.
long long getPrefix(long long number, int k) {
    int numSize = getSize(number);
    if (numSize < k) {
        return number;
    }
    long long divisor = 1;
    for (int i = 0; i < numSize - k; i++) {
        divisor *= 10;
    }
    return number / divisor;
}
