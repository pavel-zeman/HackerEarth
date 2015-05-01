// Use heap to choose the node with maximum number of edges
// https://www.hackerearth.com/may-easy-challenge-15/algorithm/panda-and-destruction/
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

#define MAX_N 100030

vector<int> neighbors[MAX_N];

int n, m;
int weight[MAX_N];

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


#define HEAP_MAX MAX_N
class Heap {
public:
    int heapSize;
    int position[HEAP_MAX];
    int heap[HEAP_MAX];


    int heapParent(int a) {
        return (a - 1) >> 1;
    }

    int heapLeftChild(int a) {
        return (a << 1) + 1;
    }

    void heapSwap(int a, int b) {
        int temp = heap[a];
        heap[a] = heap[b];
        heap[b] = temp;
        position[heap[a]] = a;
        position[heap[b]] = b;
    }


    bool less(int a, int b) {
        return weight[a] > weight[b] || (weight[a] == weight[b] && a < b);
    }

    void addHeap(int pos) {
        heap[heapSize] = pos;
        position[pos] = heapSize;
        int i = heapSize++;
        while (i > 0 && less(heap[i], heap[heapParent(i)])) {
            heapSwap(i, heapParent(i));
            i = heapParent(i);
        }
    }

    void down(int pos) {
        int i = pos;
        int child = heapLeftChild(i);
        while ((child < heapSize && less(heap[child], heap[i])) || (child + 1 < heapSize && less(heap[child + 1], heap[i]))) {
            int c = child;
            if (child + 1 < heapSize && less(heap[child + 1], heap[child])) c++;
            heapSwap(i, c);
            i = c;
            child = heapLeftChild(i);
        }

    }


    int min(void) {
        int result = heap[0];
        position[result] = -1;
        heap[0] = heap[--heapSize];
        down(0);
        return result;
    }
};


Heap heap;

int main(void) {
    n = getInt();
    m = getInt();
    FOR(i, m) {
        int a = getInt() - 1;
        int b = getInt() - 1;
        neighbors[a].push_back(b);
        neighbors[b].push_back(a);
    }
    FOR(i, n) {
        heap.position[i] = -1;
        weight[i] = neighbors[i].size();
        if (weight[i] > 0) heap.addHeap(i);
    }
    int total = 0;
    while (heap.heapSize > 0) {
        int node = heap.min();
        if (weight[node] <= 0) break;
        FOR(i, (int)neighbors[node].size()) {
            int neigh = neighbors[node][i];
            weight[neigh]--;
            if (heap.position[neigh] >= 0) heap.down(heap.position[neigh]);
        }
        total++;
    }
    printf("%d\n", total);
}
