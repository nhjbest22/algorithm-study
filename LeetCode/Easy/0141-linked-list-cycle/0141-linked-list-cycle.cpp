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
    const int Offset = 100'001;

    bool hasCycle(ListNode *head) {
        auto cur = head;
        int idx = 0;

        while(cur != nullptr){
            if(cur->val >= Offset) return true;

            cur->val = Offset + idx++;
            cur = cur -> next;
        }


        return false;
    }
};