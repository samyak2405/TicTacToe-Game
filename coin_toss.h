#ifndef cointoss
#define cointoss
#include<bits/stdc++.h>
using namespace std;
int coinToss(void)
{
    srand((time(0)));
    int randomNumber;
    randomNumber = 1+rand()%2;
    return randomNumber;
}
#endif