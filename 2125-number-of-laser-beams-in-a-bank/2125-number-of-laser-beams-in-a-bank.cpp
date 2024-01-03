class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(),m = bank[0].size();
        int temp = 0,temp1 = 0;
        int ans = 0;
        for(int i = 0;i<n;i++){
            temp = 0;
            for(int j = 0;j<m;j++){
                if(bank[i][j] == '1')
                    temp++;
            }
            if(temp != 0){
                ans += temp1*temp;
                temp1 = temp;
            }
        }
        return ans;
    }
};