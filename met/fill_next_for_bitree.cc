#include <iostream>
#include <memory>
#include <stack>
#include <vector>

template<typename T>
struct Node {
    using value_t = T;
    using ptr_t   = std::shared_ptr<Node<T>>;
    explicit Node(value_t data_) : data(data_) {}
    value_t data;
    ptr_t   left  = nullptr;
    ptr_t   right = nullptr;
    ptr_t   next  = nullptr;
};

template<typename NodePtrT>
void fill_next(NodePtrT node);
template<typename NodePtrT>
void check_next(NodePtrT node);

int main() {
    /*         0
     *     1        2
     *  3    4
     */
    auto root   = std::make_shared<Node<int>>(0);
    root->left  = std::make_shared<Node<int>>(1);
    root->right = std::make_shared<Node<int>>(2);
    root->left->left  = std::make_shared<Node<int>>(3);
    root->left->right = std::make_shared<Node<int>>(4);

    fill_next(root);
    check_next(root);

    return 0;
}

template<typename NodePtrT>
void fill_next(NodePtrT node) {
    if (nullptr != node) {
        std::vector<NodePtrT> buffer;
        buffer.push_back(node);
        for (size_t i = 0; i != buffer.size(); /* updated i by inner loop */) {
            for (size_t end = buffer.size(); i != end; ++i) {
                NodePtrT t = buffer[i];
                if (i + 1 != end)        { t->next = buffer[i + 1]; }
                if (nullptr != t->left)  { buffer.push_back(t->left); }
                if (nullptr != t->right) { buffer.push_back(t->right); }
            }
        }
    }
}

template<typename NodePtrT>
void check_next(NodePtrT node) {
    if (nullptr != node) {
        std::vector<NodePtrT> buffer;
        buffer.push_back(node);
        for (size_t i = 0; i != buffer.size(); /* updated i by inner loop */) {
            for (size_t end = buffer.size(); i != end; ++i) {
                NodePtrT t = buffer[i];
                if (nullptr != t->next) {
                    std::cout << t->data << "->" << t->next->data << std::endl;
                }
                if (nullptr != t->left)  { buffer.push_back(t->left); }
                if (nullptr != t->right) { buffer.push_back(t->right); }
            }
        }
    }
}
