class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)

a=Solution()    
haystack = "hello"
needle = "ll"
print(a.strStr(haystack,needle))