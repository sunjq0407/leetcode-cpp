// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return helper(1, n);
    }
    int helper(int start, int end) {
        if (start==end) return start;
        int tmp = start+(end-start)/2;
        if (isBadVersion(tmp)) return helper(start, tmp);
        else return helper(tmp+1, end);
    }
};