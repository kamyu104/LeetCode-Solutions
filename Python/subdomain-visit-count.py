# Time:  O(n), is the length of cpdomains (assuming the length of cpdomains[i] is fixed)
# Space: O(n)

from collections import defaultdict

try:
    xrange          # Python 2
except NameError:
    xrange = range  # Python 3

try:
    defaultdict.iteritems
except AttributeError:
    # Python 3
    def iteritems(d):
        return iter(d.items())
else:
    # Python 2
    def iteritems(d):
        return d.iteritems()

class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        result = defaultdict(int)
        for domain in cpdomains:
            count, domain = domain.split()
            count = int(count)
            frags = domain.split('.')
            curr = []
            for i in reversed(xrange(len(frags))):
                curr.append(frags[i])
                result[".".join(reversed(curr))] += count

        return ["{} {}".format(count, domain) for domain, count in iteritems(result)]

