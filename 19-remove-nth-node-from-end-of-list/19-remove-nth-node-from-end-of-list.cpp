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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp=head;
        int sz=0;
        while(tmp!=NULL){
            tmp=tmp->next;
            sz++;
        }
        int d=sz+1-n;
        tmp=head;
        if(d==1) return head->next;
        while(tmp!=NULL){
            d--;
            if(d==1){
                tmp->next=tmp->next->next;
                break;
            }
            tmp=tmp->next;
        }
        return head;
    }
};