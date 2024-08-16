class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int,int>> p;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        int n,x = 0;
        for(auto it : arrays){
            n = it.size();
            p.push({it[n-1],x});
            q.push({it[0],x});
            x++;
        }
        int a = p.top().second,b = q.top().second,c = p.top().first,d = q.top().first;
        if(a == b){
            p.pop();
            q.pop();
            if(abs(c-q.top().first)<abs(d-p.top().first)){
                c = p.top().first;
            }
            else{
                d = q.top().first;
            }
        }
        return abs(c-d);
    }
};