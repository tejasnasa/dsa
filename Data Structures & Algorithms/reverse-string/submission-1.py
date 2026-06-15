class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        n = len(s)//2
        for i in range(n):
            temp = s[i]
            s[i] = s[len(s)-i-1]
            s[len(s)-i-1] = temp
        