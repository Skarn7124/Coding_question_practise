class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<long int,int>> v(n);
        long long int ans = 0,x;
        for(int i = 0;i<n;i++){
            int j = i-1;
            if(j>=0){
                x = (long long int)nums[i]-(long long int)nums[j];
                v[i][x] += v[j][x]+1;
                ans += v[j][x];

            }
        }
        return ans;
    }
};