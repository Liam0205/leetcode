inline bool stringLengthLarger (const string & lhs, const string & rhs) {
    return lhs.length() > rhs.length();
}

class Solution {
public:
    int maxProduct(vector<string>& words) {
        size_t sz_words = words.size();
        if (sz_words < 2) {
            return 0;
        }
        sort (words.begin(), words.end(), stringLengthLarger);
        vector<int> mask (sz_words, 0);
        for (size_t i = 0; i != sz_words; ++i) {
            const string & curr = words.at(i);
            size_t sz_curr      = curr.length();
            int & curr_mask     = mask.at(i);
            for (size_t j = 0; j != sz_curr; ++j) {
                curr_mask |= 1 << (curr.at(j) - 'a');
            }
        }
        int curr_max = 0;
        for (size_t i = 0, range = sz_words - 1; i != range; ++i) {
            for (size_t j = i + 1; j != sz_words; ++j) {
                if (!(mask.at(i) & mask.at(j))) {
                    int curr = words.at(i).length() * words.at(j).length();
                    curr_max = max (curr_max, curr);
                    range    = min (range, j);
                    break;
                }
            }
        }
        return curr_max;
    }
};
