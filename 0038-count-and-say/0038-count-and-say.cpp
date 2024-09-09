class Solution {
public:
    string gen(string a){
        string ans = "";
        int x = 0,n = a.size();
        char ch;
        for(int i = 0;i<n;i++){
            ch = a[i];
            while(i<n && a[i] == ch){
                x++;
                i++;
            }
            i--;
            ans += to_string(x)+a[i];
            x = 0;
        }
        return ans;
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 2;i<=n;i++){
            ans = gen(ans);
        }
        return ans;
    }
};