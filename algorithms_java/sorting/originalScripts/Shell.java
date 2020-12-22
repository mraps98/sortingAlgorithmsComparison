/* Reference: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/06-elementary_sorting_methods/6.06-shell_sort/examples/prog-6.5-shellsort.c */
public class Shell{
	private static boolean less(long A, long B){
		return (A < B);
	}
	
	private static void exch(long A, long B){
		long t = A;
		A = B;
		B = t;
	}
	
	private static void compexch(long A, long B){
		if(less(B, A)){
			exch(A, B);
		}
	}
	
	public static void shell_sort(long a[], int l, int r)
	{
	  int i, j, h;

	  for (h = 1; h <= (r-l)/9; h = 3*h+1);
	  for ( ; h > 0; h /= 3)
		  for (i = l+h; i <= r; i++)
		{
		  j = i;
		  long  v = a[i];

		  while (j >= l+h && less(v, a[j-h]))
			{
			  a[j] = a[j-h];
			  j -= h;
			}
		  a[j] = v;
		}
	}
	
}