/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        stack<ListNode*> st;
        ListNode* tmp=head;
        while(tmp!=NULL){
            st.push(tmp);
            tmp=tmp->next;
        }
        int c=0;
        while(!st.empty()){
            ListNode* node=st.top();
            st.pop();
            if(c==0){
                tmp=node;
            }
            if(!st.empty()){
                node->next=st.top();
            }
            else node->next=NULL;
            c++;
        }
        return tmp;
    }
};