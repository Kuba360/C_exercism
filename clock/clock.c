#include "clock.h"
#include <string.h>
#include <stdlib.h>


clock_t clock_create(int hour, int minute){
    clock_t c;
    int h=0;
    int m=0;
    if(minute<0){
        if(minute==-60){
            h=hour-1;m=0;
        }else {
            h=hour-1+minute/60;
            m=minute%60+60;
        }
    }else{
        h=hour + minute/60;
        m=minute%60;
    }
    if (h<0){
        h=(h%24)+24;
    }else{
        h=h%24;
    }
    c.text[0]=h/10+'0';
    c.text[1]=h%10+'0';
    c.text[3]=m/10+'0';
    c.text[4]=m%10+'0';
    c.text[2]=':';
    c.text[5]='\0';
    return c;
}
clock_t clock_add(clock_t clock, int minute_add){
    int h=(clock.text[0]-'0')*10+clock.text[1]-'0';
    int m=(clock.text[3]-'0')*10+clock.text[4]-'0';
    int t=h*60+m+minute_add;
    t = ((t % 1440) + 1440) % 1440;
    h=t/60;
    m=t%60;
    clock_t c=clock_create(h,m);
    return c;
}
clock_t clock_subtract(clock_t clock, int minute_subtract){
    int h=(clock.text[0]-'0')*10+clock.text[1]-'0';
    int m=(clock.text[3]-'0')*10+clock.text[4]-'0';
    int t=h*60+m-minute_subtract;
    t = ((t % 1440) + 1440) % 1440;
    h=t/60;
    m=t%60;
    clock_t c=clock_create(h,m);
    return c;
}

bool clock_is_equal(clock_t a, clock_t b){
    return strcmp(a.text,b.text)==0;
}



////AI generated 
//#include "clock.h"
//#include <string.h>
//
//clock_t clock_create(int hour, int minute) {
//    clock_t c;
//    int total = ((hour * 60 + minute) % 1440 + 1440) % 1440;
//    int h = total / 60;
//    int m = total % 60;
//    c.text[0] = h / 10 + '0';
//    c.text[1] = h % 10 + '0';
//    c.text[2] = ':';
//    c.text[3] = m / 10 + '0';
//    c.text[4] = m % 10 + '0';
//    c.text[5] = '\0';
//    return c;
//}
//
//clock_t clock_add(clock_t clock, int minute_add) {
//    int h = (clock.text[0] - '0') * 10 + (clock.text[1] - '0');
//    int m = (clock.text[3] - '0') * 10 + (clock.text[4] - '0');
//    return clock_create(h, m + minute_add);
//}
//
//clock_t clock_subtract(clock_t clock, int minute_subtract) {
//    int h = (clock.text[0] - '0') * 10 + (clock.text[1] - '0');
//    int m = (clock.text[3] - '0') * 10 + (clock.text[4] - '0');
//    return clock_create(h, m - minute_subtract);
//}
//
//bool clock_is_equal(clock_t a, clock_t b) {
//    return strcmp(a.text, b.text) == 0;
//}