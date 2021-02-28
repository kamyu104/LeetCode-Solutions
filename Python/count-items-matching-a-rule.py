# Time:  O(n)
# Space: O(1)

class Solution(object):
    def countMatches(self, items, ruleKey, ruleValue):
        """
        :type items: List[List[str]]
        :type ruleKey: str
        :type ruleValue: str
        :rtype: int
        """
        rule = {"type":0, "color":1, "name":2}
        return sum(item[rule[ruleKey]] == ruleValue for item in items)
