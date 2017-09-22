# 674. Longest Continuous Increasing Subsequence
# Given an unsorted array of integers, find the length of longest continuous increasing subsequence.

# Example 1:
# Input: [1,3,5,4,7]
# Output: 3
# Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
# Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
# Example 2:
# Input: [2,2,2,2,2]
# Output: 1
# Explanation: The longest continuous increasing subsequence is [2], its length is 1. 
# Note: Length of the array will not exceed 10,000.

class Solution(object):
	def findLengthOfLCIS(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""
		l = len(nums)
		i = 0
		j = 0
		result = 0
		while i < l:
			j = i
			while i + 1 < l and nums[i] < nums[i + 1]:
				i += 1
			i += 1
			if result < i - j:
				result = i - j
		return result