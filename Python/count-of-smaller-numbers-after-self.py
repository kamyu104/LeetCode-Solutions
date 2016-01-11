# Time:  O(nlogn)
# Space: O(n)

# You are given an integer array nums and you have to 
# return a new counts array. The counts array has the 
# property where counts[i] is the number of smaller 
# elements to the right of nums[i].
#
# Example:
#
# Given nums = [5, 2, 6, 1]
#
# To the right of 5 there are 2 smaller elements (2 and 1).
# To the right of 2 there is only 1 smaller element (1).
# To the right of 6 there is 1 smaller element (1).
# To the right of 1 there is 0 smaller element.
# Return the array [2, 1, 1, 0].

# Divide and Conquer solution.
class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def countAndMergeSort(sums, start, end, counts):
            if end - start <= 0:  # The size of range [start, end] less than 2 is always with count 0.
                return 0

            mid = start + (end - start) / 2
            countAndMergeSort(num_idxs, start, mid, counts)
            countAndMergeSort(num_idxs, mid + 1, end, counts)
            r = mid + 1
            tmp = []
            for i in xrange(start, mid + 1):
                # Merge the two sorted arrays into tmp.
                while r <= end and num_idxs[r][0] < num_idxs[i][0]:
                    tmp.append(num_idxs[r])
                    r += 1
                tmp.append(num_idxs[i])
                counts[num_idxs[i][1]] += r - (mid + 1)

            # Copy tmp back to num_idxs
            num_idxs[start:start+len(tmp)] = tmp

        num_idxs = []
        counts = [0] * len(nums)
        for i, num in enumerate(nums):
            num_idxs.append((num, i))
        countAndMergeSort(num_idxs, 0, len(num_idxs) - 1, counts)
        return counts

# Time:  O(nlogn)
# Space: O(n)
# BIT solution.
class Solution2(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def binarySearch(A, target, compare):
            start, end = 0, len(A) - 1
            while start <= end:
                mid = start + (end - start) / 2
                if compare(target, A[mid]):
                    end = mid - 1
                else:
                    start = mid + 1
            return start

        class BIT(object):
            def __init__(self, n):
                self.__bit = [0] * n

            def add(self, i, val):
                while i < len(self.__bit):
                    self.__bit[i] += val
                    i += (i & -i)
    
            def query(self, i):
                ret = 0
                while i > 0:
                    ret += self.__bit[i]
                    i -= (i & -i)
                return ret

        # Get the place (position in the ascending order) of each number.
        sorted_nums, places = sorted(nums), [0] * len(nums)
        for i, num in enumerate(nums):
            places[i] = binarySearch(sorted_nums, num, lambda x, y: x <= y)

        # Count the smaller elements after the number.
        ans, bit= [0] * len(nums), BIT(len(nums) + 1)
        for i in reversed(xrange(len(nums))):
            ans[i] = bit.query(places[i])
            bit.add(places[i] + 1, 1)
        return ans

# Time:  O(nlogn)
# Space: O(n)
# BST solution.
class Solution3(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        res = [0] * len(nums)
        bst = self.BST()
        # Insert into BST and get left count.
        for i in reversed(xrange(len(nums))):
            bst.insertNode(nums[i])
            res[i] = bst.query(nums[i])

        return res
    
    class BST(object):
        class BSTreeNode(object):
            def __init__(self, val):
                self.val = val
                self.count = 0
                self.left = self.right = None
    
        def __init__(self):
            self.root = None
    
        # Insert node into BST.
        def insertNode(self, val):
            node = self.BSTreeNode(val)
            if not self.root:
                self.root = node
                return
            curr = self.root
            while curr:
                # Insert left if smaller.
                if node.val < curr.val:
                    curr.count += 1  # Increase the number of left children.
                    if curr.left:
                        curr = curr.left;
                    else:
                        curr.left = node;
                        break
                else:  # Insert right if larger or equal.
                    if curr.right:
                        curr = curr.right
                    else:
                        curr.right = node
                        break
    
        # Query the smaller count of the value.
        def query(self, val):
            count = 0
            curr = self.root
            while curr:
                # Insert left.
                if val < curr.val:
                    curr = curr.left
                elif val > curr.val:
                    count += 1 + curr.count  # Count the number of the smaller nodes.
                    curr = curr.right
                else:  # Equal.
                    return count + curr.count 
            return 0
