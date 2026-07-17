#include "anagram.h"
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


void find_anagrams(const char *subject, struct candidates *candidates){
    int b[26]={0};
    for (size_t i=0;subject[i]!='\0';i++){
        b[(tolower(subject[i])-'a')]++;
    }

    for (size_t i=0;i<candidates->count;i++){
        const char *word=candidates->candidate[i].word;

        bool sameword=(strlen(subject)==strlen(word));
        if (sameword){
            for (size_t k=0;subject[k]!='\0';k++){
                if(tolower(subject[k])!=tolower(word[k])){
                    sameword=false;
                    break;
                }
            }
        }else{
            candidates->candidate[i].is_anagram=NOT_ANAGRAM;
            continue;
        }

        if(sameword){
            candidates->candidate[i].is_anagram=NOT_ANAGRAM;
        }else{
            int c[26]={0};
            for(size_t j=0;candidates->candidate[i].word[j]!='\0';j++){
                c[(tolower(candidates->candidate[i].word[j])-'a')]++;
            }
            if (memcmp(b,c,sizeof(c))==0){
                candidates->candidate[i].is_anagram=IS_ANAGRAM;
            }else{
                candidates->candidate[i].is_anagram=NOT_ANAGRAM;
            }
        }
    }
}


//AI generated 
//#include "anagram.h"
//#include <string.h>
//#include <ctype.h>
//
//static void letter_counts(const char *word, int counts[26]) {
//    for (size_t i = 0; word[i] != '\0'; i++) {
//        counts[(unsigned char)tolower((unsigned char)word[i]) - 'a']++;
//    }
//}
//
//static bool same_word(const char *a, const char *b) {
//    while (*a != '\0' && *b != '\0') {
//        if (tolower((unsigned char)*a) != tolower((unsigned char)*b)) {
//            return false;
//        }
//        a++;
//        b++;
//    }
//    return *a == *b; // oba muszą się skończyć jednocześnie
//}
//
//void find_anagrams(const char *subject, struct candidates *candidates){
//    int subject_counts[26] = {0};
//    letter_counts(subject, subject_counts);
//
//    for (size_t i = 0; i < candidates->count; i++){
//        const char *word = candidates->candidate[i].word;
//
//        if (same_word(subject, word)) {
//            candidates->candidate[i].is_anagram = NOT_ANAGRAM;
//            continue;
//        }
//
//        int word_counts[26] = {0};
//        letter_counts(word, word_counts);
//
//        candidates->candidate[i].is_anagram =
//            (memcmp(subject_counts, word_counts, sizeof(word_counts)) == 0)
//                ? IS_ANAGRAM : NOT_ANAGRAM;
//    }
//}