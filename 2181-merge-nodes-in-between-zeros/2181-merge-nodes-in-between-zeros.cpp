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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *p,*q;
        p = head;
        q = head;
        int x = 0;
        while(p!=nullptr){
            if(p->val == 0)
                p = p->next;
            if(p == nullptr)
                break;
            q = p->next;
            while(q->val != 0){
                p->val += q->val;
                q = q->next;
            }
            p->next = q;
            p = p->next;
        }
        p = head;
        q = nullptr;
        while(p!=nullptr){
            if(p->val == 0){
                p = p->next;
            }
            if(p == nullptr)
                break;
            if(q == nullptr){
                q = p;
                head = q;
            }
            else{
                q->next = p;
                q = q->next;
            }
            p = p->next;
        }
        q->next = nullptr;
        return head;
    }
};