class Solution(object):
    def trap(self, height):
        ans = 0 
        
        max_left = height[0]
        max_right = height[-1]
        max_left_list = [0] * len(height)
        max_right_list = [0] * len(height)

        for i in range(1, len(height)-1):
            max_left_list[i] = max_left
            max_left = max(max_left, height[i])

        for i in range(len(height)-2, 0, -1):  
            max_right_list[i] = max_right
            max_right = max(max_right, height[i])

        for i in range(1, len(height)-1):
            min_num = min(max_right_list[i], max_left_list[i])
            if min_num > height[i]:
                ans += min_num - height[i]

        return ans