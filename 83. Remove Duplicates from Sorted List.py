
'''
Given a sorted linked list, delete all duplicates such that each element appear only once.
Example 1:
Input: 1->1->2
Output: 1->2
Example 2:
Input: 1->1->2->3->3
Output: 1->2->3
'''

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        first = head # first指针用来打头阵
        second = head # second指针用来断后，即指向first指针指向的节点的前一个（previous）节点（即比first指针的前进慢一步），即head->...->second->first->...->None
        temp = first.val if head is not None else -1 # temp用来暂存数值以完成比较

        while (first != None):
            if first != head: # first指针走过head节点才开始比较判断
                if temp == first.val: # 如果first指向的节点的value等于暂存的上一个节点的value
                    second.next = first.next # 把当前节点抛弃，使上一个节点（second）的next（本来指向当前节点first）指向下一个节点（first的next）
                else: # 如果值不相等
                    temp = first.val # 用当前节点（first）的value更新temp的值
                    second = second.next # 断后指针second往前进一步，即指向当前节点（first）
            first = first.next # first指向下一个节点
        return dummy.next