# Time:  ctor: O(n)
#        dot_product: O(min(n, m))
# Space: O(n)

class SparseVector:
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.lookup = {i:v for i, v in enumerate(nums) if v}

    def dotProduct(self, vec):
        """
        :type vec: 'SparseVector'
        :rtype: int
        """
        if len(self.lookup) > len(vec.lookup):
            self, vec = vec, self
        return sum(v*vec.lookup[i] for i, v in self.lookup.iteritems() if i in vec.lookup)
