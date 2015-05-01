// Calculate maximum of all pairs
// https://www.hackerearth.com/awesome-april-15/algorithm/xsquare-and-array-operations/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define FOR(c, m) for(int c=0;c<(m);c++)
#define FORE(c, f, t) for(int c=(f);c<(t);c++)

#define MAX_S 1000010
#define MOD 1000000007

vector<int> s;



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


int max(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int t = getInt();
    FOR(tt, t) {
        int n = getInt();
        long long int total = 0;
        int last = 0;
        FOR(i, n) {
            int next = getInt();
            if (i != 0) {
                total += max(last, next);
            }
            last = next;
        }
        printf("%lld\n", total);
    }
}
