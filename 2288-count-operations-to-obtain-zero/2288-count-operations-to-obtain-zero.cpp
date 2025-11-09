class Solution {
public:
    int countOperations(int num1, int num2) {
        int less = min(num1,num2);
        int more = max(num1,num2);
        if(less == 0)
            return 0;
        int ans = more/less;
        more = more-less*ans;
        int ans2 = countOperations(less,more);
        return ans + ans2;
    }
};