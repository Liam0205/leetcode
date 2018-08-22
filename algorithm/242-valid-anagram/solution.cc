class Solution {
public:
    bool isAnagram(const std::string& s, const std::string& t) {
        const size_t ssz = s.size();
        const size_t tsz = t.size();
        if (ssz != tsz) {
            return false;
        }
        std::vector<int> counter(26, 0);
        for (size_t i = 0; i != ssz; ++i) {
            ++counter[s[i] - 'a'];
            --counter[t[i] - 'a'];
        }
        return std::all_of(counter.cbegin(), counter.cend(), [](auto i) { return i == 0; });
    }
};

