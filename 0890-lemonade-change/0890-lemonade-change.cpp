class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> m;
        for(auto it : bills){
            if(it == 5){
                m[5]++;
            }
            else if(it == 10){
                if(m[5] == 0)
                    return false;
                m[5]--;
                m[10]++;
            }
            else{
                if(m[10] >= 1 && m[5] >= 1){
                    m[10]--;
                    m[5]--;
                }
                else if(m[10] == 0 && m[5] >= 3){
                    m[5] -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};