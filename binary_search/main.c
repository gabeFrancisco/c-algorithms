#include <stdio.h>

int binary_search(int list[], int list_size, int item){
	int low = 0;
	int high = list_size- 1;

	while(low <= high){
		int middle = (low + high) / 2;
		int shot = list[middle];

		if(shot == item){
			return shot;
		}
		if (shot > item){
			high = middle - 1;
		}
		else{
			low = middle + 1;
		}
	}

	return 0;
}

int main(void){
	printf("Binary Search\n");

	int list[7] = {1,3,7,12,22,24,33};
	int listSize = sizeof(list) / sizeof(list[0]);
	// int i;
	// for(i=0; i<listSize; i++){
	// 	printf("\n%d", list[i]);
	// }

	printf("Now let's make a search!");
	printf("Result of binary search: %d\n", binary_search(list, listSize, 7));

}
