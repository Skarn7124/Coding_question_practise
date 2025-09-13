class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> m;
        for(auto it : s){
            m[it]++;
        }
        int a = 0;
        a = max(m['a'],max(m['e'],max(m['i'],max(m['o'],m['u']))));
        m['a'] = 0;
        m['e'] = 0;
        m['i'] = 0;
        m['o'] = 0;
        m['u'] = 0;
        int b = 0;
        for(auto it : s){
            b = max(m[it],b);
        }
        return a+b;
    }
};