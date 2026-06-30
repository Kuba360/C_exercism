#include "square_root.h"


int square_root(int x){

    int n=x;
    while (n*n!=x){
        n=(n+x/n)/2;
    }
    return n;
}

//AI generated binary search
//unsigned int square_root(unsigned int n)
//{
//    unsigned int left = 1;
//    unsigned int right = n;
//
//    while (left <= right)
//    {
//        unsigned int mid = (left + right) / 2;
//        unsigned int square = mid * mid;
//
//        if (square == n)
//        {
//            return mid;
//        }
//        else if (square < n)
//        {
//            left = mid + 1;
//        }
//        else
//        {
//            right = mid - 1;
//        }
//    }
//
//    return 0;
//}