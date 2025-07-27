class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int prev = nums[0],ans = 0;
        int n = nums.size();
        for(int i = 1;i<n-1;i++){
            if(nums[i] == nums[i+1])
                continue;
            else if(nums[i]>prev){
                if(nums[i+1]>nums[i])
                    continue;
                else{
                    ans++;
                    prev = nums[i];
                }
            }
            else if(nums[i]<prev){
                if(nums[i] < nums[i+1]){
                    ans++;
                    prev = nums[i];
                }
                else
                    continue;
            }
            else
                continue;
        }
        return ans;
    }
};