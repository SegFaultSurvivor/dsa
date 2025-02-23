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
            int carry = 0, sum = 0;
            int len1 = 0, len2 = 0;
            vector<int> ans;
            ListNode *temp1 = l1, *temp2 = l2;
            cout << l1->val << " " << l2->val;
            while (l1 && l2) {
                sum = carry + l1->val + l2->val;
                string res = to_string(sum);
                if (res.size() < 2) {
                    ans.push_back((res[0] - '0'));
                    carry = 0;
                } else {
                    carry = res[0] - '0';
                    ans.push_back(res[1] - '0');
                }
                l1 = l1->next;
                l2 = l2->next;
                len1++;
                len2++;
            }
            while (l1) {
                sum = carry + l1->val;
                string res = to_string(sum);
                if (res.size() < 2) {
                    ans.push_back((res[0] - '0'));
                    carry = 0;
                } else {
                    carry = res[0] - '0';
                    ans.push_back((res[1] - '0'));
                }
                l1 = l1->next;
                len1++;
            }
            while (l2) {
                sum = carry + l2->val;
                string res = to_string(sum);
                if (res.size() < 2) {
                    ans.push_back((res[0] - '0'));
                    carry = 0;
                } else {
                    carry = res[0] - '0';
                    ans.push_back((res[1] - '0'));
                }
                l2 = l2->next;
                len2++;
            }
            if (carry != 0) {
                ans.push_back(carry);
            }
            for (auto& i : ans) {
                cout << i << " ";
            }
            int i = 0;
            ListNode* head = NULL;
            if (len1 >= len2) {
                head = temp1;
                while (temp1) {
                    temp1->val = ans[i++];
                    if (temp1->next == NULL) {
                        break;
                    }
                    temp1 = temp1->next;
                }
                if (ans.size() > len1) {
                    ListNode* newNode = new ListNode(ans[i]);
                    temp1->next = newNode;
                }
            } else {
                head = temp2;
                while (temp2) {
                    temp2->val = ans[i++];
                    if (temp2->next == NULL) {
                        break;
                    }
                    temp2 = temp2->next;
                }
                if (ans.size() > len2) {
                    ListNode* newNode = new ListNode(ans[i]);
                    temp2->next = newNode;
                }
            }
            return head;
        }
    };