class Solution {
public:
    string convertToTitle(int columnNumber) {
        int x = 1,y = 1;
        string temp = "";
        while(columnNumber != 0){
            y = columnNumber%26;
            // cout<<y<<" "<<x<<'\n';
            if(y == 0){
                temp += 'Z';
                columnNumber -= 26;
            }
            else{
                temp += 'A'+y-1;
                columnNumber -= y;
            }
            columnNumber/=26;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};