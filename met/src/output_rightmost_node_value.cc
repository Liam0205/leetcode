#include <iostream>
#include <memory>
#include <queue>
#include <vector>
#include <algorithm>

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

template<typename NodePtrT, typename Value = typename NodePtrT::element_type::value_t>
std::vector<Value> output_rightmost_node_value(NodePtrT root) {
  if (nullptr == root) { return std::vector<Value>(); }
  std::vector<Value> res;
  std::queue<NodePtrT> q;
  q.push(root);
  size_t lc = q.size();
  while (not q.empty()) {
    size_t c = 0;
    for (size_t i = 0; i != lc; ) {
      NodePtrT n = q.front();
      q.pop();
      if (nullptr != n->left) {
        q.push(n->left);
        ++c;
      }
      if (nullptr != n->right) {
        q.push(n->right);
        ++c;
      }
      if (++i == lc) {
        res.push_back(n->data);
      }
    }
    lc = c;
  }
  return res;
}
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

  auto res = output_rightmost_node_value(root);
  std::for_each(res.begin(), res.end(), [&](auto e) { std::cout << e << ' '; });
  std::cout << std::endl;

  return 0;
}
