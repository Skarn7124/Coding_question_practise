class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,int> m;
        int n = path.size();
        int x = 0,y = 0;
        m[{x,y}] = 1;
        for(int i = 0;i<n;i++){
            if(path[i] == 'N'){
                y++;
            }
            else if(path[i] == 'S'){
                y--;
            }
            else if(path[i] == 'E'){
                x++;
            }
            else{
                x--;
            }
            if(m[{x,y}] == 1){
                return true;
            }
            else
                m[{x,y}] = 1;
            cout<<x<<" "<<y<<"\n";
        }
        return false;
    }
};