#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Prompt user for x
    // float x = get_float("x: ");

    // Prompt user for y
    // float y = get_float("y: ");

    // Divide x by y
    // float z = x / y;

    // printf("%.50f\n", z);

    // com uma entrada de 4.20 o resultado será 419 "(4.20 might be stored as 4.199999...)"
    float amount = get_float("Dollar Amount: ");
    // a função round() resolve o problema
    int pennies = round(amount * 100);
    printf("Pennies: %i\n", pennies);
}
