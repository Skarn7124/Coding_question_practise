class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& arr) {
        long long int ans = 0;
        int count  = 0;
        int n = arr.size();
        int m = arr[0].size();
        int mini = INT_MAX;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(arr[i][j]<0){
                    count++;
                    ans += -(arr[i][j]);
                }
                else{
                    ans += arr[i][j];
                }
                mini = min(mini,abs(arr[i][j]));
            }
        }
        // cout<<ans<<" "
        if(count%2 == 0)
            return ans;
        return ans - 2*mini;
    }
};