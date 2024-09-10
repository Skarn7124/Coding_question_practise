class Solution {
public:
    set<vector<int>> s;
    void gen(int i,int n,vector<int>& nums,vector<int>& a){
        if(i == n){
            s.insert(a);
            return;
        }
        for(int j = 0;j<n;j++){
            if(a[j] == -11){
                a[j] = nums[i];
                gen(i+1,n,nums,a);
                a[j] = -11;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n,-11);
        gen(0,n,nums,a);
        vector<vector<int>> ans;
        for(auto it : s){
            ans.push_back(it);
        }
        return ans;
    }
};