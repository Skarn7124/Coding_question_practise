class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = temperatures.size();
        vector<int> t(n,0);
        for(int i = n-1;i>=0;i--){
            if(s.empty()){
                s.push(i);
                t[i] = 0;
            }
            else{
                if(temperatures[s.top()]>temperatures[i]){
                    t[i] = s.top()-i;
                    s.push(i);
                }
                else{
                    while(!s.empty() && temperatures[s.top()]<=temperatures[i]){
                        s.pop();
                    }
                    if(s.empty()){
                        s.push(i);
                        t[i] = 0;
                    }
                    else{
                        t[i] = s.top()-i;
                        s.push(i);
                    }
                }
            }
        }
        return t;
    }
};