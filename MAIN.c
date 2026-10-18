#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <complex.h>
#include <math.h>
#include "ANSI-color-codes.h"



//• isspace(c): Returns true if the character is a space, tab, or newline.
//• isalpha(c): Returns true if the character is a letter (A-Z or a-z).
//• isdigit(c): Returns true if the character is a number (0-9).


//double complex derivative(double complex (*f)(double complex), double complex z) {
//    double h = 1e-6; // step size
//    return (f(z + h) - f(z - h)) / (2.0 * h);
//    
//    // printf("%lf", derivative(*f,6););
//}
//
//// Example complex function: f(z) = z^2
//double complex FofX(double complex z) {
//    return z * z;
//}

struct Tokens{

	float NUMBERS[64];
	char OPERATORS[64];
	char TRIGNO[64];
	char LOG[64];
	char RELATIONAL_OP[64];
	char EXP[64];
	char EXPRESSION[64];
	
	int NUMBERS_COUNT;
	int OPERATORS_COUNT;
	int TRIGNO_COUNT;
	int LOG_COUNT;
	int RELATIONAL_OP_COUNT;
	int EXP_COUNT;
	int EXPRESSION_COUNT;
	
}ILATE;


void Function_Reader(){
		//x + 4*x
	
	char INPUT_FIELD[256];
	
	if (!fgets(INPUT_FIELD, sizeof INPUT_FIELD, stdin)) return;
	
	const char *p = INPUT_FIELD;
	
	int arrayLen;
	
	while(true){//"x + 4x"
		
		if(isspace(*p) || *p == '\t'){
			p++;
			arrayLen++;
			continue;
		}			//^()
		else if(*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%%' || *p == '^' || *p == '(' || *p == ')'){
			printf("operator: %c", *p);
			ILATE.OPERATORS[ILATE.OPERATORS_COUNT++] = *p;
			p++;
			arrayLen++;
			printf(" %c ", ILATE.OPERATORS[ILATE.OPERATORS_COUNT]);
			
		}			//<>=!
		else if(*p == '<' || *p == '>' || *p == '=' || *p == '!'){
			printf("operator : %c", *p);
			ILATE.OPERATORS[ILATE.OPERATORS_COUNT++] = *p;
			p++;
			arrayLen++;
			
		}
		else if(isdigit(*p)){
			const char *start = p;
			
			while(isdigit(*p) || *p == '.'){
				ILATE.OPERATORS[ILATE.NUMBERS_COUNT++] = *p;
				p++;
				arrayLen++;
			}
			
			int length = p - start;
            printf("Number:   %.*s %c\n", length, start); 
            continue;
		}
		
		else if(isalpha(*p)){
			const char *start = p;
			
			while(isalpha(*p) || *p == '.'){
				printf("%c", *p);
				p++;
				ILATE.OPERATORS[ILATE.EXPRESSION_COUNT++] = *p;
				arrayLen++;
				printf("%c", *p);
			}
			
			int length = p - start;
            printf("WORD:   % *s %c\n", length, start); 
            continue;
		}
		else{
		printf("Unknown:  %c\n", *p);
        p++;
        
        
        printf("%p", p);
        printf("%d", arrayLen);
        printf("%c", p);
        continue;
        
	}
		
		printf("%p", p);
        printf("%d", arrayLen);
        printf("%c", p);
	break;
}
	
}

int main(){
	
	Function_Reader();

	return 0;
}
