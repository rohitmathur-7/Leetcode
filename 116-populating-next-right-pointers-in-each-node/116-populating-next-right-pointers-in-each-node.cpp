/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    //BFS solution S.C - O(W) = O(N) ... W=width of binary tree, W=(n+1)/2 = O(N)  
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* ptr=NULL;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                if(q.front()->right!=NULL) q.push(q.front()->right);
                if(q.front()->left!=NULL) q.push(q.front()->left);
                q.front()->next=ptr;
                ptr=q.front();
                q.pop();
            }
        }
        return root;
    }
};