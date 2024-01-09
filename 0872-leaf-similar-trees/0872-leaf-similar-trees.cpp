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
    void gen(TreeNode *root,vector<int> &v){
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr)
            v.push_back(root->val);
        gen(root->left,v);
        gen(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a,b;
        gen(root1,a);
        gen(root2,b);
        if(a == b)
            return 1;
        return 0;
    }
};