// Precalculate factorials up to MOD. For biggenr N, the answer is always 0.
// https://www.hackerearth.com/may-easy-challenge-15/algorithm/panda-and-chain-reaction/
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

#define MOD 1000003

int fact[MOD];


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
    fact[0] = 1;
    FORE(i, 1, MOD) fact[i] = ((long long int )i) * fact[i - 1] % MOD;

    int t = getInt();
    FOR(tt, t) {
        long long int n = getLongLongInt();
        long long int x = getLongLongInt() % MOD;
        printf("%d\n", n >= MOD ? 0 : (int)(x * fact[n] % MOD));
    }
}
