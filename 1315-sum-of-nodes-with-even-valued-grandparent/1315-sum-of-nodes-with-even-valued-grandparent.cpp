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
    int ans = 0;
    void porder(TreeNode *root,TreeNode *p,TreeNode *gp){
        if(root == nullptr)
            return;
        if(gp!=nullptr){
            if(gp->val %2 == 0){
                ans += root->val;
            }
        }
        porder(root->right,root,p);
        porder(root->left,root,p);
    }
    int sumEvenGrandparent(TreeNode* root) {
        porder(root,nullptr,nullptr);
        return ans;
    }
};