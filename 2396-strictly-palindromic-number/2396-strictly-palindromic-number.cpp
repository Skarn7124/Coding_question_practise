class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        string t = "",s;
        int x = 0,y,z;
        for(int i = 2;i<=n-2;i++){
            x = n;
            y = i;
            t = "";
            while(x>=y){
                z = x%y;
                if(z>9){
                    t += 'A'+z-10;
                }
                else{
                    t += z+'0';
                }
                x/=y;
            }
            z = x;
            if(z>9){
                t += 'A'+z-10;
            }
            else{
                t += z+'0';
            }
            s = t;
            reverse(t.begin(),t.end());
            // cout<<s<<"\n";
            if(t != s)
                return 0;
        }
        return 1;
    }
};