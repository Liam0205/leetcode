/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return; // empty tree
        if (root -> left) // if root has left child, then it must have right child (perfect tree)
            root -> left -> next = root -> right;
        if (root -> next && root -> right) // if root has next and right child, then the next to root must have left child
            root -> right -> next = root -> next -> left;
        // recursively connect all the nodes
        connect(root -> left);
        connect(root -> right);
    }
};
