//852. Peak Index in a Mountain Array - leetcode (medium) (acc : 67%)
//https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
/*
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
Return the index of the peak element.
Your task is to solve it in O(log(n)) time complexity.
*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                ans = mid;
                break;
            }
            else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) left = mid;
            else right = mid;
        }
        return ans;
    }
};
