#include<stdio.h>
#include <string.h>
#include"funcoes.h"
//#include<stdlib.h>
int main(int argc, char const *argv[])
{
    char* comando, *ficheiro;
    printf("Interpretador ligado\n");
    while(1){
        printf("> "); 
        if (scanf("%s %s", comando, ficheiro) != 2) {
            printf("Erro a ler comando.\n");
            continue;
        }
        if(strcmp(comando,"termina")==0){
            break;
        }
        if(!ficheiroExiste(ficheiro)){
            printf("Ficheiro não existe\n");
            continue;
        }
        if(strcmp(comando,"mostra")==0){
            int r = mostra(ficheiro);
            if(!r){
                printf("Erro a abrir o ficheiro, verifique as permissões\n");
            }
        }else if(strcmp(comando,"copia")==0){
            copia(ficheiro);
        }else if(strcmp(comando,"acrescenta")==0){
            acrescenta(ficheiro);
        }else if(strcmp(comando,"conta")==0){
            conta(ficheiro);
        }else if(strcmp(comando,"apaga")==0){
            apaga(ficheiro);
        }else if(strcmp(comando,"informa")==0){
            informa(ficheiro);
        }else if(strcmp(comando,"lista")==0){
            listaDiretoria(ficheiro);
        }else{
            printf("Comando: \"%s\" não existe\n",comando);
        }
    }
    return 0;
}
