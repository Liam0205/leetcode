class Solution {
public:
    int firstUniqChar(const std::string& s) {
        std::unordered_set<char> checked;
        const size_t sz = s.size();
        for (size_t i = 0; i != sz; ++i) {
            const char cc = s[i];
            if (checked.find(cc) == checked.end()) {
                checked.insert(cc);
                if (std::all_of(s.cbegin() + i + 1, s.cend(), [cc](char c) { return c != cc; })) {
                    return i;
                }
            }
        }
        return -1;
    }
};

