# Time:  O(n)
# Space: O(h)

# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []


# one pass solution without recursion
class Solution(object):
    def moveSubTree(self, root, p, q):
        """
        :type root: Node
        :type p: Node
        :type q: Node
        :rtype: Node
        """
        def iter_find_parents(node, parent, p, q, is_ancestor, lookup):
            stk = [(1, [node, None, False])]
            while stk:
                step, params = stk.pop()
                if step == 1:
                    node, parent, is_ancestor = params
                    if node in (p, q):
                        lookup[node] = parent
                        if len(lookup) == 2:
                            return is_ancestor
                    stk.append((2, [node, is_ancestor, reversed(node.children)]))
                else:
                    node, is_ancestor, it = params
                    child = next(it, None)
                    if not child:
                        continue
                    stk.append((2, [node, is_ancestor, it]))
                    stk.append((1, [child, node, is_ancestor or node == p]))
            assert(False)
            return False

        lookup = {}
        is_ancestor = iter_find_parents(root, None, p, q, False, lookup)
        if p in lookup and lookup[p] == q:
            return root
        q.children.append(p)
        if not is_ancestor:
            lookup[p].children.remove(p)
        else:
            lookup[q].children.remove(q)
            if p == root:
                root = q
            else:
                lookup[p].children[lookup[p].children.index(p)] = q
        return root


# Time:  O(n)
# Space: O(h)
# one pass solution with recursion (bad in deep tree)
class Solution_Recu(object):
    def moveSubTree(self, root, p, q):
        """
        :type root: Node
        :type p: Node
        :type q: Node
        :rtype: Node
        """
        def find_parents(node, parent, p, q, is_ancestor, lookup):
            if node in (p, q):
                lookup[node] = parent
                if len(lookup) == 2:
                    return True, is_ancestor
            for child in node.children:
                found, new_is_ancestor = find_parents(child, node, p, q, is_ancestor or node == p, lookup)
                if found:
                    return True, new_is_ancestor
            return False, False

        lookup = {}
        is_ancestor = find_parents(root, None, p, q, False, lookup)[1]
        if p in lookup and lookup[p] == q:
            return root
        q.children.append(p)
        if not is_ancestor:
            lookup[p].children.remove(p)
        else:
            lookup[q].children.remove(q)
            if p == root:
                root = q
            else:
                lookup[p].children[lookup[p].children.index(p)] = q
        return root


# Time:  O(n)
# Space: O(h)
# two pass solution without recursion
class Solution2(object):
    def moveSubTree(self, root, p, q):
        """
        :type root: Node
        :type p: Node
        :type q: Node
        :rtype: Node
        """
        def iter_find_parents(node, parent, p, q, lookup):
            stk = [(1, [node, None])]
            while stk:
                step, params = stk.pop()
                if step == 1:
                    node, parent = params
                    if node in (p, q):
                        lookup[node] = parent
                        if len(lookup) == 2:
                            return
                    stk.append((2, [node, reversed(node.children)]))
                else:
                    node, it = params
                    child = next(it, None)
                    if not child:
                        continue
                    stk.append((2, [node, it]))
                    stk.append((1, [child, node]))

        def iter_is_ancestor(node, q):
            stk = [(1, [node])]
            while stk:
                step, params = stk.pop()
                if step == 1:
                    node = params[0]
                    stk.append((2, [reversed(node.children)]))
                else:
                    it = params[0]
                    child = next(it, None)
                    if not child:
                        continue
                    if child == q:
                        return True
                    stk.append((2, [it]))
                    stk.append((1, [child]))
            return False

        lookup = {}
        iter_find_parents(root, None, p, q, lookup)
        if p in lookup and lookup[p] == q:
            return root
        q.children.append(p)
        if not iter_is_ancestor(p, q):
            lookup[p].children.remove(p)
        else:
            lookup[q].children.remove(q)
            if p == root:
                root = q
            else:
                lookup[p].children[lookup[p].children.index(p)] = q
        return root


# Time:  O(n)
# Space: O(h)
# two pass solution with recursion (bad in deep tree)
class Solution2_Recu(object):
    def moveSubTree(self, root, p, q):
        """
        :type root: Node
        :type p: Node
        :type q: Node
        :rtype: Node
        """
        def find_parents(node, parent, p, q, lookup):
            if node in (p, q):
                lookup[node] = parent
                if len(lookup) == 2:
                    return True
            for child in node.children:
                if find_parents(child, node, p, q, lookup):
                    return True
            return False

        def is_ancestor(node, q):
            for child in node.children:
                if node == q or is_ancestor(child, q):
                    return True
            return False

        lookup = {}
        find_parents(root, None, p, q, lookup)
        if p in lookup and lookup[p] == q:
            return root
        q.children.append(p)
        if not is_ancestor(p, q):
            lookup[p].children.remove(p)
        else:
            lookup[q].children.remove(q)
            if p == root:
                root = q
            else:
                lookup[p].children[lookup[p].children.index(p)] = q
        return root
