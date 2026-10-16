#include <stdio.h>
#include <math.h>

int main()
{
	//----------------MACLORIAN'S SERIES--------------------------//
	
    int choice, n, i;		///DEFINITION
    double x, m, term, sum, coeff;

    printf("MACLAURIN SERIES\n");//TEXT- BASED-UI
    printf("1. e^x\n");
    printf("2. sin(x)\n");
    printf("3. cos(x)\n");
    printf("4. log(1+x)\n");
    printf("5. 1/(1-x)\n");
    printf("6. (1+x)^m\n");

	//USER INPUTS
	
    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter x: ");
    scanf("%lf", &x);

    printf("Enter number of terms: ");
    scanf("%d", &n);

	//VERIFICATION USING- NESTED IF'S
	
    if (n < 1 || choice < 1 || choice > 6)
    {
        printf("Invalid input!\n");
        return 0;
    }

    if ((choice == 4 || choice == 5) && fabs(x) >= 1)
    {
        printf("Use -1 < x < 1 for this series.\n");
        return 0;
    }

    if (choice == 6)
    {
        printf("Enter m: ");
        scanf("%lf", &m);
    }

    sum = 0;
    term = 1;

    printf("\nMaclaurin Series:\n");
	//NESTED-IF TO CREATE POWER EXPRESSION/NO. OF EXPRESSION
    if (choice == 1)
    {
        sum = 1;
        printf("e^x = 1");

        for (i = 1; i < n; i++)
        {
            term = term * x / i;
            sum += term;
            printf(" + (x^%d)/%d!", i, i);
        }
    }
    else if (choice == 2)
    {
        term = x;
        sum = x;
        printf("sin(x) = x");

        for (i = 1; i < n; i++)
        {
            term = -term * x * x /
                   ((2.0 * i) * (2.0 * i + 1));
            sum += term;

            if (term < 0)
                printf(" - x^%d/%d!",
                       2 * i + 1, 2 * i + 1);
            else
                printf(" + x^%d/%d!",
                       2 * i + 1, 2 * i + 1);
        }
    }
    else if (choice == 3)
    {
        sum = 1;
        printf("cos(x) = 1");

        for (i = 1; i < n; i++)//LOOPS TO GO THROUGH fcos();
        {
            term = -term * x * x /
                   ((2.0 * i - 1) * (2.0 * i));
            sum += term;

            if (i % 2 == 1)
                printf(" - x^%d/%d!", 2 * i, 2 * i);
            else
                printf(" + x^%d/%d!", 2 * i, 2 * i);
        }
    }
    else if (choice == 4)
    {
        sum = 0;
        term = x;
        printf("log(1+x) = ");

        for (i = 1; i <= n; i++) //LOOPS TO GO THROUGHT THE TERMS
        {
            if (i > 1)
                term *= x;

            if (i > 1)
                printf(i % 2 ? " + " : " - ");

            printf("x^%d/%d", i, i);
            sum += (i % 2 ? 1 : -1) * term / i;
        }
    }
    else if (choice == 5)// CHECHKING INPUT OF EXPRESSION TO USE;
    {
        sum = 0;
        term = 1;
        printf("1/(1-x) = ");

        for (i = 0; i < n; i++)
        {
            if (i > 0)
                printf(" + ");
            printf("x^%d", i);
            sum += term;
            term *= x;
        }
    }
    else
    {
        sum = 1;
        term = 1;
        printf("(1+x)^m = 1");

        for (i = 1; i < n; i++)
        {
            term = term * (m - i + 1) * x / i;
            sum += term;

            if (term < 0)
                printf(" - ");
            else
                printf(" + ");

            printf("|C%d|x^%d", i, i);
        }
    }

    printf("\n\nApproximate value = %.8f\n", sum);

    return 0;
}

