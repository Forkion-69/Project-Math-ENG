#include <stdio.h>
#include <math.h>


float f(float x)
{
	
    return x*x + x - 1;
}


float fd(float x)
{
    return 2*x + 1;
}
// MAIN 
int main()
{	//Definition
    float a, b, x;
    int found = 0;
	
	//Print
    printf("Rolle's Theorem\n");
    printf("f(x) = x^2 - 4x + 3\n\n");
	
	//Input
    printf("Enter interval min a : ");
    scanf("%f", &a);
    printf("Enter b Interval max b :");
    scanf("%f", &b);

	//Print Function
    printf("f(a) = %.2f\n", f(a));
    printf("f(b) = %.2f\n", f(b));


	//CONDITION-1
	
    if (f(a) == f(b))
    {
        printf("\nf(a) = f(b), so Rolle's theorem can be applied\n");

        for (x = a; x <= b; x = x + 0.001)
        {
            if (fabs(fd(x)) < 0.001)
            {
                printf("c = %.2f\n", x);
                printf("f'(c) = 0, Rolle's theorem is verified\n");
                found = 1;
                break;
            }
        }
		//CONDITION IF ZERO
        if (found == 0)
            printf("c not found.\n");
    } //FALSE-SAFE
    else
    {
        printf("\nf(a) is not equal to f(b), Rolle's theorem cannot be applied\n");
    }
 //STOP
    return 0;
}
