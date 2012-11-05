class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long ans = 0;
        int sign = 1;      
        int i = 0;
        int len = strlen(str);
        while (i < len && str[i] == ' ') i++;
        if (str[i] == '-') sign = -1;
        if (str[i] == '-' || str[i] == '+') i++;
        for ( ; i < len; i++)
        {
            if (isdigit(str[i])) ans = ans * 10 + str[i] - '0';
            else break;
        }
        ans = ans * sign;
        if (ans > INT_MAX) ans = INT_MAX;
        if (ans < INT_MIN) ans = INT_MIN;
        return ans;
    }
};
