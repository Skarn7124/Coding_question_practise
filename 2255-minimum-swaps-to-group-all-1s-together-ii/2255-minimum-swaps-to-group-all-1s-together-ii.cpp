class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> v;
        int cnt = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            cnt += nums[i];
        }
        int ans = INT_MAX;
        int cur = 0;
        for(int i = 0;i<cnt;i++){
            cur += nums[i];
        }
        ans = min(ans,cnt-cur);
        // cout<<cnt<<" * "<<cur<<"\n";
        for(int i = 1;i<n;i++){
            cur -= nums[i-1];
            cur += nums[(i+cnt-1+n)%n];
            ans = min(ans,cnt-cur);
            // cout<<cur<<" "<<ans<<"\n";
        }
        return ans;
    }
};