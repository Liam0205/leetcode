class Solution {
public:
    int fourSumCount(const std::vector<int>& A,
                     const std::vector<int>& B,
                     const std::vector<int>& C,
                     const std::vector<int>& D) {
        std::unordered_map<int, size_t> half_sum;
        for (auto a : A) {
            for (auto b: B) {
                auto sum = a + b;
                if (half_sum.find(sum) ==  half_sum.end()) {
                    half_sum.insert({sum, 1});
                } else {
                    ++half_sum[sum];
                }
            }
        }
        size_t res = 0;
        for (auto c : C) {
            for (auto d : D) {
                auto sum = c + d;
                if (half_sum.find(-sum) != half_sum.end()) {
                    res += half_sum[-sum];
                }
            }
        }
        return res;
    }
};

