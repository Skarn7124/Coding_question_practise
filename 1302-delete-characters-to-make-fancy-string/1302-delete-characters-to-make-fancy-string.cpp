class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        char c = s[0];
        int count = 1;
        string ans = "";
        ans += s[0];
        for(int i = 1;i<n;i++){
            if(s[i] == c){
                if(count == 2){
                    continue;
                }
                else{
                    ans += s[i];
                    count++;
                }
            }
            else{
                count = 1;
                c = s[i];
                ans += s[i];
            }
        }
        return ans;
    }
};