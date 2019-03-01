class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        const int sz = S.size();
        std::vector<int> res(sz, sz);
        int last_meet_pos = -sz;
        for (int i = 0; i != sz; ++i) {
            if (C == S[i]) {
                last_meet_pos = i;
            }
            res[i] = std::min(res[i], std::abs(i - last_meet_pos));
        }
        for (int j = 0, i; j != sz; ++j) {
            i = sz - 1 - j;
            if (C == S[i]) {
                last_meet_pos = i;
            }
            res[i] = std::min(res[i], std::abs(i - last_meet_pos));
        }
        return res;
    }
};
