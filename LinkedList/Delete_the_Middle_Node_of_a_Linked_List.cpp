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
        ListNode* deleteMiddle(ListNode* head) {
            if (head == NULL || head->next == NULL) {
                return NULL;
            }
            if (head->next->next == NULL) {
                ListNode* temp = head->next;
                head->next = NULL;
                delete (temp);
                return head;
            }
            int len = 0;
            ListNode* temp = head;
            while (temp) {
                len++;
                temp = temp->next;
            }
            int steps = len / 2;
            temp = head;
            while (temp && steps) {
                steps--;
                temp = temp->next;
            }
            ListNode* res = temp->next;
            temp->val = temp->next->val;
            temp->next = temp->next->next;
            delete (res);
            return head;
        }
    };