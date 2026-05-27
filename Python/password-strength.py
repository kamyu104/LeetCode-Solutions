# Time:  O(n)
# Space: O(1)

# string, hash table
class Solution(object):
    def passwordStrength(self, password):
        """
        :type password: str
        :rtype: int
        """
        return sum(1 if x.islower() else 2 if x.isupper() else 3 if x.isdigit() else 5 for x in set(password))
