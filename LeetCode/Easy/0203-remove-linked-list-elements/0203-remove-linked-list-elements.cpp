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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        
        dummy -> next = head;

        while(cur -> next){
            if(cur->next->val != val){
                cur = cur -> next;
                continue;
            }
            
            ListNode* toDelete = cur->next;
            cur->next = cur->next->next;
            delete toDelete;
        }

        return dummy -> next;
    }
};