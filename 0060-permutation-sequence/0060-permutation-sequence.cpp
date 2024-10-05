class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v = {1,2,6,24,120,720,5040,40320,362880};
        k--;
        vector<int> ans(n);
        string str = "";
        vector<int> e (n);

        for(int i = 1;i<=n;i++){
            e[i-1] = i;
        }

        for(int i = n-2;i>=0;i--){
            ans[i] = k/v[i];
            k %= v[i];
            cout<<ans[i]<<" "<<i<<'\n';
        }

        for(int i = n-2;i>=0;i--){
            for(int j = 0;j<n;j++){
                if(e[j] == -1)
                    continue;
                if(ans[i] == 0){
                    str += e[j]+'0';
                    e[j] = -1;
                    break;
                }
                ans[i]--;
            }
        }
        for(int j = 0;j<n;j++){
            if(e[j] == -1)
                continue;
            str += e[j]+'0';
            e[j] = -1;
        }
        return str;

    }
};