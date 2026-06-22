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
    int numComponents(ListNode* head, vector<int>& nums) {
        bool isExist[10'005];
        fill(isExist, isExist + 10'005, false);

        for(auto& num: nums) isExist[num] = true;

        int ans = 0;
        bool isConnected = false;
        while(head){
            if(!isExist[head -> val]){
                isConnected = false;
                head = head -> next;
                continue;
            }

            if(!isConnected) ans++;

            isConnected = true;
            head = head -> next;
        }

        return ans;
    }
};