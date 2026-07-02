#include "sublist.h"
#include <stdbool.h>



comparison_result_t check_lists(int *list_to_compare, int *base_list,
                                size_t list_to_compare_element_count,
                                size_t base_list_element_count)
    {
        if (base_list_element_count==0){
            return (list_to_compare_element_count==0) ? EQUAL : SUPERLIST;
        }else if(list_to_compare_element_count==0){
            return SUBLIST;
        }else if (list_to_compare_element_count<base_list_element_count){
            size_t n=0;
            for(size_t i=0;i<base_list_element_count;i++){
                if(base_list[i]==list_to_compare[0]){
                    for (size_t j=1;j<list_to_compare_element_count;j++){
                       if(base_list[i+j]==list_to_compare[j]){
                            n++;
                       } 
                    }
                }
                if(n+1==list_to_compare_element_count){
                    return SUBLIST;
                }else {n=0;}
            }
            return UNEQUAL;
        }else if (list_to_compare_element_count>=base_list_element_count){
            size_t n=0;
            for(size_t i=0;i<list_to_compare_element_count;i++){
                if(list_to_compare[i]==base_list[0]){
                    for (size_t j=1;j<base_list_element_count;j++){
                       if(list_to_compare[i+j]==base_list[j]){
                            n++;
                       } 
                    }
                }
                if(n+1==base_list_element_count){
                    return (base_list_element_count==list_to_compare_element_count) ? EQUAL : SUPERLIST;
                }else {n=0;}
            }
            return UNEQUAL;
        }
        return UNEQUAL; 
    }

//AI generated 
// The biggest problem was that my function could go beyond length
// of list. Additionaly memcmp is faster and I have two blocks that
// are almost identical.
//#include "sublist.h"
//#include <stdbool.h>
//#include <string.h>
//
//static bool contains(const int *haystack, size_t haystack_count,
//                      const int *needle, size_t needle_count) {
//    if (needle_count == 0) {
//        return true;
//    }
//    if (needle_count > haystack_count) {
//        return false;
//    }
//
//    for (size_t i = 0; i <= haystack_count - needle_count; i++) {
//        if (memcmp(&haystack[i], needle, needle_count * sizeof(int)) == 0) {
//            return true;
//        }
//    }
//    return false;
//}
//
//comparison_result_t check_lists(int *list_to_compare, int *base_list,
//                                 size_t list_to_compare_element_count,
//                                 size_t base_list_element_count) {
//
//    if (list_to_compare_element_count == base_list_element_count) {
//        if (memcmp(list_to_compare, base_list,
//                   base_list_element_count * sizeof(int)) == 0) {
//            return EQUAL;
//        }
//        return UNEQUAL;
//    }
//
//    if (list_to_compare_element_count > base_list_element_count) {
//        return contains(list_to_compare, list_to_compare_element_count,
//                         base_list, base_list_element_count)
//                   ? SUPERLIST
//                   : UNEQUAL;
//    }
//
//    return contains(base_list, base_list_element_count,
//                     list_to_compare, list_to_compare_element_count)
//               ? SUBLIST
//               : UNEQUAL;
//}
        





