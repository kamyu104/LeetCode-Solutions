# Time:  O(n + tlogt + flogf)
# Space: O(n)

import collections


class Solution(object):
    def displayTable(self, orders):
        """
        :type orders: List[List[str]]
        :rtype: List[List[str]]
        """
        table_count = collections.defaultdict(collections.Counter)
        for _, table, food in orders:
            table_count[int(table)][food] += 1
        foods = sorted({food for _, _, food in orders})
        result = [["Table"]]
        result[0].extend(foods)
        for table in sorted(table_count):
            result.append([str(table)])
            result[-1].extend(str(table_count[table][food]) for food in foods)
        return result
