class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> vec_int_counter(26, 0);
        size_t sz_length = s.length();
        for (size_t i = 0; i != sz_length; ++i) {
            ++vec_int_counter.at(s.at(i) - 'a');
            --vec_int_counter.at(t.at(i) - 'a');
        }
        for (size_t i = 0; i != 26; ++i) {
            if (vec_int_counter.at(i) != 0) return false;
        }
        return true;
    }
};
