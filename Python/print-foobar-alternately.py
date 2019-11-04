# Time:  O(n)
# Space: O(1)

import threading


class FooBar(object):
    def __init__(self, n):
        self.__n = n
        self.__curr = False
        self.__cv = threading.Condition()

    def foo(self, printFoo):
        """
        :type printFoo: method
        :rtype: void
        """
        for i in xrange(self.__n):
            with self.__cv:
                while self.__curr != False:
                    self.__cv.wait()
                self.__curr = not self.__curr
                # printFoo() outputs "foo". Do not change or remove this line.
                printFoo()
                self.__cv.notify()

    def bar(self, printBar):
        """
        :type printBar: method
        :rtype: void
        """
        for i in xrange(self.__n):
            with self.__cv:
                while self.__curr != True:
                        self.__cv.wait()
                self.__curr = not self.__curr
                # printBar() outputs "bar". Do not change or remove this line.
                printBar()
                self.__cv.notify()
