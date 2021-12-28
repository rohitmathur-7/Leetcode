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
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode* tmp=head;
        ListNode* tmp1=head;
        while(tmp!=NULL){
            n++;
            tmp=tmp->next;
        }
        int pos,i=0;
        pos=(n/2)+1;
        while(tmp1!=NULL){
            i++;
            if(i==pos) break;
            tmp1=tmp1->next;
        }
        return tmp1;
    }
};