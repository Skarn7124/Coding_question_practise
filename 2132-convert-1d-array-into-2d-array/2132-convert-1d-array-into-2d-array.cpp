class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        vector<int> t;
        if(m*n != original.size())
            return ans;
        for(int i = 0;i<n*m;i++){
            if(i%n == 0 && i!=0){
                ans.push_back(t);
                t.clear();
                t.push_back(original[i]);
            }
            else{
                t.push_back(original[i]);
            }
        }
        ans.push_back(t);
        return ans;
    }
};