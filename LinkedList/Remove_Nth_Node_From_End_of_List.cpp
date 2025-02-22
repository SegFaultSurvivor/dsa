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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            int len = 0;
            ListNode* temp = head;
            while (temp) {
                len++;
                temp = temp->next;
            }
            if (n == len) {
                temp = head;
                head = head->next;
                delete (temp);
                return head;
            }
            int steps = len - n;
            temp = head;
            while (temp && steps - 1) {
                steps--;
                temp = temp->next;
            }
            ListNode* res = temp->next;
            temp->next = temp->next->next;
            delete (res);
            return head;
        }
    };