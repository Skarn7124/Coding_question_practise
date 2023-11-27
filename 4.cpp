/*
  935. Knight Dialer
Solved
Medium
Topics
Companies
The chess knight has a unique movement, it may move two squares vertically and one square horizontally, or two squares horizontally and one square vertically (with both forming the shape of an L). The possible movements of chess knight are shown in this diagaram:

A chess knight can move as indicated in the chess diagram below:


We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell (i.e. blue cell).


Given an integer n, return how many distinct phone numbers of length n we can dial.

You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

As the answer may be very large, return the answer modulo 109 + 7.
  */
class Solution {
public:
    int mod = 1e9+7;
    int knightDialer(int n) {
        vector<vector<int>> v(10);
        vector<int> ans (5001,0);
        ans[1] = 10;
        v[0] = {4,6},v[1] = {6,8},v[2] = {7,9},v[3] = {4,8},v[4] = {0,3,9};
        v[6] = {0,1,7},v[7] = {2,6},v[8] = {1,3},v[9] = {2,4};
        vector<int> num(10,1),temp(0);
        for(int i = 2;i<=n;i++){
            for(int j = 0;j<10;j++){
                ans[i] += (num[j]*(v[j].size()))%mod;;
                ans[i]%=mod;
            }
            temp = {0,0,0,0,0,0,0,0,0,0};
            for(int j = 0;j<10;j++){
                for(auto &it : v[j]){
                    temp[it]+=num[j];
                    temp[it]%=mod;
                }
            }
            num = temp;
        }
        return ans[n];
    }
};
