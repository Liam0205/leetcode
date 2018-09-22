#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
#include <algorithm>

struct Hamming {
    using ptr_t = std::shared_ptr<Hamming>;
    Hamming(const int data_) : data(data_) {}
    int data             = 0;
    unsigned int hamming = 0;
};

struct HammingLess{
    bool operator()(const typename Hamming::ptr_t& lhs, const typename Hamming::ptr_t& rhs) const {
        return lhs->hamming < rhs->hamming;
    }
};

bool calculateHammingDistance(const int origin, std::vector<typename Hamming::ptr_t>* vec);
bool getLessK(size_t k, const std::vector<typename Hamming::ptr_t>& input,
        std::vector<typename Hamming::ptr_t>* output);

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::vector<typename Hamming::ptr_t> hamming;
    hamming.reserve(vec.size());
    for (auto v : vec) {
        hamming.emplace_back(std::make_shared<Hamming>(v));
    }
    if (calculateHammingDistance(0, &hamming)) {
        decltype(hamming) res;
        if (getLessK(3, hamming, &res)) {
            for (auto v : res) {
                std::cout << v->data << ' ';
            }
            std::cout << std::endl;
        }
    }
    return 0;
}

unsigned int calculateHammingDistance(const int lhs, const int rhs) {
    unsigned int res = 0;
    for (int work = lhs ^ rhs; work != 0; work &= (work - 1)) {
        ++res;
    }
    return res;
}

bool calculateHammingDistance(const int origin, std::vector<typename Hamming::ptr_t>* vec) {
    if (nullptr == vec) {
        return false;
    } else {
        for (auto v : *vec) {
            v->hamming = calculateHammingDistance(origin, v->data);
        }
        return true;
    }
}

bool getLessK(size_t k, const std::vector<typename Hamming::ptr_t>& input,
        std::vector<typename Hamming::ptr_t>* output) {
    if (nullptr == output) {
        return false;
    } else {
        output->clear();
        std::copy(input.begin(), input.end(), std::back_inserter(*output));
        std::make_heap(output->begin(), output->end(), HammingLess());
        std::sort_heap(output->begin(), output->end(), HammingLess());
        output->erase(output->begin() + k, output->end());
        return true;
    }
}
