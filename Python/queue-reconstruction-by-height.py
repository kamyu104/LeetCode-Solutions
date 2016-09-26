# Time:  O(n * sqrt(n))
# Space: O(n)

# Suppose you have a random list of people standing in a queue. 
# Each person is described by a pair of integers (h, k), 
# where h is the height of the person and k is the number of people
# in front of this person who have a height greater than or equal to h.
# Write an algorithm to reconstruct the queue.
#
# Note:
# The number of people is less than 1,100.
#
# Example
#
# Input:
# [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
#
# Output:
# [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        people.sort(key=lambda (h, k): (-h, k))

        blocks = [[]]
        for p in people:
            index = p[1]
    
            for i, block in enumerate(blocks):
                if index <= len(block):
                    break
                index -= len(block)
            block.insert(index, p)

            if len(block) * len(block) > len(people):
                blocks.insert(i+1, block[len(block)/2:])
                del block[len(block)/2:]
    
        return [p for block in blocks for p in block]


# Time:  O(n^2)
# Space: O(n)
class Solution2(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        people.sort(key=lambda (h, k): (-h, k))
        result = []
        for p in people:
            result.insert(p[1], p)
        return result
