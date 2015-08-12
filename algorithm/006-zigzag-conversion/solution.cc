class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        unsigned int len = s.size();
        int strIdx = 0, idxDir = -1;
        string strArr[numRows];
        for (int i = 0; i != numRows; ++i) {
            strArr[i] = "";
        }
        for (int i = 0; i != len; ++i) {
            idxDir = (strIdx == 0 || strIdx == numRows - 1) ? -1 * idxDir : idxDir;
            strArr[strIdx] += s.at(i);
            strIdx += idxDir;
        }
        string result = "";
        for (int i = 0; i != numRows; ++i) {
            result += strArr[i];
        }
        return result;
    }
};
