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
        def binarySearch(image, left, right, find, has_one):
            while left <= right:  # O(logn) times
                mid = left + (right - left) / 2
                if find(mid, image, has_one):  # Time: O(n)
                    right = mid - 1
                else:
                    left = mid + 1
            return left


        searchColumns = lambda mid, image, has_one: any([int(row[mid]) for row in image]) == has_one
        left = binarySearch(image, 0, y - 1, searchColumns, True)
        right = binarySearch(image, y + 1, len(image[0]) - 1, searchColumns, False)
        
        searchRows = lambda mid, image, has_one: any(itertools.imap(int, image[mid])) == has_one
        top = binarySearch(image, 0, x - 1, searchRows, True)
        bottom = binarySearch(image, x + 1, len(image) - 1, searchRows, False)
        return (right - left) * (bottom - top)
