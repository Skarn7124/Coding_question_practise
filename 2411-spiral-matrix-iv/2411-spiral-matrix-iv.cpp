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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int x1 = 0,y1= 0;
        vector<vector<int>> matrix(m,vector<int>(n));
        int i = 0,j = 0,x2 = 0,y2 = 0,count = 1;
        int s = n*m;
        while(count<=s){
            for(;j<n-y2;j++){
                if(head!=nullptr){
                    matrix[i][j] = head->val;
                    head = head->next;
                }
                else{
                    matrix[i][j] = -1;
                }
                count++;
            }
            j--;
            if(count>s)
                break;
            x1++;
            i++;
            for(;i<m-x2;i++){
                if(head!=nullptr){
                    matrix[i][j] = head->val;
                    head = head->next;
                }
                else{
                    matrix[i][j] = -1;
                }
                count++;
            }
            i--;
            if(count>s)
                break;
            j--;
            y2++;
            for(;j>=y1;j--){
                if(head!=nullptr){
                    matrix[i][j] = head->val;
                    head = head->next;
                }
                else{
                    matrix[i][j] = -1;
                }
                count++;
            }
            j++;
            if(count>s)
                break;
            i--;
            x2++;
            for(;i>=x1;i--){
                if(head!=nullptr){
                    matrix[i][j] = head->val;
                    head = head->next;
                }
                else{
                    matrix[i][j] = -1;
                }
                count++;
            }
            i++;
            if(count>s)
                break;
            y1++;
            j++;
        }
        return matrix;
    }
};