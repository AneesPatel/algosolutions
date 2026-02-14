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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* l3 = temp;
        int overflow = 0;
        ListNode* newNode = new ListNode(0);
        
        while(l1 and l2){
            if ((l1->val + l2->val + overflow) > 9){
                newNode = new ListNode((l1->val + l2->val + overflow) % 10);
                overflow = (l1->val + l2->val + overflow) / 10;
            } else{
                newNode = new ListNode((l1->val + l2->val + overflow) % 10);
                overflow = 0;
            }

            l3->next = newNode;
            l3 = l3->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            if ((l1->val + overflow) > 9){
                newNode = new ListNode((l1->val + overflow) % 10);
                overflow = (l1->val + overflow) / 10;
            } else{
                newNode = new ListNode((l1->val + overflow) % 10);
                overflow = 0;
            }

            l3->next = newNode;
            l3 = l3->next;
            l1 = l1->next;

        }
        while(l2){
            if ((l2->val + overflow) > 9){
                newNode = new ListNode((l2->val + overflow) % 10);
                overflow = (l2->val + overflow) / 10;
            } else{
                newNode = new ListNode((l2->val + overflow) % 10);
                overflow = 0;
            }
            l3->next = newNode;
            l3 = l3->next;
            l2 = l2->next;

        }
        if (overflow > 0){
            l3->next = new ListNode(overflow);
        }

        return (temp->next);
    }
};
