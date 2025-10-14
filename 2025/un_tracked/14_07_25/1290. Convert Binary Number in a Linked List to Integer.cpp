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
    int getDecimalValue(ListNode* head) {
        int height = LL_length(head);

        int ans=0;
        LL_to_integer(head,height,ans);
        return ans;
    }

    int LL_length(ListNode*head){
        int height = 0;
        ListNode *temp = head;
        while(temp != nullptr){
            height++;
            temp=temp->next;
        }
        return height;
    }

    void LL_to_integer(ListNode *head,int height,int &ans){
        ListNode* temp = head;
        int power = height - 1;
        while(temp != nullptr){
            if(temp->val == 1){
                ans += pow(2,power);
            }
            power--;
            temp = temp->next;
        }
    }
};