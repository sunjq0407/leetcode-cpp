class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = -1, maxlen = 0;
        map<char, int> mymap;
        for (int i=0; i<s.length(); i++){
            if (mymap.count(s[i])!=0) {
                start = max(start, mymap[s[i]]);
            }
            mymap[s[i]] = i;
            maxlen = max(maxlen, i-start);
        }
        return maxlen;
    }
};