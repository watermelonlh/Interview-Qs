class Solution {
public:
    void add(int num, char one, char five, char ten, string &ans)
    {
        switch(num)
        {
        case 0 :
            break;
        case 1 :
        case 2 :
        case 3 :
            ans = ans + string(num, one);
            break;
        case 4 :
            ans = ans + one + five;
            break;
        case 5 :
            ans = ans + five;
            break;
        case 6 :
        case 7 :
        case 8 :
            ans = ans + five + string(num - 5, one);
            break;
        case 9 :
            ans = ans + one + ten;
            break;
        }
    }
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string ans = "";
        string digits = "MDCLXVI";
        for (int i = 0, p = 1000; i < 4; i++, p /= 10)
        {
            if (num / p)
            {
                int one = i * 2;
                int five = (one > 0) ? one - 1 : 0;
                int ten = (five > 0) ? five - 1 : 0;
                add(num / p, digits[one], digits[five], digits[ten], ans);
                num %= p;
            }
            
        }
        return ans;
    }
};
