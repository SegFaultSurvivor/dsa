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
        ListNode* rotateRight(ListNode* head, int k) {
            ListNode* temp = head;
            vector<int> ans;
            while (temp) {
                ans.push_back(temp->val);
                temp = temp->next;
            }
            vector<int> res(ans.size(), -1);
            for (int i = 0; i < ans.size(); i++) {
                res[(i + k) % ans.size()] = ans[i];
            }
            temp = head;
            for (auto& i : res) {
                temp->val = i;
                temp = temp->next;
            }
            return head;
        }
    };