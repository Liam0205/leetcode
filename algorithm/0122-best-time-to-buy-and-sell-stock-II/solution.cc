class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        const size_t sz = prices.size();
        if (sz < 2) {
            return 0;
        }
        int res = 0;
        for (size_t i = 1; i != sz; ++i) {
            res += std::max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};

