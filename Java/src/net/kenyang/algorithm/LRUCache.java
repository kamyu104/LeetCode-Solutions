package net.kenyang.algorithm;

import java.util.HashMap;
import java.util.Map;

public class LRUCache {
    int iCapacity;
    int iCurrentSize = 0;
    Map<Integer, Node> map = new HashMap<Integer, Node>();
    int iLastKey = -1;
    int iFirstKey = -1;

    private class Node {
        public int value;
        public int nextKey = -1;
        public int preKey = -1;
    }

    public LRUCache(int capacity) {
        this.iCapacity = capacity;
    }

    /**
     * move to the tail
     * 
     * @param current
     * @param key
     */
    private void updateToNewestNode(Node current, int key) {
        map.get(iLastKey).nextKey = key;
        current.preKey = iLastKey;
        current.nextKey = -1;
        iLastKey = key;
    }

    /**
     * We need to move middleNode to the end, so we need to reconnect the
     * prevNode and nextNode.
     * 
     * @param middleNode
     */
    private void reconnectNode(Node middleNode) {
        Node prev = map.get(middleNode.preKey);
        Node next = map.get(middleNode.nextKey);
        if (prev != null) {
            prev.nextKey = middleNode.nextKey;
        }
        if (next != null) {
            next.preKey = middleNode.preKey;
        }
    }

    public void set(int key, int value) {

        Node current = map.get(key);
        if (current != null) {
            current.value = value;
            if (iFirstKey == key) {
                iFirstKey = current.nextKey;
                updateToNewestNode(current, key);
            } else if (key != iLastKey) {
                reconnectNode(current);
                updateToNewestNode(current, key);
            }
        } else {
            current = new Node();
            current.value = value;
            current.preKey = iLastKey;

            if (iCurrentSize >= iCapacity) {
                int newFirstKey = map.get(iFirstKey).nextKey;
                map.remove(iFirstKey);
                iFirstKey = newFirstKey;
            } else {
                iCurrentSize++;
            }

            if (iLastKey != -1 && iCurrentSize != 1) {
                map.get(iLastKey).nextKey = key;
            }

            iLastKey = key;
        }
        map.put(key, current);

        if (iFirstKey == -1) {
            iFirstKey = key;
        }

    }

    public int get(int key) {
        Node current = map.get(key);
        if (current == null) {
            return -1;
        }

        if (iFirstKey == key && iCurrentSize != 1) {
            iFirstKey = current.nextKey;
            updateToNewestNode(current, key);
        } else if (key != iLastKey) {
            reconnectNode(current);
            updateToNewestNode(current, key);
        }

        return current.value;
    }
}