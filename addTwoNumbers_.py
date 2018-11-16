'''
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
'''

# Ref: https://github.com/caoyuan0816/LeetCode-Python/blob/master/2.add-two-numbers.python3.py

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        root = ListNode(-1) # 链表头节点
        head = root # 保存链表的头结点，因为对一个链表而言，只要知道头结点，就可以通过next访问到所有元素

        while not (l1 is None and l2 is None):
            temp = carry
            if l1 is not None:
                temp += l1.val
                l1 = l1.next
            if l2 is not None:
                temp += l2.val
                l2 = l2.next
            digit = temp % 10
            carry = 1 if temp >= 10 else 0
            head.next = ListNode(digit) # 赋值给当前节点下一个节点，如果是第一次就是赋值给链表头节点-1的下一个节点
            head = head.next # 赋值完成后把下一个节点赋值为当前节点

        if carry == 1: # 循环完成后还有进位
            head.next = ListNode(1) # 把进位值1赋值给下一个节点
        return root.next # 返回链表头节点的下一个节点，即第一个有具体指的节点