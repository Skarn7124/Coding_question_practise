class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int i = log10(low)+1;
        int n = log10(high)+1;
        string t = "";
        int y,x;
        vector<int> ans;
        for(int j = i;j<=n;j++){
            t = "";
            for(int k = 0;k<j;k++){
                t += '1'+k;
            }
            x = t.size();
            while(t[x-1]<='9'){
                y = stoi(t);
                if(y>=low && y<=high){
                    ans.push_back(y);
                }
                for(int k = 0;k<j;k++){
                    t[k] += 1;
                }
            }
        }
        return ans;
    }
};