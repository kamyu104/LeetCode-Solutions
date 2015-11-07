# Time:  O(nlogn)
# Space: O(1)

class Solution(object):
    def minArea(self, image, x, y):
        """
        :type image: List[List[str]]
        :type x: int
        :type y: int
        :rtype: int
        """
        def binarySearch(left, right, find, image, has_one):
            while left <= right:  # O(logn) times
                mid = left + (right - left) / 2
                if find(image, has_one, mid):  # Time: O(n)
                    right = mid - 1
                else:
                    left = mid + 1
            return left


        searchColumns = lambda image, has_one, mid: any([int(row[mid]) for row in image]) == has_one
        left = binarySearch(0, y - 1, searchColumns, image, True)
        right = binarySearch(y + 1, len(image[0]) - 1, searchColumns, image, False)
        
        searchRows = lambda image, has_one, mid: any(itertools.imap(int, image[mid])) == has_one
        top = binarySearch(0, x - 1, searchRows, image, True)
        bottom = binarySearch(x + 1, len(image) - 1, searchRows, image, False)
        return (right - left) * (bottom - top)
