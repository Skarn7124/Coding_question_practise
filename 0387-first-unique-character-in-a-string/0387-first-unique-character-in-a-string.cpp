class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> a(26,0);
        for(auto it : s){
            a[it-'a']++;
        }
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(a[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};