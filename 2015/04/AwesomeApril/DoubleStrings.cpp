// Create histogram of characters - the string is double, if at least one character exists at least twice
// https://www.hackerearth.com/awesome-april-15/algorithm/xsquare-and-double-strings-1/
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

#define MAX_S 200

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
    while (!(c >= 'a' && c <= 'z')) c = getc_unlocked(stdin);
    while (c >= 'a' && c <= 'z') {
        s[pos++] = c;
        c = getc_unlocked(stdin);
    }
    return pos;
}



int main(void) {
    int t = getInt();
    FOR(tt, t) {
        int size = getString();
        char count[MAX_S];
        FOR(i, MAX_S) count[i] = 0;
        bool found = false;
        FOR(i, size) {
            count[s[i]]++;
            if (count[s[i]] >= 2) {
                found = true;
                break;
            }
        }
        puts(found ? "Yes": "No");
    }
}
