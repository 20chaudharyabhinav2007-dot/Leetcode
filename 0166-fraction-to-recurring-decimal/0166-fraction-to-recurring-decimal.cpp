class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<long long,int>mp;
        string ans = "";
        if(numerator == 0){
            return "0";
        }
        if((numerator < 0) != (denominator < 0)){
            ans +="-";
        }
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);
        long long whole = n/d;
        long long rem = n%d;
        ans+=to_string(whole);
        if(rem != 0){
            ans+=".";
        }
        while(rem !=0){
            if(mp.count(rem)){
                ans.insert(mp[rem] , "(");
                ans +=")";
                break;
            }
            mp[rem] = ans.length();
            rem*=10;
            ans+=to_string(rem/d);
            rem%=d;
        }
        return ans;
    }
};