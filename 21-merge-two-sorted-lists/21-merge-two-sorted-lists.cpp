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
        ListNode *ans,*one=list1,*two=list2;
        ListNode* cur=new ListNode(0,NULL);
        ans=cur;
        while(one!=NULL && two!=NULL){
            if(one->val<=two->val){
                ListNode* node=new ListNode(one->val);
                cur->next=node;
                one=one->next;
                cur=cur->next;
            }
            else{
                ListNode* node=new ListNode(two->val);
                cur->next=node;
                two=two->next;
                cur=cur->next;
            }
        }
        while(one!=NULL){
            ListNode* node=new ListNode(one->val);
            cur->next=node;
            one=one->next;
            cur=cur->next;
        }
        while(two!=NULL){
            ListNode* node=new ListNode(two->val);
            cur->next=node;
            two=two->next;
            cur=cur->next;
        }
        return ans->next;
    }
};