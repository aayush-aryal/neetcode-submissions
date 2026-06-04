class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        l=0
        r=len(matrix)-1

        while l <= r:
            mid = (l + r) // 2
            if target < matrix[mid][0]:
                r = mid - 1
            elif target > matrix[mid][-1]:
                l = mid + 1
            else:
                l_=0
                r_=len(matrix[mid])-1
                while l_<=r_:
                    mid_=(l_+r_)//2
                    if target>matrix[mid][mid_]:
                        l_=mid_+1
                    elif target<matrix[mid][mid_]:
                        r_=mid_-1
                    else:
                        return True 
                return False
        return False        