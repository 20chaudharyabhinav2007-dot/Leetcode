class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        vector<int>st;
        vector<long double>t;
        vector<int>pos;
        for(int i = n-1 ; i>=0 ; i--){
            bool m = false;
            while(!st.empty()){
                int j = st.back();
                if(pos.back() - position[i]<=distance){
                    pos.back() = position[i];
                    m=true;
                    break;
                }
                if(speed[i] > speed[j]){
                    long double time = (long double)(pos.back() - position[i] - distance)/(speed[i]-speed[j]);
                    if(time<=t.back()){
                        pos.back()=position[i];
                        m = true;
                        break;;
                    }
                    pos.pop_back();
                    st.pop_back();
                    t.pop_back();
                }else{
                    break;
                }
            }
            if(!m){
                pos.push_back(position[i]);
                st.push_back(i);
                t.push_back(1000000000000000);
            }
        }
        return st.size();
    }
};