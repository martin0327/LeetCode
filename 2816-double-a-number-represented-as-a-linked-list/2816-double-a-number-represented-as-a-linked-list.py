# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        a = []
        cur = head
        while (cur):
            a.append(cur.val)
            cur = cur.next
        b = []
        a.reverse()
        # print(a)
        cum = 0
        for x in a:
            y = 2*x + cum
            b.append(y%10)            
            cum = y//10
        if (cum > 0): b.append(cum)
        b.reverse()
        a = b
        # s = ''.join(map(str,a))
        # x = 2*int(s)
        # s = str(x)
        cur = head
        for i in range(len(a)):
            cur.val = a[i]
            if (i<len(a)-1): cur.next = ListNode()
            cur = cur.next
        return head
        