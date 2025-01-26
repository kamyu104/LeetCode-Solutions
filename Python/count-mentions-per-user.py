# Time:  O(eloge + e * n), e = len(events)
# Space: O(e + n)

# simulation
class Solution(object):
    def countMentions(self, numberOfUsers, events):
        """
        :type numberOfUsers: int
        :type events: List[List[str]]
        :rtype: List[int]
        """
        result = [0]*numberOfUsers
        lookup = [1]*numberOfUsers
        events.sort(key=lambda x: (int(x[1]), x[0] == "MESSAGE"))
        for m, t, s in events:                  
            if m == "OFFLINE":
                lookup[int(s)] = int(t)+60
                continue
            if s == "ALL":
                for i in xrange(len(lookup)):
                    result[i] += 1
            elif s == "HERE":
                for i in xrange(len(lookup)):
                    if lookup[i] <= int(t):
                        result[i] += 1
            else:
                for idx in s.split():
                    result[int(idx[2:])] += 1
        return result
