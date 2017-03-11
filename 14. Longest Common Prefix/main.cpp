/* 
    14. Longest Common Prefix
    Write a function to find the longest common prefix string amongst an array of strings. 
*/

#include <bits/stdc++.h>
using namespace std;


/*
    traverse and compare
*/
char* longestCommonPrefix(char** strs, int strsSize) {
    int len = 0;
    for(;strsSize;len++){
        if(strs[0][len] == '\0') break;
        int i;
        /* compare the len st position */
        for(i=1;i<strsSize;i++){
            if(strs[0][len] != strs[i][len])
                break;
        }
        if(i<strsSize) break;
    }
    char *ret = (char *)malloc(sizeof(char)*len);
    memcpy(ret, strs[0], len);
    ret[len] = '\0';
    return ret;
}

int main(void){
    char *ss[] = {"1234","123555","12567"};
    puts(longestCommonPrefix(ss,3));
    return 0;
}