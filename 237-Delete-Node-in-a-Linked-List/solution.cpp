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
        void deleteNode(ListNode* node) {
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};
// 一般我们删除一个链表节点，直接将其上一个节点的next指向其下一个节点就可以了，但是这里只给出了该节点本身，也就是说你只能获取到该节点本身以及其下一个节点。那么就只能将该节点直接变成下一个节点了，将其值设为下一个节点的值，将其next指向下一个节点的next，就可以了。