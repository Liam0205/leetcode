#include <vector>
#include <algorithm>
#include <iostream>

template<typename Iter, typename Compare>
void merge_sort(Iter first, Iter last, Compare comp) {
    if (last - first > 1) {
        Iter middle = first + (last - first) / 2;
        merge_sort(first, middle, comp);
        merge_sort(middle, last, comp);
        std::inplace_merge(first, middle, last, comp);
    }
}

int main() {
    std::vector<int> v{8, 2, -2, 0, 11, 11, 1, 7, 3};
    merge_sort(v.begin(), v.end(), std::less<int>());
    for (auto n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}
