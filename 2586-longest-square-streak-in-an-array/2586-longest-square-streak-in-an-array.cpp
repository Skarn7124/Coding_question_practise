class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<long long int,int> m;
        for(auto it : nums){
            m[it]++;
        }
        sort(nums.begin(),nums.end());
        int ans = 0;
        int cur = 0;
        int n = nums.size();
        long long int x = 1;
        for(int i = 0;i<n;i++){
            if(m[nums[i] == 0]) continue;
            cout<<nums[i]<<" ";
            x = nums[i];
            cur = 1;
            while(m[(x*x)] >= 1){
                cur++;
                m[x] = 0;
                x = x*x;
            }
            ans = max(cur,ans);
            cur = 1;
        }
        if(ans<2)
            return -1;
        return ans;
    }
};