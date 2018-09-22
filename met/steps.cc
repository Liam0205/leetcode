#include <iostream>
#include <vector>

static std::vector<size_t> steps = {1, 2, 3};

bool calculateSteps(const size_t n, std::vector<size_t>* helper, size_t* res);

int main() {
    size_t res = 0;
    if (calculateSteps(100, &steps, &res)) {
        std::cout << res << std::endl;
    }
    return 0;
}

bool calculateSteps(const size_t n, std::vector<size_t>* helper, size_t* res) {
    if (nullptr == helper or nullptr == res) {
        return false;
    } else {
        if (helper->size() < n) {
            helper->reserve(n);
            for (size_t i = helper->size(); i != n; ++i) {
                helper->operator[](i) = helper->operator[](i - 1) + helper->operator[](i - 2) +
                    helper->operator[](i - 3);
            }
        }
        *res = helper->operator[](n - 1);
        return true;
    }
}
