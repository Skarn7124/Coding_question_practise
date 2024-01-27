class Solution {
public:
    void dfs(vector<vector<int>>&adj,int numCourses,int i,vector<int>&vis){
        if(vis[i] == 1){
            vis[i] = -1;
            return;
        }
        // cout<<i<<" ";
        vis[i] = 1;
        int n = adj[i].size();
        for(int ik = 0;ik<n;ik++){
            if(vis[adj[i][ik]] == 0){
                dfs(adj,numCourses,adj[i][ik],vis);
            }
            else if(vis[adj[i][ik]] == 1){
                vis[i] = -1;
                return;
            }
        }
        vis[i] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n = prerequisites.size();
        for(int i = 0;i<n;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> vis(numCourses);
        for(int i = 0;i<numCourses;i++){
            if(vis[i] == 0){
                dfs(adj,numCourses,i,vis);
            }
            if(vis[i] == -1){
                return false;
            }
            // cout<<i<<" : "<<vis[i]<<'\n';
            continue;
        }
        return true;
    }
};