class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        path = "/" + path + "/";
        int len = path.size();
        stack<string> s;
        string cur = "";
        for (int i = 1; i < len; i++)
        {
            if (path[i] == '/')
            {
                if (cur == ".") 
                {}
                else if (cur == "..") 
                {
                    if (!s.empty()) s.pop();
                } else if (cur != "") 
                {
                    s.push(cur);
                }
                cur = "";
            } else cur = cur + path[i];
        }
        if (s.empty()) return "/";
        else 
        {
            string ans = "";
            while (!s.empty())
            {
                ans = "/" + s.top() + ans;
                s.pop();
            }
            return ans;
        }
    }
};
