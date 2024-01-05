class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> s;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            auto it = lower_bound(s.begin(),s.end(),nums[i]);
            if(it == s.end()){
                s.push_back(nums[i]);
            }
            else{
                *it = nums[i];
            }
        }
        return s.size();
    }
};