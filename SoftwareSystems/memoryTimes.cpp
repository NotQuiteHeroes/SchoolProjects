/*
Paige Eckstein
Software Systems
This program illustrates the time taken to declare an array of 100,000 elements 10,000 times statically, on the stack, and on the heap
*/

#include<iostream>
#include<ctime>

using namespace std;

void staticArray();
void stackArray();
void heapArray();

int main()
{
	//variables to hold clock ticks for each function time
	clock_t staticStart, staticFinish, stackStart, stackFinish, heapStart, heapFinish;
	

	/*
	Starts Clock, calls each function 10,000 times which in turn declares each
	array, initializing 100000 elements to 0. Stops clock
	*/
	
	staticStart = clock();
	for(int i = 0; i < 10000; i++)
	{
		staticArray();
	}
	staticFinish = clock();
	
	stackStart = clock();
	for(int j = 0; j < 10000; j++)
	{
		stackArray();
	}
	stackFinish = clock();
	
	heapStart = clock();
	for(int k = 0; k < 10000; k++)
	{
		heapArray();
	}
	heapFinish = clock();
	
	//Print out time taken to call each function 10,000x - measured in milliseconds
	cout<<"Static time: "<<((staticFinish - staticStart)/(double)(CLOCKS_PER_SEC/1000))<<"ms"<<endl;
	cout<<"Stack time: "<<((stackFinish - stackStart)/(double)(CLOCKS_PER_SEC/1000))<<"ms"<<endl;
	cout<<"Heap time: "<<((heapFinish - heapStart)/(double)(CLOCKS_PER_SEC/1000))<<"ms"<<endl;
	
	return 0;
}

//declares static array with 100,000 elements initialized to 0
void staticArray()
{
	
	static int a[100000] = {0};

}

//declares array on the stack with 100,000 elements initialized to 0
void stackArray()
{
	int b[100000] = {0};	
}

//declares array on the heap with 100,000 elements initialized to 0
void heapArray()
{
	int *c = new int[100000];
}
