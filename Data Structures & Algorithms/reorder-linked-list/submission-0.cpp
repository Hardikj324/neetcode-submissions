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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;
        ListNode* prevnode = nullptr;
        while(temp!=nullptr){
            ListNode* newnode = temp->next;
            temp->next = prevnode;
            prevnode = temp;
            temp = newnode;
        }
        head = prevnode;

        return head;
    }

    void reorderList(ListNode* head) {   
        if(head==nullptr || head->next ==nullptr) return ;

        
        ListNode* temp = head;
        
        ListNode* slow = head;
        ListNode* fast= head;

        while(fast->next->next && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* second = reverseList(slow->next);

        slow->next = nullptr;

        ListNode* first = head;

        while(second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            second = temp2;
            first = temp1;
        }

        
    }
};
