# Time:  O(m * nlogn + l * t), m is the max number of folders in a path,
#                            , n is the number of paths
#                            , l is the max length of folder name
#                            , t is the size of trie
# Space: O(l * t)

import collections


class Solution(object):
    def deleteDuplicateFolder(self, paths):
        """
        :type paths: List[List[str]]
        :rtype: List[List[str]]
        """
        def mark(node, lookup, ids):
            node_id = ids[tuple("%s %s" % (subfolder, mark(child, lookup, ids)) for subfolder, child in sorted(node.iteritems()) if child != "_del")]
            if node_id != 0:
                if node_id in lookup:
                    lookup[node_id]["_del"]
                    node["_del"]
                else:
                    lookup[node_id] = node
            return node_id

        trees = collections.defaultdict(list)
        lookup = collections.defaultdict()
        lookup.default_factory = lookup.__len__
        
        def sweep(node, path, result):
            if path:
                result.append(path[:])
            for subfolder, child in node.iteritems():
                if "_del" in child:
                    continue
                path.append(subfolder)
                sweep(child, path, result)
                path.pop()

        _trie = lambda: collections.defaultdict(_trie)
        trie = _trie()
        for path in paths:
            reduce(dict.__getitem__, path, trie)
        lookup, result = {}, []
        ids = collections.defaultdict()
        ids.default_factory = ids.__len__
        mark(trie, lookup, ids)
        sweep(trie, [], result)
        return result


# Time:  O(m * nlogn + l * t^2), m is the max number of folders in a path,
#                              , n is the number of paths
#                              , l is the max length of folder name
#                              , t is the size of trie
# Space: O(l * t^2)
import collections


class Solution2(object):
    def deleteDuplicateFolder(self, paths):
        """
        :type paths: List[List[str]]
        :rtype: List[List[str]]
        """
        def mark(node, lookup):
            serialized_tree = "(" + "".join(subfolder + mark(child, lookup) for subfolder, child in sorted(node.iteritems()) if child != "_del") + ")"
            if serialized_tree != "()":
                if serialized_tree in lookup:
                    lookup[serialized_tree]["_del"]
                    node["_del"]
                else:
                    lookup[serialized_tree] = node
            return serialized_tree
        
        def sweep(node, path, result):
            if path:
                result.append(path[:])
            for subfolder, child in node.iteritems():
                if "_del" in child:
                    continue
                path.append(subfolder)
                sweep(child, path, result)
                path.pop()

        _trie = lambda: collections.defaultdict(_trie)
        trie = _trie()
        for path in paths:
            reduce(dict.__getitem__, path, trie)
        lookup, result = {}, []
        mark(trie, lookup)
        sweep(trie, [], result)
        return result
