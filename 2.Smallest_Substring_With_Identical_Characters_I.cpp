//Smallest Substring With Identical Characters I - leetcode (hard) (14%)
//https://leetcode.com/problems/smallest-substring-with-identical-characters-i/description/
/*
You are given a binary string s of length n and an integer numOps.
You are allowed to perform the following operation on s at most numOps times:
Select any index i (where 0 <= i < n) and flip s[i]. If s[i] == '1', change s[i] to '0' and vice versa.
You need to minimize the length of the longest 
substring of s such that all the characters in the substring are identical.
Return the minimum length after the operations.
*/
class Solution {
public:
    bool pred(int mid, string s, int numOps) {
        if (mid == 1) {//special case for handling if mid is 1
            char cur1 = '0';
            char cur2 = '1';
            string x1;
            string x2;
            int count1 = 0, count2 = 0;
            for (int i = 0; i < s.size(); i++) {
                x1 += s[i] ^ cur1;
                if (cur1 == '0') {
                    cur1 = '1';
                }
                else if (cur1 == '1') {
                    cur1 = '0';
                }
            }
            for (auto i : x1) {
                if (i == 1) count1++;
            }
            for (int i = 0; i < s.size(); i++) {
                x2 += s[i] ^ cur2;
                if (cur2 == '1') {
                    cur2 = '0';
                }
                else if (cur2 == '0') {
                    cur2 = '1';
                }
            }
            for (auto i : x2) {
                if (i == 1) count2++;
            }
            int k = min(count1,count2);
            if (k <= numOps) {
                return true;
            }
            else {
                return false;
            }
        }
        //predicate function for calculating 
        int cnt = 1, val = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                cnt++;
            }
            else {
                val += (cnt / (mid + 1));
                cnt = 1;
            }
        }
        val += (cnt / (mid + 1));
        if (val <= numOps) {
            return true;
        }
        return false;
    }
    int minLength(string s, int numOps) {
        int q;
        int low = 1, high = s.size();
        while(low <= high) {
            int mid = (low + high) / 2;
            bool ans = pred(mid, s, numOps);
            if (ans == true) {
                q = mid;
                high = mid - 1;
            }
            else {
                // if (mid == 1) {
                //     return s.size();
                // }
                low = mid + 1;
            }
        }
        return q;
    }
};
