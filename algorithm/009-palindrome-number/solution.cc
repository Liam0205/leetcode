class Solution {
public:
    bool isPalindrome(int num) {
        if (num < 0 || (num != 0 && num % 10 == 0))
            // if the integer is negtive or
            // if the integer is ended with an zero
            // then the reverse of it must not equal to itself
            return false;
        int reversed = 0;
        while (reversed < num) {
            // we only have to check about half of the length
            // remember that:
            // At the END of while circle,
            // the length of reversed is equal to that of num, or
            // the length of reversed is longer than that of num by 1 digit
            reversed = 10 * reversed + num % 10;
            num     /= 10;
        }
        return (reversed == num || reversed / 10 == num);
    }
};
