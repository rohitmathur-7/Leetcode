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
    unordered_map<Node*,Node*> mp;
    Node* cloneGraph(Node* node){
        if(node==NULL) return NULL;
        
        Node* new_node=new Node(node->val);
        mp[node]=new_node;
        
        for(auto x:node->neighbors){
            if(mp.count(x)){
                new_node->neighbors.push_back(mp[x]);
            }
            else{
                new_node->neighbors.push_back(cloneGraph(x));                
            }
        }
        
        return new_node;
    }
};