class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        set<int> r,c;
        int n = mat.size(),m = mat[0].size(); 
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(auto it : r){
            for(int i = 0;i<m;i++){
                mat[it][i] = 0;
            }
        }
        for(auto it : c){
            for(int i = 0;i<n;i++){
                mat[i][it] = 0;
            }
        }
    }
};