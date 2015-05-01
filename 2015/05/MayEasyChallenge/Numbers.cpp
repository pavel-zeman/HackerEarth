// Iteratively pre-calculate the results one by one
// https://www.hackerearth.com/may-easy-challenge-15/algorithm/panda-and-numbers/
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

#define MAX_N 1000010

bool ok[MAX_N];


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

long long int getLongLongInt() {
    long long int r = 0;
    while (!(c >= '0' && c <= '9')) c = getc_unlocked(stdin);
    while (c >= '0' && c <= '9') {
        r = r * 10 + (c - '0');
        c = getc_unlocked(stdin);
    }
    return r;
}


int main(void) {
    FOR(i, MAX_N) ok[i] = false;
    ok[1] = ok[4] = ok[27] = ok[256] = ok[3125] = ok[46656] = ok[823543] = true;
    FORE(i, 1, MAX_N) if (!ok[i]) {
        int x = i;
        while (x > 0) {
            int m = x % 10;
            int test = i - m * m;
            if (test > 0 && ok[test]) {
                ok[i] = true;
                break;
            }
            x /= 10;
        }
    }
    int t = getInt();
    FOR(tt, t) {
        int n = getInt();
        puts(ok[n] ? "Yes" : "No");
    }
}
