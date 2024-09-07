class Solution {
public:
    int getLucky(string s, int k) {
        int ans = 0,t;
        for(auto it : s){
            t = it-'a'+1;
            while(t){
                ans += t%10;
                t /= 10;
            }
        }
        if(k == 1)
            return ans;
        k-=1;
        while(k--){
            int t = 0;
            while(ans){
                t += ans%10;
                ans /= 10;
            }
            ans = t;
        }
        return ans;
    }
};