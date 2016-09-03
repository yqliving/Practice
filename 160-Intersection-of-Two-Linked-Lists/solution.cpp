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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;
        
    if (p1 == NULL || p2 == NULL) return NULL;

    while (p1 != NULL && p2 != NULL && p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;

        //
        // Any time they collide or reach end together without colliding 
        // then return any one of the pointers.
        //
        if (p1 == p2) return p1;

        //
        // If one of them reaches the end earlier then reuse it 
        // by moving it to the beginning of other list.
        // Once both of them go through reassigning, 
        // they will be equidistant from the collision point.
        //
        if (p1 == NULL) p1 = headB;
        if (p2 == NULL) p2 = headA;
    }
        
    return p1;
}
};

/*
解法二:
  链表到尾部后,跳到另一个链表的头部, 相遇点即为intersection points. (相当于前面的部分长度和)
  
 ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝ 
  解法一:
  第一遍循环，找出两个链表的长度差N
  第二遍循环，长链表先走N步，然后同时移动，判断是否有相同节点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode* iter1 = headA;
        ListNode* iter2 = headB;
        int len1 = 1;
        while(iter1->next != NULL)
        {
            iter1 = iter1->next;
            len1 ++;
        }
        int len2 = 1;
        while(iter2->next != NULL)
        {
            iter2 = iter2->next;
            len2 ++;
        }
        if(iter1 != iter2)
            return NULL;
        if(len1 > len2)
        {
            for(int i = 0; i < len1-len2; i ++)
                headA = headA->next;
        }
        else if(len2 > len1)
        {
            for(int i = 0; i < len2-len1; i ++)
                headB = headB->next;
        }
        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};