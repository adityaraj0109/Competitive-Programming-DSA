#include <bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k)
{
    if (s.size() == 0)
        return 0;

    vector<int> freq(26, 0);
    for (auto ch : s)
        freq[ch - 'a']++;
    int i;
    for (i = 0; i < s.size(); i++)
        if (freq[s[i] - 'a'] < k)
            break;
    if (i == s.size())
        return s.size();
    int left = longestSubstring(s.substr(0, i), k);
    int right = longestSubstring(s.substr(i + 1), k);
    return max(left, right);
}

int main()
{
    int k = 4;
    string s = "aaabbbacccbdc";
    int ans = longestSubstring(s, k);
    cout << ans << endl;
    return 0;
}