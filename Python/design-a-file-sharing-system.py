# Time:  ctor:    O(1)
#        join:    O(logu + c), u is the number of total joined users
#        leave:   O(logu + c), c is the number of chunks
#        request: O(u)
# Space: O(u)

import collections
import heapq


# "u ~= n" solution, n is the average number of users who own the chunk
class FileSharing(object):

    def __init__(self, m):
        """
        :type m: int
        """
        self.__users = collections.defaultdict(set) 
        self.__min_heap = []

    def join(self, ownedChunks):
        """
        :type ownedChunks: List[int]
        :rtype: int
        """
        userID = heapq.heappop(self.__min_heap) if self.__min_heap else len(self.__users)+1
        self.__users[userID] = set(ownedChunks)
        return userID

    def leave(self, userID):
        """
        :type userID: int
        :rtype: None
        """
        if userID not in self.__users:
            return
        self.__users[userID] = set()
        heapq.heappush(self.__min_heap, userID)

    def request(self, userID, chunkID):
        """
        :type userID: int
        :type chunkID: int
        :rtype: List[int]
        """
        result = []
        for u, chunks in self.__users.iteritems():
            if chunkID not in chunks:
                continue
            result.append(u)
        if not result:
            return
        self.__users[userID].add(chunkID)
        return result


# Time:  ctor:    O(1)
#        join:    O(logu + c), u is the number of total joined users
#        leave:   O(logu + c), c is the number of chunks
#        request: O(nlogn)   , n is the average number of users who own the chunk
# Space: O(u + m), m is the total number of unique chunks
import collections
import heapq


# "u >> n" solution
class FileSharing2(object):

    def __init__(self, m):
        """
        :type m: int
        """
        self.__users = collections.defaultdict(set) 
        self.__chunks = collections.defaultdict(set)
        self.__min_heap = []

    def join(self, ownedChunks):
        """
        :type ownedChunks: List[int]
        :rtype: int
        """
        userID = heapq.heappop(self.__min_heap) if self.__min_heap else len(self.__users)+1
        self.__users[userID] = set(ownedChunks)
        for c in ownedChunks:
            self.__chunks[c].add(userID)
        return userID

    def leave(self, userID):
        """
        :type userID: int
        :rtype: None
        """
        if userID not in self.__users:
            return
        for c in self.__users[userID]:
            self.__chunks[c].remove(userID)
        self.__users[userID] = set()
        heapq.heappush(self.__min_heap, userID)

    def request(self, userID, chunkID):
        """
        :type userID: int
        :type chunkID: int
        :rtype: List[int]
        """
        result = sorted(self.__chunks[chunkID])
        if not result:
            return
        self.__users[userID].add(chunkID)
        self.__chunks[chunkID].add(userID)
        return result
