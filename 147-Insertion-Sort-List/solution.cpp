/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*Well, life gets difficult pretty soon whenever the same operation on array is transferred to linked list.

First, a quick recap of insertion sort:

Start from the second element (simply a[1] in array and the annoying head -> next -> val in linked list), each time when we see a node with val smaller than its previous node, we scan from the head and find the position that the current node should be inserted. Since a node may be inserted before head, we create a new_head that points to head. The insertion operation, however, is a little easier for linked list.

Now comes the code:*/
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *sortedHead = new ListNode(-1);
        while(head != NULL)
        {
            //保存head位置
            ListNode *temp = head->next;
            ListNode *cur = sortedHead;
            while(cur->next != NULL && cur->next->val < head->val)
            {
                cur = cur->next;
            }
            //插入
            head->next = cur->next;
            cur->next = head;
            //恢复head
            head = temp;
        }
        return sortedHead->next;
    }
};

/*
class Solution { 
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;
        while (cur) {
            if (cur -> next && cur -> next -> val < cur -> val) {
                while (pre -> next && pre -> next -> val < cur -> next -> val)
                    pre = pre -> next;
                /* Insert cur -> next after pre.*/
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                /* Move pre back to new_head. */
                pre = new_head;
            }
            else cur = cur -> next;
        }
        ListNode* res = new_head -> next;
        delete new_head;
        return res;
    }
};
 /*
 class Solution{
     public:
 
ListNode* insertionSortList(ListNode* head) {
    return helper(head,nullptr);
}

ListNode* helper(ListNode* head,ListNode*end){
    if(head==end  || head->next == end){
        head ?head->next = nullptr:head;
        return head;
    }
    ListNode* slow  = head;
    ListNode* fast  = head;
    while(fast!=end && fast->next!=end){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* left = helper(head,slow);
    ListNode* right = helper(slow,end);
    return merge(left,right);
}

ListNode* merge(ListNode* left,ListNode* right){
    ListNode* head;
    if(left->val > right->val){
        head = right;
        right = right->next;
    }else{
        head = left;
        left = left->next;
    }
    ListNode* tail = head;
    while(right && left){
        if(left->val > right->val){
            tail -> next = right;
            right = right->next;
        }else{
            tail -> next = left;
            left = left->next;
        }
        tail = tail->next;
        tail->next = nullptr;
    }
    right? tail->next = right:tail->next = left;
    return head;
}
};