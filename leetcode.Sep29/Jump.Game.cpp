class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int far = 0;
        for (int i = 0; i <= far && far < n - 1; i++)
        {
            far = max(far, A[i] + i);
        }
        return far >= n - 1;
    }
};
