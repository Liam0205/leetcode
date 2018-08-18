class Solution {
public:
    string toLowerCase(string str) {
        std::transform(str.begin(), str.end(), str.begin(), [](auto c){ return std::tolower(c); });
        return str;
    }
};
