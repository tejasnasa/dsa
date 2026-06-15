class Solution:
    def isPalindrome(self, s: str) -> bool:

        t = ""

        for c in s.lower():
            if c.isalnum():
                t += c
        
        return t == t[::-1]
        