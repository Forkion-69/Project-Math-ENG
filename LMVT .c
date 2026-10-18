//Verify Lagrange’s Mean value theorem
//for the function
//sin(inverse) in [0,1];

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> 

float f(float x)
{

	return asinf(x);
}


float fdx(float x)
{
	return 1/(1 + powf(x,2));
}


int main(){
	
	float a,b;

	printf("put required interval, lower followed with the higher ");
	
	scanf("%f%f",&a ,&b);
	
	printf("Checking continuity....\n");
	
	srand(time(NULL));
	
	float rando = (rand() % (1 - 0 + 1)) + 0;
	float c = rando;
	
	if(f(rando) != NAN){
		
		float derivative = fdx(rando);
		
		if(derivative != NAN )
		{
			printf("Will satisfy LMVT");
			double temp;
			temp = sqrt((a + b/(f(a)+f(b))-1));
			
			printf("%lf at  %lf with size %lf", temp, &temp,sizeof(temp));
			
		}else{
			return 0;
		}
		
	}else{
		return 0;
	}
	
	return 0;
}
