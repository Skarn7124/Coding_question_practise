class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> dic;
        if(s1.size() < s2.size()){
            swap(s1,s2);
        }
        string t = "";
        for(auto it : s1){
            if(it == ' '){
                dic.push_back(t);
                t = "";
            }
            else{
                t += it;
            }
        }
        dic.push_back(t);
        t = "";
        vector<string> check;
        for(auto it : s2){
            if(it == ' '){
                check.push_back(t);
                t = "";
            }
            else{
                t += it;
            }
        }
        check.push_back(t);

        int n = dic.size(),m = check.size();
        int i = 0,j = m-1;
        int x = 0,y = n-1;
        int d1 = 0,d2 = 0;
        while(i<=j){
            if(dic[x] == check[i] && dic[y] == check[j]){
                x++;
                y--;
                i++;
                j--;
            }
            else if(dic[x] == check[i]){
                x++;
                i++;
                d2 = 1;
                if(d1 == 1){
                    return 0;
                }
            }
            else if(dic[y] == check[j]){
                y--;
                j--;
                d1 = 1;
                if(d2 == 1){
                    return 0;
                }
            }
            else{
                if(i>j)
                    return 1;
                return 0;
            }
        }
        return 1;
    }
};