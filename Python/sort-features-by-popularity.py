# Time:  O(nlogn)
# Space: O(n)

import collections


class Solution(object):
    def sortFeatures(self, features, responses):
        """
        :type features: List[str]
        :type responses: List[str]
        :rtype: List[str]
        """
        features_set = set(features)
        order = {word: i for i, word in enumerate(features)}
        freq = collections.defaultdict(int)
        for r in responses:
            for word in set(r.split(' ')):
                if word in features_set:
                    freq[word] += 1
        features.sort(key=lambda x: (-freq[x], order[x]))
        return features
