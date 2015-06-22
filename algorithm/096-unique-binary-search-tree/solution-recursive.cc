class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 0;
        vector<int> vec_int_result(1, 1);
        for (int i = 1; i < n + 1; ++i) {
            int int_tmp = 0;
            for (int j = 0; j != i; ++j) {
                int_tmp += vec_int_result.at(j) * vec_int_result.at(i - j - 1);
            }
            vec_int_result.push_back(int_tmp);
        }
        return vec_int_result.back();
    }
};
