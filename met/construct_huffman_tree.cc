#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <iterator>
#include <algorithm>

template <typename T>
struct Node {
    using value_type = T;
    using pointer_type = std::shared_ptr<Node<T>>;

    Node(const value_type& data_) : data(data_) {}
    bool operator<(const Node<T>& rhs) const {
        return this->data < rhs.data;
    }

    value_type data;
    pointer_type left  = nullptr;
    pointer_type right = nullptr;
};

template <typename T>
bool translate(const std::vector<T>& input, std::list<typename Node<T>::pointer_type>* output);
template <typename T>
bool constructHuffmanTree(const std::list<typename Node<T>::pointer_type>& input,
        typename Node<T>::pointer_type* output);
template<typename T>
void levelorder_traverse(typename Node<T>::pointer_type node);

int main() {
    std::vector<int>                            input{1, 2, 3, 4, 5};
    std::list<typename Node<int>::pointer_type> tmp_list;
    typename Node<int>::pointer_type            res;
    if (translate(input, &tmp_list)) {
        if (constructHuffmanTree<int>(tmp_list, &res)) {
            levelorder_traverse<int>(res);  // 15 6 9 3 3 4 5 1 2
        }
    }
    return 0;
}

template <typename T>
bool translate(const std::vector<T>& input, std::list<typename Node<T>::pointer_type>* output) {
    if (nullptr == output) {
        return false;
    } else {
        output->clear();
        std::for_each(input.begin(), input.end(), [&](const T& v){
                output->insert(output->end(), std::make_shared<Node<T>>(v));
            });
        return true;
    }
}

template <typename T>
bool constructHuffmanTree(const std::list<typename Node<T>::pointer_type>& input,
        typename Node<T>::pointer_type* output) {
    using ptr_t  = typename Node<T>::pointer_type;
    std::list<ptr_t> work(input);
    for (auto iter = work.begin(); std::distance(iter, work.end()) > 1; iter = work.begin()) {
        ptr_t left  = *iter;
        iter        = work.erase(iter);
        ptr_t right = *iter;
        iter        = work.erase(iter);

        T temp_data = left->data + right->data;
        ptr_t temp  = std::make_shared<Node<T>>(temp_data);
        temp->left  = left;
        temp->right = right;

        decltype(iter) it;
        for (it = iter; it != work.end() and **it < *temp; ++it);  // intentionally
        work.insert(it, temp);
    }
    if (1 == work.size()) {
        *output = *(work.begin());
        return true;
    } else {
        *output = nullptr;
        return false;
    }
}

template<typename T>
void levelorder_traverse(typename Node<T>::pointer_type node) {
    if (nullptr != node) {
        std::vector<typename Node<T>::pointer_type> buffer;
        buffer.push_back(node);
        for (size_t i = 0, end = buffer.size(); i < buffer.size(); end = buffer.size()) {
            for (; i != end; ++i) {
                auto t = buffer[i];
                std::cout << t->data << ' ';
                if (nullptr != t->left) {
                    buffer.push_back(t->left);
                }
                if (nullptr != t->right) {
                    buffer.push_back(t->right);
                }
            }
        }
    }
    std::cout << std::endl;
}
