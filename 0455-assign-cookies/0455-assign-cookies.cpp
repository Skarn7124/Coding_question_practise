class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end()); 
        sort(s.begin(),s.end());
        int j = 0;
        int n = g.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            auto it = lower_bound(s.begin()+j,s.end(),g[i]);
            if(it != s.end()){
                j = it-s.begin()+1;
                ans++;
            }
            else{
                return ans;
            }
        }
        return ans;
    }
};