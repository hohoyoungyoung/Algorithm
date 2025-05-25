class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        profit = 0
        min_num = float('inf')

        for price in prices:
            if price < min_num:
                min_num = price

            if profit < (price-min_num):
                profit = (price-min_num)

        
        return profit
