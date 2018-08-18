class Solution {
public:
    vector<int> partitionLabels(string S) {
        std::vector<int> res;
        std::unordered_map<char, size_t> map;
        size_t sz = S.size();
        for (size_t i = 0; i != sz; ++i) {
            size_t t = sz - 1 - i;
            char c = S[t];
            if (map.end() == map.find(c)) {
                map.insert(std::make_pair(c, t));
            }
        }
        for (size_t i = 0; i != sz;) {
            size_t start = i;
            size_t last  = map[S[start]];
            for (size_t j = i; j != last + 1; ++j) {
                last = std::max(last, map[S[j]]);
            }
            res.push_back(last + 1 - start);
            i = last + 1;
        }
        return res;
    }
};
