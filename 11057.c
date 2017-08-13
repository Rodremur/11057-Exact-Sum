/*-------------------------------------------------------
 * Tarea de Analisis de Algoritmos: 11057 - Exact Sum
 * Fecha: 02-03-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 */

#include <stdio.h>
#include <stdlib.h>
int binarySearch(int *A, int low, int high, int key);

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char const *argv[])
{
	int *books;
	int r1, r2, min;
	int pos;
	int i, k, n, m, diff, s1, s2;
    books = (int*)malloc(10000*sizeof(int*));
    while(scanf("%d", &n) != EOF) {
    r1 = 0;
    r2 = 0;
    min = 100000;
        for (i=0; i<n; i++) {
            scanf("%d", &books[i]);
        }

        scanf("%d", &m);
        qsort(books, n, sizeof(int), compare);

        for (k=0; k<n; k++) {
            if (books[k] < m) {
                pos = binarySearch(books, 0, n-1, m-books[k]);
                if (pos != -1 && pos != k) {
                    s1 = books[k];
                    s2 = m - books[k];
                    diff = abs(s1 - s2);
                    if (min > diff) {
                        r1 = s1;
                        r2 = s2;
                        min = diff;
                    }
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", r1, r2);
    }
    free(books);
    return 0;
}

int binarySearch(int *A, int low, int high, int key) {
    if (low <= high) {
        int mid = (high+low)/2;
        if (key == A[mid]) {
            return mid;
        }
        else if (key < A[mid]) {
            return binarySearch(A, low, mid-1, key);
        }
        else {
            return binarySearch(A, mid+1, high, key);
        }
    }
    return -1;
}
