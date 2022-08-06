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
    bool isPalindrome(ListNode* head){
        if(head==NULL || head->next==NULL) return true;
        
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        ListNode* tmp;
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            tmp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=tmp;
        }
        
        ListNode* mid=prev;
        if(fast){
            tmp=slow->next;
        }
        
        while(mid!=NULL and tmp!=NULL){
            if(mid->val!=tmp->val) return false;
            mid=mid->next;
            tmp=tmp->next;
        }
        
        if(mid==NULL && tmp==NULL) return true;
        return false;
    }
};