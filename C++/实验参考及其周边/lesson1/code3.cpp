# include<iostream>
# include <cstring>
# include<ctime>
# include<time.h>

using namespace std;

int main()
{
   int birthYear,birthMon,birthDay;
   cout<<"enter your birthday:";
   cin>>birthYear>>birthMon>>birthDay;


   //日期转时间戳
   time_t now = time(0);
   struct tm* birth = localtime(&now);
   birth->tm_year = birthYear - 1900;
   birth->tm_mon = birthMon - 1;
   birth->tm_mday = birthDay;
   birth->tm_min = 0;
   birth->tm_sec = 0;
   time_t timestamp = mktime(birth);

   //86400是一天的秒数
   cout<<"birth to now:"<<(now-timestamp)/86400<<" Days"<<endl;

}



