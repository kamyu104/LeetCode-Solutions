# Time:  ctor: O(n * logh)
#        get:  O(logh)
# Space: O(n * logh)

# binary jump solution (frequently used in competitive programming)
# Template:
# https://github.com/kamyu104/FacebookHackerCup-2019/blob/master/Final%20Round/little_boat_on_the_sea.py
class TreeAncestor(object):

    def __init__(self, n, parent):
        """
        :type n: int
        :type parent: List[int]
        """
        par = [[p] if p != -1 else [] for p in parent]
        i, max_depth = 0, 1
        while i < max_depth:
            for p in par:
                if not (i < len(p) and i < len(par[p[i]])):
                    continue
                p.append(par[p[i]][i])
                if len(p) > max_depth:
                    max_depth = len(p)
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
                if not (i < len(par[node])):
                    return -1
                node = par[node][i]
            i += 1
            pow_i_of_2 *= 2
        return node
