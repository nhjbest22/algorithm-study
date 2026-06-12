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
        unordered_map<ListNode*, bool> um;

        auto cur = head;
        while(cur != nullptr){
            if(um.find(cur) != um.end()) return true;

            um[cur] = true;
            cur = cur -> next;
        }

        return false;
    }
};