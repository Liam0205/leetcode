class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;  // 1111 1111 1111 1111 1111 1111 1111 1111
        while (mask & num) {     // for effective bits, do not mask them
            mask <<= 1;
        }
        return ~mask & ~num;
    }
};
