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
        ListNode* oddEvenList(ListNode* head) {
            if (head == NULL || head->next == NULL) {
                return head;
            }
            ListNode *first = head, *second = head->next, *res = second;
            while (second && second->next) {
                first->next = second->next;
                second->next = second->next->next;
                first = first->next;
                second = second->next;
            }
            first->next = res;
            return head;
        }
    };