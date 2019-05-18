/*
Эффективен для больших n. В худшем случае требуется n·log2n шагов, сдвигающих элементы. 
Среднее число перемещений: (n/2)·log2n, отклонения от этого значения относительно невелики
*/

#include <stdio.h>
#include <stdlib.h>

# define N 10

void downsift(int* unit, int root, int limit)
{
	int index_min; 
	bool done = false; 

	while ((root * 2 <= limit) and (!done))
	{
		if (root * 2 == limit)    
			index_min = root * 2;   
		else if (unit[root * 2] > unit[root * 2 + 1])
			index_min = root * 2;
		else
			index_min = root * 2 + 1;
		
		if (unit[root] < unit[index_min])
		{
			int temp = unit[root]; 
			unit[root] = unit[index_min];
			unit[index_min] = temp;
			root = index_min;
		}
		else 
			done = true;
	}
}


void heapsort(int* unit, int ar_size)
{
	for (int i = (ar_size / 2) - 1; i >= 0; i--)
		downsift(unit, i, ar_size - 1);
	
	for (int i = ar_size - 1; i >= 1; i--)
	{
		int temp = unit[0];
		unit[0] = unit[i];
		unit[i] = temp;
		downsift(unit, 0, i - 1);
	}
}
int main()
{
	int ar[N];
	
	for (int i = 0; i < N; i++)
		ar[i] = rand() % 100 - 10;
	
	for (int i = 0; i < N; i++)
		printf("%d ", ar[i]);
	printf("\n");

	heapsort(ar, N); 

	for (int i = 0; i < N; i++)
		printf("%d ", ar[i]);
	printf("\n");
	
	getchar();
	return 0;
}