class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n < 1) {
            res.push_back(0);
            return res;
        }
        vector<string> wk;
        for (int i = 0; i != n; ++i) {
            size_t times = static_cast<size_t>(pow(2, i));
            string basic = string(times, '0') + string(times, '1');
            string reverse = string(times, '1') + string(times, '0');
            if (i + 1 == n) {
                wk.push_back (basic);
            } else {
                size_t times = static_cast<size_t>(pow(2, n - i - 2));
                string tmp;
                for (size_t j = 0; j != times; ++j) {
                    tmp += basic + reverse;
                }
                wk.push_back (tmp);
            }
        }
        size_t len = wk[0].size();
        for (size_t i = 0; i != len; ++i) {
            int tmp = 0;
            for (int j = 0; j != n; ++j) {
                tmp += (wk[j][i] - '0') * pow (2, j);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
