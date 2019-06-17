# Time:  O(nlogn)
# Space: O(n)

import collections


class Solution(object):
    def largestValsFromLabels(self, values, labels, num_wanted, use_limit):
        """
        :type values: List[int]
        :type labels: List[int]
        :type num_wanted: int
        :type use_limit: int
        :rtype: int
        """
        counts = collections.defaultdict(int)
        val_labs = zip(values,labels)
        val_labs.sort(reverse=True)
        result = 0
        for val, lab in val_labs:
            if counts[lab] >= use_limit:
                continue
            result += val
            counts[lab] += 1
            num_wanted -= 1
            if num_wanted == 0:
                break
        return result
