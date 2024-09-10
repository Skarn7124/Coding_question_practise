class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int,int> m;
    void gen(int i,int n,vector<int>&c,int t,vector<int>&v){
        if( i == n){
            if(t == 0){
                ans.push_back(v);
            }
            return;
        }
        int cnt = m[c[i]];
        for(int j = 1;j<=cnt;j++){
            if(t-j*c[i]>=0){
                for(int jd = 1;jd<=j;jd++)
                    v.push_back(c[i]);

                gen(i+1,n,c,t-j*c[i],v);

                for(int jd = 1;jd<=j;jd++)
                    v.pop_back();
            }
            else 
                break;
        }
        gen(i+1,n,c,t,v);
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(),c.end());
        for(auto it : c){
            m[it]++;
        }
        vector<int> x;
        for(auto it : m){
            x.push_back(it.first);
        }
        int n = x.size();
        vector<int> v;
        gen(0,n,x,target,v);
        return ans;
    }
};