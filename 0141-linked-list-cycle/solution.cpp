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
        if (not head) return false;
        if (head->next == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast and fast->next){
            if (slow == fast){
                return true;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};
