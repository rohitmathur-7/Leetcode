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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1=list1;
        ListNode* p2=list2;
        ListNode* root=NULL;
        ListNode* tmp=root;
        while(p1!=NULL && p2!=NULL){
            if(p1->val<p2->val){
                if(root==NULL){
                    root=p1;
                    tmp=root;
                }
                else{
                    tmp->next=p1;
                    tmp=tmp->next;
                }
                p1=p1->next;
            }
            else{
                if(root==NULL){
                    root=p2;
                    tmp=root;
                }
                else{
                    tmp->next=p2;
                    tmp=tmp->next;
                }
                p2=p2->next;
            }
        }
        if(p1!=NULL){
            if(tmp!=NULL){
                 tmp->next=p1;
                tmp=tmp->next;
            }
            else{
                root=p1;
                tmp=p1;
            }
            p1=p1->next;
        }
        if(p2!=NULL){
            if(tmp!=NULL){
                tmp->next=p2;
                tmp=tmp->next;
            }
            else{
                root=p2;
                tmp=p2;
            }
        }
        return root;
    }
};