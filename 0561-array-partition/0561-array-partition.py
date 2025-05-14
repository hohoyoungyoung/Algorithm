class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # 두개씩 쌍짓고 그 두개의 min 중에서 max값 구하기
        nums.sort()

        ans = 0
        
        i = 0
        j = 1

        while j <= len(nums):
            ans += min(nums[i], nums[j])

            i += 2
            j += 2

        return ans 
