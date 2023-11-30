#include<stdio.h>
#include "pair.h"

int pair(int i){
    if (i==0) return 1;
    else return impair(i-1);
}
