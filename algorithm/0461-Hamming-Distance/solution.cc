class Solution {
public:
    int hammingDistance(int x, int y) {
        int res  = 0;
        for (int work = x ^ y; work != 0; work &= (work - 1)) {
            ++res;
        }
        return res;
    }
};
