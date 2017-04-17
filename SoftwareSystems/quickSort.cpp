/*
Paige Eckstein
Software Systems 
10/4/16
This program illustrates Quicksort with recursion, and without recursion
*/

#include <iostream>

int partition(int arrayToSort[], int left, int right);
void quickSortRecursive(int toSort1[], int left, int right);
void quickSortIterative(int toSort2[], int left, int right);
void printArray(int arrayToPrint[]);

//Partition application used by both recursive and iterative versions
int partition(int arrayToSort[], int left, int right)
{
	//set pivot point to first element in array
	int pivot = arrayToSort[left];
	
	while(true)
	{
		//while element is less than pivot, move element to the right
		while(arrayToSort[left] < pivot)
		{
			left++;
		}
		
		//while element is greater than pivot, move element to the left
		while(arrayToSort[right] > pivot)
		{
			right--;
		}
		
		//if left is less than right, swap the two elements are their given
		//positions
		if( left < right)
		{
			std::swap(arrayToSort[left], arrayToSort[right]);
		}
		else
		{
			return right;
		}
	}
}

//recursive quick sort, left is beginning of array, right is end of array
void quickSortRecursive(int toSort1[], int left, int right)
{
	if(left < right)
	{
		int localPartition = partition(toSort1, left, right);
		quickSortRecursive(toSort1, left, localPartition-1);
		quickSortRecursive(toSort1, localPartition+1, right);
	}
}

//iterative quick sort
void quickSortIterative(int toSort2[], int left, int right)
{
	//emulates stack from recursive version
	
	int start = left;
	int end = right;
	int top = -1;
	int* stack = new int[10];
	
	//'push' start and end values to stack
	stack[++top] = start;
	stack[++top] = end;
	
	//while stack isn't empty
	while(top >= 0)
	{
		//'pop' end and start values from stack
		end = stack[top--];
		start = stack[top--];
		
		int localPartition = partition(toSort2, start, end);
		
		//emulate first recursive call in standard quicksort
		//will change end position to localPartition - 1
		if(localPartition - 1 > start)
		{
			stack[++top] = start;
			stack[++top] = localPartition - 1;
		}
		
		//emulate second recursive call in standard quicksort
		//will change start position to localPartition + 1
		if(localPartition + 1 < end)
		{
			stack[++top] = localPartition + 1;
			stack[++top] = end;
		}
	}
	
	//free space allocated with new
	delete[] stack;
}

void printArray(int arrayToPrint[])
{
	for(int i = 0; i < 10; i++)
	{
		std::cout<<arrayToPrint[i]<<" ";
	}
}

int main()
{
	int toSort1[10] = {4, 2, 8, 16, 3, 9, 5, 6, 11, 20};
	int toSort2[10] = {10, 9, 4, 13, 25, 42, 34, 22, 19, 7};
	
	std::cout<<"Recursive QuickSort:"<<std::endl;
	std::cout<<"Before sorting: ";
	printArray(toSort1);
	std::cout<<std::endl;
	std::cout<<"After sorting: ";
	quickSortRecursive(toSort1, 0, 9);
	printArray(toSort1);
	std::cout<<std::endl;
	
	std::cout<<"Iterative QuickSort:"<<std::endl;
	std::cout<<"Before sorting: ";
	printArray(toSort2);
	std::cout<<std::endl;
	std::cout<<"After sorting: ";
	quickSortIterative(toSort2, 0, 9);
	printArray(toSort2);
	std::cout<<std::endl;
	
	return 0;
}