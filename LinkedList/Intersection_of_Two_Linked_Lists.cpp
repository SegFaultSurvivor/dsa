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
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
            int len1 = 0, len2 = 0;
            ListNode* temp = headA;
            while (temp) {
                len1++;
                temp = temp->next;
            }
            temp = headB;
            while (temp) {
                len2++;
                temp = temp->next;
            }
            int diff = abs(len1 - len2);
            if (len1 < len2) {
                temp = headB;
                while (diff) {
                    diff--;
                    temp = temp->next;
                }
                while (headA && temp) {
                    if (headA == temp) {
                        return headA;
                    }
                    headA = headA->next;
                    temp = temp->next;
                }
                return NULL;
            } else {
                temp = headA;
                while (diff) {
                    diff--;
                    temp = temp->next;
                }
                while (headB && temp) {
                    if (headB == temp) {
                        return headB;
                    }
                    headB = headB->next;
                    temp = temp->next;
                }
                return NULL;
            }
        }
    };