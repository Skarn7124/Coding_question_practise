class Solution {
public:
    string check(string s){
        int n = s.size();
        for(int i = 1;i<n;i++){
            if(s[i] == '1' && s[i-1] == '0'){
                s[i-1] = '1';
                s[i] = '0';
                i++;
            }
        }
        // cout<<s<<'\n';
        return s;
    }
    int secondsToRemoveOccurrences(string s) {
        int ans = 0;
        int n = s.size();
        // int x = 0;
        if(n<2)
            return 0;
        string str = "";
        while(1){
            str = check(s);
            if(s == str)
                break;
            s = str;
            ans++;
        }
        return ans;
    }
};