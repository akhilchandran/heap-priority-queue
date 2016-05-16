/*
 * time complexity
 * 
 * time complexity: O(NlogN)
 * 
 */
#include <stdio.h>
/* when index count from 0
 * left child index = 2*index+1,
 * right child index = 2*index+2, 
 * parent index for any child is = (index - 1)/2.
 */
int heapify(int list[], int index, int length);

int extract_maximum (int list[], int *listsize)
{
	if(*listsize == 0){
		return -1;
    	}
    	int max = list[0];
    	list[0] = list[*listsize - 1];
	*listsize = *listsize -1;
	heapify(list, 0, *listsize);
	return max;
}

void increase_val(int list[], int index, int val, int length)
{
	list[index] = val;
	int parent = (index - 1)/2;
	while(heapify(list, parent, length)){
		parent = (parent - 1)/2;
	}
}

void insert_value (int list[], int *length, int val)
{
	*length = *length + 1;
	list[*length - 1] = val;
	increase_val (list, *length - 1, val, *length);
}

void makeheap(int list[], int length)
{
	int i;
	for(i = length/2; i >= 0; i--){//since index is length-1;
		heapify(list, i, length);
	}
}

int heapify(int list[], int index, int length)
{
	int left, right, largest, temp;
	left = 2*index + 1;
	right = 2*index + 2;
	largest = index;
	if(left < length && list[left] > list[index]){
		largest = left;
	}
	if(right < length && list[right] > list[largest]){
		largest = right;
	}
	if(largest != index){
		temp = list[index];
		list[index] = list[largest];
		list[largest] = temp;
		heapify(list, largest, length);
		return 1;
	}
	return 0;
}

void heapsort(int list[], int length)
{
	int i, temp;
	//makeheap(list, length);
	for(i = length - 1; i > 0; i--){
		temp = list[0];
		list[0] = list[i];
		list[i] = temp;
		heapify(list, 0, i);
	}	
}

int main()
{
	int a[12];// {65,87,77,99,31,989,2143};
	int length = 0;
	insert_value(a, &length, 65);
	printf("maximum priority of [65] is: %d\n", extract_maximum(a, &length));
	insert_value(a, &length, 65);
	insert_value(a, &length, 87);
	insert_value(a, &length, 77);
	insert_value(a, &length, 99);
	insert_value(a, &length, 31);
	insert_value(a, &length, 989);
	insert_value(a, &length, 2143);
	printf("maximum of [65, 87, 77, 99, 31, 989, 2143] is :%d\n", extract_maximum(a, &length));
	printf("next maximum of [65, 87, 77, 99, 31, 989, 2143] is :%d\n", extract_maximum(a, &length));
	printf("next maximum of [65, 87, 77, 99, 31, 989, 2143] is :%d\n", extract_maximum(a, &length));
	printf("next maximum of [65, 87, 77, 99, 31, 989, 2143] is :%d\n", extract_maximum(a, &length));
	printf("next maximum of [65, 87, 77, 99, 31, 989, 2143] is :%d\n", extract_maximum(a, &length));
	printf("next maximum of [65, 87, 77, 99, 31, 989, 2143] is :%d\n", extract_maximum(a, &length));
	printf("next maximum of [65, 87, 77, 99, 31, 989, 2143] is :%d\n", extract_maximum(a, &length));
}
