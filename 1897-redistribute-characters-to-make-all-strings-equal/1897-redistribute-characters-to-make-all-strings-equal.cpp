class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int> m;
        int n = words.size();
        for(int i = 0;i<n;i++){
            for(auto it : words[i]){
                m[it]++;
            }
        }
        for(auto it : m){
            if(it.second%n == 0){
                continue;
            }
            return 0;
        }
        return 1;
    }
};