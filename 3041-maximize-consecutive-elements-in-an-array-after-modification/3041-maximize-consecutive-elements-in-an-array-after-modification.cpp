class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        unordered_map<int,int>m;
        int ans = 0,a,b;
        for(int i = 0;i<n;i++){
            a = 1,b = 1;
            if(m.find(nums[i]-1)!=m.end()){
                a = m[nums[i]-1]+1;
            }
            if(m.find(nums[i])!=m.end()){
                b = m[nums[i]]+1;
            }
            if(m.find(nums[i]) == m.end())
                m[nums[i]] = a;
            if(m.find(nums[i]+1) == m.end())
                m[nums[i]+1] = b;
            m[nums[i]] = max(m[nums[i]],a);
            m[nums[i]+1] = max(m[nums[i]+1],b);
            ans = max(max(m[nums[i]],m[nums[i]+1]),ans);
        }
        return ans;
    }
};