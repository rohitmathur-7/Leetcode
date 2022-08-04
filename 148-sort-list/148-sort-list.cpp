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
    
    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* ptr=new ListNode(0);
        ListNode* cur=ptr;
        
        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                cur->next=l1;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        
        if(l1!=NULL){
            cur->next=l1;
            l1=l1->next;
        }
        if(l2!=NULL){
            cur->next=l2;
            l2=l2->next;
        }
        
        return ptr->next;
    }
    
    ListNode* sortList(ListNode* head){
        
        //0 or 1 element
        if(head==NULL || head->next==NULL) return head;
        
        //so first find mid by using slow and fast pointers
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* tmp=NULL;
        
        
        while(fast!=NULL && fast->next!=NULL){
            tmp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        tmp->next=NULL; //this cuts the connection of left and right half
        //Left half = head->tmp
        //Right half = slow->end
        
        //Apply merge sort from here
        
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(slow);                
        
        return merge(l1,l2);
        
    }
};