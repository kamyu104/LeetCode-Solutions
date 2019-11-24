# Time:  O(n)
# Space: O(sqrt(n))

import math


class Solution(object):
    def printLinkedListInReverse(self, head):
        """
        :type head: ImmutableListNode
        :rtype: None
        """
        def print_nodes(head, count):
            nodes = []
            while head and len(nodes) != count:
                nodes.append(head)
                head = head.getNext()
            for node in reversed(nodes):
                node.printValue()
                   
        count = 0
        curr = head
        while curr:
            curr = curr.getNext()
            count += 1
        bucket_count = int(math.ceil(count**0.5))
        
        buckets = []
        count = 0
        curr = head
        while curr:
            if count % bucket_count == 0:
                buckets.append(curr)
            curr = curr.getNext()
            count += 1
        for node in reversed(buckets):
            print_nodes(node, bucket_count)
            
        
# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def printLinkedListInReverse(self, head):
        """
        :type head: ImmutableListNode
        :rtype: None
        """
        nodes = []
        while head:
            nodes.append(head)
            head = head.getNext()
        for node in reversed(nodes):
            node.printValue()


# Time:  O(n^2)
# Space: O(1)
class Solution3(object):
    def printLinkedListInReverse(self, head):
        """
        :type head: ImmutableListNode
        :rtype: None
        """
        tail = None
        while head != tail:
            curr = head
            while curr.getNext() != tail:
                curr = curr.getNext()
            curr.printValue()
            tail = curr
