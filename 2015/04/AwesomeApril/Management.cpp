// Brute force solution just for the small input
// https://www.hackerearth.com/awesome-april-15/algorithm/xsquare-and-management/
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

#define MAX_N 500010


int n, m;

vector<int> neighbor[MAX_N];
int component[MAX_N];
bool used[MAX_N];
int componentLength[MAX_N];
int componentSize[MAX_N];
int maxDepthVertex[MAX_N][2];
int dist[MAX_N][2];
int currentComponent;
int maxDepth;
int selectedNode;
int currentSize;
int dpt[MAX_N];
int componentDepth[MAX_N];
int componentRoots[MAX_N];


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


void visit(int node, int parent) {
    currentSize++;
    used[node] = true;
    component[node] = currentComponent;
    FOR(i, (int)neighbor[node].size()) {
        int n = neighbor[node][i];
        if (n != parent) visit(n, node);
    }
}

void calcDepth(int node, int parent, int depth) {
    if (depth > maxDepth) {
        maxDepth = depth;
        selectedNode = node;
    }
    FOR(i, (int)neighbor[node].size()) {
        int n = neighbor[node][i];
        if (n != parent) calcDepth(n, node, depth + 1);
    }
}

void calcDistance(int node, int parent, int run, int depth) {
    dist[node][run] = depth;
    FOR(i, (int)neighbor[node].size()) {
        int n = neighbor[node][i];
        if (n != parent) calcDistance(n, node, run, depth + 1);
    }
}

int calcDepth(int node, int parent) {
    int maxDepth = 0;
    FOR(i, (int)neighbor[node].size()) {
        int n = neighbor[node][i];
        if (n != parent) {
            int temp = calcDepth(n, node);
            if (temp + 1 > maxDepth) maxDepth = temp + 1;
        }
    }
    return maxDepth;
}


int main(void) {
    int t = getInt();
    FOR(tt, t) {
        n = getInt();
        m = getInt();
        FOR(i, n) neighbor[i].clear();
        FOR(i, m) {
            int u = getInt() - 1;
            int v = getInt() - 1;
            neighbor[u].push_back(v);
            neighbor[v].push_back(u);
        }
        FOR(i, n) used[i] = false;
        currentComponent = 0;
        FOR(i, n) {
            if (!used[i]) {
                currentSize = 0;
                visit(i, i);
                currentComponent++;
                //componentSize[currentComponent] = currentSize;
                /*if (currentSize == 1) componentLength[currentComponent] = 0;
                else if (currentSize == 2) componentLength[currentComponent] = 1;
                else {
                    maxDepth = 0;
                    calcDepth(i, i, 0);
                    maxDepthVertex[currentComponent][0] = selectedNode;
                    maxDepth = 0;
                    calcDepth(selectedNode, selectedNode, 0);
                    maxDepthVertex[currentComponent][1] = selectedNode;
                    componentLength[currentComponent] = maxDepth;

                    calcDistance(maxDepthVertex[currentComponent][0], maxDepthVertex[currentComponent][0], 0, 0);
                    calcDistance(maxDepthVertex[currentComponent][1], maxDepthVertex[currentComponent][1], 1, 0);

                    find
                }
                currentComponent++;*/
            }
        }
        int totalComponents = currentComponent;
        FOR(i, n) {
            dpt[i] = calcDepth(i, i);
        }
        FOR(i, totalComponents) componentDepth[i] = 100000000;
        FOR(i, n) {
            if (dpt[i] < componentDepth[component[i]]) componentDepth[component[i]] = dpt[i];
        }
        int maxDepth = 0;
        FOR(i, totalComponents) if (componentDepth[i] > maxDepth) maxDepth = componentDepth[i];
        FOR(i, totalComponents) componentRoots[i] = 0;
        FOR(i, n)
            if (dpt[i] <= maxDepth) componentRoots[component[i]]++;
        long long int total = 1;
        FOR(i, totalComponents) {
            total = total * componentRoots[i] % 1000000007;
        }
        printf("%lld\n", total);
    }
}
