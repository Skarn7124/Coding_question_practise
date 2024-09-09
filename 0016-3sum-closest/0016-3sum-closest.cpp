class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int cur = 0,ans = 0,check = INT_MAX;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            cur = nums[i];
            int x = i+1,y = n-1;
            while(x<y){
                cur = nums[i]+nums[x]+nums[y];
                if(abs(cur-target)<check){
                    check = abs(cur-target);
                    ans = cur;
                }
                if(cur > target){
                    y--;
                }
                else if(cur == target){
                    return target;
                }
                else{
                    x++;
                }
            }
        }
        return ans;
    }
};