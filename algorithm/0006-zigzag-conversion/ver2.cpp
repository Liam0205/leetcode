static const auto speedup =[]() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();

class Solution {
public:
    string convert(string s, int numRows) {
        if (1 == numRows || numRows >= s.length()) {
            return s;
        } // Infinite loop occurs when without this case;
        
        vector<string> strArray(numRows, "");
        int cnt(0);
        int row = 0;
        
        while (cnt < s.length()) {
            while (cnt < s.length() && row < numRows - 1) {
                strArray[row++] += s[cnt++];
            } // zig
        
            while (cnt < s.length() && row > 0) {
                strArray[row--] += s[cnt++];
            } // zag
        }
        
        string ans("");
        for (auto str : strArray) {
            ans += str;
        }
        return ans;
    }
};
