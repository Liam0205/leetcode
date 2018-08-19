class Solution {
public:
    string customSortString(string S, string T) {
        std::unordered_map<char, size_t> order_map;
        getOrderMap(S, &order_map);
        auto comp = [order_map](char lhs, char rhs) mutable { return order_map[lhs] < order_map[rhs]; };
        std::sort(T.begin(), T.end(), comp);
        return T;
    }

private:
    void getOrderMap(const std::string& S, std::unordered_map<char, size_t>* order_map) {
        const size_t sz = S.size();
        for (size_t i = 0; i != sz; ++i) {
            order_map->insert({S[i], i});
        }
    }
};
