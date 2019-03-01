class Solution {
public:
    string reverseString(string s) {
        std::reverse(s.begin(), s.end());
        return s;
    }
};
