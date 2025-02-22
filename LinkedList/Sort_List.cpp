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
        ListNode* sortList(ListNode* head) {
            priority_queue<int, vector<int>, greater<int>> pq;
            ListNode* temp = head;
            while (temp) {
                pq.push(temp->val);
                temp = temp->next;
            }
            ListNode* prev = NULL;
            int flag = 0;
            while (!pq.empty()) {
                int value = pq.top();
                ListNode* res = new ListNode(value);
                if (flag == 0) {
                    head = res;
                    flag = 1;
                }
                if (prev != NULL) {
                    prev->next = res;
                }
                prev = res;
                pq.pop();
            }
            return head;
        }
    };