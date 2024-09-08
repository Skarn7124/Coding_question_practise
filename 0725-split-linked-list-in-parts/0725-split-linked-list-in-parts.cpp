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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *p = head,*q = nullptr,*t;
        vector<ListNode*> ans;
        int n = 0,x = 0,y = 0;
        while(p!=nullptr){
            n++;
            p = p->next;
        }
        if(n<=k){
            p = head;
            while(p != nullptr){
                t = p->next;
                p->next = nullptr;
                ans.push_back(p);
                p = t;
                k--;
            }
            while(k--){
                ans.push_back(nullptr);
            }
            return ans;
        }
        y = n/k;
        n %= k;
        p = head;
        q = head;
        // cout<<y<<" "<<n<<" ";
        while(p!=nullptr){
            if(x == y){
                if(n && p->next != nullptr){
                    n--;
                    p = p->next;
                }
                t = p->next;
                p->next = nullptr;
                ans.push_back(q);
                p = t;
                x = 0;
            }
            if(x == 0){
                q = p;
                x++;
            }
            else{
                p=p->next;
                x++;
            }
        }
        return ans;
    }
};