class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        for (int x : asteroids) {
            bool a = true;
            while (!st.empty() && st.back() > 0 && x < 0) {
                if (st.back() < -x) {
                    st.pop_back();
                }
                else if (st.back() == -x) {
                    st.pop_back();
                    a = false;
                    break;
                }
                else {
                    a = false;
                    break;
                }
            }
            if (a) {
                st.push_back(x);
            }
        }
        return st;
    }
};