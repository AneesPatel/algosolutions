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
        if (!head) return nullptr;
        Node* cur = head;
        unordered_map<Node*, Node*> map = {};
        while (cur){
            Node* copy = new Node(cur->val);
            map[cur] = copy;
            cur = cur->next;
        }
        
        cur = head;
        while(cur){
            Node* newNext = map[cur->next];
            Node* newRandom = map[cur->random];
            map[cur]->next = newNext;
            map[cur]->random = newRandom;
            cur = cur->next;
        }
        return map[head];

    }
};
