#define ROW 3
#define COLUMN 12

void initialize2DArrayOfVisitors(int numOfVisitors[ROW][COLUMN]);
void printYearlyVisitsOfAllHotels(char* hotels[ROW], int numOfVisitors[ROW][COLUMN]);
void printYearlyVisitsOfAllHotelsWithDynamicCharArray(char* hotels[ROW], int numOfVisitors[ROW][COLUMN]);
void printHotelWithMinimumVisitors(int numOfVisitors[ROW][COLUMN], char* hotels[ROW]);
void printArr(int arr[ROW][COLUMN], unsigned row, unsigned column);
