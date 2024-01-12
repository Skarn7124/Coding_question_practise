class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1 = 0;
        int n = s.size();
        n /= 2;
        for(int i = 0;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                count1++;
        }
        n = 2*n;
        for(int i = n/2;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                count1--;
        }
        return count1 == 0;
    }
};