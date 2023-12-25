class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> m;
        int sum = 0,t;
        while(n!=1){
            if(m[n] == 1)
                return 0;
            m[n] = 1;
            t = n;
            sum = 0;
            while(t>0){
                sum += (t%10)*(t%10);
                t /= 10;
            }
            n = sum;
        }
        return 1;
    }
};