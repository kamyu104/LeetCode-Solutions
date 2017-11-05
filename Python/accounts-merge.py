# Time:  O(nlogn), n is the number of total emails, and the max length of email is 320, p.s. {64}@{255}
# Space: O(n)

# Given a list accounts, each element accounts[i] is a list of strings,
# where the first element accounts[i][0] is a name,
# and the rest of the elements are emails representing emails of the account.
#
# Now, we would like to merge these accounts.
# Two accounts definitely belong to the same person if there is some email that is common to both accounts.
# Note that even if two accounts have the same name,
# they may belong to different people as people could have the same name.
# A person can have any number of accounts initially, but all of their accounts definitely have the same name.
#
# After merging the accounts, return the accounts in the following format:
# the first element of each account is the name, and the rest of the elements are emails in sorted order.
# The accounts themselves can be returned in any order.
#
# Example 1:
# Input: 
# accounts = [["John", "johnsmith@mail.com", "john00@mail.com"],
#             ["John", "johnnybravo@mail.com"],
#             ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
#             ["Mary", "mary@mail.com"]]
# Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],
#          ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
#
# Explanation: 
# The first and third John's are the same person as they have the common email "johnsmith@mail.com".
# The second John and Mary are different people as none of their email addresses are used by other accounts.
# We could return these lists in any order,
# for example the answer [['Mary', 'mary@mail.com'],
#                         ['John', 'johnnybravo@mail.com'], 
#                         ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']]
# would still be accepted.
#
# Note:
#
# The length of accounts will be in the range [1, 1000].
# The length of accounts[i] will be in the range [1, 10].
# The length of accounts[i][j] will be in the range [1, 30].

class UnionFind(object):
    def __init__(self):
        self.set = []

    def get_id(self):
        self.set.append(len(self.set))
        return len(self.set)-1
        
    def find_set(self, x):
        if self.set[x] != x:
            self.set[x] = self.find_set(self.set[x])  # path compression.
        return self.set[x]

    def union_set(self, x, y):
        x_root, y_root = map(self.find_set, (x, y))
        if x_root != y_root:
            self.set[min(x_root, y_root)] = max(x_root, y_root)


class Solution(object):
    def accountsMerge(self, accounts):
        """
        :type accounts: List[List[str]]
        :rtype: List[List[str]]
        """
        union_find = UnionFind()
        email_to_name = {}
        email_to_id = {}
        for account in accounts:
            name = account[0]
            for i in xrange(1, len(account)):
                email_to_name[account[i]] = name
                if account[i] not in email_to_id:
                    email_to_id[account[i]] = union_find.get_id()
                union_find.union_set(email_to_id[account[1]], email_to_id[account[i]])

        result = collections.defaultdict(list)
        for email in email_to_name.keys():
            result[union_find.find_set(email_to_id[email])].append(email)
        for emails in result.values():
            emails.sort()
        return [[email_to_name[emails[0]]] + emails for emails in result.values()]
