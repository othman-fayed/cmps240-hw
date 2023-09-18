#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char* UpsideDownTraingle(int height) {
    if(height <= 0) {
        return NULL;
    }

    // printf("# # # #   #\n # # #   # #\n");
    int indentCount = (height / 2) * (1 + height);
    int cols = height + 2; //height / 2 * 3 + 1;
    // printf("%d\n", cols);
    // printf("%d\n", height * (cols - 1) * 2 + indentCount + 1);
    char* _buffer = (char*)malloc(height * cols * 2 + indentCount + 1); // we are allocating more than we need here! basically max cols
    // printf("Allocated %d %ld\n", height * cols * 2 + 1, sizeof(_buffer));

    // int leftStart = 0, skipIndex = height, rightStart = height + 1, rightEnd = rightStart + 1;
    int skipIndex = height;
    // printf("leftStart %d skipIndex %d cols %d rightStart %d rightEnd %d\n", l    eftStart, skipIndex, cols, rightStart, rightEnd);

    int i = 0;
    int index = 0;
    char space = '_';
    for (i = 0; i < height; i++) {
        int j;
        for(j = 0; j < i; j++) {
            _buffer[index++] = space;
        }
        for(j = 0; j < cols; j++) {
            if (j == skipIndex) {
                _buffer[index++] = space;
            } else {
                _buffer[index++] = '#';
                _buffer[index++] = space;
            } 
        }
        index--;
        _buffer[index++] = '\n';
        // leftStart++;
        // rightEnd++;
        skipIndex--;
        // printf("leftStart %d skipIndex %d width %d rightStart %d rightEnd %d\n", leftStart, skipIndex, cols, rightStart, rightEnd);
    }
        // printf("%d\n", index);
    _buffer[index] = '\0';

    return _buffer;
}