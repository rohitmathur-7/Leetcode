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
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* ptr=NULL;
            int sze=q.size();
            for(int i=0;i<sze;i++){
                Node* node=q.front();
                node->next=ptr;
                ptr=node;
                if(node->right!=NULL) q.push(node->right);
                if(node->left!=NULL) q.push(node->left);
                q.pop();    
            }
        }
        return root;
    }
};









