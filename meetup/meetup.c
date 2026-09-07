#include "meetup.h"
#include <time.h>
#include <string.h>
#include <stdio.h>

static const char *weekdays[]={"Sunday","Monday","Tuesday","Wednesday","Thursday",
                                "Friday","Saturday"};
static const char *weeknum[]={"first","second","third","fourth","last","teenth"};

int meetup_day_of_month(unsigned int year, unsigned int month, const char *week,
                        const char *day_of_week){
        int wd=0;
        for(int i=0;i<7;i++){
            if(strcmp(weekdays[i],day_of_week)==0){
                wd=i;
            }
        }
        
        int wn=0;
        for(int i=0;i<6;i++){
            if(strcmp(weeknum[i],week)==0){
                wn=i;
            }
        }
        int x=1; 


        for(int d=1;d<32;d++){
            struct tm date = {0};
            date.tm_year=year-1900;
            date.tm_mon=month-1;
            date.tm_mday=d;
            
            mktime(&date);

            if (date.tm_mon != (int)(month - 1)) {
                break;
            }

            if(date.tm_wday==wd){
                switch (wn){
                    case 5:
                        if(d<20 && d>12){
                            return d;
                        }
                        break;
                    case 4: 
                        x=d;
                        break;
                    default:
                        if(wn==0){
                            return d;
                        }
                        wn--;
                        break;
                }

            }
        }
        return x;
        
    }