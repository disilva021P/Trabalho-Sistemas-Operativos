#include<stdio.h>
#include <string.h>
#include"interpretador.h"
#include"funcoes.h"
int interpretador(){
    char comando[11], ficheiro[255],ficheiroLeitura[255],linha[521];
    int leitura;
    printf("Interpretador ligado\n");
    while(1){
        printf("%% "); 

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            printf("Erro a ler input\n");
            return 1;
        }
        // Remove \n do final, se existir
        linha[strcspn(linha, "\n")] = '\0';      
        int leitura=sscanf(linha, "%s %s %[^\n]", comando, ficheiro, ficheiroLeitura);
        if(strcmp(comando,"termina")==0){
            break;
        }
        if (strcmp(comando,"acrescenta") && leitura != 2) {
            printf("Erro a ler comando.\n");
            continue;
        }
        if(ficheiro==NULL){
            printf("Identifique um ficheiro!\n");
            continue;
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
            acrescenta(ficheiro,ficheiroLeitura);
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
}