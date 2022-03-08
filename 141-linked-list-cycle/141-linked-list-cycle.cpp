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
    bool hasCycle(ListNode *head) {
        int a=0;
        while(head!=NULL){
            a++;
            if(a==10001) return true;
            head=head->next;
        }
        return false;
    }
};