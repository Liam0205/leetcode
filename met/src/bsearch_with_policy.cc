#include <iostream>
#include <iterator>
#include <vector>

enum class BsearchPolicy { FIRST, LAST, UNSPECIFIED };

template <typename IterT, typename ValueT, typename Compare>
IterT bsearch(IterT first,
              IterT last,
             ValueT target,
            Compare comp,
      BsearchPolicy policy = BsearchPolicy::UNSPECIFIED) {
    IterT result = last;
    while (std::distance(first, last) > 0) {
        IterT mid = first + std::distance(first, last) / 2;
        if (comp(*mid, target)) {
            first = mid + 1;
        } else if (comp(target, *mid)) {
            last = mid;
        } else {  // equal
            if (policy == BsearchPolicy::FIRST) {
                if (mid == first or comp(*(mid - 1), *mid)) {
                    result = mid;
                    break;
                } else {
                    last = mid;
                }
            } else if (policy == BsearchPolicy::LAST) {
                if (std::distance(mid, last) == 1 or comp(*mid, *(mid + 1))) {
                    result = mid;
                    break;
                } else {
                    first = mid + 1;
                }
            } else {
                result = mid;
                break;
            }
        }
    }
    return result;
}

template <typename IterT, typename ValueT>
IterT bsearch(IterT first,
              IterT last,
             ValueT target,
      BsearchPolicy policy = BsearchPolicy::UNSPECIFIED) {
    return bsearch(first, last, target, std::less<ValueT>(), policy);
}

int main() {
    std::vector<int> test{0, 0, 1, 2, 3, 4, 4, 5, 5, 5, 5, 5, 6, 7};  // std::less<int>()

    auto it = bsearch(test.begin(), test.end(), 8);
    std::cout << std::distance(test.begin(), it) << std::endl;  // 14
    it = bsearch(test.begin(), test.end(), -1);
    std::cout << std::distance(test.begin(), it) << std::endl;  // 14

    it = bsearch(test.begin(), test.end(), 0);
    std::cout << std::distance(test.begin(), it) << std::endl;  // 0, 1
    it = bsearch(test.begin(), test.end(), 0, BsearchPolicy::FIRST);
    std::cout << std::distance(test.begin(), it) << std::endl;  // 0
    it = bsearch(test.begin(), test.end(), 0, BsearchPolicy::LAST);
    std::cout << std::distance(test.begin(), it) << std::endl;  // 1

    it = bsearch(test.begin(), test.end(), 4);
    std::cout << std::distance(test.begin(), it) << std::endl;  // 5, 6
    it = bsearch(test.begin(), test.end(), 4, BsearchPolicy::FIRST);
    std::cout << std::distance(test.begin(), it) << std::endl;  // 5
    it = bsearch(test.begin(), test.end(), 4, BsearchPolicy::LAST);
    std::cout << std::distance(test.begin(), it) << std::endl;  // 6

    it = bsearch(test.begin(), test.end(), 5);
    std::cout << std::distance(test.begin(), it) << std::endl;  // 7, 8, 9, 10, 11
    it = bsearch(test.begin(), test.end(), 5, BsearchPolicy::FIRST);
    std::cout << std::distance(test.begin(), it) << std::endl;  // 7
    it = bsearch(test.begin(), test.end(), 5, BsearchPolicy::LAST);
    std::cout << std::distance(test.begin(), it) << std::endl;  // 11

    it = bsearch(test.begin(), test.end(), 7);
    std::cout << std::distance(test.begin(), it) << std::endl;  // 13
    it = bsearch(test.begin(), test.end(), 7, BsearchPolicy::FIRST);
    std::cout << std::distance(test.begin(), it) << std::endl;  // 13
    it = bsearch(test.begin(), test.end(), 7, BsearchPolicy::LAST);
    std::cout << std::distance(test.begin(), it) << std::endl;  // 13

    return 0;
}
