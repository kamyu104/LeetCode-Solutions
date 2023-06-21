# Time:  O(1)
# Space: O(1)

# math
class Solution(object):
    def distanceTraveled(self, mainTank, additionalTank):
        """
        :type mainTank: int
        :type additionalTank: int
        :rtype: int
        """
        USE, REFILL, DIST = 5, 1, 10
        cnt = min((mainTank-REFILL)//(USE-REFILL), additionalTank)
        return (mainTank+cnt*REFILL)*DIST
