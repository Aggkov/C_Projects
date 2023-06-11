#include <time.h>
#include <limits.h>
#include <ctype.h>
#include "helpers.h"

// initialize number of visitors for each hotel and for each month of the year
void initialize2DArrayOfVisitors(int numOfVisitors[ROW][COLUMN]) {
	time_t t;
	srand((unsigned)time(&t));
	// init
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			numOfVisitors[i][j] = rand() % 2000;
		}
	}
}

// Print in a nice way the hotels and their visitors for each month of the year. If visitors for given month is less 1000 print No Visitors
void printYearlyVisitsOfAllHotelsWithDynamicCharArray(char* hotels[ROW], int numOfVisitors[ROW][COLUMN]) {
	printf("HOTELS\n");
	printf("-------------\n");
	for (int i = 0; i < ROW; i++) {
		// convert 1st char to uppercase of hotel name
		hotels[i][0] = toupper(hotels[i][0]);
		printf("%s Hotel Summary", hotels[i]);
		printf("\n");
		printf("\n");
		int k = 0;
		int sum = 0;
		for (k = 0; k < COLUMN; k++) {
			sum += numOfVisitors[i][k];
			int visitors = numOfVisitors[i][k];
			visitors = visitors > 1000 ? visitors : 0;
			char* message = "No Visitors";
			if (visitors > 1000) {
				printf("Month %d Visitors --> %d\n", k + 1, numOfVisitors[i][k]);
			}
			else {
				printf("Month %d Visitors --> %s\n", k + 1, message);
			}

		}
		printf("\n");
		printf("Total Visitors = %d", sum);
		printf("\n");
		printf("\n");
	}
}

// Print hotel names, that had the less total amount of visitors in the year
void printHotelWithMinimumVisitors(int numOfVisitors[ROW][COLUMN], char* hotels[ROW]) {
	int min = INT_MAX;
	int index = 0;
	int currentSum;
	for (int i = 0; i < ROW; i++) {
		currentSum = 0;
		for (int j = 0; j < COLUMN; j++) {
			currentSum += numOfVisitors[i][j];
		}
		if (currentSum < min) {
			min = currentSum;
			index = i;
		}
	}
	char hotelBuffer[50];
	for (int i = 0; i < ROW; i++) {
		if (i == index) {
			strcpy_s(hotelBuffer, strlen(hotels[i]) + 1, hotels[i]);
			break;
		}
	}
	printf("%s Hotel number %d had the minimum visitors %d\n", hotelBuffer, index + 1, min);
}

void printArr(int arr[ROW][COLUMN], unsigned row, unsigned column) {
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//void printYearlyVisitsOfAllHotels(char* hotels[ROW], int numOfVisitors[ROW][COLUMN]) {
//	int k = 0;
//	printf("HOTELS\n");
//	printf("-------------\n");
//	for (int i = 0; i < ROW; i++) {
//		for (int j = 0; j < STRLENHOTELNAME; j++) {
//			printf("%c", hotels[i][j]);
//		}
//		printf("\n");
//		printf("\n");
//		for (int k = 0; k < COLUMN; k++) {
//			int visitors = numOfVisitors[i][k];
//			visitors = visitors > 1000 ? visitors : 0;
//			char* message = "No Visitors";
//			if (visitors > 1000) {
//				printf("Month %d Visitors --> %d\n", k + 1, numOfVisitors[i][k]);
//			}
//			else {
//				printf("Month %d Visitors --> %s\n", k + 1, message);
//			}
//		}
//		printf("\n");
//		printf("\n");
//	}
//}