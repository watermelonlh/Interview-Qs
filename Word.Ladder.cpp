class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> que;
        vector<int> step;
        que.push_back(start);
        step.push_back(1);
        int head = 0, tail = 1;
        dict.erase(start);
        while (head < tail)
        {
            string nowStr = que[head];
            int nowStep = step[head];
            head++;
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                for (int i = 0; i < start.size(); i++)
                {
                    if (nowStr[i] == ch) continue;
                    string nextStr = nowStr;
                    nextStr[i] = ch;
                    if (nextStr == end) return nowStep + 1;
                    if (dict.find(nextStr) != dict.end())
                    {
                        dict.erase(nextStr);
                        que.push_back(nextStr);
                        step.push_back(nowStep + 1);
                        tail++;
                    }
                 
                }
            }
        }
        return 0;
    }
};

