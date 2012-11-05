class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int far = 0;
        int ans = 0;
        int i = 0;
        while (far < n - 1)
        {
            ans++;
            int nextFar = far;
            for (int k = i; k <= far; k++)
            {
                nextFar = max(nextFar, A[k] + k);
            }
            i = far + 1;
            far = nextFar;
        }
        return ans;
    }
};
