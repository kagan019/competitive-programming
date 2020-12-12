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
    unordered_map<int,int> m;
    int recurse(TreeNode *n) {
        if (n == nullptr) return 0;
        int sts = n->val + recurse(n->left) + recurse(n->right);
        auto f = m.find(sts);
        if(f == m.end())
            m.insert(make_pair(sts,0));
        m[sts]++;
        return sts;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        recurse(root);
        int g = -1;
        for (auto &p : m) {
            if (p.second > g) {
                g = p.second;
            }
        }
        vector<int> s;
        for (auto &p : m) {
            if (p.second == g) {
                s.push_back(p.first);
            }
        }
        return s;
        
    }
};
