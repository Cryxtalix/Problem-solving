#include "lib/lib.h"

int main(void) {
        for (int row = 0; row < 9; row++) {
                for (int column = 0; column < 9; column++) {
                        printf("%d", get_grid_num(column, row));
                }
                printf("\n");
        }

        printf("%d\n", 1 & 0 & 1);
}

//Group testGroup = {1, 2, 3, 4, 5, 7, 6, 9, 8};
//bool result = is_filled(testGroup);

//printf("Is filled: %s\n", result ? "true" : "false");

//result = is_invalid(testGroup);

//printf("Is invalid: %s\n", result ? "true" : "false");