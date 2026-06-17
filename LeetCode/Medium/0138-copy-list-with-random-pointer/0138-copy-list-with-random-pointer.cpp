/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* new_head = new Node(0);
        Node* new_cur = new_head;
        Node* ori_cur = head;

        unordered_map<Node*, int> N2I;
        unordered_map<int, Node*> I2N;

        int idx = 0;

        while(ori_cur != nullptr){
            Node* node = new Node(ori_cur->val);
            
            N2I[ori_cur] = idx;
            I2N[idx] = node;
            
            new_cur->next = node;

            new_cur = node;
            ori_cur = ori_cur->next;
            idx++;
        }

        new_cur = new_head->next;
        ori_cur = head;

        while(ori_cur != nullptr){
            if(ori_cur -> random != nullptr){
                int idx = N2I[ori_cur->random];

                Node* rand = I2N[idx];
                new_cur -> random = rand;
            }

            ori_cur = ori_cur -> next;
            new_cur = new_cur -> next;
        }

        return new_head->next;
    }
};