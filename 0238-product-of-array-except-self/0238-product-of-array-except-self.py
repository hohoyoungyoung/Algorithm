class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        ans = []
        output = [1]
        

        for i in range(len(nums)-1):
            output.append(output[-1] * nums[i])

        p = 1

        for i in range(len(nums) - 1, -1, -1):
            ans.append(p * (output.pop()))
            p *= nums[i]

        return ans[::-1]

        





        
        return ans

        