class Solution {
public:
    string stradd(string a,string b){
        if(a == "")
            return b;
        if(a.size()>b.size()){
            swap(a,b);
        }
        int n = max(a.size(),b.size());
        int x = 0,y = 0;
        string ans = "";
        for(int i = 0;i<n;i++){
            if(i<a.size()){
                x = (a[i]-'0')+(b[i]-'0');
            }
            else{
                x = b[i]-'0';
            }
            x += y;
            y = x/10;
            x = x%10;
            ans += x+'0';
        }
        if(y != 0){
            ans += y+'0';
        }
        // cout<<a<<" "<<b<<" "<<ans<<'\n';
        return ans;
    }
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ans = "";
        int x = 0,y = 0;
        for(int i = 0;i<m;i++){
            string cur = "";
            for(int j = 0;j<i;j++){
                cur += '0';
            }
            x = 0,y = 0;
            for(int j = 0;j<n;j++){
                x = (num2[i]-'0')*(num1[j]-'0');
                x += y;
                y = x/10;
                x = x%10;
                cur += x+'0';
            }
            if(y != 0)
                cur += y+'0';
            // cout<<cur<<'\n';
            ans = stradd(ans,cur);
        }
        n = ans.size();
        while(n>1 && ans[n-1] == '0'){
            ans.pop_back();
            n--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};