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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* head1 = head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        prev = nullptr;
        ListNode* temp = nullptr;

        while(slow){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        ListNode* next1 = nullptr;
        ListNode* next2 = nullptr;
        while(head1){
            next1 = head1->next;
            next2 = prev->next;
            head1->next = prev;
            if (next1 == nullptr){
                return;
            }
            prev->next = next1;
            head1 = next1;
            prev = next2;
        }




    }
};
