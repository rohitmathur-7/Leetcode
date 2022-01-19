/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool > m;
        ListNode* tmp=head;
        int i=0;
        while(tmp!=NULL){
            if(m[tmp]) return tmp;
            m[tmp]=tmp;
            tmp=tmp->next;
        }
        return NULL;
    }
};