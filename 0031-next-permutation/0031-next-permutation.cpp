class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int id1 = -1;
        priority_queue<int,vector<int>,greater<int>> p;
        for(int i = n-2;i>=0;i--){
            p.push(nums[i+1]);
            if(nums[i]<nums[i+1]){
                id1 = i;
                break;
            }
        }
        // cout<<id1<<" ";
        if(id1 == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int t = nums[id1];
        queue<int> q;
        while(p.top() <= t){
            q.push(p.top());
            p.pop();
        }

        nums[id1] = p.top();
        // cout<<nums[id1]<<" ";
        p.pop();
        p.push(t);

        while(!q.empty()){
            p.push(q.front());
            q.pop();
        }

        for(int i = id1+1;i<n;i++){
            nums[i] = p.top();
            p.pop();
        }
        return;
    }
};