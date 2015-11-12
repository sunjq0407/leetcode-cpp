class Solution {
public:
    int calculate(string s) {
        int it = 0;
        return helper1(s,it);
    }
    int helper1(string &s, int &it) {
        int tmp=0, cur=0;
        char cal = NULL;
        for(;it<s.length();it++) {
            if(s[it]==' ') continue;
            else if (isdigit(s[it])) tmp=tmp*10+s[it]-'0';
            else if (s[it]=='+'||s[it]=='-') {
                if(cal=='+') cur += tmp;
                else if(cal=='-') cur -= tmp;
                else cur = tmp;
                tmp = 0;
                cal = s[it];
            }
            else if (s[it]=='*'||s[it]=='/') {
                tmp = helper2(s, it, tmp);
                it--;
            }
        }
        if(cal=='+') cur += tmp;
        else if(cal=='-') cur -= tmp;
        else cur = tmp;
        return cur;
    }
    int helper2(string &s, int &it, int prev) {
        int tmp = 0, cur = prev;
        char cal = NULL;
        for(;it<s.length();it++) {
            if(s[it]==' ') continue;
            else if (isdigit(s[it])) tmp=tmp*10+s[it]-'0';
            else if(s[it]=='*'||s[it]=='/') {
                if(cal=='*') cur *= tmp;
                else if(cal=='/') cur /= tmp;
                tmp = 0;
                cal = s[it];
            }
            else break;
        }
        if(cal=='*') cur *= tmp;
        else if(cal=='/') cur /= tmp;
        else cur = tmp;
        return cur;
    }
};