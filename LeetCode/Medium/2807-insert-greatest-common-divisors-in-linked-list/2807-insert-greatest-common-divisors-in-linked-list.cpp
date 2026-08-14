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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cur = head;

        while(cur->next){
            ListNode* nxt = cur->next;

            ListNode *ptr = new ListNode(__gcd(cur->val, nxt->val), nxt);
            cur->next = ptr;

            cur = nxt;
        }

        return head;
    }
};