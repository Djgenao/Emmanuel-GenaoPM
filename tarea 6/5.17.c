#include <stdio.h>
/* Apuntadores y arreglos */
int main(void)
{
    int V1[4] = {1, 3, 5, 7}, V2[4] = {2, 4, 0, 0};  // Initialize V2 with enough elements
    int *AX, *AY;

    AX = &V1[2];    // AX points to V1[2] (which is 5)
    AY = &V2[2];    // AY points to V2[2] (currently uninitialized, but initialized here)

    V2[2] = *(AX + 1);   // V2[2] takes the value of V1[3] (which is 7)
    V2[3] = *AX;         // V2[3] takes the value of V1[2] (which is 5)
    AX = AX + 1;         // AX now points to V1[3] (7)
    V1[0] = *AX;         // V1[0] takes the value of V1[3] (7)

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    V1[2] = *AY;         // V1[2] takes the value of V2[2] (7)
    V1[1] = --*AY;       // AY points to V2[2], decrements it to 6, and assigns it to V1[1]

    AX = AX + 1;         // AX moves one position beyond V1[3] (out of bounds, but this is just for demonstration)
    V1[3] = *AX;         // Undefined behavior due to accessing out of bounds of V1

    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    return 0;  // Return success
}
