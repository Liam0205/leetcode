class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t result;
        while (n) {
            result += 1 & n;
            n       = n >> 1;
        }
        return result;
    }
};
