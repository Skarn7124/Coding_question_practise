class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if((nums[i]&1) == 0)
                count++;
            if(count>=2)
                return 1;
        }
        return 0;
    }
};