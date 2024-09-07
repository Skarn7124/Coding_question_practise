/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == nullptr) 
            return false;
        if(check(head,root)) return true;
        return isSubPath(head,root->right) || isSubPath(head,root->left);
    }
    bool check(ListNode* head, TreeNode* root){
        if(head == nullptr) 
            return true;
        if(root == nullptr)
            return false;
        if(head->val == root->val){
            return check(head->next,root->right) || check(head->next,root->left);
        }
        return false;
    }
};