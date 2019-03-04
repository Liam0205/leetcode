/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (nullptr == root) {
            return 0;
        }
        std::vector<Node*> node_vec;
        node_vec.push_back(root);
        int res = 0;
        for (size_t i = 0, j = node_vec.size(); i != node_vec.size(); i = j, j = node_vec.size()) {
            ++res;
            for (size_t k = i; k != j; ++k) {
                std::copy(node_vec[k]->children.begin(), node_vec[k]->children.end(),
                        std::back_inserter(node_vec));
            }
        }
        return res;
    }
};
