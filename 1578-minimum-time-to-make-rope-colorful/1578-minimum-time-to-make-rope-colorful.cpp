class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char,int>> s;
        int n = colors.size();
        int ans = 0,x;
        for(int i = 0;i<n;i++){
            if(s.empty()){
                s.push({colors[i],i});
            }
            else{
                if(s.top().first == colors[i]){
                    x = s.top().second;
                    if(neededTime[x]>=neededTime[i]){
                        ans += neededTime[i];
                    }
                    else{
                        ans += neededTime[x];
                        s.pop();
                        s.push({colors[i],i});
                    }
                }
                else
                    s.push({colors[i],i});
            }
        }
        return ans;
    }
};