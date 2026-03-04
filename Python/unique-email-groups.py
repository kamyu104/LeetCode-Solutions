# Time:  O(n * l)
# Space: O(n * l)

# string, hash table
class Solution(object):
    def uniqueEmailGroups(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        result = set()
        for email in emails:
            email = email.lower()
            local = email[:next(i for i, x in enumerate(email) if x in "+@")].replace('.', '')
            domain = email[next(i for i, x in enumerate(email) if x == '@')+1:]
            result.add(local+'@'+domain)
        return len(result)
