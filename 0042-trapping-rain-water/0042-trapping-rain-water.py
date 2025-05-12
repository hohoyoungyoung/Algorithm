class Solution(object):
    def trap(self, height):
        if not height:
            return 0

        n = len(height)
        max_left_list = [0] * n
        max_right_list = [0] * n

        max_left_list[0] = height[0]
        for i in range(1, n):
            max_left_list[i] = max(max_left_list[i-1], height[i])

        max_right_list[n-1] = height[n-1]
        for i in range(n-2, -1, -1):
            max_right_list[i] = max(max_right_list[i+1], height[i])

        ans = 0
        for i in range(n):
            water = min(max_left_list[i], max_right_list[i]) - height[i]
            if water > 0:
                ans += water

        return ans
