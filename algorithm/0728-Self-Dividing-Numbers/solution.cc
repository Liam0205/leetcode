class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        std::vector<int> res;
        res.reserve(right + 1 - left);
        for (int work = left; work != right + 1; ++work) {
            bool flag = true;
            for (int copy = work, div = copy % 10; flag and copy != 0; copy /= 10, div = copy % 10) {
                if (div == 0 or work % div != 0) {
                    flag = false;
                }
            }
            if (flag) {
                res.push_back(work);
            }
        }
        return res;
    }
};
