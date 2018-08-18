class Solution {
public:
    int romanToInt(string s) {
        size_t sz_length = s.size();
        if (sz_length == 0) return 0;
        int int_result = 0;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if (s.find("IV") != string::npos) int_result -= 2 * 1;
        if (s.find("IX") != string::npos) int_result -= 2 * 1;
        if (s.find("XL") != string::npos) int_result -= 2 * 10;
        if (s.find("XC") != string::npos) int_result -= 2 * 10;
        if (s.find("CD") != string::npos) int_result -= 2 * 100;
        if (s.find("CM") != string::npos) int_result -= 2 * 100;
        for (size_t i = 0; i != sz_length; ++i) {
            switch (s.at(i)) {
                case 'I': int_result += 1;    break;
                case 'V': int_result += 5;    break;
                case 'X': int_result += 10;   break;
                case 'L': int_result += 50;   break;
                case 'C': int_result += 100;  break;
                case 'D': int_result += 500;  break;
                case 'M': int_result += 1000; break;
            }
        }
        return int_result;
    }
};
