//Trabalho de translação de vetores
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>

int main (void){
    int n, v, *vx, *vy, cx, cy;
    float *va;
    

    printf("Digite o tamanho do vetor desejado: ");
    scanf("%d", &n);

    //Alocação dinâmica
    vx= alocaVetor(n);
    vy= alocaVetor(n);
    va= (float*) malloc(n*sizeof(float)) ;;

    //Gerar o vetor, chamando a função
    printf("Para X: \n");
    gerarVet (n, vx);
    printf("Para Y: \n");
    gerarVet (n, vy);

    //Exibir o vetor
    printf("\n-------------------------------------------------\n");
    printf("Vetores escolhidos: ");
    exibir (n, vx, vy);
    printf("\n-------------------------------------------------\n");

    //Calcular o centroide
    cx= centroide(n, vx);
    cy= centroide(n, vy);

    printf("\nCentroide: \n[%d,%d]\n", cx, cy);
    printf("\n-------------------------------------------------\n");

    //transladar com a origem
    transladar (n, vx, vy, cx, cy);
    printf("Vetores transladados: ");
    exibir (n, vx, vy);
    printf("\n-------------------------------------------------\n");
    //Calcular Angulo
    CalculaReta (n, vx, vy, va);
   
return (0);
}

int alocaVetor (int n){
    int *v;
    v = (int*) malloc(n*sizeof(int)) ;
    return (v);
}

void gerarVet (int n, int *v){
    int i;
    for(i=0; i<n; i++){
        printf("digite o numero no indice %d: ", i);
        scanf ("%d", &v[i]);

    }
}

void exibir (int n, int *v, int *vy){
    int i;
    for(i=0;i<n;i++){
        printf("\n[%d,%d]", v[i], vy[i]);
    }
}

int centroide (int n, int *v){
    int c=0;
    int i;
    for(i=0;i<n;i++){
        c= c+ v[i];
    }
    return(c/n);
}

void transladar (int n, int *vx, int *vy, int cx, int cy){
    int i;
    for(i=0;i<n;i++){
        vx[i]= vx[i] - cx;
        vy[i]= vy[i] - cy;
        
    }
}

void CalculaAngulo (int *vx, int *vy, float *va){
        
        
     int det= *vy;
     int dot= *vx;
     double angle= atan2(det, dot);
    //printf("\n %.2f", angle*180/3,14);
    *va = angle*180/3,14;
    //correção de angulo
    if (*vy<0){
        if(*vx<0){
            *va= 180 + *va;
        }
        else{
            *va= 360 + *va;
        }
    }
    printf("\n %.2f",*va);
   
    

    
        
}

void CalculaReta(int n, int *vx, int *vy, float *va){
    int i;
    for(i=0; i<n; i++){
        CalculaAngulo(&vx[i], &vy[i], &va[i]);
    }
}

