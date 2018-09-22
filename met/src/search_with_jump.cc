#include <iostream>
#include <vector>

static const std::vector<int> CASE1{1, 2, 3, 2, 1, 0, 1, 0, -1, 0, 1, 2, 3, 4, 5};
static const std::vector<int> CASE2{};

bool jump_search(const std::vector<int>& array, const int target, size_t* pos);

int main() {
    size_t pos = 0;
    if (jump_search(CASE1, 4, &pos)) {
        std::cout << "CASE1: " << pos << std::endl;
    }
    if (jump_search(CASE2, 4, &pos)) {
        std::cout << "CASE2: " << pos << std::endl;
    }
    return 0;
}

bool jump_search(const std::vector<int>& array, const int target, size_t* pos) {
    size_t sz = array.size();
    int work;
    for (*pos = 0; *pos < sz and work != target; *pos += std::abs(target - work)) {
        work = array[*pos];
    }
    return work == target;
}
