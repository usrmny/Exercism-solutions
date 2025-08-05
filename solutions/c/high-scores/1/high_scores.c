#include "high_scores.h"

/// Return the latest score.
int32_t latest(const int32_t *scores, size_t scores_len){
    return scores[scores_len - 1];
}

/// Return the highest score.
int32_t personal_best(const int32_t *scores, size_t scores_len){
    int32_t highest = 0;
    for(size_t i = 0; i < scores_len; i++){
        if(scores[i] > highest) highest = scores[i];
    }
    return highest;
}

/// Write the highest scores to `output` (in non-ascending order).
/// Return the number of scores written.
size_t personal_top_three(const int32_t *scores, size_t scores_len, int32_t *output){
    //if(scores_len == 0) return 0;
    if(scores_len <= 1){
        memcpy(output, scores, scores_len * sizeof(int32_t));
        return scores_len;
    }
    
    for(size_t i = 0; i < scores_len; i++){
        if(scores[i] > output[0]){
            output[2] = output[1];
            output[1] = output[0];
            output[0] = scores[i];
        }
        else if(scores[i] > output[1]){
            output[2] = output[1];
            output[1] = scores[i];
        }
        else if(scores[i] > output[2]){
            output[2] = scores[i];
        }
        //printf("1: %d 2: %d 3: %d\n", output[0], output[1], output[2]);
    }
    return (scores_len < 3) ? scores_len : 3;

}