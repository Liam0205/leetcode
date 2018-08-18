class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> wkMap; // store the latest pos of char, a Hash Table
        int curMaxLen = 0;
        int lastRepeatPosition = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (wkMap.find(s[i]) != wkMap.end() && lastRepeatPosition < wkMap[s[i]]) {
                // find new repeat char, update lastRepeatPosition
                lastRepeatPosition = wkMap[s[i]];
            }
            // update curMaxLen, if needed
            curMaxLen = (i - lastRepeatPosition > curMaxLen) ? i - lastRepeatPosition : curMaxLen;
            // update the latest pos of s[i]
            wkMap[s[i]] = i;
        }
        return curMaxLen;
    }
};
