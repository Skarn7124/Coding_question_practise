class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        queue<int> a,b,c;
        for(int i = 0;i<n;i++){
            if(nums[i]<pivot){
                a.push(nums[i]);
            }
            else if(nums[i]==pivot){
                b.push(nums[i]);
            }
            else{
                c.push(nums[i]);
            }
        }
        int i = 0;
        while(!a.empty()){
            nums[i] = a.front();
            a.pop();
            i++;
        }
        while(!b.empty()){
            nums[i] = b.front();
            b.pop();
            i++;
        }
        while(!c.empty()){
            nums[i] = c.front();
            c.pop();
            i++;
        }
        return nums;
    }
};