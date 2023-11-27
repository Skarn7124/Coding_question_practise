/*
You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.
*/
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int j = 0;j<m;j++){
            for(int i = 1;i<n;i++){
                if(matrix[i][j]==1){
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            sort(matrix[i].begin(),matrix[i].end());
            reverse(matrix[i].begin(), matrix[i].end());
        }
        for(int i = 0;i<n;i++){
            for(int j = 0; j < m; j++)
                ans = max(ans, matrix[i][j]*(j+1));
        }
        return ans;
    }
};
