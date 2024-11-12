'''
Descripttion: 
Author: laidui
version: 
Date: 2024-11-11 21:52:48
LastEditors: lai dui
LastEditTime: 2024-11-11 21:53:07
'''
class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        ans = 0
        n = len(nums)
        nums.sort()
        j = 0
        arr = []
        mp = dict()
        heapq.heapify(arr)
        for i in range(n):
            if mp.get(nums[i], -1)==-1:
                heapq.heappush(arr, (-1, nums[i]))
            else:
                mp[nums[i]] += 1
                heapq.heappush(arr, (-mp[nums[i]], nums[i]))
            while nums[i]-2*k>nums[j]:
                mp[nums[j]] = mp.get(nums[j], 0)-1
                if mp[nums[j]]!=0:
                    heapq.heappush(arr, (-mp.get(nums[j], 0), nums[i]))
                j += 1
            while -arr[0][0]!=mp.get(nums[j],0):
                heapq.heappop(arr)
            
        return ans 