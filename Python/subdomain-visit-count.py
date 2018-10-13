# Time:  O(n), is the length of cpdomains (assuming the length of cpdomains[i] is fixed)
# Space: O(n)

import collections


class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        result = collections.defaultdict(int)
        for domain in cpdomains:
            count, domain = domain.split()
            count = int(count)
            frags = domain.split('.')
            curr = []
            for i in reversed(xrange(len(frags))):
                curr.append(frags[i])
                result[".".join(reversed(curr))] += count

        return ["{} {}".format(count, domain) \
                for domain, count in result.iteritems()]

