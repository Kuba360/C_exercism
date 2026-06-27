#include "triangle.h"
#include <stdbool.h>




bool is_triangle(triangle_t sides){
    if(sides.a==0||sides.b==0||sides.c==0){return false;}
    if(sides.a+sides.b>=sides.c && sides.a+sides.c>=sides.b 
    && sides.c+sides.b>=sides.a){
        return true;
    }else{return false;}
}
bool is_equilateral(triangle_t sides){
    if(is_triangle(sides)==false){return false;}
    if(sides.a==sides.b && sides.b==sides.c){
        return true;
    }else{return false;}
}

bool is_isosceles(triangle_t sides){
    if(is_triangle(sides)==false){return false;}
    if(sides.a==sides.b || sides.b==sides.c || sides.a==sides.c){
        return true;
    }else{return false;}
}

bool is_scalene(triangle_t sides){
    if(is_triangle(sides)==false){return false;}
    if(sides.a!=sides.b && sides.b!=sides.c && sides.a!=sides.c){
        return true;
    }else{return false;}
}


//#include "triangle.h"
//#include <stdbool.h>
//
//bool is_triangle(triangle_t s)
//{
//    return s.a > 0 && s.b > 0 && s.c > 0 &&
//           s.a + s.b > s.c &&
//           s.a + s.c > s.b &&
//           s.b + s.c > s.a;
//}
//
//bool is_equilateral(triangle_t s)
//{
//    return is_triangle(s) &&
//           s.a == s.b &&
//           s.b == s.c;
//}
//
//bool is_isosceles(triangle_t s)
//{
//    return is_triangle(s) &&
//           (s.a == s.b || s.b == s.c || s.a == s.c);
//}
//
//bool is_scalene(triangle_t s)
//{
//    return is_triangle(s) &&
//           s.a != s.b &&
//           s.b != s.c &&
//           s.a != s.c;
//}