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
    map<int,int> m;
    void gen(TreeNode* root,int level){
        if(root == nullptr)
            return;
        m[level]+=root->val;
        gen(root->left,level+1);
        gen(root->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        gen(root,1);
        int ans = INT_MIN,ind = 0;
        for(auto it : m){
            if(it.second>ans){
                ans = it.second;
                ind = it.first;
            }
        }
        return ind;
    }
};