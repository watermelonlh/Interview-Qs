class Solution {
public:
    bool match(char a, char b)
    {
        return a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}';
    }
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> c;
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
                case '(':
                case '[':
                case '{':
                    c.push(s[i]);
                    break;
                case ')':
                case ']':
                case '}':
                    if (!c.empty() && match(c.top(), s[i])) c.pop();
                    else return false;
            }
        }
        return c.empty();        
    }
};
