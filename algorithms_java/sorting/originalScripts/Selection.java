/* Reference: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/06-elementary_sorting_methods/6.02-selection_sort/examples/prog-6.2-selection_sort.c */
public class Selection{
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
	
	public static void selection_sort(long a[], int l, int r)
	{
	  for (int i = l; i < r; i++)
		{
		  int min = i;
		  for (int j = i+1; j <= r; j++)
			if (less(a[j], a[min])) min = j;
		  exch(a[i], a[min]);
		}
	}
}