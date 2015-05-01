// Goal is to calculate N in base M (and there is a special case, when M = 1)
// https://www.hackerearth.com/may-easy-challenge-15/algorithm/panda-and-combination/
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
    int t = getInt();
    FOR(tt, t) {
        long long int n = getLongLongInt();
        long long int m = getLongLongInt();
        if (m == 1) printf("%lld\n", n); else {
            long long int result = 0;
            while (n > 0) {
                result += n % m;
                n /= m;
            }
            printf("%lld\n", result);
        }
    }
}
