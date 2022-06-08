# Time:  ctor:        O(1)
#        addText:     O(l)
#        deleteText:  O(k)
#        cursorLeft:  O(k)
#        cursorRight: O(k)
# Space: O(n)

# design, stack
class TextEditor(object):

    def __init__(self):
        self.__LAST_COUNT = 10
        self.__left = []
        self.__right = []

    def addText(self, text):
        """
        :type text: str
        :rtype: None
        """
        for x in text:
            self.__left.append(x)

    def deleteText(self, k):
        """
        :type k: int
        :rtype: int
        """
        cnt = min(k, len(self.__left))
        for _ in xrange(cnt):
            self.__left.pop()
        return cnt

    def cursorLeft(self, k):
        """
        :type k: int
        :rtype: str
        """
        cnt = min(k, len(self.__left))
        for _ in xrange(cnt):
            self.__right.append(self.__left.pop())
        return self.__last_characters()

    def cursorRight(self, k):
        """
        :type k: int
        :rtype: str
        """
        cnt = min(k, len(self.__right))
        for _ in xrange(cnt):
            self.__left.append(self.__right.pop())
        return self.__last_characters()

    def __last_characters(self):
        return "".join(self.__left[-self.__LAST_COUNT:])
