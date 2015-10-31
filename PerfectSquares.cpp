class Solution {
public:
    int numSquares(int n) {
        int min = INT_MAX;
        if (pow((int)sqrt(n),2) == n) return 1;
        set<int> squares;
        for (int i=1; i*i<n; i++) squares.insert(i*i);
        return helper(squares, n, 1, min);
    };
    int helper(const set<int> & squares, int n, int deep, int min) {
        if(deep>=min) return min;
        else if(squares.count(n)) return 1;
        else {
            for(int i : squares) {
                int tmp = 1+helper(squares, n-i, deep+1, min);
                if(tmp<min) min = tmp;
            }
            return min;
        }
    }
};