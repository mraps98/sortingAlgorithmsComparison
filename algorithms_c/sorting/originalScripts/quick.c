/* Source: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/07-quicksort/7.01-the_basic_algorithm/examples/prog_7.1-7.2-quicksort.c */
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}

int partition(Item a[], int l, int r)
{
  int i = l-1, j = r;
  Item v = a[r];

  for (;;)
    {
      while (less(a[++i], v));
      while (less(v, a[--j]))
	if (j == l)
	  break;
      if (i >= j)
	break;
      exch(a[i], a[j]);
    }
  exch(a[i], a[r]);
  return i;
}

void quicksort(Item a[], int l, int r)     
{
  int i;

  if (r <= l)
    return;
  i = partition(a, l, r);
  quicksort(a, l, i-1);
  quicksort(a, i+1, r);
}

int main(int argc, char *argv[]) 
{
  int i, N, sw;
  int *a = malloc(N*sizeof(int));

  srand(time(NULL));
  if (argc < 3)
    printf("You have not entered enough arguments: N and sw required!\n ");
  else
    {
      N = atoi(argv[1]);
      sw = atoi(argv[2]);
      if (sw)
	for (i = 0; i < N; i++)
	  a[i] = 1000 * (1.0*rand()/RAND_MAX);
      else
	while (scanf("%d", &a[N]) == 1)
	  N++;
      printf("Initial: ");
      for(i = 0; i < N; i++)
	printf("%3d ", a[i]);
      printf("\nAfter: ");
      quicksort(a, 0, N-1);
      for(i = 0; i < N; i++)
	printf("%3d ", a[i]);
      printf("\n");
    }
  return 0;
}