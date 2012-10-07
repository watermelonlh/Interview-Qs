class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (*haystack == *needle && *needle == '\0') return haystack;
        for (int i = 0; haystack[i] != '\0'; i++)
        {
            bool match = true;
            int j = 0;
            for (; needle[j] != '\0'; j++)
            {
                if (haystack[i + j] == '\0') break;
                if (haystack[i + j] != needle[j])
                {
                    match = false;
                    break;
                }
            }
            if (match && needle[j] == '\0') return haystack + i;
            if (haystack[i + j] == '\0') break;
        }
        return NULL;
    }
};
