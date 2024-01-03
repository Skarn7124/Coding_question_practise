class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0,count = 0;
        int n = nums.size();
        for(int i = 0;i<32;i++){
            count = 0;
            for(int j = 0;j<n;j++){
                if((nums[j] & (1<<i)) != 0)
                    count++;
            }
            if(count%3 != 0)
                ans += (1<<i);
        }
        return ans;
    }
};