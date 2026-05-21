class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        #keep a max heap and pop the kth largest element
        heap=[]
        for num in nums:
            if len(heap)<k:
                heapq.heappush(heap,num)
            else:
                heapq.heappush(heap,num)
                heapq.heappop(heap)
        return heap[0]
        

        