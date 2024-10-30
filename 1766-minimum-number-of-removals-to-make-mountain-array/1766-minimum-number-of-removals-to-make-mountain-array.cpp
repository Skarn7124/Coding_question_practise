class Solution {
public:
    void gen(vector<int>&is,int n,vector<int>&nums,vector<int>&v){
        for(int i = 0;i<n;i++){
            auto it = lower_bound(v.begin(),v.end(),nums[i]);
            if(it == v.end()){
                is[i] = v.size();
                v.push_back(nums[i]);
            }
            else{
                v[it-v.begin()] = nums[i];
                is[i] = it-v.begin();
            }
        }
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> is(n),ds(n);
        vector<int> v;
        gen(is,n,nums,v);
        v = {};
        reverse(nums.begin(),nums.end());
        gen(ds,n,nums,v);
        reverse(ds.begin(),ds.end());
        reverse(nums.begin(),nums.end());
        int ans = INT_MAX;
        for(int i = 0;i<n;i++){
            if(is[i] == 0 || ds[i] == 0)
                continue;    
            ans = min(ans,n-(1+is[i]+ds[i]));
        }
        return ans;
    }
};