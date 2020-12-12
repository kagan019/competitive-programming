/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, int> longest_cache;
    
    int longest(TreeNode* node) {
        if (node == NULL) 
            return -1;
        if (longest_cache.find(node) != longest_cache.end()) {
            return longest_cache[node];
        }
        longest_cache[node] =
            1 + max(longest(node->right), longest(node->left));
        return longest_cache[node];
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        int ll = longest(root->left);
        int dobl = diameterOfBinaryTree(root->left);
        int lr = longest(root->right);
        int dobr = diameterOfBinaryTree(root->right);
        
        
        
        return
            max(1+lr + 1 + ll,
                max(dobr, dobl));
            
    }
};
