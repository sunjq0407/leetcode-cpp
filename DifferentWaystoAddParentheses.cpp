class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        bool pureNum=true;
        for (int i=0; i<input.length(); i++) {
            char c = input[i];
            if (!isdigit(c)) {
                pureNum=false;
                vector<int> L=diffWaysToCompute(input.substr(0, i));
                vector<int> R=diffWaysToCompute(input.substr(i+1, input.length()-i-1));
                for (auto l : L) {
                    for (auto r : R) {
                        if (c=='+') ans.push_back(l+r);
                        else if (c=='-') ans.push_back(l-r);
                        else if (c=='*') ans.push_back(l*r);
                    }
                }
            }
        }
        if (pureNum)
            ans.push_back(atoi(input.c_str()));
        return ans;
    }
};