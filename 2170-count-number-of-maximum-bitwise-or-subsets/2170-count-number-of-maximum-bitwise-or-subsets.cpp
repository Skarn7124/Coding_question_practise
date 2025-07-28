class Solution {
public:
    int gen(int i,int n,int cur,int max,vector<int>& nums){
        if(i == n){
            if(cur == max)
                return 1;
            return 0;
        }
        int ans = gen(i+1,n,cur|nums[i],max,nums)+gen(i+1,n,cur,max,nums);
        return ans;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int max = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            max |= nums[i];
        }
        int ans = gen(0,n,0,max,nums);
        return ans;
    }
};