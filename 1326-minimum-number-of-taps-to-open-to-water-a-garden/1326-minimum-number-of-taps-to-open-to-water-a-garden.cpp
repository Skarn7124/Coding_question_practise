class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> v;
        int n1 = ranges.size();
        for(int i = 0;i<n1;i++){
            v.push_back({max(0,i-ranges[i]),min(n,i+ranges[i])});
        }
        sort(v.begin(),v.end());
        int start = 0,end = INT_MIN,ans = INT_MAX,i = 0,count = 0;
        while(start<n){
            end = INT_MIN;
            while(i<n1 && v[i].first<=start){
                end = max(end,v[i].second);
                i++;
            }
            if(end == INT_MIN && ans != n)
                return -1;
            ans = end;
            count++;
            start = end;
        }
        return count;
    }
};