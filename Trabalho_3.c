/*Versao que usa arquivos, e foi alterado a forma de calcular
fonte: http://stackoverflow.com/questions/2049582/how-to-determine-a-point-in-a-2d-triangle
*/
#include <stdio.h>
#include <stdlib.h>

int calc_area(int x1, int y1, int x2, int y2, int x3, int y3){
    int calc = 0;

    calc = ((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3));
    return calc;
}

int main(){
    int x1, x2, x3, y1, y2, y3; //coordenadas do triangulo
    int px, py; //coordenadas do ponto
    int result_a, result_b, result_c, i=0;
    int count = 0;

    FILE *coordenadas; //coordenadas dos pontos e do triangulo
    FILE *result; //resultado

    coordenadas = fopen("coordenadas.txt","r");
    result = fopen("resultado_C.txt","w");
    if(coordenadas == NULL){
       printf("Nao foi possivel abrir o arquivo\n");
       exit(1);
    }
    for(i=0; i<1000;i++){
    	fscanf(coordenadas,"%d %d %d %d %d %d %d %d\n",
    	&px, &py, &x1, &y1, &x2, &y2, &x3, &y3); //ler as coordenadas

	result_a = calc_area(px, py, x1, y1, x2, y2);
	result_b = calc_area(px, py, x2, y2, x3, y3);
	result_c = calc_area(px, py, x3, y3, x1, y1);

	if((result_a == result_b) && (result_a == result_c)){
	    fprintf(result,("1\n"));//1 se esta dentro do triangulo;
            count ++;
        }
        else{
            fprintf(result,("0\n"));//0 se não está
        }		
    }
    printf("\n%d ",count);//quant. de resultados positivos
    fclose(coordenadas);
    fclose(result);

    return 0;
}
