#include <iostream>

#include "task.h"

using namespace std;

int toBinary(int n, int b)
{
    int count = 0;
    if (b > n){
        return -1;
    }
    for (int j = n; j <= b; ++j) {
        int i = j;
        while (i != 0) {
            if (i % 2 == 1){
                count += 1;
            }
            i /= 2;
        }
    }
    return count;
}

