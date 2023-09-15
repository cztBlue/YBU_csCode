#include <iostream>
#include <cstring>
#include <ctime>
#include <time.h>

using namespace std;

// 公元年份非4的倍数，为365天平年。
// 公元年份为4的倍数但非100的倍数，为366天闰年。
// 公元年份为100的倍数但非400的倍数，（1700年、1800年及1900年）为平年。
// 公元年份为400的倍数，（1600年及2000年）为闰年。

bool isLeap(int year)
{
   if (year % 4 != 0)
      return false;
   if (year % 4 == 0 && year % 100 != 0)
      return true;
   if (year % 100 == 0 && year % 400 != 0)
      return false;
   if (year % 400 == 0)
      return true;
   return false;
}

int getLastDay(int year, int month, int day)
{
   int lastDay = 0;
   int monDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   if (isLeap(year))

      monDay[1] = 29;

   for (int i = month - 1; i < 12; i++)
   {
      // cout << "last" << i + 1 << endl;
      if (i == month - 1)
      {
         lastDay += (monDay[i] - day);
      }
      else
      {
         lastDay += monDay[i];
      }
   }

   return lastDay;
}

int getBeforeDay(int year, int month, int day)
{
   int beforeDay = 0;

   int monDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
   if (isLeap(year))
      monDay[1] = 29;

   for (int i = month - 1; i >= 0; i--)
   {
      // cout << "befo" << i + 1 << endl;
      if (i == month - 1)
      {
         beforeDay += day;
      }
      else
      {
         beforeDay += monDay[i];
      }
   }

   return beforeDay;
}

int getGapYearDay(int starYear, int stopYear)
{
   int sumDay = 0;
   for (int i = starYear + 1; i < stopYear; i++)
   {
      if (isLeap(i))
      {
         sumDay += 366;
      }
      else
      {
         sumDay += 365;
      }
   }
   return sumDay;
}

int main()
{
   int birthYear = 2004;
   int birthMon = 3;
   int birthDay = 18;

   int deltaYear;
   int deltaMon;
   int deltaDay;

   // 日期转时间戳
   time_t now = time(0);
   struct tm *now_ = localtime(&now);

   deltaYear = (now_->tm_year + 1900) - birthYear;
   deltaMon = (now_->tm_mon + 1) - birthMon;
   deltaDay = (now_->tm_mday) - birthDay;

   cout << getGapYearDay(birthYear, now_->tm_year + 1900) + getLastDay(birthYear, birthMon, birthDay) +
               getBeforeDay(now_->tm_year + 1900, now_->tm_mon + 1, now_->tm_mday)<<" Days"<< endl;

   // cout << getLastDay(birthYear, birthMon, birthDay) << endl;
   // cout << getBeforeDay(now_->tm_year + 1900, now_->tm_mon + 1, now_->tm_mday) << endl;
}
