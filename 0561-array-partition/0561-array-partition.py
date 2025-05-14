class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # 두개씩 쌍짓고 그 두개의 min 중에서 max값 구하기
        nums.sort()

        ans = 0
        
        for i in range(2, len(nums)+1, 2):
            ans += min(nums[i-2:i])

        return ans 
