# Time:  O(1) per peek(), next(), hasNext()
# Space: O(1)

# Given an Iterator class interface with methods: next() and hasNext(),
# design and implement a PeekingIterator that support the peek() operation --
# it essentially peek() at the element that will be returned by the next call to next().
#
# Here is an example. Assume that the iterator is initialized to the beginning of
# the list: [1, 2, 3].
#
# Call next() gets you 1, the first element in the list.
#
# Now you call peek() and it returns 2, the next element. Calling next() after that
# still return 2.
#
# You call next() the final time and it returns 3, the last element. Calling hasNext()
# after that should return false.
#

# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator(object):
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """

class PeekingIterator(object):
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.iterator = iterator
        self.val_ = None
        self.has_next_ = iterator.hasNext()
        self.has_peeked_ = False
        

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        if not self.has_peeked_:
            self.has_peeked_ = True
            self.val_ = self.iterator.next()
        return self.val_;

    def next(self):
        """
        :rtype: int
        """
        self.val_ = self.peek()
        self.has_peeked_ = False
        self.has_next_ = self.iterator.hasNext()
        return self.val_;

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.has_next_


# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
