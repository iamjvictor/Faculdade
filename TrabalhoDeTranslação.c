//Trabalho de translação de vetores
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>

void main (void){
    int n, v, vx, vy, cx, cy;
    

    printf("Digite o tamanho do vetor desejado: ");
    scanf("%d", &n);

    //Alocação dinâmica
    vx= alocaVetor(n);
    vy= alocaVetor(n);

    //Gerar o vetor, chamando a função
    printf("Para X: \n");
    gerarVet (n, vx);
    printf("Para Y: \n");
    gerarVet (n, vy);

    //Exibir o vetor
    exibir (n, vx, vy);
   

    //Calcular o centroide
    cx= centroide(n, vx);
    cy= centroide(n, vy);

    printf("\n [%d,%d]\n", cx, cy);

    //transladar com a origem
    transladar (n, vx, vy, cx, cy);
    exibir (n, vx, vy);

    //Calcular Angulo
    CalculaAngulo (n, vx, vy);

    
    

   
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
        printf("[%d,%d]", v[i], vy[i]);
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

void CalculaAngulo (int n, int *vx, int *vy){
    int i;
    for(i=0;i<n;i++){
     int det= vx[i]*1 + vy[i] *0;
     int dot= vx[i]*0 - vy[i] *1;
     int angle= atan2(det, dot);

        printf("%f", angle);
    }
        
}
