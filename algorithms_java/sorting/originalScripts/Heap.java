/* Reference: https://github.com/caisah/Sedgewick-algorithms-in-c-exercises-and-examples/blob/master/09-priority_queues_and_heapsort/9.04-heapsort/prog_9.7-heapsort/main.c*/

public class Heap{
	private static boolean less(long A, long B){
		return (A < B);
	}
	
	private static void exch(long A, long B){
		long t = A;
		A = B;
		B = t;
	}
	
	private static void fixUp(long a[], int k)
	{
	  while (k > 1 && less(a[k/2], a[k]))
		{
		  exch(a[k], a[k/2]);
		  k = k/2;
		}
	}

	private static void fixDown(long a[], int k, int N)
	{
	  int j;

	  while (2*k <= N)
		{
		  j = 2*k;
		  if (j < N && less(a[j], a[j+1]))
		j++;
		  if (!less(a[k], a[j]))
		break;
		  exch(a[k], a[j]);
		  k = j;
		}
	}

	public static void heap_sort(long a[], int l, int r)
	{
		int k, N = r-l+1;
		long[] pq = new long[100];
		pq[0] = a[l-1];

	  for (k = N/2; k >= 1; k--)
		fixDown(pq, k, N);
	  while (N > 1)
		{
		  exch(pq[1], pq[N]);
		  fixDown(pq, 1, --N);
		}
	}
}