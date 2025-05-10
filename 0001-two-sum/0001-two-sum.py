class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic = {}
        for i, num in enumerate(nums):
            num2 = target - num
            if num2 in dic:
                return [dic[num2], i]
            dic[num] = i
