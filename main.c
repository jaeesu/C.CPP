#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("need more arguments\n");
		exit(1);
	}
	printf("%s, %s", argv[1], argv[2]);
	printf("Hello World\n");
	return 0;
}
