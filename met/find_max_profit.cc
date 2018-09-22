#include <iostream>
#include <vector>

static const std::vector<double> PRICES{1.0, 1.5, 0.9, 2.1, 2.0, 1.9, 1.8, 1.7, 2.2, 0.9};

bool find_max_profit(const std::vector<double>& prices, double* res);

int main() {
    double res = 0.0;
    if (find_max_profit(PRICES, &res)) {
        std::cout << res << std::endl;
    }
    return 0;
}

bool differentiate(const std::vector<double>& orig, std::vector<double>* res) {
    res->clear();
    size_t sz = orig.size();
    if (not sz > 1) {
    if (not sz > 1) {
        return false;
    }
    res->reserve(sz - 1);

    for (size_t i = 1; i != sz; ++i) {
        res->push_back(orig[i] - orig[i - 1]);
    }
    return true;
}

template<typename T>
bool kanade(const std::vector<T>& array, T* res) {
    size_t sz = array.size();
    if (0 == sz) {
        return false;
    } else if (1 == sz) {
        *res = array[0];
        return true;
    } else {
        T max_till_now = array[0];
        *res = max_till_now;
        for (size_t i = 1; i != sz; ++i) {
            max_till_now = std::max(array[i], array[i] + max_till_now);
            *res         = std::max(*res, max_till_now);
        }
        return true;
    }
}

bool find_max_profit(const std::vector<double>& prices, double* res) {
    std::vector<double> diff;
    if (not differentiate(prices, &diff)) {
        return false;
    }
    return kanade(diff, res);
}
