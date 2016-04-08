#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    int vetor_A[1000], vetor_B[1000];
    
    FILE *A; 
    FILE *B; 
    FILE *result; 

    A = fopen("resultado_C.txt","r");
    B = fopen("resultado_V.txt","r");
    result = fopen("Resultado_comparação.txt","w");
    
    for(i=0; i<1000;i++){
        fscanf(A,"%d",&vetor_A[i]); //ler as coordenadas
    	fscanf(B,"%d",&vetor_B[i]); 
    	
    	if(vetor_A[i] != vetor_B[i]){
	    fprintf(result," Diferenca na linha %d\n", i+1);//vai gravar no arquivo o n° da linha 
	}                                                   //onde os valores são diferentes
    }
    fclose(A);
    fclose(B);
    fclose(result);
    
    return 0;
}
