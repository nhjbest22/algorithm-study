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
    const int check = 100'001;

    bool hasCycle(ListNode *head) {
        auto cur = head;

        while(cur != nullptr){
            if(cur->val == check) return true;

            cur->val = check;
            cur = cur -> next;
        }

        return false;
    }
};