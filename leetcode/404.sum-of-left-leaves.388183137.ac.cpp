/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sleft(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int k = 0;
        if (root->left == nullptr && root->right == nullptr)
            k += root->val;
        k += sleft(root->left);
        k += sumOfLeftLeaves(root->right);
        return k;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        int k = 0;
        k += sleft(root->left);
        k += sumOfLeftLeaves(root->right);
        return k;
    }
};
