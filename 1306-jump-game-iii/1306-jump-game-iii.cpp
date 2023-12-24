class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0)
            return 1;
        queue<pair<int,int>>q;
        int n = arr.size();
        vector<int> vis(n+1,0);
        q.push({start,0});
        int ans = 0;
        int x,y;
        int z = 0;
        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            vis[x] = 1;
            q.pop();
            if(arr[x] == 0){
                ans = y;
                break;
            }
            if(x+arr[x]<n && vis[(x+arr[x])] == 0){
                q.push({x+arr[x],y+1});
            }
            if(x-arr[x]>=0 && vis[(x-arr[x])] == 0){
                q.push({x-arr[x],y+1});
            }
        }
        return ans;
    }
};