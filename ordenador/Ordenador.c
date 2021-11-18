#include <stdio.h>
#include <string.h>
#include <io.h>

int main (void) {
    
    int vetorTam[3];

    FILE *file;
    file= fopen ("teste.txt", "r");  
    FileSize("teste.txt", vetorTam[0]); 
    FILE *file2;
    file2 = fopen("teste2.txt", "r");
    FileSize("teste2.txt", vetorTam[1]);
    FILE *file3;
    file3 = fopen("teste3.txt", "r");
    FileSize("teste3.txt", vetorTam[2]);
    printf(vetorTam[0]);
    printf(vetorTam[1]);
    printf(vetorTam[2]);
    
    fclose(file);
    fclose(file2);
    fclose(file3);

    if(file==NULL){
        printf ("arquivo não pode ser aberto");
        system("pause");

        return 1;
    }
    return 0;
}   


int FileSize (char *nomearq, int vetorTam[]){
    FILE *arq;
    long tam;
    arq= fopen(nomearq, "r");
    tam=0;

    if (arq != NULL){
        fseek (arq, 0, SEEK_END);
        tam= ftell(arq);
        vetorTam[0]= tam;
        printf ("O arquivo %s tem %i bytes\n", nomearq, tam);
        fclose(arq);
    }else{
        printf("arquivo não existe");


        
    }
    return 0;
}




