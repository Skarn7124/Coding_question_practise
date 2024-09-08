class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total = (m+n)*mean;
        for(auto it : rolls){
            total -= it;
        }
        vector<int> ans(n);
        int x = total/n;
        for(int i = 0;i<n;i++){
            ans[i] = x;
            total -= x;
        }
        for(int i = 0;i<total;i++){
            ans[i]++;
        }
        for(auto it : ans){
            if(it>0 && it<=6){

            }
            else{
                return {};
            }
        }
        return ans;
    }
};