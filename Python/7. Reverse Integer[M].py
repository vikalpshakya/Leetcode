# Given a signed 32-bit integer x, return x with its digits reversed. 
# If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31- 1], then return 0.

# Time complexity O(1) , Space complexity O(1)

class Solution:
    def reverse(self, x: int) -> int:
        a=str(x)
        if(a[0]=="-"):
            b=a[:0:-1]
            n=int(a[0]+b)
        else:
            b= a[::-1]
            x=int(b)
            n= x
        if(n>2147483648 or n<-2147483648):
            return 0
        else:
            return n
