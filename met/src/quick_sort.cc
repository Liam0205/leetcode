#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

namespace {
namespace details {
template <typename T, typename BinaryPredicate>
T median(T&& a, T&& b, T&& c, BinaryPredicate bipred) {
    if ((bipred(b, a) and bipred(a, c)) or (bipred(c, a) and bipred(a, b))) {
        return a;
    } else if ((bipred(a, b) and bipred(b, c)) or (bipred(c, b) and bipred(b, a))) {
        return b;
    } else {
        return c;
    }
}

template <typename ForwardIt, typename BinaryPredicate, typename T>
ForwardIt partition(ForwardIt first, ForwardIt last, BinaryPredicate bipred, T pivot) {
    ForwardIt cut =
        std::partition(first, last, [bipred, pivot](auto&& e){ return bipred(e, pivot); });
    std::partition(cut, last, [bipred, pivot](auto&& e){ return !bipred(pivot, e); });
    return cut;
}
}  // namespace details

template <typename ForwardIt, typename BinaryPredicate>
void quick_sort(ForwardIt first, ForwardIt last, BinaryPredicate bipred) {
    while (std::distance(first, last) > 1) {
        auto pivot =
            details::median(*first, *(first + std::distance(first, last) / 2), *(last - 1), bipred);
        ForwardIt cut = details::partition(first, last, bipred, pivot);
        quick_sort(cut + 1, last, bipred);
        last = cut;
    }
}
}  // namespace

int main() {
    std::vector<int> test{1, 30, -4, 3, 5, -4, 1, 6, -8, 2, -5, 64, 1, 92};
    std::cout << "before sort:\n\t";
    for (auto v : test) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
    quick_sort(test.begin(), test.end(), std::less<int>());
    std::cout << "after sort:\n\t";
    for (auto v : test) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;

    return 0;
}
