class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        long int ans = 0;
        for(int i = 1971; i<year ; i++){
            if(i%400 == 0|| (i%100!=0 &&i%4 == 0)){
                ans+=366;
            }else{
                ans+=365;
            }
        }
        vector<string> days = {"Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday"};
        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
                months[1] = 29;
        }
        for(int i = 0 ; i<month-1;i++){
            ans+=months[i];
        }
        ans= ans+day-1;
        ans=ans%7;
        return days[ans];
    }
};