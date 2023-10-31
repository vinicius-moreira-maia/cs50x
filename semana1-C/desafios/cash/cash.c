#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int c; // tava dando erro quando declarada dentro do while()
    while(true)
    {
        c = get_int("Change Owed: ");

        if (c >= 0)
        {
            break;
        }
    }
    
    return c;
}

int calculate_quarters(int cents)
{
    int moedas = 0;

    while (cents >= 25)
    {
        cents -= 25;
        moedas++;
    }

    return moedas;
}

int calculate_dimes(int cents)
{
    int moedas = 0;

    while (cents >= 10)
    {
        cents -= 10;
        moedas++;
    }

    return moedas;
}

int calculate_nickels(int cents)
{
    int moedas = 0;

    while (cents >= 5)
    {
        cents -= 5;
        moedas++;
    }

    return moedas;
}

int calculate_pennies(int cents)
{
    int moedas = 0;

    while (cents > 0)
    {
        cents -= 1;
        moedas++;
    }

    return moedas;
}
