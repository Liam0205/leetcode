class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        return binsearch(A, 0, A.size(), [](int x, int y, int z) {
            if (x < y and y < z) {
                return -1;
            } else if (x < y and y > z) {
                return 0;
            } else {
                return 1;
            }
        });
    }

private:
    template <typename TriplePredicate>
    size_t binsearch(const std::vector<int>& A, const size_t first, const size_t last, TriplePredicate tripred) {
        if (last - first < 1) {
            std::terminate();
        } else if (last - first == 1) {
            return first;
        } else {
            size_t cut    = first + (last - first) / 2;
            const int tmp = tripred(A[cut - 1], A[cut], A[cut + 1]);
            if (tmp == 1) {
                return binsearch(A, first, cut, tripred);
            } if (tmp == 0) {
                return cut;
            } else {
                return binsearch(A, cut, last, tripred);
            }
        }
    }
};
