/* 
    524. Longest Word in Dictionary through Deleting 

    Given a string and a string dictionary, 
    find the longest string in the dictionary that 
    can be formed by deleting some characters of the given string. 
    If there are more than one possible results, 
    return the longest word with the smallest lexicographical order. 
    If there is no possible result, return the empty string. 
*/
#include <bits/stdc++.h>
using namespace std;


/* string sort */
int cmp_func(const void * _a, const void * _b){
    const char * a = *(const char**)_a;
    const char * b = *(const char**)_b;
    int ret = 0;

    for(;*a!='\0' && *b!='\0';){
        if(!ret && *a != *b){
            if(*a < *b) ret = -1;
            else ret = 1;
        }
        a++;
        b++;
    }
    if(*a == '\0' && *b == '\0') return ret;
    if(*a == '\0') return 1;
    return -1;
}

char* findLongestWord(char* s, char** d, int dSize) {
    qsort(d, dSize, sizeof(char*), cmp_func);
    /* two pointers */
    for(int i = 0;i<dSize;i++){
        char*p,*q;
        for(p=s,q=d[i];*p && *q;p++){
            if(*q == *p) 
                q++;
        }
        if(!*q) return d[i];
    }
    return "";
}

int main(void){
    int n;
    char *ss[] = {
        "apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"
    };
    puts(findLongestWord("aewfafwafjlwajflwajflwafj", ss, 6));

    getchar();
    return 0;
}