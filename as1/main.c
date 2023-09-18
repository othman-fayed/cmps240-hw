#include <stdio.h>
#include <stdlib.h>
#include "ass1.h"

int main() {
    int height;

    printf("Enter the height of the triangles: ");
    scanf("%d", &height);

    char* result = UpsideDownTraingle(height);

    if (result != NULL) {
        printf("%s", result);
        free(result); // Free the allocated memory
    } else {
        printf("Invalid input. Height must be a positive integer.\n");
    }

    return 0;
}