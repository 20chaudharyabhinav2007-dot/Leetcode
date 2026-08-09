#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        int i = prices.size()-1;
        int j = discounts.size()-1;
        long double sum = 0;
        while(i>=0 && j>=0){
            sum += (long double)prices[i]*(100 - discounts[j])/100;
            i--;
            j--;
        }
        while(i>=0){
            sum+= prices[i];
            i--;
        }
        return sum;
    }
};