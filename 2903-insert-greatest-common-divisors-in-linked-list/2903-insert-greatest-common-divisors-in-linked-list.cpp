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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode *p = head,*q;
        int a,b,x;
        while(p!=nullptr){
            q = p->next;
            if(q == nullptr)
                break;
            a = p->val;
            b = q->val;
            x = __gcd(a,b);
            ListNode *temp = new ListNode(x,q);
            p->next = temp;
            p = q;
        }
        return head;
    }
};