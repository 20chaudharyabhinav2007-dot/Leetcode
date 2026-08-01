class Solution {
public:
    vector<vector<int>> dp;

    bool match(int sIndex, int pIndex, string &s, string &p) {

        if (dp[sIndex][pIndex] != -1)
            return dp[sIndex][pIndex];

        if (pIndex == p.size())
            return dp[sIndex][pIndex] = (sIndex == s.size());

        bool firstMatch = false;

        if (sIndex < s.size()) {
            if (s[sIndex] == p[pIndex] || p[pIndex] == '.')
                firstMatch = true;
        }

        if (pIndex + 1 < p.size() && p[pIndex + 1] == '*') {

            bool skipStar = match(sIndex, pIndex + 2, s, p);

            bool useStar = false;
            if (firstMatch)
                useStar = match(sIndex + 1, pIndex, s, p);

            return dp[sIndex][pIndex] = skipStar || useStar;
        }

        if (firstMatch)
            return dp[sIndex][pIndex] = match(sIndex + 1, pIndex + 1, s, p);

        return dp[sIndex][pIndex] = false;
    }

    bool isMatch(string s, string p) {

        dp.assign(s.size() + 1, vector<int>(p.size() + 1, -1));

        return match(0, 0, s, p);
    }
};