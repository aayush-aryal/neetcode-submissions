class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        #intuition is have a window
        #expand the window till profit is increasing
        #if we stumble upon a new low day to buy stock start from there
        #get the max
        l=0
        r=1
        curr_low=prices[0]
        mp=0
        while r<len(prices):
            curr_prof=prices[r]-prices[l]
            mp=max(mp,curr_prof)
            #shift the window based on what you see
            if prices[r]<prices[l]:
                l=r
                r=l
            else:
                r+=1
        
        return mp


        
            
            
            

        