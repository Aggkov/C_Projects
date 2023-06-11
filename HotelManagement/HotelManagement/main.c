#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "helpers.h"


int main() {
	char* hotelNames2[ROW];
	char nameBuffer[50];
	for (int i = 0; i < ROW; i++) {
		printf("Enter hotel name: ");
		gets(nameBuffer);
		size_t size = strlen(nameBuffer);
		hotelNames2[i] = malloc(sizeof(char) * size + 1);
		if (hotelNames2[i] == NULL) {
			exit(1);
		}
		strcpy_s(hotelNames2[i], size + 1, nameBuffer);
		
	}
	//printf("%s", hotelNames2[0]); // dynamic array prints first element
	for (int i = 0; i < ROW; i++) {
		printf("%s ", hotelNames2[i]);
	}
	printf("\n");
	

	int hotelArrayVisitorsPerMonth[ROW][COLUMN];
	initialize2DArrayOfVisitors(hotelArrayVisitorsPerMonth);
	printArr(hotelArrayVisitorsPerMonth, ROW, COLUMN);
	printYearlyVisitsOfAllHotelsWithDynamicCharArray(hotelNames2, hotelArrayVisitorsPerMonth);
	printHotelWithMinimumVisitors(hotelArrayVisitorsPerMonth, hotelNames2);

	return 0;
}

