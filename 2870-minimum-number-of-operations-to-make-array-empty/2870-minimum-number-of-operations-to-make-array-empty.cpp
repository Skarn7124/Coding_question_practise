class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            m[nums[i]]++;
        }
        int ans = 0;
        for(auto it : m){
            if(it.second == 1)
                return -1;
            else if(it.second%3 == 0){
                ans += it.second/3;
            }
            else if(it.second%3 == 2){
                ans += it.second/3;
                ans++;
            }
            else if(it.second%3 == 1){
                ans += it.second/3;
                ans++;
            }
            else if(it.second%2 == 0){
                ans += it.second/2;
            }
        }
        return ans;
    }
};