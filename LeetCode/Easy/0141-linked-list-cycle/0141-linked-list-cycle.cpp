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
        unordered_set<ListNode*> us;

        auto cur = head;
        while(cur != nullptr){
            if(us.find(cur) != us.end()) return true;

            us.insert(cur);
            cur = cur -> next;
        }

        return false;
    }
};