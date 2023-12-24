class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxl = 0,maxr = 0;
        int len1 = 0,len2 = 0,j,k;
        for(int i = 0;i<n;i++){
            len1 = 0;
            len2 = 0;
            j = i+1;
            k = i;
            while(j<n && k>=0){
                if(s[j] != s[k]){
                    break;
                }
                len1 = j-k+1;
                if(s[j] == s[k]){
                    if(j+1<n)
                        j++;
                    else
                        break;
                    if(k-1>=0)
                        k--;
                    else
                        break;
                }
            }
            j = i+1;
            k = i-1;
            while(j<n && k>=0){
                if(s[j] != s[k]){
                    break;
                }
                len2 = j-k+1;
                if(j+1<n)
                    j++;
                else
                    break;
                if(k-1>=0)
                    k--;
                else
                    break;
            }
            // cout<<i<<" "<<len1<<" "<<len2<<" ";
            len1 = max(len1,len2);
            if(len1>(maxr-maxl)){
                maxl = i-((len1+1)/2)+1;
                maxr = i+(len1/2);
            }
            // cout<<maxl<<" "<<maxr<<'\n';
        }

        return s.substr(maxl,maxr-maxl+1);
    }
};