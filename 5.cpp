/*
2147. Number of Ways to Divide a Long Corridor

Along a long library corridor, there is a line of seats and decorative plants. You are given a 0-indexed string corridor of length n consisting of letters 'S' and 'P' where each 'S' represents a seat and each 'P' represents a plant.

One room divider has already been installed to the left of index 0, and another to the right of index n - 1. Additional room dividers can be installed. For each position between indices i - 1 and i (1 <= i <= n - 1), at most one divider can be installed.

Divide the corridor into non-overlapping sections, where each section has exactly two seats with any number of plants. There may be multiple ways to perform the division. Two ways are different if there is a position with a room divider installed in the first way but not in the second way.

Return the number of ways to divide the corridor. Since the answer may be very large, return it modulo 109 + 7. If there is no way, return 0.
  */

class Solution {
public:
    int numberOfWays(string corridor) {
        int rem = 0;
        int mod = 1e9+7;
        int n = corridor.size();
        for(int i = 0;i<n;i++){
            if(corridor[i] == 'S')
                rem++;
        }
        if(rem%2!=0)
            return 0;
        int temp = 0,cur = 0;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(corridor[i] == 'S'){
                if(cur!=2){
                    rem--;
                    cur++;
                    if(cur == 2){
                        temp = 1;
                    }
                }
                else{
                    ans.push_back(temp);
                    temp = 0;
                    cur = 1;
                    rem--;
                }
            }
            else{
                if(cur!=2){
                    continue;
                }
                else{
                    if(rem == 0){
                        ans.push_back(1);
                        break;
                    }
                    temp++;
                }
            }
        }
        if(temp != 0)
            ans.push_back(temp);
        long int res = 1;
        if(ans.size() == 0)
            return 0;
        for(auto it : ans){
            res = (res*it)%(mod);
        }
        return res;
    }
};
