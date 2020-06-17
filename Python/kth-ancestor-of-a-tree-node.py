# Time:  ctor: O(n * logh)
#        get:  O(logh)
# Space: O(n * logh)

# binary jump solution (frequently seen in contest programming)
# Template:
# https://github.com/kamyu104/FacebookHackerCup-2019/blob/master/Final%20Round/little_boat_on_the_sea.py
class TreeAncestor(object):

    def __init__(self, n, parent):
        """
        :type n: int
        :type parent: List[int]
        """
        par = [[p] for p in parent]
        i, max_depth, changed = 0, 1, True
        while i != max_depth:
            for curr in xrange(len(par)):
                if not (i < len(par[curr]) and par[curr][i] != -1):
                    continue
                par[curr].append(par[par[curr][i]][i]
                                 if i < len(par[par[curr][i]]) 
                                 else -1)
                if len(par[curr]) > max_depth:
                    max_depth = len(par[curr])
            i += 1
        self.__parent = par

    def getKthAncestor(self, node, k):
        """
        :type node: int
        :type k: int
        :rtype: int
        """
        par, i, pow_i_of_2 = self.__parent, 0, 1
        while pow_i_of_2 <= k:
            if k & pow_i_of_2:
                if not (i < len(par[node]) and par[node][i] != -1):
                    return -1
                node = par[node][i]
            i += 1
            pow_i_of_2 *= 2
        return node
