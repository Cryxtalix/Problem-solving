#include <stdio.h>
#include <string.h>

int main()
{
        for (int i = 0; i < 101; i++) {
                char special[9] = "\0";

                if (i % 3 == 0) {
                        strncat(special, "fizz", 9);
                }
                if (i % 5 == 0) {
                        strncat(special, "buzz", 9);
                }
                
                if (strlen(special) == 0) {
                        printf("%d\n", i);
                } else {
                        printf("%s\n", special);
                }

        }
        return 0;
}