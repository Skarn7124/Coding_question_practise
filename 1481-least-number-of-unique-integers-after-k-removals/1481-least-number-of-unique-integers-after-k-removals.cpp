class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> m;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            m[arr[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        for(auto it : m){
            p.push({it.second,it.first});
        }
        while(!p.empty() && k>0){
            k -= p.top().first;
            p.pop();
        }
        if(k<0)
            return p.size()+1;
        return p.size();
    }
};