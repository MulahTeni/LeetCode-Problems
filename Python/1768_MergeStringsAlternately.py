class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        result = ""
        if len(word1) < len(word2):
            for i in range(len(word1)):
                result += word1[i] + word2[i]
            result += word2[len(word1):]
        else:
            for i in range(len(word2)):
                result += word1[i] + word2[i]
            result += word1[len(word2):]
        return result