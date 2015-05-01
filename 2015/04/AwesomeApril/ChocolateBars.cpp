// Test strings starting at positions 0, 1 and 2
// https://www.hackerearth.com/awesome-april-15/algorithm/xsquare-and-chocolates-bars-2/
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

#define MAX_S 1000010

char s[MAX_S];


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

int getString() {
    int pos = 0;
    while (!(c >= 'A' && c <= 'Z')) c = getc_unlocked(stdin);
    while (c >= 'A' && c <= 'Z') {
        s[pos++] = c;
        c = getc_unlocked(stdin);
    }
    return pos;
}



int main(void) {
    int t = getInt();
    FOR(tt, t) {
        int size = getString();
        int max = 0;
        FOR(i, 3) {
            int start = i;
            while (start + 3 <= size) {
                int currentSize = 0;
                while (start + 3 <= size) {
                    if (s[start] != s[start + 1] || s[start] != s[start + 2]) {
                        currentSize += 3;
                        start += 3;
                    } else {
                        start += 3;
                        break;
                    }
                }
                if (currentSize > max) max = currentSize;
            }
        }
        printf("%d\n", size - max);
    }
}
