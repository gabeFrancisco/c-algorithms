/*
	The Binary Search is a O(log n) algorithm in the worst case possible,
	but it has chances to find the value earlier.
*/

#include <stdio.h>

// Struct for a custom method return type
typedef struct
{
	int value;
	int index;
	int interactions;
	int found;
} SearchResult;

SearchResult binary_search(int list[], int list_size, int item)
{
	// The lowest possible value in the array
	int low = 0;

	// The highest value in the array - 1 because arrays starts in 0
	int high = list_size - 1;

	// Initializes the SearchResult struct with standard values
	SearchResult res = {0, 0, -1, 0};

	while (low <= high)
	{
		res.interactions++;

		int middle = (low + high) / 2;
		int shot = list[middle];

		if (shot == item)
		{
			// Return the found value with the SearchResult template
			res.value = shot;
			res.index = middle;
			res.found = 1;

			return res;
		}
		if (shot > item)
		{
			high = middle - 1;
		}
		else
		{
			low = middle + 1;
		}
	}

	return res;
}

int main(void)
{
	printf("Binary Search\n");

	int list[100] = {
		3, 4, 5, 7, 9, 11, 13, 14, 16, 18,
		20, 22, 23, 25, 27, 29, 31, 33, 35, 36,
		38, 40, 42, 44, 46, 48, 50, 52, 54, 55,
		57, 59, 61, 63, 65, 67, 69, 71, 73, 75,
		77, 79, 81, 83, 85, 87, 89, 91, 93, 95,
		97, 99, 101, 103, 105, 107, 109, 111, 113, 115,
		117, 119, 121, 123, 125, 127, 129, 131, 133, 135,
		137, 139, 141, 143, 145, 147, 149, 151, 153, 155,
		157, 159, 161, 163, 165, 167, 169, 171, 173, 175,
		177, 179, 181, 183, 185, 187, 189, 191, 193, 196};

	int listSize = sizeof(list) / sizeof(list[0]);
	int shot;

	printf("Enter the desired value: ");
	scanf("%d", &shot);

	SearchResult search = binary_search(list, listSize, shot);

	if (search.found)
	{
		printf("Value %d found!\n", search.value);
		printf("Index: %d\n", search.index);
		printf("Number of interactions: %d\n", search.interactions);
	}
	else
	{
		printf("No value was found in the search!\n");
	}

	// printf("Result of binary search: %d\n", binary_search(list, listSize, 7));

	return 0;
}
