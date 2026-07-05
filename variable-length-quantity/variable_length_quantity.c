#include "variable_length_quantity.h"

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
{
   int l=0;
   for (size_t i=0;i<integers_len;i++){
      int n=0;
      uint32_t a=integers[i];
      for (int j=0;a>0;j++){
         a>>=7;
         n++;
      }
      if (n==0) n=1; 
      a=integers[i];
      int base=l;
      int m=n-1;
      while (m>=0){
         uint32_t b=a&127;
         a >>=7;
         if (m!=n-1) b+=128;
         output[base+m]=b;
         m--;
         l++;
      }
   }
   return l;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
{
   int n=0;
   int l=0;
   for (size_t i=0;i<buffer_len;i++){

      if((bytes[i]&128)==0){
         unsigned int x=0;
         for (size_t j=0;(n+1)!=0;j++){
            x+=(bytes[i-j]&127)<<(7*j);
            n--;
         }
         output[l]=x;
         l++;
         n=0; 
      }else{
         n++;
      }

   }
   if(l==0) return -1;

   return l;
}

//AI generated 
//#include "variable_length_quantity.h"
//
//#define GROUP_MASK 0x7F
//#define CONTINUATION_BIT 0x80
//#define MAX_GROUPS 5 
//
//int encode(const uint32_t *integers, size_t integers_len, uint8_t *output)
//{
//    int pos = 0;
//
//    for (size_t i = 0; i < integers_len; i++) {
//        uint32_t value = integers[i];
//        uint8_t groups[MAX_GROUPS];
//        int n = 0;
//
//
//        do {
//            groups[n++] = value & GROUP_MASK;
//            value >>= 7;
//        } while (value > 0);
//
//        for (int j = n - 1; j >= 0; j--) {
//            uint8_t byte = groups[j];
//            if (j != 0) byte |= CONTINUATION_BIT;
//            output[pos++] = byte;
//        }
//    }
//
//    return pos;
//}
//
//int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output)
//{
//    int count = 0;
//    uint32_t value = 0;
//    int in_progress = 0; 
//
//    for (size_t i = 0; i < buffer_len; i++) {
//        value = (value << 7) | (bytes[i] & GROUP_MASK);
//        in_progress = 1;
//
//        if ((bytes[i] & CONTINUATION_BIT) == 0) {
//            output[count++] = value;
//            value = 0;
//            in_progress = 0;
//        }
//    }
//
//    if (in_progress) {
//        return -1;
//    }
//
//    return count;
//}