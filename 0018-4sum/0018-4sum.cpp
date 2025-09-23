class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long int temp;
        set<vector<int>> ans;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    temp = (long int)nums[i]+(long int)nums[j]+(long int)nums[k];
                    auto it1 = lower_bound(nums.begin()+k+1,nums.end(),target-temp);
                    auto it2 = upper_bound(nums.begin()+k+1,nums.end(),target-temp);
                    if ((it2-it1) != 0){
                        ans.insert({nums[i],nums[j],nums[k],*it1});
                    }
                }
            }
        }   
        vector<vector<int>> a1;
        for(auto it : ans){
            a1.push_back(it);
        }
        return a1;
    }
};