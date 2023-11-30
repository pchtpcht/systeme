#include<stdio.h>

#include "pair.h"

int impair(int i){
    if(i==0) return 0;
    else return pair(i-1);
}