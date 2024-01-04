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
    ListNode* swapPairs(ListNode* head) {
        ListNode *p,*q,*temp,*prev = nullptr;
        p = head;
        if(p == nullptr)
            return p;
        temp = p->next;
        while(p!=nullptr){
            q = p->next;
            if(q == nullptr)
                break;
            // cout<<p->val<<" "<<q->val<<"*";
            p->next = q->next;
            q->next = p;
            // cout<<q->val<<" "<<q->next->val<<" | ";
            if(prev!=nullptr){
                prev->next = q;
            }
            prev = p;
            p = p->next;
        }
        p=temp;
        while(p!=nullptr){
            cout<<p->val<<" ";
            p = p->next;
        }
        if(temp == nullptr)
            return head;
        return temp;
    }
};