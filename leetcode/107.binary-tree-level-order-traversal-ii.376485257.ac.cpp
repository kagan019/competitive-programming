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
    void recurse(vector<vector<int>> &m, TreeNode *node, int lvl) {
        if (node == nullptr)
            return;
        
        if (m.size() <= lvl) {
            m.emplace_back();
        }
        m[lvl].push_back(node->val);
        recurse(m,node->left,lvl+1);
        recurse(m,node->right,lvl+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> m;
        recurse(m, root, 0);
        reverse(m.begin(), m.end());
        return m;
    }
};
