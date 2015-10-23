//
//  main.cpp
//  getLargestPerm
//
//  Created by LiLingyu on 15/10/22.
//  Copyright © 2015年 LiLingyu. All rights reserved.
//

/*
 input: an integer n
 output: the largest perm of n, less than n
 else return 0
 */




#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

static void int2string(int n, char* a)
{
    int i=0;
    for (i=0; n!=0; i++) {
        int tmp = n%10;
        a[i] = tmp+'0';
        n/=10;
    }
    
    a[i]='\0';
    
    for (int j=0; j<(i)/2; j++) {
        char ch = a[j];
        
        a[j] = a[(i-1)-j];
        
        a[(i-1)-j] = ch;
    }
}

static void swap(char* a, char* b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

static bool compare(char a, char b)
{
    return a>b;
}

int getLargestPerm(int n)
{
    
    
    int result =0;
    
    char a[100];
    char bk[100];
    
    int2string(n, bk);
    int2string(n, a);
    int len = (int)strlen(a);
    
    if(1==len)
        return 0;
    
    if (2==len) {
        if (a[0]>a[1]) {
            swap(&a[0], &a[1]);
            
        }
    }
    
    int i;
    for (i=1; i<len-1; i++) {
        if (a[i]>a[i-1] && a[i]>a[i+1]) {
            break;
        }
    }
    
    int j;
    int maxi = (i+1<len)?(i+1):len-1;
    for (j=i+1; j<len; j++) {
        if (a[j]>a[maxi]) {
            maxi = j;
        }
    }
    
    while (i>=0) {
        
        if(a[i]>a[maxi])
            break;
        i--;
    }
    if (i<0) {
        return 0;
    }
    
    if (i>=0) {
        swap(&a[i], &a[maxi]);
    }
    
    std::sort(a+i+1, a+len, compare);
    
    if (0==strcmp(a, bk)) {
        return 0;
    }
    else
        return atoi(a);
    
    
    
    return result;
}

int main(int argc, const char * argv[]) {
    
    /*
     sample input output
     165    156
     7123   3721
     8918   8891
     23     0
     103    0
     */
    int n=103;
    
    int result = getLargestPerm(n);
    
    printf("input: %d\n", n);
    printf("result: %d\n", result);
    
    return 0;
}
