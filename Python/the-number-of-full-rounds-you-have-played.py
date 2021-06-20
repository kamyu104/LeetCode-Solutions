# Time:  O(1)
# Space: O(1)

class Solution(object):
    def numberOfRounds(self, startTime, finishTime):
        """
        :type startTime: str
        :type finishTime: str
        :rtype: int
        """
        h1, m1 = map(int, startTime.split(":"))
        h2, m2 = map(int, finishTime.split(":"))
        start = h1*60+m1
        finish = h2*60+m2
        if start > finish:
            finish += 1440
        return max(finish//15-(start+15-1)//15, 0)


# Time:  O(1)
# Space: O(1)
class Solution2(object):
    def numberOfRounds(self, startTime, finishTime):
        """
        :type startTime: str
        :type finishTime: str
        :rtype: int
        """
        h1, m1 = map(int, startTime.split(":"))
        h2, m2 = map(int, finishTime.split(":"))
        if m1 > m2:
            h2 -= 1
            m2 += 60
        return max((h2-h1)%24*4 + m2//15 - (m1+15-1)//15, 0)
