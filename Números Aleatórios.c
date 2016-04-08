#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int quant_pontos[2], quant_tri[6];
    int i=0, j=0;

    FILE *coordenadas;
    coordenadas = fopen("coordenadas.txt","w");

    srand(time(NULL));

    while(i != 1000){
        for(j = 0; j < 2; j++){
	    quant_pontos[j] = rand()%5;
	    fprintf(coordenadas,("%d "), quant_pontos[j]);
	}
	for(j = 0; j < 5; j++){
	    quant_tri[j] = rand()%5;
	    fprintf(coordenadas,("%d "), quant_tri[j]);
	    if(j == 4){
	        fprintf(coordenadas,("%d \n"),quant_tri[j]);
		break;
	    }
	}
	i++;
    }
    fclose(coordenadas);
    return 0;
}
