// Sort the numbers and then use interval halving to find the requested number
// https://www.hackerearth.com/awesome-april-15/algorithm/xsquare-and-number-list/
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

char getChar() {
    while (c != '<' && c != '>' && c != '=') c = getc_unlocked(stdin);
    return c;
}

long long int mul(long long int a, long long int power) {
    long long int res = 1;
    while (power > 0) {
        if ((power & 1) == 1) res = res * a % MOD;
        a = a * a % MOD;
        power >>= 1;
   }
   return res;
}

int main(void) {
    int n = getInt();
    int q = getInt();
    s.reserve(n);
    FOR(i, n) s.push_back(getInt());
    sort(s.begin(), s.end());
    long long int all = mul(2, n);
    FOR(i, q) {
        char op = getChar();
        int k = getInt();
        vector<int>::iterator first;
        switch (op) {
            case '<':
                first = lower_bound(s.begin(), s.end(), k);
                printf("%lld\n", mul(2, first - s.begin()));
                break;

            case '=':
                first = lower_bound(s.begin(), s.end(), k);
                if (*first != k) printf("0\n"); else {
                    vector<int>::iterator next = lower_bound(s.begin(), s.end(), k + 1);
                    long long int resNext = mul(2, next - s.begin());
                    long long int resFirst = mul(2, first - s.begin());
                    printf("%lld\n", (resNext - resFirst + MOD) % MOD);
                }
                break;

            case '>':
                first = lower_bound(s.begin(), s.end(), k + 1);
                printf("%lld\n", (all - mul(2, first - s.begin()) + MOD) % MOD);
                break;
        }
    }

}
