#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
//functions

int* InputMonth(char* str);
int* InputDay(char* str);
char* RemoveDigits(char* input);
char* RemoveChars(char* input);
char* toLowerCase(char* s);
int daynumYear(int inputday, int inputmonth, int inputyear);
//main function
int main()
{
    char str[15];
    time_t s;
    struct tm* current_time;
    s = time(NULL);
    current_time = localtime(&s);

      FILE *f = fopen("text.txt" , "r");

      if(f == NULL){
        perror("Error opening file");
        return(-1);
      }
      else{
        while(fgets(str, 15, f)) {
                int inputday = InputDay(str);
                int inputmonth = InputMonth(str);
                int inputyear = 2020;
                if(inputmonth==current_time->tm_mon+1 && inputday==current_time->tm_mday) {
                    printf("Birthday is today");

                }else if (inputmonth>current_time->tm_mon+1 && inputday > current_time->tm_mday) {
                    inputyear = 2020;
                }else {
                    inputyear = 2021;
                }
            Calculate(inputday,inputmonth,inputyear);
        }
      }
      fclose(f);
      return 0;
}
//do the days calculation and print the result

void Calculate(int inday, int inmonth, int inyear){
	int day, month, year;

	time_t now;

	time(&now);
    int inputday = inday;
    int inputmonth = inmonth;
    int inputyear = inyear;
	struct tm *local = localtime(&now);

	day = local->tm_mday;
	month = local->tm_mon + 1;
	year = local->tm_year + 1900;

	//printf("Date is : %02d/%02d/%d\n", day, month, year);
	int currentdaynum = daynumYear(day,month,year);
	int birthdaynum = daynumYear(inputday,inputmonth,inputyear);
	int days;
	if(inyear>year){
        days = 365-currentdaynum+birthdaynum;
	}else if(inmonth>month){
        days = birthdaynum - currentdaynum;
	}
    printf("%02d-%02d-%d in %d Days \n", inputday, inputmonth, inputyear, days);
}


int* InputMonth(char* str){
    char* inputMonth = RemoveDigits(str);
    int monthcount;
    if(strncmp(inputMonth, "jan", 3) == 0)
        monthcount = 1;
    else if(strncmp(inputMonth, "feb", 3) == 0)
        monthcount = 2;
    else if(strncmp(inputMonth, "mar", 3) == 0)
        monthcount = 2;
    else if(strncmp(inputMonth, "apr", 3) == 0)
        monthcount = 4;
    else if(strncmp(inputMonth, "may", 3) == 0)
        monthcount = 5;
    else if(strncmp(inputMonth, "jun", 3) == 0)
        monthcount = 6;
    else if(strncmp(inputMonth, "jul", 3) == 0)
        monthcount = 7;
    else if(strncmp(inputMonth, "aug", 3) == 0)
        monthcount = 8;
    else if(strncmp(inputMonth, "sep", 3) == 0)
        monthcount = 9;
    else if(strncmp(inputMonth, "oct", 3) == 0)
        monthcount = 10;
    else if(strncmp(inputMonth, "nov", 3) == 0)
        monthcount = 11;
    else if(strncmp(inputMonth, "dec", 3) == 0)
        monthcount = 12;
    else monthcount = 0;
return monthcount;
}
int* InputDay(char* str){
    char* inputDay = RemoveChars(str);
    return inputDay;
}

char* RemoveDigits(char* input)
{
    char* dest = input;
    char* src = input;

    while(*src)
    {
        if (isspace(*src) || isdigit(*src)) { src++; continue; }
        *dest++ = *src++;
    }

    return toLowerCase(input);
}


char* RemoveChars(char* input)
{
    char* dest = input;
    char* src = input;
    int val;
    while(*src)
    {

        if (isdigit(*src)) {
            val = strtol(src, &src, 10);
        }else{
            src++;
        }
    }

    return val;
}


char* toLowerCase(char* s) {
  for(char *p=s; *p; p++) *p=tolower(*p);
  return s;
}

int daynumYear(int inputday, int inputmonth, int inputyear){
    int day, mon, year, days_in_feb = 28, doy;
    day = inputday;
    mon = inputmonth;
    year = inputyear;

    doy = day;

    // check for leap year
    if( (year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0) )
    {
        days_in_feb = 29;
    }

    switch(mon)
    {
        case 2:
            doy += 31;
            break;
        case 3:
            doy += 31+days_in_feb;
            break;
        case 4:
            doy += 31+days_in_feb+31;
            break;
        case 5:
            doy += 31+days_in_feb+31+30;
            break;
        case 6:
            doy += 31+days_in_feb+31+30+31;
            break;
        case 7:
            doy += 31+days_in_feb+31+30+31+30;
            break;
        case 8:
            doy += 31+days_in_feb+31+30+31+30+31;
            break;
        case 9:
            doy += 31+days_in_feb+31+30+31+30+31+31;
            break;
        case 10:
            doy += 31+days_in_feb+31+30+31+30+31+31+30;
            break;
        case 11:
            doy += 31+days_in_feb+31+30+31+30+31+31+30+31;
            break;
        case 12:
            doy += 31+days_in_feb+31+30+31+30+31+31+30+31+30;
            break;
    }

    return doy;

}
