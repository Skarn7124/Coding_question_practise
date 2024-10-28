class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<long long int,int> m,t;
        for(auto it : nums){
            m[it]++;
        }
        int ans = 0;
        int cur = 0;
        int n = nums.size();
        long long int x = 1;
        for(int i = 0;i<n;i++){
            if(m[nums[i] == 0]) continue;
            x = nums[i];
            cur = 1;
            while(m[(x*x)] >= 1){
                x = x*x;
                if(t[x] != 0){
                    cur += t[x];
                    break;
                }
                cur++;
                m[x] = 0;
            }
            t[nums[i]] = cur;
            ans = max(cur,ans);
            cur = 1;
        }
        if(ans<2)
            return -1;
        return ans;
    }
};