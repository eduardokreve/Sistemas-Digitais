#include <stdio.h>
#include <stdlib.h>

int calc_area(int x1, int y1, int x2, int y2, int x3, int y3){
	int calc = 0;

	calc = ((x1-x3)*(y2-y3)-(x2-x3)*(y1-y3));
	return calc;
}

int main(){
	int x1, x2, x3, y1, y2, y3; //coordenadas do triangulo
	int px,py; //coordenadas do ponto
	int result_a, result_b, result_c, result_d;

	
	printf("Coordenadas do triangulo:\n");
	printf("X1 e Y1: ");
	scanf("%d %d",&x1,&y1);
	printf("X2 e Y2: ");
	scanf("%d %d",&x2,&y2);
	printf("X3 e Y3: ");
	scanf("%d %d",&x3,&y3);
	printf("Coordenadas do ponto: \n");
	scanf("%d %d",&px,&py);

 	result_a = calc_area(x1, y1, x2, y2, x3, y3);
	result_b = calc_area(x1, y1, x3, y3, px, py);
	result_c = calc_area(x1, y1, x2, y2, px, py);
	result_d = calc_area(x3, y3, px, py, x1, y1);

	if(result_a == (result_b+result_c+result_d)){
		printf("Esta dentro do triangulo\n");
	}
	else{
		printf("Nao esta dentro do triangulo\n\n");
	}

	return 0;
}
