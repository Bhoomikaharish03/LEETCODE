#include <limits.h> // For INT_MAX

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending with 0 (except 0 itself) are not
        // palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed = 0;
        int original = x; // Store the original value of x

        while (x > 0) {
            int digit = x % 10;

            // Check for overflow before reversing
            if (reversed > (INT_MAX - digit) / 10) {
                return false; // Return false if overflow would occur
            }

            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return reversed == original; // Compare reversed with original
    }
};
