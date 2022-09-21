# Time:  O(nlogn + mlogm)
# Space: O(1)

# greedy, sort
class Solution(object):
    def matchPlayersAndTrainers(self, players, trainers):
        """
        :type players: List[int]
        :type trainers: List[int]
        :rtype: int
        """
        players.sort()
        trainers.sort()
        result = 0
        for x in trainers:
            if players[result] > x:
                continue
            result += 1
            if result == len(players):
                break
        return result
