class Solution {
public:
    int minBitFlips(int start, int goal) {
        string a = "",b = "";
        int ans = 0;
        for(int i = 0;i<32;i++){
            if((1<<i) & start){
                a += "1";
            }
            else{
                a += "0";
            }
            if((1<<i) & goal){
                b += "1";
            }
            else{
                b += "0";
            }
            // cout<<a[i]<<" "<<b[i]<<'\n';
            if(abs(a[i]-b[i]) == 1){
                ans++;
            }
        }
        return ans;
    }
};