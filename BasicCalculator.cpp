class Solution {
public:
    int returnoffset = 0;
    int calculate(string s) {
        int tmp = 0, cur = 0;
        char cal;
        for(int i=0; i<s.length(); i++) {
            char c = s[i];
            if(c==' ') continue;
            if(c>='0'&&c<='9') tmp=tmp*10+c-'0';
            else if(c=='+'||c=='-') {
                if(cal=='+') cur += tmp;
                else if(cal=='-') cur -= tmp;
                else cur = tmp;
                tmp = 0;
                cal = c;
            }
            else if(c=='(') {
                tmp=calculate(s.substr(i+1));
                i += returnoffset;
            }
            else if(c==')') {
                returnoffset = i+1;
                if(cal=='+') cur += tmp;
                else if(cal=='-') cur -= tmp;
                else cur = tmp;
                return cur;
            }
        }
        if(cal=='+') cur += tmp;
        else if(cal=='-') cur -= tmp;
        else cur = tmp;
        return cur;
    }
};