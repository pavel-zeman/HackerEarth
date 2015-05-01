// Nothing special
// https://www.hackerearth.com/practice-challenge/algorithm/eab008eed22dc06e6280a2b6dbb042e0/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <vector>
#include <map>

using namespace std;

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)


char c = 0;
int getInt() {
    int r = 0;
    while (!(c >= '0' && c <= '9')) c = getc_unlocked(stdin);
    while (c >= '0' && c <= '9') {
        r = r * 10 + (c - '0');
        c = getc_unlocked(stdin);
    }
    return r;
}



int main(void) {
    int t = getInt();
    FOR(tt, t) {
        int n = getInt();
        FORE(i, 1, n + 1) {
            if (i % 3 != 0 && i % 5 != 0) printf("%d", i);
            if (i % 3 == 0) printf("Fizz");
            if (i % 5 == 0) printf("Buzz");
            printf("\n");
        }
    }
}
