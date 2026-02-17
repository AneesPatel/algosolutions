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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* tempcounting = head;
        while(tempcounting){
            count++;
            tempcounting = tempcounting->next;
        }
        ListNode* tempres = new ListNode(0);
        ListNode* res = tempres;
        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* revtemp = nullptr;
        int runningcount = 0;
        ListNode* curgroup = nullptr;

        while(temp){
            if (count < k){
                res->next = temp;
                break;
            }
            curgroup = temp;
            
            while(runningcount < k){
                revtemp = temp->next;
                temp->next = prev;
                prev = temp;
                temp = revtemp;
                runningcount++;
            }

            res->next = prev;
            res = curgroup;

            count -= k;
            runningcount = 0;
            prev = nullptr;
        }
        return tempres->next;

    }
};
