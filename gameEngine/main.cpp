#include <stdio.h>
#include <stdlib.h>

void printFizzBuzz() {
	for (int i = 1; i < 101; i++) {
		if ((i % 3 == 0) & (i % 5 == 0)) {
			printf("Fizzbuzz");
		}
		else if (i % 3 == 0) {
			printf("Fizz");
		}
		else if (i % 5 == 0) {
			printf("Buzz");
		}
		else {
			printf("%i", i);
		}
		printf("\n");
	}
}

int main() {
	printf("Simple fizzbuzz program:\n");
	printFizzBuzz();
	system("pause");

}
