class Solution {
public:
    int romanToInt(std::string s) {
        size_t sz = s.size();
        if (sz == 0) return 0;
        int res = 0;
        std::transform(s.begin(), s.end(), s.begin(), ::toupper);
        for (size_t i = 0; i != sz; ++i) {
            switch (s[i]) {
                case 'I': res += 1;    break;
                case 'V': res += 5;    break;
                case 'X': res += 10;   break;
                case 'L': res += 50;   break;
                case 'C': res += 100;  break;
                case 'D': res += 500;  break;
                case 'M': res += 1000; break;
            }
        }
        if (s.find("IV") != std::string::npos) res -= 2 * 1;
        if (s.find("IX") != std::string::npos) res -= 2 * 1;
        if (s.find("XL") != std::string::npos) res -= 2 * 10;
        if (s.find("XC") != std::string::npos) res -= 2 * 10;
        if (s.find("CD") != std::string::npos) res -= 2 * 100;
        if (s.find("CM") != std::string::npos) res -= 2 * 100;
        return res;
    }
};
