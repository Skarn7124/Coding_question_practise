class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int a1 = 0,a2 = 0;
        for(int i = 0;i<n;i++){
            if(i%2 == 0){
                if(s[i] == '0')
                    a2++;
                else
                    a1++;
            }
            else{
                if(s[i] == '1')
                    a2++;
                else
                    a1++;
            }
        }
        return min(a1,a2);
    }
};