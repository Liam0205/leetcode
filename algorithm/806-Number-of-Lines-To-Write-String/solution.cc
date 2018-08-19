class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int line_num  = 1;
        int curr_used = 0;
        for (auto c : S) {
            if (widths[c - 'a'] + curr_used > 100) {
                ++line_num;
                curr_used = 0;
            }
            curr_used += widths[c - 'a'];
        }
        return {line_num, curr_used};
    }
};
