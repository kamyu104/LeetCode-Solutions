# Time:  set: O((r * c)^2)
#        get: O(1)
#        sum: O((r * c)^2)
# Space: O(r * c)

import collections


class Excel(object):

    def __init__(self, H, W):
        """
        :type H: int
        :type W: str
        """
        self.__exl = [[0 for _ in xrange(ord(W)-ord('A')+1)] \
                      for _ in xrange(H+1)]
        self.__fward = collections.defaultdict(lambda : collections.defaultdict(int))
        self.__bward = collections.defaultdict(set)


    def set(self, r, c, v):
        """
        :type r: int
        :type c: str
        :type v: int
        :rtype: void
        """
        self.__reset_dependency(r, c);
        self.__update_others(r, c, v);


    def get(self, r, c):
        """
        :type r: int
        :type c: str
        :rtype: int
        """
        return self.__exl[r][ord(c) - ord('A')]


    def sum(self, r, c, strs):
        """
        :type r: int
        :type c: str
        :type strs: List[str]
        :rtype: int
        """
        self.__reset_dependency(r, c)
        result = self.__calc_and_update_dependency(r, c, strs)
        self.__update_others(r, c, result)
        return result


    def __reset_dependency(self, r, c):
        key = (r, c)
        if key in self.__bward.keys():
            for k in self.__bward[key]:
                self.__fward[k].pop(key, None)
            self.__bward[key] = set()


    def __calc_and_update_dependency(self, r, c, strs):
        result = 0
        for s in strs:
            s, e = s.split(':')[0], s.split(':')[1] if ':' in s else s
            left, right, top, bottom = ord(s[0])-ord('A'), ord(e[0])-ord('A'), int(s[1:]), int(e[1:])
            for i in xrange(top, bottom+1):
                for j in xrange(left, right+1):
                    result += self.__exl[i][j]
                    self.__fward[(i, chr(ord('A')+j))][(r, c)] += 1
                    self.__bward[(r, c)].add((i, chr(ord('A')+j)))
        return result


    def __update_others(self, r, c, v):
        prev = self.__exl[r][ord(c)-ord('A')]
        self.__exl[r][ord(c)-ord('A')] = v
        q = collections.deque()
        q.append(((r, c), v-prev))
        while q:
            key, diff = q.popleft()
            if key in self.__fward:
                for k, count in self.__fward[key].iteritems():
                    q.append((k, diff*count))
                    self.__exl[k[0]][ord(k[1])-ord('A')] += diff*count


# Your Excel object will be instantiated and called as such:
# obj = Excel(H, W)
# obj.set(r,c,v)
# param_2 = obj.get(r,c)
# param_3 = obj.sum(r,c,strs)
