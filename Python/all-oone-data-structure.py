# Time:  O(1), per operation
# Space: O(k)

# Implement a data structure supporting the following operations:
#
# Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1.
# Key is guaranteed to be a non-empty string.
# Dec(Key) - If Key's value is 1, remove it from the data structure.
# Otherwise decrements an existing key by 1. If the key does not exist,
# this function does nothing. Key is guaranteed to be a non-empty string.
# GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
# GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
# Challenge: Perform all these in O(1) time complexity.

class Node(object):
    """
    double linked list node
    """
    def __init__(self, value, keys):
        self.value = value
        self.keys = keys
        self.prev = None
        self.next = None


class LinkedList(object):
    def __init__(self):
        self.head, self.tail = Node(0, set()), Node(0, set())
        self.head.next, self.tail.prev = self.tail, self.head

    def insert(self, pos, node):
        node.prev, node.next = pos.prev, pos
        pos.prev.next, pos.prev = node, node
        return node

    def erase(self, node):
        node.prev.next, node.next.prev = node.next, node.prev
        del node

    def empty(self):
        return self.head.next is self.tail
    
    def begin(self):
        return self.head.next

    def end(self):
        return self.tail
    
    def front(self):
        return self.head.next
    
    def back(self):
        return self.tail.prev


class AllOne(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.bucket_of_key = {}
        self.buckets = LinkedList()

    def inc(self, key):
        """
        Inserts a new key <Key> with value 1. Or increments an existing key by 1.
        :type key: str
        :rtype: void
        """
        if key not in self.bucket_of_key:
            self.bucket_of_key[key] = self.buckets.insert(self.buckets.begin(), Node(0, set([key])))
            
        bucket, next_bucket = self.bucket_of_key[key], self.bucket_of_key[key].next
        if next_bucket is self.buckets.end() or next_bucket.value > bucket.value+1:
            next_bucket = self.buckets.insert(next_bucket, Node(bucket.value+1, set()))
        next_bucket.keys.add(key)
        self.bucket_of_key[key] = next_bucket

        bucket.keys.remove(key)
        if not bucket.keys:
            self.buckets.erase(bucket)

    def dec(self, key):
        """
        Decrements an existing key by 1. If Key's value is 1, remove it from the data structure.
        :type key: str
        :rtype: void
        """
        if key not in self.bucket_of_key:
            return

        bucket, prev_bucket = self.bucket_of_key[key], self.bucket_of_key[key].prev
        self.bucket_of_key.pop(key, None)
        if bucket.value > 1:
            if bucket is self.buckets.begin() or prev_bucket.value < bucket.value-1:
                prev_bucket = self.buckets.insert(bucket, Node(bucket.value-1, set()))
            prev_bucket.keys.add(key)
            self.bucket_of_key[key] = prev_bucket

        bucket.keys.remove(key)
        if not bucket.keys:
            self.buckets.erase(bucket)

    def getMaxKey(self):
        """
        Returns one of the keys with maximal value.
        :rtype: str
        """
        if self.buckets.empty():
            return ""
        return iter(self.buckets.back().keys).next()

    def getMinKey(self):
        """
        Returns one of the keys with Minimal value.
        :rtype: str
        """
        if self.buckets.empty():
            return ""
        return iter(self.buckets.front().keys).next()
