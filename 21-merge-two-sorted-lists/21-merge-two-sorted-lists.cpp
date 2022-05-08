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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if(list1==NULL) return list2;
        ListNode* one=list1,*two=list2,*prev=NULL;
        while(one!=NULL && two!=NULL){
            if(one->val>two->val){
                ListNode* node=new ListNode(two->val);
                if(prev!=NULL) prev->next=node;
                else{
                    list1=node;
                }
                prev=node;
                node->next=one;
                two=two->next;
            }
            else if(one->val==two->val){
                ListNode* node=new ListNode(two->val);
                ListNode* nxt=one->next;
                one->next=node;
                node->next=nxt;
                one=one->next;
                two=two->next;
            }
            else{
                prev=one;
                one=one->next;
            }
        }
        while(two!=NULL){
            prev->next=two;
            prev=two;
            two=two->next;
        }
        return list1;
    }
};