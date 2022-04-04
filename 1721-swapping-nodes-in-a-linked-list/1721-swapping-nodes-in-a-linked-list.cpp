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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* tmp=head;
        int n=0;
        while(tmp!=NULL){
            n++;
            tmp=tmp->next;
        }
        tmp=head;
        int cnt=1,val1,val2;
        while(cnt<=k){
            if(cnt==k) val1=tmp->val;
            tmp=tmp->next;
            cnt++;
        }
        cnt=1;
        tmp=head;
        while(cnt<=n-k+1){
            if(cnt==(n-k+1)) val2=tmp->val;
            tmp=tmp->next;
            cnt++;
        }
        cnt=1;
        tmp=head;
        while(cnt<=k){
            if(cnt==k) tmp->val=val2;
            tmp=tmp->next;
            cnt++;
        }
        cnt=1;
        tmp=head;
        while(cnt<=n-k+1){
            if(cnt==(n-k+1)) tmp->val=val1;
            tmp=tmp->next;
            cnt++;
        }
        tmp=head;
        
        return tmp;
    }
};