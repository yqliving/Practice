/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    if (head == NULL)   return true;
    
    // find the list center
    ListNode* slow = head,* fast = head;
    while (  fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    // reverse the second half of the list (slow.next is the beginning)
    fast = slow->next;
    while (fast != NULL && fast->next != NULL) {
        ListNode* nd = fast->next->next;
        fast->next->next = slow->next;
        slow->next = fast->next;
        fast->next = nd;
    }

    // compare two list (start from head and slow.next)
    while (slow->next != NULL) {
        slow = slow->next;
        if (head->val != slow->val)   return false;
        head = head->next;
    }
    return true;
}
}; 
/* Time ~ O(N), Space ~ O(1)
Since it requires constant space, we can't use Hashtable.
Approach:
1) Find the middle of the Linked List using two pointers:
If it contains odd number of nodes, slow stops at the the middle node between the first and second half;
If it contains even number of nodes, slow stops at the end of the first half.
2) Reverse the second half of the Linked List (see Reverse Linked List I)
After it's reverted, the slow.next should still points to the beginning of the reverted second half.
3) Compare the two half if they're the same.
If so we have a palindrome Linked List, otherwise, we don't.


/*1）比较朴素的算法。 
　　申请一个辅助栈结构来存储链表的内容，第一次遍历将链表节点值依次入栈，第二次遍历比较判断是否为回文。
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        stack<int> st;
    ListNode *tmp = head;
        while(tmp)
        {
            st.push(tmp->val);
            tmp = tmp->next;
        }

    while(head)
    {
        if(head->val != st.top() ) return false;
        head = head->next;
        st.pop();
    }
        return true;
    }
}; 

//可以想到递归的过程本身就是出入栈的过程，我们可以先递归访问单链表，然后做比较。这样就省去了辅助空间，从而将空间复杂度降为O(1)
/*
class Solution {
private:
    ListNode *lst;
public:
    bool judge(ListNode *head)
    {
        if(head == NULL) return true;

        if(judge(head->next) == false) return false;

        if(lst->val != head->val) return false;
        else{
            lst = lst->next;
            return true;
        }
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        lst = head;

        return judge(head);
    }
};
