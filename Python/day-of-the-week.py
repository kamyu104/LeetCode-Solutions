# Time:  O(1)
# Space: O(1)

class Solution(object):
    def dayOfTheWeek(self, day, month, year):
        """
        :type day: int
        :type month: int
        :type year: int
        :rtype: str
        """
        DAYS = ["Sunday", "Monday", "Tuesday", "Wednesday", \
                "Thursday", "Friday", "Saturday"]

        # Zeller Formula
        if month < 3:
            month += 12
            year -= 1
        c, y = divmod(year, 100)
        w = (c//4 - 2*c + y + y//4 + 13*(month+1)//5 + day - 1) % 7
        return DAYS[w]
