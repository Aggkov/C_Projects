#include <stdio.h>

// 1 to 60 seconds = charge full minute
// 61 to 120 = charge 2 minutes
// first 3 min = 0.06 per minute
// > 3 min = 0.04 per minute

double charge(seconds);
int convertSecondsToMinutes(int seconds);

int main() {
	int seconds = 0;
	int calls = 0;
	double chargeForCall = 0.0;
	double totalCharge = 0.0;
	int chargeMoreThan2Euros = 0;
	while (totalCharge <= 10 && calls <= 100) {
		do {
			printf("\nEnter how many seconds was the call: ");
			scanf_s("%d", &seconds);
			chargeForCall = charge(seconds);
			if (chargeForCall > 2) {
				chargeMoreThan2Euros++;
			}
			printf("Charge for the call was %.2f\n", chargeForCall);
			calls++;
			
		} while (seconds < 0);
	}
	int percentage = (chargeMoreThan2Euros / calls) * 100;
	printf("Percentage of calls charged more than 2 euros is %d", percentage);

	return 0;
}

double charge(seconds) {
	int minutes = convertSecondsToMinutes(seconds);
	int remainder = seconds % 60;
	if (remainder > 0) {
		minutes++;
	}
	double charge = 0.0;
	if (minutes <= 3) {
		charge = minutes * 0.06;
	} 
	else {
		charge = 3 * 0.06 + (minutes - 3) * 0.04;
	}
	return charge;
}

int convertSecondsToMinutes(int seconds) {
	return seconds / 60;
}