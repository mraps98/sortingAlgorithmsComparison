/* Reference : https://github.com/TheAlgorithms/C/blob/master/sorting/shaker_sort.c */

public class Shaker{
	private static void swap(long a, long b)
	{
		long temp;
		temp = a;
		a = b;
		b = temp;
	}
	public static void shaker_sort(long a[], int n)
	{
		int p, i;
		for (p = 1; p <= n / 2; p++)
		{
			for (i = p - 1; i < n - p; i++)
				if (a[i] > a[i + 1])
				{
					swap(a[i], a[i + 1]);
				}
			for (i = n - p - 1; i >= p; i--)
				if (a[i] < a[i - 1])
				{
					swap(a[i], a[i - 1]);
				}
		}
	}
}