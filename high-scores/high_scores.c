#include "high_scores.h"
#include "stdlib.h"


int32_t latest(const int32_t *scores, size_t scores_len){
    return scores[scores_len- 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len){
    int n=scores[0];
    for(size_t i=1;i<scores_len;i++){
        if(scores[i]>n){
            n=scores[i];
        }
    }
    return n;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
                          int32_t *output)
    {
    int32_t *temp = malloc(scores_len * sizeof(int32_t));
    for (size_t i = 0; i < scores_len; i++) {
        temp[i] = scores[i];
    }

    size_t count = scores_len < 3 ? scores_len : 3;

    for (size_t i = 0; i < count; i++) {
        int32_t max = temp[0];
        int max_idx = 0;
        for (size_t j = 1; j < scores_len; j++) {
            if (temp[j] > max) {
                max = temp[j];
                max_idx = j;
            }
        }
        output[i] = max;
        temp[max_idx] = 0;
    }
    free(temp);
    return count;
    }