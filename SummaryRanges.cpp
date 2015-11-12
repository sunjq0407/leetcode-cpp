class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size()==0) return result;
        int prev = 0, start = 0;
        bool loop = false;
        string s;
        for(int i:nums) {
            if(!loop) {
                start = i;
                prev = i;
                loop = true;
            }
            else {
                if(i==prev+1) {
                    prev++;
                    continue;
                }
                else {
                    s = to_string(prev);
                    if(start!=prev) s = to_string(start) + "->" + s;
                    result.push_back(s);
                    start = i;
                    prev = i;
                }
            }
        }
        if(loop) {
            s = to_string(prev);
            if(start!=prev) s = to_string(start) + "->" + s;
            result.push_back(s);
        }
        return result;
    }
};