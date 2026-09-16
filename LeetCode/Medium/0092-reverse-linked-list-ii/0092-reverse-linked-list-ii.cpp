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
    void dfs(ListNode* cur, int idx, int right, queue<int>& Q){
        Q.push(cur->val);

        if(idx != right) dfs(cur->next, idx + 1, right, Q);

        cur->val = Q.front();
        Q.pop();
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        left--;
        right--;

        queue<int> Q;

        auto cur = head;
        for(int i = 0; i < left; i++)
            cur = cur->next;
        
        dfs(cur, left, right, Q);

        return head;
    }
};