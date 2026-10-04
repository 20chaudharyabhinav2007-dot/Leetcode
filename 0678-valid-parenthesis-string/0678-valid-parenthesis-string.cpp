class Solution {
public:
    bool checkValidString(string s) {
        stack<int> S;
        stack<int> star;
        for(int i = 0; i < s.size(); i++){            
            if(s[i] == '('){
                S.push(i);
            }            
            if(s[i] == '*'){
                star.push(i);
            }            
            if(s[i] == ')'){
                if(!S.empty()){
                    S.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!S.empty() && !star.empty()){
            if(S.top() > star.top()){
                return false;
            }
            S.pop();
            star.pop();
        }
        if(S.empty()){
            return true;
        }
        else{
            return false;
        }

    }
};