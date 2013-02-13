class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        deque<string> que;
        deque<int> step;
        que.push_back(start);
        step.push_back(1);
        while (!que.empty())
        {
            string now = que.front();
            int nowStep = step.front();
            que.pop_front();
            step.pop_front();
            for (int l = 0; l < now.size(); l++)
                for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        string next = now;
                        if (ch == next[l]) continue;
                        next[l] = ch;
                        if (next == end) return nowStep + 1;
                        if (dict.count(next))
                        {
                            que.push_back(next);
                            step.push_back(nowStep + 1);
                            dict.erase(next);
                        }
                    }
        }
        return 0;
    }
};
