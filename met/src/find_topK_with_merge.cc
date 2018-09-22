#include <iostream>
#include <vector>

static const std::vector<int> LHS{3, 4, 5, 6, 7};
static const std::vector<int> RHS{1, 2, 8, 9};

bool find_topK_with_merge(const std::vector<int>&, const std::vector<int>&, const size_t, int*);

int main() {
    int res;
    if (find_topK_with_merge(LHS, RHS, 8, &res)) {
        std::cout << res << std::endl;
    }
    return 0;
}

bool find_topK_with_merge(const std::vector<int>& lhs,
                          const std::vector<int>& rhs,
                                     const size_t k,
                                             int* res) {
    size_t lsz = lhs.size();
    size_t rsz = rhs.size();
    if (k > lsz + rsz) {
        return false;
    }
    size_t l, r;
    for (l = 0, r = 0; l + r != k and l != lsz and r != rsz;) {
        if (lhs[l] < rhs[r]) {
            *res = lhs[l];
            ++l;
        } else {
            *res = rhs[r];
            ++r;
        }
    }
    if (l + r != k) {
        if (l != lsz) {
            *res = lhs[k - rsz - 1];
            return true;
        } else if (r != rsz) {
            *res = rhs[k - lsz - 1];
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}
