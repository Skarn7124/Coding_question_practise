class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int n = events.size();
        int start = events[0][0];
        int end = 0;
        for(int i = 0;i<n;i++){
            end = max(end,events[i][1]);
        }
        int ans = 0,i = 0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for (int d = 1; d <= 100000; ++d) {
            while (pq.size() && pq.top() < d)
                pq.pop();
            while (i < n && events[i][0] == d)
                pq.push(events[i++][1]);
            if (pq.size()) {
                pq.pop();
                ++ans;
            }
        }
        return ans;
    }
};