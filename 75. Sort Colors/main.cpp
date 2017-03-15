/* 
    75. Sort Colors 
    Given an array with n objects colored red, white or blue, 
    sort them so that objects of the same color are adjacent,
    with the colors in the order red, white and blue.

    Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

*/

#include <bits/stdc++.h>
using namespace std;

int cmp_func(const void * a, const void * b){
    return *(int*)a - *(int*)b;
}
/* qsort  O(NlogN) */
void sortColors(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp_func);
}

/* count O(N) */
void sortColors(int* nums, int numsSize) {
    int counts[3] = {0};
    for(int i=0;i<numsSize;counts[nums[i++]]++);
    for(int i=0, j=0;j<3;j++)
        for(;counts[j];counts[j]--)
            nums[i++] = j;
}

int main(void){
    int colors[] = {0,1,1,2,0,2,0,1,1,1,0,2,0};
    int n = sizeof(colors)/sizeof(int);

    sortColors(colors, n);
    for(int i = 0;i<n;i++){
        printf("%d ", colors[i]);
    }
    puts("");

    getchar();
    return 0;
}