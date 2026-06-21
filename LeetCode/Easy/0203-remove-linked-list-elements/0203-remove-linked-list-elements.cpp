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
        ListNode *prev = dummy, *cur = head;
        
        dummy -> next = head;

        while(cur){
            if(cur -> val != val){
                prev = cur;
                cur = cur -> next;

                continue;
            }

            prev -> next = cur -> next;
            delete cur;
            cur = prev -> next;
        }

        return dummy -> next;
    }
};