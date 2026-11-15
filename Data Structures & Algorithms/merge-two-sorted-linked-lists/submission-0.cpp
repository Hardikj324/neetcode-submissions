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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* node = new ListNode(0);
        ListNode* start = node;
        while(temp1 && temp2){
            if(temp1->val >temp2->val){
                node->next = new ListNode(temp2->val);
                temp2 = temp2->next;
            }
            else {
                node->next = new ListNode(temp1->val);
                temp1 = temp1->next;
            }
            node = node->next;
        }
        if(temp1){
            node->next = temp1;
        }
        if(temp2){
            node->next = temp2;
        }

        return start->next;
    }
};
