# Time:  ls: O(l + klogk), l is the path length, k is the number of entries in the last level directory
#        mkdir: O(l)
#        addContentToFile: O(l + c), c is the content size
#        readContentFromFile: O(l + c)
# Space: O(n + s), n is the number of dir/file nodes, s is the total content size.

class TrieNode(object):

    def __init__(self):
        self.is_file = False
        self.children = {}
        self.content = ""

class FileSystem(object):

    def __init__(self):
        self.__root = TrieNode()


    def ls(self, path):
        """
        :type path: str
        :rtype: List[str]
        """
        curr = self.__getNode(path)

        if curr.is_file:
            return [self.__split(path, '/')[-1]]

        return sorted(curr.children.keys())


    def mkdir(self, path):
        """
        :type path: str
        :rtype: void
        """
        curr = self.__putNode(path)
        curr.is_file = False


    def addContentToFile(self, filePath, content):
        """
        :type filePath: str
        :type content: str
        :rtype: void
        """
        curr = self.__putNode(filePath)
        curr.is_file = True
        curr.content += content


    def readContentFromFile(self, filePath):
        """
        :type filePath: str
        :rtype: str
        """
        return self.__getNode(filePath).content


    def __getNode(self, path):
        curr = self.__root
        for s in self.__split(path, '/'):
            curr = curr.children[s]
        return curr


    def __putNode(self, path):
        curr = self.__root
        for s in self.__split(path, '/'):
            if s not in curr.children:
                curr.children[s] = TrieNode()
            curr = curr.children[s]
        return curr


    def __split(self, path, delim):
        if path == '/':
            return []
        return path.split('/')[1:]


