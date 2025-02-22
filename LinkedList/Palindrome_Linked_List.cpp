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
        bool isPalindrome(ListNode* head) {
            ListNode *temp = head, *prev = NULL;
            while (temp) {
                ListNode* newNode = new ListNode(temp->val);
                newNode->next = prev;
                prev = newNode;
                if (temp->next == NULL) {
                    temp = newNode;
                    break;
                }
                temp = temp->next;
            }
            while (temp && head) {
                if (temp->val != head->val) {
                    return 0;
                }
                temp = temp->next;
                head = head->next;
            }
            return 1;
        }
    };