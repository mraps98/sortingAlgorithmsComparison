/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/08-merging_and_mergesort/8.03-top_down_mergesort/examples/prog_8.3-top_down_mergesort.c */
#ifndef MERGE_H
#define MERGE_H
typedef long Item;

void merge(Item a[], int l, int m, int r);
void merge_sort(Item a[], int l, int r);
#endif