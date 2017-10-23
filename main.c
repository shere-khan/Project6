#include <stdio.h>
#include <stdbool.h>

#define NUM_KEYS 7

int main() {
    int keys[NUM_KEYS];
    FILE *ifp;
    if ((ifp = fopen("input.txt", "r")) != NULL) {

        printf("File open success.\n");
        for (int i = 0; i < NUM_KEYS; i++)
            fscanf(ifp, "%d", &keys[i]);
        bool chest_open = false;
        int matches = 0;
        do {
            printf("You have %d matches", matches);
            int keys_to_use[NUM_KEYS];
            printf("Now you must enter 7 keys you would like to use\n");
            int keys_entered = 0;
            while (keys_entered < 7) {
                printf("Enter key #%d:", keys_entered + 1);
                scanf("%d", &keys_to_use[keys_entered]);
                keys_entered++;
            }

            printf("\n");
            int matches_in_order = 0;
            for (int i = 0; i < NUM_KEYS; i++) {
                for (int j = 0; j < NUM_KEYS; j++)
                    if (keys_to_use[i] == keys[j])
                        matches++;
                if (keys_to_use[i] == keys[i])
                    matches_in_order++;
            }
            if (matches_in_order == 7)
                chest_open = true;
        } while (!chest_open);
        printf("you opened the chest");
    } else {
        printf("File open failure.\n");
        return 0;
    }
    return 0;
}