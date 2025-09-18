class TaskManager {
public:
    map<int,int> done;
    map<int,int> userList;
    priority_queue<vector<int>> p;
    int tempTaskId,tempUserId,tempPriority;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it : tasks){
            p.push({it[2],it[1],it[0]});
            done[it[1]] = it[2];
            userList[it[1]] = it[0];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        p.push({priority,taskId,userId});
        done[taskId] = priority;
        userList[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        p.push({newPriority,taskId,userList[taskId]});
        done[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        done[taskId] = -1;
    }
    
    int execTop() {
        while(!p.empty()){
            tempPriority = p.top()[0];
            tempTaskId = p.top()[1];
            tempUserId = p.top()[2];
            p.pop();
            if(done[tempTaskId] == tempPriority){
                done[tempTaskId] = -1;
                return tempUserId;
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */