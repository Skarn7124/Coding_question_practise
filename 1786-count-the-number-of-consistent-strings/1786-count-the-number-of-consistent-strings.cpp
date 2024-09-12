class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> m;
        for(auto it : allowed){
            m[it]++;
        }
        int ans = 0,y;
        for(auto it : words){
            y = 0;
            for(auto itr : it){
                if(m[itr]>=1){
                    continue;
                }
                else{
                    y = 1;
                }
            }
            if(y == 0)
                ans++;
        }
        return ans;
    }
};