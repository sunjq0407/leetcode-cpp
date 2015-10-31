class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size()==1) return citations[0] ? 1 : 0;
        vector<int> copy = citations;
        sort(copy.begin(), copy.end());
        int h = 0;
        for (int i=0; i<copy.size(); i++) {
            if (copy[i]>=copy.size()-i) {
                h = copy.size() - i;
                break;
            }
        }
        return h;
    }
};