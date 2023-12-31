class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> start(26,-1),end(26,-1);
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(start[s[i]-'a'] == -1){
                start[s[i]-'a'] = i;
            }
            end[s[i]-'a'] = i;
        }
        int ma = -1;
        for(int i = 0;i<26;i++){
            if(end[i]!=-1){
                if(end[i]-start[i]-1>ma){
                    ma = end[i]-start[i]-1;
                }
            }
        }
        return ma;
    }
};