class Solution {
public:
    long long dividePlayers(vector<int>& nums) {
        int n = nums.size();
        map<int,int> m;
        long long int sum = 0,ans = 0;
        for(int i = 0;i<n;i++){
            m[nums[i]]++;
            sum += nums[i];
        }
        sum /= (n/2);
        for(int i = 0;i<n;i++){
            if(m[sum-nums[i]]>=1){
                m[sum-nums[i]]--;
                ans += (sum-nums[i])*nums[i];
            }
            else
                return -1;
        }
        ans /= 2;
        return ans;
    }
};