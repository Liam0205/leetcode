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
};

template<typename NodePtrT>
void preorder_traverse(NodePtrT node);
template<typename NodePtrT>
void midorder_traverse(NodePtrT node);
template<typename NodePtrT>
void postorder_traverse(NodePtrT node);
template<typename NodePtrT>
void levelorder_traverse(NodePtrT node);

int main() {
    /*         0
     *     1        2
     *  3    4
     *      5 6
     */
    auto root   = std::make_shared<Node<int>>(0);
    root->left  = std::make_shared<Node<int>>(1);
    root->right = std::make_shared<Node<int>>(2);
    root->left->left  = std::make_shared<Node<int>>(3);
    root->left->right = std::make_shared<Node<int>>(4);
    root->left->right->left  = std::make_shared<Node<int>>(5);
    root->left->right->right = std::make_shared<Node<int>>(6);

    preorder_traverse(root);   // 0 1 3 4 5 6 2
    midorder_traverse(root);   // 3 1 5 4 6 0 2
    postorder_traverse(root);  // 3 5 6 4 1 2 0
    levelorder_traverse(root); // 0 1 2 3 4 5 6

    preorder_traverse<decltype(root)>(nullptr);
    midorder_traverse<decltype(root)>(nullptr);
    postorder_traverse<decltype(root)>(nullptr);
    levelorder_traverse<decltype(root)>(nullptr);
    return 0;
}

template<typename NodePtrT>
void preorder_traverse(NodePtrT node) {
    std::stack<NodePtrT> buffer;
    while (nullptr != node or not buffer.empty()) {
        while (nullptr != node) {
            std::cout << node->data << ' ';  // output when meet a node
            buffer.push(node);
            node = node->left;               // loop to the final left node
        }
        node = buffer.top();
        buffer.pop();
        node = node->right;                  // look at the right brother
    }
    std::cout << std::endl;
}

template<typename NodePtrT>
void midorder_traverse(NodePtrT node) {
    std::stack<NodePtrT> buffer;
    while (nullptr != node or not buffer.empty()) {
        while (nullptr != node) {
            buffer.push(node);
            node = node->left;               // loop to the final left node
        }
        node = buffer.top();
        buffer.pop();
        std::cout << node->data << ' ';      // output the final left node in this moment
        node = node->right;                  // look at its right child, if any
    }
    std::cout << std::endl;
}

template<typename NodePtrT>
void postorder_traverse(NodePtrT node) {
    if (nullptr != node) {
        std::stack<NodePtrT> buffer;
        NodePtrT prev = nullptr;
        buffer.push(node);
        while (not buffer.empty()) {
            node = buffer.top();
            if ((nullptr == node->left and nullptr == node->right) or
                    (prev == node->left and nullptr == node->right) or
                    prev == node->right) {
                std::cout << node->data << ' ';
                buffer.pop();
                prev = node;
            } else {
                if (nullptr != node->right) { buffer.push(node->right); }
                if (nullptr != node->left)  { buffer.push(node->left); }
            }
        }
    }
    std::cout << std::endl;
}

template<typename NodePtrT>
void levelorder_traverse(NodePtrT node) {
    if (nullptr != node) {
        std::vector<NodePtrT> buffer;
        buffer.push_back(node);
        for (size_t i = 0; i != buffer.size(); /* updated i by inner loop */) {
            for (size_t end = buffer.size(); i != end; ++i) {
                NodePtrT t = buffer[i];
                std::cout << t->data << ' ';
                if (nullptr != t->left)  { buffer.push_back(t->left); }
                if (nullptr != t->right) { buffer.push_back(t->right); }
            }
        }
    }
    std::cout << std::endl;
}
