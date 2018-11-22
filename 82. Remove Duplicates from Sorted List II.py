
'''
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
Example 1:
Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:
Input: 1->1->1->2->3
Output: 2->3
'''

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution_1:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        dummy = ListNode(0)
        dummy.next = head
        first = head # 打头阵指针，用来指向最新的节点，然后往前进行比较（previously comparison）
        second = dummy # 断后指针，用来指向赋值给temp的节点的previous的节点
        temp = head.val if head is not None else 0 # 上一个暂存值，令temp=node_previous.value，如果后一个node_next的value不等于node_previous的value，则更新，即temp=node_next.value；否则不更新，知道遇到不相等的node_next再更新
        flag = False # 标志位，判断当前是否是有未删除的相等元素的情况

        while (first is not None):
            if first != head: # 从第2个node开始往前比较
                if first.val != temp: # first指向的node的value如果不等于temp
                    if flag == False: # 且同时之前没有node相等的情况
                        second = second.next # second指向下一个node
                    else: # 若之前是有多个节点相等的情况（大于等于2个node的value相等，则要启动删除）
                        second.next = first # 因为second的位置（详见second定义），此语句为删除second和first所指的node中间所有value相等的node
                        flag = False # flag归位
                    temp = first.val # temp更新
                else: # first指向的node的value等于temp
                    flag = True # 出现node的value相等的情况，flag开启为True
            if first.next == None:
                if flag == True:
                    second.next = first.next # 因为second的位置（详见second定义），此语句为删除second和first所指的node中间所有value相等的node
            first = first.next # 每次循环的时候first指针都要往next方向走一个节点
        return dummy.next




# Ref: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/discuss/191507/Python-100-time-solution.-Easy-to-understand.-Two-Pointers-only.
class Solution_2:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        first = head
        second = dummy

        while first:
            is_deleted = False
            while first.next is not None and first.val == first.next.val:
                first.next = first.next.next
                is_deleted = True

            if is_deleted == True:
                second.next = first.next
            else:
                second = first

            first = first.next

        return dummy.next