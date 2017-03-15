/* 
    69. Sqrt(x) 
    Implement int sqrt(int x).
    Compute and return the square root of x.
*/

#include <bits/stdc++.h>
using namespace std;

/*
    binary search
*/
int mySqrt(int x) {
    unsigned long long l,r,m;
    l = 0, r = x;
    for(;l <= r;){
        m = (l+r)>>1;
        //printf("(%d,%d) m:%d\n",l,r,m);
        if(m*m == x)
            return m;
        if(m*m < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return m*m>x?m-1:m;
}

int main(void){
    int x;
    for(;~scanf("%d",&x);){
        printf("sqrt(%d) = %d\n",x,mySqrt(x));
    }
    return 0;
}