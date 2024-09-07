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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode *ans = nullptr,*p = head,*q = nullptr;
        unordered_map<int,int> m;
        for(auto it : nums){
            m[it]++;
        }
        while(p!=nullptr){
            if(m[p->val] == 0){
                if(ans == nullptr){
                    ans = p;
                    q = ans;
                }
                else{
                    q->next = p;
                    q = q->next;
                    // cout<<q->val<<":";
                }
            }
            p = p->next;
        }
        if(q != nullptr)
            q->next = nullptr;
        return ans;
    }
};