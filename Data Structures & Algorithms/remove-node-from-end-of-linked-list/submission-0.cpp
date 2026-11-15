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
    int size(ListNode* head){
        int n = 0;
        ListNode* temp = head;
        while(temp){
            n++;
            temp = temp->next;
        }
        return n;
    }
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        int n = size(head) - k;
        ListNode* temp = head;
        ListNode* del;

        if(n == 0) {
        del = head;
        head = head->next;
        delete del;
        return head;
        }
        
        int i = 0;
        while(temp){
            if(i==n-1){
                del = temp->next;
                temp->next = temp->next->next;
                delete del;
                break;
            }
            temp = temp->next;
            i++;
        }

        return head;
    }
};
