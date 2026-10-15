#include <stdio.h>
#include <stdlib.h>
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
int main(int argc, char *argv[]) {
	printf("linear algebra calculation\n");
	//sleep(3);
	int mode;
	MAT matrix_0,matrix_1,matrix_2;
	mode = mode_choose();
	//printf("%d",mode);     //test point1
	if (!mode){
		return 0;
	}
	switch(mode){
		case 1:
			matrix_1 = input_matrix(1);
			
	}
	return 0;
}
int mode_choose(void){
	int mode;
	char certain;
	back_to_mode_choose:
	printf("Choose a mode:\n");
	printf("[1]det calculation\n");
	printf("[0]exit\n\n\n");
	sleep(3); 
	printf("Enter the number befor the mode:\n\n");
	mode = input_number();
	getchar();
	switch(mode){
		case 1:
			printf("det calculation?");break;
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
	//sleep(2);
	
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
