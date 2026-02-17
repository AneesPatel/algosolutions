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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int> q;
        for(auto x:lists){
            while(x){
                q.push((x->val) * -1);
                x = x->next;
            }
        }
        if (q.empty()) return nullptr;
        ListNode* head = new ListNode(q.top() * -1);
        q.pop();
        ListNode* temp = new ListNode(0);

        temp->next = head;
        
        while(not q.empty()){
            ListNode* next = new ListNode(q.top() * -1);
            q.pop();
            head->next = next;
            head = head->next;
        }
        return temp->next;
    }
};
