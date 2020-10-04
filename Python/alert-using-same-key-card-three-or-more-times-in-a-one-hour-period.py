# Time:  O(nlogn)
# Space: O(n)

import collections
import itertools


class Solution(object):
    def alertNames(self, keyName, keyTime):
        """
        :type keyName: List[str]
        :type keyTime: List[str]
        :rtype: List[str]
        """
        THRESHOLD = 3
        name_to_times = collections.defaultdict(list)
        for name, hour_minute in itertools.izip(keyName, keyTime):
            hour, minute = map(int, hour_minute.split(':'))
            name_to_times[name].append(hour*60 + minute)
        names = []    
        for name, times in name_to_times.iteritems():
            times.sort()
            left = 0
            for right, time in enumerate(times):
                while time-times[left] > 60:
                    left += 1
                if right-left+1 >= THRESHOLD:
                    names.append(name)
                    break
        names.sort()
        return names
