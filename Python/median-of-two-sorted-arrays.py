# Time:  O(log(m + n))
# Space: O(1)
# 
# There are two sorted arrays A and B of size m and n respectively. 
# Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
#

class Solution:
    # @return a float
    def findMedianSortedArrays(self, A, B):
        lenA, lenB = len(A), len(B)
        if (lenA + lenB) % 2 == 1: 
            return self.getKth(A, B, (lenA + lenB)/2 + 1)
        else:
            return (self.getKth(A, B, (lenA + lenB)/2) + self.getKth(A, B, (lenA + lenB)/2 + 1)) * 0.5
            
    def getKth(self, A, B, k):
        m, n = len(A), len(B)
        if m > n:
            return self.getKth(B, A, k)
            
        left, right = 0, m    
        while left < right:
            mid = left + (right - left) / 2
            j = k - 1 - mid
            if 0 <= j and j < n and A[mid] >= B[j]:
                right = mid
            else:
                left = mid + 1
            
        Ai_minus_1, Bj = float("-inf"), float("-inf")
        if left - 1 >= 0:
            Ai_minus_1 = A[left - 1]
        if k - 1 - left >= 0:
            Bj = B[k - 1 - left]
        
        return max(Ai_minus_1, Bj)
            
# Time:  O(log(m + n))
# Space: O(1)
class Solution2:
    # @return a float
    def findMedianSortedArrays(self, A, B):
        lenA, lenB = len(A), len(B)
        if (lenA + lenB) % 2 == 1: 
            return self.getKth(A, B, (lenA + lenB)/2 + 1)
        else:
            return (self.getKth(A, B, (lenA + lenB)/2) + self.getKth(A, B, (lenA + lenB)/2 + 1)) * 0.5
            
    def getKth(self, A, B, k):
        b = max(0, k - len(B))
        t = min(len(A), k)
        while b < t:
            x = b + (t - b) / 2
            A_x_1, A_x, B_k_x_1, B_k_x = float("-inf"), float("inf"), float("-inf"), float("inf")
            if x > 0:
                A_x_1 = A[x - 1]
            if x < len(A):
                A_x = A[x]
            if k - x > 0:
                B_k_x_1 = B[k - x - 1]
            if k - x < len(B):
                B_k_x = B[k - x]
            
            if A_x < B_k_x_1:
                b = x + 1
            elif A_x_1 > B_k_x:
                t = x - 1
            else:
                return max(A_x_1, B_k_x_1)
        
        A_b_1, B_k_b_1 = float("-inf"), float("-inf")
        if b > 0:
            A_b_1 = A[b - 1]
        if k - b - 1 >= 0:
            B_k_b_1 = B[k - b - 1]
            
        return max(A_b_1, B_k_b_1)

# Time:  O(log(m + n))
# Space: O(log(m + n))
class Solution3:
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

# using list slicing (O(k)) may be slower than Solution3
class Solution4:
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
    
