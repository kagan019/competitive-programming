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
    vector<int> po;
    int idx;
    TreeNode* helper(int limit){
        cout << limit << " " << idx << "\n";
        if (idx >= po.size() || po[idx] > limit)
            return NULL;
        int root_val = po[idx];
        TreeNode* node = new TreeNode(root_val);
        idx++;
        node->left = helper(root_val);
        node->right = helper(limit);
        return node;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        po = preorder;
        idx = 0;
        return helper(INT_MAX);
    }
};
