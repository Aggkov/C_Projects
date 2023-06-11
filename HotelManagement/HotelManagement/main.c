#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "helpers.h"


int main() {
	char* hotelNames[ROW];
	char nameBuffer[50];
	for (int i = 0; i < ROW; i++) {
		printf("Enter hotel name: ");
		gets(nameBuffer);
		size_t size = strlen(nameBuffer);
		hotelNames[i] = malloc(sizeof(char) * size + 1);
		if (hotelNames[i] == NULL) {
			exit(1);
		}
		strcpy_s(hotelNames[i], size + 1, nameBuffer);
		
	}
	for (int i = 0; i < ROW; i++) {
		printf("%s ", hotelNames[i]);
	}
	printf("\n");
	int hotelArrayVisitorsPerMonth[ROW][COLUMN];
	initialize2DArrayOfVisitors(hotelArrayVisitorsPerMonth);
	printArr(hotelArrayVisitorsPerMonth, ROW, COLUMN);
	printYearlyVisitsOfAllHotelsWithDynamicCharArray(hotelNames, hotelArrayVisitorsPerMonth);
	printHotelWithMinimumVisitors(hotelArrayVisitorsPerMonth, hotelNames);

	return 0;
}

