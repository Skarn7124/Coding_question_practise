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
    int height = 0;
    void gen(TreeNode* root,int h,vector<long long int>&v){
        if(root == nullptr)
            return ;
        height = max(height,h);
        if(v[h] == -1){
            v[h] = root->val;
        }
        else{
            v[h] += root->val;
        }
        gen(root->left,h+1,v);
        gen(root->right,h+1,v);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long int> v(200000,-1);

        gen(root,0,v);

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        k--;
        if(k>=height+1)
            return -1;
        return v[k];
    }
};