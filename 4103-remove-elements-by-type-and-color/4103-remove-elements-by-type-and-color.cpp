
class Solution {
public:
    struct Group {
        int type;
        int color;
        int count;
    };

    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {

        vector<Group> st;

        for (int i = 0; i < types.size(); i++) {

            int t = types[i];
            int c = colors[i];

            if (!st.empty() && st.back().type == t &&
                st.back().color == c) {
                st.back().count++;
            }
            else {
                st.push_back({t, c, 1});
            }

            if (st.back().count == groupSize[t]) {
                st.pop_back();
            }
        }

        return st.empty();
    }
};
