class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        long long int a,b,r;
        int n = queries.size(),m = points.size();
        vector<int> ans(n,0);
        for(int i = 0;i<n;i++){
            a = queries[i][0];
            b = queries[i][1];
            r = queries[i][2];
            r = r*r;
            for(int j = 0;j<m;j++){
                a = queries[i][0]-points[j][0];
                b = queries[i][1]-points[j][1];
                a = a*a;
                b = b*b;
                a = a+b;
                if(a<=r){
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};