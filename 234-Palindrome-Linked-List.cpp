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
        stack<int> listStack;
        ListNode* curr=head;
        while(curr!=nullptr){
            listStack.push(curr->val);
            curr=curr->next;

        }
        curr=head;
        while(curr!=nullptr){
            if(listStack.top() != curr->val)
            {
                return false;
            }
            listStack.pop();
            curr=curr->next;
        }
        return true;
    }
};