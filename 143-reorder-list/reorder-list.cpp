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
    void reorderList(ListNode* head) {
        ListNode * tmp = head;
        vector<int> list;
        while (tmp != NULL)
        {
            list.push_back(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        int length = list.size();
        int flag = 0;
        for (int i = 0; i < length; i++)
        {
            tmp->val = list[flag * (length - 1) + (i / 2) * (1 - 2 * flag)];
            flag ^= 1;
            tmp = tmp->next;
        }
    }
};