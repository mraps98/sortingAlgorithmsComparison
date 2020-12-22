/* Reference: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/06-elementary_sorting_methods/6.04-bubble_sort/examples/prog_6.4-bubble_sort.c*/

public class Bubble{
	
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
	
	public static void bubble_sort(long a[], int l, int r)
	{
	  int i, j;

	  for (i = l; i < r; i++)
		for (j = r;  j > i; j--)
		  compexch(a[j-1], a[j]);
	}
}