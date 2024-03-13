class Solution(object):
    def pivotInteger(self, n):
        """
        :type n: int
        :rtype: int
        """
        left = n * (n + 1) / 2
        right = pivot = n
        while (pivot > 0):
            if left == right:
                return pivot
            left -= pivot
            pivot -= 1
            right += pivot
        return -1
