/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        map<int,Node*> m;
        map<int,int> vis;
        queue<Node*> q;
        q.push(node);
        Node *temp;
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(vis[temp->val] == 1){
                continue;
            }
            vis[temp->val] = 1;
            m[temp->val] = new Node(temp->val);
            for(auto it : temp->neighbors){
                q.push(it);
            }
        }
        q.push(node);
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(vis[temp->val] == 2){
                continue;
            }
            vis[temp->val] = 2;
            for(auto it : temp->neighbors){
                m[temp->val]->neighbors.push_back(m[it->val]);
                q.push(it);
            }
        }
        return m[node->val];
    }
};