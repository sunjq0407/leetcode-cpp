class Solution {
public:
    map<int, string> toEng = {
        {1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},
        {6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"},{10,"Ten"},
        {11,"Eleven"},{12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},{15,"Fifteen"},
        {16,"Sixteen"},{17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"},{20,"Twenty"},
        {30,"Thirty"},{40,"Forty"},{50,"Fifty"},{60,"Sixty"},{70,"Seventy"},
        {80,"Eighty"},{90,"Ninety"}};
    string numberToWords(int num) {
        string ret;
        if (num == 0) return "Zero";
        int units = num%1000;
        num /= 1000;
        int thousands = num%1000;
        num /= 1000;
        int millions = num%1000;
        num /= 1000;
        int billions = num%1000;
        if (billions) ret += helper(billions, ret) + " Billion";
        if (millions) ret += helper(millions, ret) + " Million";
        if (thousands) ret += helper(thousands, ret) + " Thousand";
        if (units) ret += helper(units, ret);
        while (ret.back() == ' ') ret.pop_back();
        while (ret.front() == ' ') ret.erase(ret.begin());
        return ret;
    }
    string helper(int num, string check) {
        string ret;
        if (check.back() != ' ') ret += " ";
        int units = num%10;
        num /= 10;
        int tens = num%10;
        num /= 10;
        int hundreds = num%10;
        if (hundreds) ret += toEng[hundreds] + " Hundred";
        if (tens == 1) {
            if(ret.length()!=0&&ret.back()!=' ') ret += " ";
            ret += toEng[10+units];
        }
        else {
            if (tens) {
                if(ret.length()!=0&&ret.back()!=' ') ret += " ";
                ret += toEng[10*tens];
            }
            if (units) {
                if(ret.length()!=0&&ret.back()!=' ') ret += " ";
                ret += toEng[units];
            }
        }
        return ret;
    }
};