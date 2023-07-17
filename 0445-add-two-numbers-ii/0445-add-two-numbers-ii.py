# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        x, y = 0, 0
        while l1:
            x = x*10 + l1.val
            l1 = l1.next
        while l2:
            y = y*10 + l2.val
            l2 = l2.next
        
        a = list(str(x+y)[::-1])
        cur = ret = ListNode()
        
        while True:
            cur.val = int(a.pop())
            if not a: break
            cur.next = ListNode()
            cur = cur.next
        return ret
        
        
        
        