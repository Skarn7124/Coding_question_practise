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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode *p = head;
        while(p!=nullptr){
            p = p->next;
            n++;
        }
        if(n == 0)  return head;
        k %= n;
        ListNode *start = nullptr;
        p = head;
        int x = n-k;
        if(k == 0)
            return head;
        while(x>1){
            p = p->next;
            x--;
        }
        // cout<<p->val<<" ";
        start = p->next;
        p->next = nullptr;
        p = start;
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = head;
        return start;
    }
};