#include <stdio.h>
#include <string.h>





void FileSize (char *nomearq, int *vetTam, int i){
    FILE *arq;
    int tam;
    arq= fopen(nomearq, "r");
    tam=0;
    
  
    if (arq != NULL){
        fseek (arq, 0, SEEK_END);
        tam= ftell(arq);
       
        vetTam[i]= tam;          
        
        printf ("O arquivo %s tem %i bytes\n", nomearq, tam);
        
        fclose(arq);
    }else{
        printf("arquivo não existe");       
    }
    
}



void ordena (char *vnomes, int *vetTam){
    int i=0;
    int aux;
    char aux2;
    if (vetTam[i]<vetTam[i+1]){
        i++;
    }else{
      aux = vetTam[i] ;
      vetTam[i] = vetTam[i+1];
      vetTam[i+1] = aux;
      
    }
    
}

    




int main () {
    char *vnomes[3]={"teste.txt", "teste2.txt", "teste3.txt"};
    int vetTam[3];
    int i = 0;
    printf("--------------------------\n");
    
    for(i=0; i<3; i++){
        FileSize (vnomes[i], vetTam, i);   
                
    };
     
    printf("\n-------- Ordenado -------------\n");
    
    ordena(vnomes, vetTam);

    for(i=0; i<3; i++){
        printf("-------- %i bytes\n", vetTam[i]); 
                
    };
    
    return 0;
}   