//3065. Minimum Operations to Exceed Threshold Value I - leetcode (easy) (acc : 86%)
//https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/description/
/*
You are given a 0-indexed integer array nums, and an integer k.
In one operation, you can remove one occurrence of the smallest element of nums.
Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int n = nums.size();
        int right = n - 1;
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= k) {
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};
