#include "binary_search.h"
#include <math.h>
#include <stddef.h>




const int *binary_search(int value, const int *arr, size_t length){

    if (length == 0) return NULL;
    if(value<arr[0] || value>arr[length-1]){return NULL;}
    int l=0;
    int r=length-1; 
    int mid=(l+r)/2;
    while(l<=r){
        
        if (arr[mid] == value) {
            return &arr[mid];
        }
        if(arr[mid]>value){
            r=mid-1;
        }else{
            l=mid+1;
        }
        mid=(r+l)/2;
    }
    return NULL;

}