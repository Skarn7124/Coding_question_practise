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
    void gen(TreeNode* root,string s,vector<string>&ans){
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr){
            string t = s+to_string(root->val);
            ans.push_back(t);
            return ;
        }
        string t = s+to_string(root->val)+"->";
        gen(root->left,t,ans);
        gen(root->right,t,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string s = "";
        gen(root,s,ans);
        return ans;
    }
};