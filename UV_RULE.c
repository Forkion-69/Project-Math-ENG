//INTIALIZATION AND DEFINES

#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<complex.h>



		// --DEFINITION-OF-DIFFERENTIATION USING COMPLEX-- //
		
double complex derivative(double complex (*f)(double complex), double complex z) {
    double h = 1e-6; // step size
    return (f(z + h) - f(z - h)) / (2.0 * h);
}

// Example complex function: f(z) = z^2
double complex FofX(double complex z) {
    return z * z;
}


//  ------DX DIFFERENTIATION FUNCTION--------

float f(float x){
	
	return x * x * sin(x);
	
}

float fdx(float x){
	return 2 * x * cos(x) - x * x * cos(x); 
}

// ------UV-RULE DIFFERENTIATION------

int main()
{
	//----------DEFINITION-----------
	
double a,b,x;
double dx = 2; //VALUE

///-------------------PRINTING--------------
printf("----------------Product rule of differentiation--------------- \n");
printf("----d(uv)/dx=u(dv/dx)+v(du/dx)----\n");

//-------------INPUTS----------------------

printf("Enter a u(a) \n");
scanf("%lf",&a);

printf("Enter a v(b) \n");
scanf("%lf",&b);

printf("Enter value of x: \n");
scanf("%lf",&x);




////////----------FOR COMPLEX DIFFERENTIATION---------

//double u;
//double v;
//double product(double x);
//
//double complex du=derivative(double *u,dx); 
//double complex dv=derivative(double *v,dx);
//
//double complex result3 = du;
//double complex result4 = dv;

//-----------CALLING FUNCTION---------

//PRINTING OUTPUT

printf("u=%lf ,v = %lf",a,b);
printf("du\dx=%lf\n",a);
printf("dv\dx=%lf\n",b);
printf("Derivatives using uv rule= %lf\n",f(dx));
return 0;

}

