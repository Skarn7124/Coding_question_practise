class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long int tot = 0;
        int n = chalk.size();
        vector<long int>c(n);
        for(int i = 0;i<n;i++){
            tot += (long int)chalk[i];
            c[i] = chalk[i];
            if(i>0)
                c[i] += c[i-1];
        }
        k %= tot;
        auto it = upper_bound(c.begin(),c.end(),k);
        int ind = it-c.begin();
        return ind;
    }
};