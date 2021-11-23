#include <stdio.h>
#include <string.h>
#include <io.h>




void FileSize (char *nomearq){
    FILE *arq;
    long tam;
    arq= fopen(nomearq, "r");
    tam=0;
    

    if (arq != NULL){
        fseek (arq, 0, SEEK_END);
        tam= ftell(arq);
        
        printf ("O arquivo %s tem %i bytes\n", nomearq, tam);
        
        fclose(arq);
    }else{
        printf("arquivo não existe");       
    }
    
}


int guardaTam (char *nomearq,int vetortam[], int i){
    FILE *arq;
    long tam;
    arq= fopen(nomearq, "r");
    tam=0;
   
    if (arq != NULL){
        fseek (arq, 0, SEEK_END);
        tam = ftell(arq);
      
        printf ("O arquivo %s tem %i bytes\n", nomearq, tam);
             
        fclose(arq);
    }else{
        printf("arquivo não existe");       
    }
    return 0;


    
}

int main () {
    char *vnomes[3]={"teste.txt", "teste2.txt", "teste3.txt"};
    int vtam[3];
    int i = 0;
    printf("--------------------------\n");
    
    for(i=0; i<3; i++){
        FileSize (vnomes[i]);   
                
    };
    
    printf("\n-------- Ordenado -------------\n");
    
    
    for(i=0; i<3; i++){
       guardaTam(vnomes[i], vtam[i], i); 
                 
    };

    

    return 0;
}   