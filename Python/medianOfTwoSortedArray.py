# Time:  O(log(m + n))
# Space: O(log(m + n))
# 
# There are two sorted arrays A and B of size m and n respectively. 
# Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
#

class Solution:
    # @return a float
    def findMedianSortedArrays(self, A, B):
        lenA, lenB = len(A), len(B)
        if (lenA + lenB) % 2 == 1: 
            return self.getKth(A, 0, B, 0, (lenA + lenB)/2 + 1)
        else:
            return (self.getKth(A, 0, B, 0, (lenA + lenB)/2) + self.getKth(A, 0, B, 0, (lenA + lenB)/2 + 1)) * 0.5
            
    def getKth(self, A, i, B, j, k):
        lenA, lenB = len(A) - i, len(B) - j
        if lenA > lenB:
            return self.getKth(B, j, A, i, k)
        
        if lenA == 0:
            return B[j + k - 1]
        
        if k == 1:
            return min(A[i], B[j])
        
        pa = min(k/2, lenA)
        pb = k - pa
        
        if A[i + pa - 1] < B[j + pb - 1]:
            return self.getKth(A, i + pa, B, j , k - pa)
        elif A[i + pa - 1] > B[j + pb - 1]:
            return self.getKth(A, i, B, j + pb, k - pb)
        else:
            return A[i + pa - 1]

# using list slicing (O(k)) may be slower than solution1
class Solution2:
    # @return a float
    def findMedianSortedArrays(self, A, B):
        lenA, lenB = len(A), len(B)
        if (lenA + lenB) % 2 == 1: 
            return self.getKth(A, B, (lenA + lenB)/2 + 1)
        else:
            return (self.getKth(A, B, (lenA + lenB)/2) + self.getKth(A, B, (lenA + lenB)/2 + 1)) * 0.5
            
    def getKth(self, A, B, k):
        lenA, lenB = len(A), len(B)
        if lenA > lenB:
            return self.getKth(B, A, k)
        
        if lenA == 0:
            return B[k - 1]
        
        if k == 1:
            return min(A[0], B[0])
        
        pa = min(k/2, lenA)
        pb = k - pa
        
        if A[pa - 1] < B[pb - 1]:
            return self.getKth(A[pa:], B, k - pa)
        elif A[pa - 1] > B[pb - 1]:
            return self.getKth(A, B[pb:], k - pb)
        else:
            return A[pa - 1]
    
if __name__ == "__main__":
    print Solution().findMedianSortedArrays([1, 3, 5, 7], [2, 4, 6])
    print Solution().findMedianSortedArrays([1, 3, 5], [2, 4, 6])
    