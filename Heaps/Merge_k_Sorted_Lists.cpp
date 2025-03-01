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
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<int, vector<int>, greater<int>> pq;
            for (auto& i : lists) {
                ListNode* temp = i;
                while (temp) {
                    pq.push(temp->val);
                    temp = temp->next;
                }
            }
            ListNode* prev = NULL;
            ListNode* head = NULL;
            int flag = 1;
            while (!pq.empty()) {
                for (auto& i : lists) {
                    ListNode* temp = i;
                    if (prev != NULL) {
                        prev->next = temp;
                    }
                    while (temp) {
                        if (flag == 1) {
                            head = temp;
                            flag = 0;
                        }
                        int value = pq.top();
                        temp->val = value;
                        if (temp->next == NULL) {
                            prev = temp;
                        }
                        temp = temp->next;
                        pq.pop();
                    }
                }
            }
            return head;
        }
    };