'''
Given a linked list, remove the n-th node from the end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Follow up:
Could you do this in one pass?
'''

'''
Thought:
D->1->2->3->4->5->null
D->1->2->3->     5->null
'''

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution_1:
    # Approach 1: Two pass algorithm
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head # "dummy" node is used to simplify some corner cases: only one node in a list; removing the head of the list.
        first = head
        length = 0

        while first != None: # The 1st loop: count the length of the linked list
            length += 1
            first = first.next
        length = length - n # 链表的长度 - n = 要删除的节点前（不包括要删除的节点）的节点个数（E.g. 5 - 2 = 3）
        first = dummy
        while length > 0: # The 2nd pass: Move the pointer to the node right before the node to be deleted.
            length -= 1
            first = first.next
        first.next = first.next.next # Making the pointer of the node right before the node (to be deleted) pointing to the node next to the node (to be deleted).

        return dummy.next # Return to the head node.

class Solution_2:
    # Approach 2: One pass algorithm
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """

        dummy = ListNode(0)
        dummy.next = head
        first = dummy
        second = dummy
        step = 0

        while first != None:
            first = first.next
            step += 1
            if step > n + 1:
                second = second.next
        second.next = second.next.next

        return dummy.next