# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: bool
        """

        current = head

        ans = []

        while current:
            ans.append(current.val)
            current = current.next

        if ans[::-1] == ans:
            return True
        else:
            return False