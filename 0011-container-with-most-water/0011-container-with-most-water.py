class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        
        # 결국 두 개 고르는거 

        # 두개 고르고 그 중 작은거 높이 * 둘 사이의 거리가 최대 찾기
        # 일단 넓이계산 중간에 무조건 넣어야함

        store = 0 

        i = 0
        j = len(height) - 1

        while i < j:
            
            
            if height[i] <= height[j]:
                store = max(store, (j-i) * (height[i]))
                i += 1

            else:
                store = max(store, (j-i) * (height[j]))
                j -= 1

        return store

