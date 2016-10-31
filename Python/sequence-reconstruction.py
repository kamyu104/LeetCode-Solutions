# Time:  O(|V| + |E|)
# Space: O(|E|)

class Solution(object):
    def sequenceReconstruction(self, org, seqs):
        """
        :type org: List[int]
        :type seqs: List[List[int]]
        :rtype: bool
        """
        graph = collections.defaultdict(set)
        indegree = collections.defaultdict(int)
        integer_set = set()
        for seq in seqs:
            for i in seq:
                integer_set.add(i)
            if len(seq) == 1:
                if seq[0] not in indegree:
                    indegree[seq[0]] = 0
                continue
            for i in xrange(len(seq)-1):
                if seq[i] not in indegree:
                    indegree[seq[i]] = 0
                if seq[i+1] not in graph[seq[i]]:
                    graph[seq[i]].add(seq[i+1])
                    indegree[seq[i+1]] += 1

        cnt_of_zero_indegree = 0
        res, q = [], []
        for i in indegree:
            if indegree[i] == 0:
                cnt_of_zero_indegree += 1
                if cnt_of_zero_indegree > 1:
                    return False
                q.append(i)

        while q:
            i = q.pop()
            res.append(i)
            cnt_of_zero_indegree = 0
            for j in graph[i]:
                indegree[j] -= 1
                if indegree[j] == 0:
                    cnt_of_zero_indegree += 1
                    if cnt_of_zero_indegree > 1:
                        return False
                    q.append(j)

        return res == org and set(org) == integer_set
