// 646. Maximum Length of Pair Chain
// https://leetcode.com/problems/maximum-length-of-pair-chain/

/*
You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.

Example 1:
Input: [[1,2], [2,3], [3,4]]
Output: 2
Explanation: The longest chain is [1,2] -> [3,4]
Note:
The number of given pairs will be in the range [1, 1000].
*/

class Solution {
public:
	int findLongestChain(vector<vector<int>>& pairs) {
		sort(begin(pairs), end(pairs));
		int sz = pairs.size(), result = 0;
		vector<int> A(sz, 0);
		for (int i = sz - 1; i >= 0; --i) {
			if (i + 1 == sz) {
				A[i] = 1;
				result = max(result, 1);
				continue;
			}
			int longest = -1;
			for (int j = i + 1; j < sz ;  ++j) {
				if (pairs[i][1] < pairs[j][0]) {
					if (longest < 0 or A[longest] < A[j]) {
						longest = j;
					}
				}
			}
			if (longest < 0) {
				A[i] = 1;
				result = max(result, 1);
			}
			else {
				A[i] = 1 + A[longest];
				result = max(result, A[i]);
			}
		}
		return result;
	}
};