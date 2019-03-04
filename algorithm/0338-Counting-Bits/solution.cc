class Solution {
public:
    vector<int> countBits(int num) {
        std::vector<int> res;
        res.resize(num + 1);
        for (size_t i = 0; i != num + 1; ++i) {
            res[i] = calculateHammingWeight(i);
        }
        return res;
    }

private:
    int calculateHammingWeight(int num) {
        int res = 0;
        while (num) {
            res += num & 0x01;
            num >>= 1;
        }
        return res;
    }
};
