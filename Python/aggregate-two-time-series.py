# Time:  O(n + m)
# Space: O(1)

# two pointers
class Solution(object):
    def aggregateTimeSeries(self, series1, series2):
        """
        :type series1: List[List[int]]
        :type series2: List[List[int]]
        :rtype: List[List[int]]
        """
        result = []
        i = j = 0
        while i != len(series1) or j != len(series2):
            if j == len(series2) or (i != len(series1) and series1[i][0] < series2[j][0]):
                result.append([series1[i][0], series1[i][1]+(series2[j][1] if j != len(series2) else 0)])
                i += 1
            elif i == len(series1) or (j != len(series2) and series2[j][0] < series1[i][0]):
                result.append([series2[j][0], series2[j][1]+(series1[i][1] if i != len(series1) else 0)])
                j += 1
            else:
                result.append([series1[i][0], series1[i][1]+series2[j][1]])
                i += 1
                j += 1
        return result
