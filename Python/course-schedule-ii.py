# Time:  O(|V| + |E|)
# Space: O(|V|)

# There are a total of n courses you have to take, labeled from 0 to n - 1.
# 
# Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
# which is expressed as a pair: [0,1]
# 
# Given the total number of courses and a list of prerequisite pairs, return the ordering of courses 
# you should take to finish all courses.
# 
# There may be multiple correct orders, you just need to return one of them. If it is impossible 
# to finish all courses, return an empty array.
# 
# For example:
# 
# 2, [[1,0]]
# There are a total of 2 courses to take. To take course 1 you should have finished course 0.
# So the correct course order is [0,1]
# 
# 4, [[1,0],[2,0],[3,1],[3,2]]
# There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2.
# Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. 
# Another correct ordering is[0,2,1,3].
# 
# Note:
# The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
# Read more about how a graph is represented.
# 
# Hints:
# This problem is equivalent to finding the topological order in a directed graph. 
# If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
# Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining 
# the basic concepts of Topological Sort.
# Topological sort could also be done via BFS.
# 

class Solution:
    # @param {integer} numCourses
    # @param {integer[][]} prerequisites
    # @return {integer[]}
    def findOrder(self, numCourses, prerequisites):
        res, zero_in_degree_queue, in_degree, out_degree = [], [], {}, {}
        
        for i, j in prerequisites:
            if i not in in_degree:
                in_degree[i] = {}
            if j not in out_degree:
                out_degree[j] = {}
            in_degree[i][j] = True
            out_degree[j][i] = True
        
        for i in xrange(numCourses):
            if i not in in_degree:
                zero_in_degree_queue.append(i)
        
        while zero_in_degree_queue:
            prerequisite = zero_in_degree_queue.pop()
            res.append(prerequisite)
            
            if prerequisite in out_degree:
                for course in out_degree[prerequisite]:
                    del in_degree[course][prerequisite]
                    if not in_degree[course]:
                        zero_in_degree_queue.append(course)
            
                del out_degree[prerequisite]
        
        if len(out_degree):
            return []
        
        return res
