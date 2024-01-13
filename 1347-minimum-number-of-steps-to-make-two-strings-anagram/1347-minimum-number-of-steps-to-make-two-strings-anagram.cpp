class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> a(26),b(26);
        int n = s.size();
        for(auto it : s){
            a[it-'a']++;
        }
        for(auto it : t){
            b[it-'a']++;
        }
        int ans = 0,c = 0;
        for(int i = 0;i<26;i++){
            if(a[i] == 0){
                ans += b[i];
            }
            else if(b[i] == 0){
                ans += a[i];
            }
            else{
                ans += abs(a[i]-b[i]);
            }
            // cout<<a[i]<<" "<<b[i]<<'\n';
        }
        ans = ceil((double)ans/2);
        return ans;
    }
};