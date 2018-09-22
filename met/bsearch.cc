#include <iostream>
#include <iterator>
#include <vector>

template <typename IterT, typename ValueT, typename Compare>
IterT bsearch(IterT first, IterT last, ValueT target, Compare comp) {
    IterT result = last;
    while (std::distance(first, last) > 0) {
        IterT mid = first + std::distance(first, last) / 2;
        if (comp(*mid, target)) {
            first = mid + 1;
        } else if (comp(target, *mid)) {
            last = mid;
        } else {  // equal
            result = mid;
            break;
        }
    }
    return result;
}

int main() {
    std::vector<int> test{0, 1, 2, 3, 4, 5, 6, 7};  // std::less<int>()
    auto it = bsearch(test.begin(), test.end(), 5, std::less<int>());
    std::cout << std::distance(test.begin(), it) << std::endl;  // 5
    it = bsearch(test.begin(), test.end(), 8, std::less<int>());
    std::cout << std::distance(test.begin(), it) << std::endl;  // 8
    it = bsearch(test.begin(), test.end(), -1, std::less<int>());
    std::cout << std::distance(test.begin(), it) << std::endl;  // 8

    return 0;
}
