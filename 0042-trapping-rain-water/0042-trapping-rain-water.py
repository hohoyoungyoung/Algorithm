class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """

        ans = 0 
        
        max_left = 0
        max_right = 0
        max_left_list = [0] * len(height)
        max_right_list = [0] * len(height)

        # max_left_list[i]: i 기준 왼쪽에서 가장 큰 높이 (자기 자신 제외)
        for i in range(1, len(height)):
            max_left = max(max_left, height[i-1])
            max_left_list[i] = max_left

        # max_right_list[i]: i 기준 오른쪽에서 가장 큰 높이 (자기 자신 제외)
        for i in range(len(height)-2, -1, -1):
            max_right = max(max_right, height[i+1])
            max_right_list[i] = max_right

        for i in range(1, len(height)-1):
            min_num = min(max_right_list[i], max_left_list[i])
            if min_num > height[i]:
                ans += min_num - height[i]

        return ans
