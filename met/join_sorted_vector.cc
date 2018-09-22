#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>

template<typename T>
bool set_join(const std::vector<T>& lhs, std::list<T>* rhs) {
    if (nullptr == rhs) {
        return false;
    }
    auto l = lhs.begin();
    auto r = rhs->begin();
    while (l != lhs.end() and r != rhs->end()) {
        if (*l < *r) {
            ++l;
        } else if (*l > *r) {
            r = rhs->erase(r);
        } else {
            ++l;
            ++r;
        }
    }
    return true;
}

template<typename T>
bool set_join(const std::vector<std::vector<T>>& input, std::vector<T>* output) {
    if (input.empty() or nullptr == output) {
        return false;
    }
    output->clear();
    auto iter = input.begin();
    std::list<T> work(iter->begin(), iter->end());
    for (++iter; iter != input.end(); ++iter) {
        if (not set_join(*iter, &work)) {
            return false;
        }
    }
    std::copy(work.begin(), work.end(), std::inserter(*output, output->begin()));
    return true;
}

int main() {
    std::vector<std::vector<int>> input = {{1, 2, 3}, {2, 3, 4}, {1, 3, 5}};
    std::vector<int> output;
    if (set_join(input, &output)) {
        for (auto i : output) {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}
