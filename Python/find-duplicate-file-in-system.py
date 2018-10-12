# Time:  O(n * l), l is the average length of file content
# Space: O(n * l)

import collections


class Solution(object):
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        files = collections.defaultdict(list)
        for path in paths:
           s = path.split(" ")
           for i in xrange(1,len(s)):
               file_name = s[0] + "/" + s[i][0:s[i].find("(")]
               file_content = s[i][s[i].find("(")+1:s[i].find(")")]
               files[file_content].append(file_name)

        result = []
        for file_content, file_names in files.iteritems():
            if len(file_names)>1:
                result.append(file_names)
        return result

