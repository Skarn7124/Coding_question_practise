class StockSpanner {
public:
    vector<int> v;
    stack<int> s;
    int x = 0;
    StockSpanner() {
        v.clear();
    }    
    int next(int price) {
        v.push_back(price);
        while(!s.empty() && v[s.top()]<=price)
            s.pop();
        int ans = 0;
        if(s.empty()){
            ans = x+1;
        }
        else{
            ans = x-s.top();
        }
        s.push(x);
        cout<<v[x]<<" ";
        x++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */