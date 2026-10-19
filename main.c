#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct matrix{
	int row;
	int column;
	int* matrix;
}MAT;
int mode_choose(void);
MAT input_matrix( int mode );
char confirm(void);
int input_number(void);
void output_matrix(MAT matrix);
char input_char(void);
int det_cal(MAT det);
MAT matrix_multiple(MAT A,MAT B);
void display(void);

int main(int argc, char *argv[]) {
	printf("linear algebra calculation\n");
	sleep(1);
	int mode;
	int det_result;
	int i;
	MAT matrix_0,matrix_1,matrix_2;
	mode = mode_choose();
	if (!mode){
		return 0;
	}
	switch(mode){
		case 1:
			matrix_0 = input_matrix(1);
			display();
			det_result = det_cal(matrix_0);
			printf("%d",det_result);
			break;
		case 2:
			printf("Enter the left one:\n");
			matrix_1 = input_matrix(2);
			printf("Enter the right one:\n");
			matrix_2 = input_matrix(2);
			display();
			matrix_0 = matrix_multiple(matrix_1,matrix_2);
			if(matrix_0.matrix != NULL){
				output_matrix(matrix_0);
			}
			break;	
	}
	return 0;
}


int mode_choose(void){
	int mode;
	char certain;
	back_to_mode_choose:
	printf("Choose a mode:\n");
	printf("[1]det calculation\n");
	printf("[2]matrix multiple\n");
	printf("[0]exit\n\n\n");
	sleep(1); 
	printf("Enter the number befor the mode:\n\n");
	mode = input_number();
	getchar();
	switch(mode){
		case 1:
			printf("det calculation?");break;
		case 2:
			printf("matrix multiple?");break;
		default:
			printf("exit?");break;
	}
	certain = confirm();
	switch(certain){
		case 'N':
			goto back_to_mode_choose;
		case 'Y':
			;
	}
	return mode;
}


MAT input_matrix( int mode ){
	MAT matrix;
	char certain;
	switch(mode){
		case 1:
			do{
				printf("Enter a number for rows and columns\n");
				matrix.row = input_number();
				getchar();
				matrix.column = matrix.row;
				certain = confirm();
				}while(certain == 'N');
			break;
		case 2:
			do{
				printf("Enter a number for rows \n");
				matrix.row = input_number();
				getchar();
				certain = confirm();
				}while(certain == 'N');
			do{
				printf("Enter a number for columns \n");
				matrix.column = input_number();
				getchar();
				certain = confirm();
			}while(certain == 'N');
			break;

	}
	
	int i,j;
	int x,y,n;
	matrix.matrix = (int*)malloc(matrix.column*matrix.row*sizeof(int));
	if(matrix.matrix == NULL){
		free( matrix.matrix );
		printf("too huge!\n");
		matrix.row = -1;
		return matrix;
	}
	int *p;
	p=matrix.matrix;
	for(i=0;i<matrix.row;i++){
		printf("Enter the numbers of row %d:\n",i+1);
		for(j=0;j<matrix.column;j++){
			*p = input_number();
			p++;
		}
	}
	sleep(1);
	do{
	printf("This is the matrix you inputed/revised just now:\n");
	output_matrix(matrix);
	printf("Check it.\n");
	printf("If you want to revise, enter 'R'; otherwise, enter 'C'\n");
	getchar();
	certain = input_char();
	if(certain == 'R'){
		printf("Enter the element to revise.\nrow: ");
		scanf("%d",&x);
		printf("\ncolumn: ");
		scanf("%d",&y);
		printf("Enter the number to replace the wrong one:\n");
		scanf("%d",&n);
		p=matrix.matrix;
		*(p+(x-1)*matrix.row+y-1)= n;
	}
	}while(certain == 'R');
	sleep(1);
	return matrix;
}


char confirm(void){
	char certain;
	printf("\nY for yes N for no\n");
	certain = input_char();
	return certain;
}


int input_number(void){
	int number;
	while(scanf("%d",&number) == EOF){
		printf("Invalid Input!\n");
		getchar();
		printf("Enter again:\n");
	}
	return number;
}


void output_matrix(MAT matrix){
	int i,j;
	int *p;
	p = matrix.matrix;
	for(i=0;i<matrix.row;i++){
		for(j=0;j<matrix.column;j++){
			printf("%d\t",*p);
			p++;
		}
		printf("\n\n");
	}
}


char input_char(void){
	char c;
	while(scanf("%c",&c) == EOF){
		printf("Invalid Input!\n");
		getchar();
		printf("Enter again.\n");
	}
	return c;
}

int det_cal(MAT det){
	int sum,i,j,counter;
	int *p,*q;
	MAT det_sub;
	p = det.matrix;
	if(det.row == 1){
		return *p;
	}if(det.row == 2){
		return (*p * *(p+3) - *(p+1) * *(p+2));
	}else{
		sum = 0;
		det_sub.row = det_sub.column = det.row - 1;
		for(i = 0;i<det.row;i++){
			counter = 0;
			p = (det.matrix+det.row);
			det_sub.matrix = (int*)malloc((det.row)*(det.column)*sizeof(int));
			q = det_sub.matrix;
			for(j = 0;j<det_sub.row*det_sub.column;j++){
				if(counter%det.row == i){
					p++;
					counter++;
				}
				*q = *p;
				q++;
				p++;
				counter++;
			}
			p = det.matrix;
			output_matrix( det_sub );
			sum = sum + *(p+i) * pow(-1,i) * det_cal( det_sub );
			q = det_sub.matrix;
			free(q);
		}
		return sum;
	}
}

void display(void){
	int i;
	printf("Calculating");
			for(i=0;i<3;i++){
				sleep(1);
				printf(".");
			}
			printf("\n");
}

MAT matrix_multiple(MAT A,MAT B){
	MAT result;
	if(A.column != B.row){
		printf("Invalid input!");
		result.row = result.column = -1;
		result.matrix = NULL;
	}else{
		;
	}
	return result;
	
}
