class Solution {
public:
    string decodeString(string s) {
    stack<int> num;
    stack<string> st;
    string curr = "";
    int n = 0;
    for(char c : s) {
        if(isdigit(c)) {
            n = n * 10 + (c - '0');
        }
        else if(c == '[') {
            num.push(n);
            st.push(curr);
            n = 0;
            curr = "";
        }
        else if(c == ']') {
            int k = num.top();
            num.pop();
            string temp = st.top();
            st.pop();
            for(int i = 0; i < k; i++) {
                temp += curr;
            }
            curr = temp;
        }
        else {
            curr += c;
        }
    }
    return curr;
    }
};