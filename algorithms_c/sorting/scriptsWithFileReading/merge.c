/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/08-merging_and_mergesort/8.03-top_down_mergesort/examples/prog_8.3-top_down_mergesort.c */
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#include "merge.h"

#define key(A) (A)
#define less(A, B) (key(A) < key(B))

typedef long Item;

long *aux;

void merge(Item a[], int l, int m, int r)
{
  int i, j, k;

  for (i = m+1; i > l; i--)
    aux[i-1] = a[i-1];
  for (j = m; j < r; j++)
    aux[r+m-j] = a[j+1];
  for (k = l; k <= r; k++)
    if (less(aux[j], aux[i]))
      a[k] = aux[j--];
    else
      a[k] = aux[i++];
}

void merge_sort(Item a[], int l, int r)
{
  int m = (r+l)/2;

  if (r <= l) return;
  merge_sort(a, l, m);
  merge_sort(a, m+1, r);
  merge(a, l, m, r);
}