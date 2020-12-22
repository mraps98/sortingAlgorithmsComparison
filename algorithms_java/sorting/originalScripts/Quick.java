/* Reference: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/07-quicksort/7.01-the_basic_algorithm/examples/prog_7.1-7.2-quicksort.c */
public class Quick{
	private static boolean less(long A, long B){
		return (A < B);
	}
	
	private static void exch(long A, long B){
		long t = A;
		A = B;
		B = t;
	}
	
	private static int partition(long a[], int l, int r)
	{
	  int i = l-1, j = r;
	  long v = a[r];

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

	public static void quick_sort(long a[], int l, int r)     
	{
	  int i;

	  if (r <= l)
		return;
	  i = partition(a, l, r);
	  quick_sort(a, l, i-1);
	  quick_sort(a, i+1, r);
	}
}