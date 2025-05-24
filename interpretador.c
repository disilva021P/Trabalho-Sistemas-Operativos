#include<stdio.h>
#include <string.h>
#include <unistd.h>    
#include <sys/wait.h>  
#include <sys/types.h>
#include <stdlib.h>
#include"funcoes.h"
int interpretador(){
    char comando[11], ficheiro[255],ficheiroAcrescentar[255],linha[521];
    char programa[521] = "./funcoes/";
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
        int leitura=sscanf(linha, "%s %s %[^\n]", comando, ficheiro, ficheiroAcrescentar);
        if(strcmp(comando,"termina")==0){
            break;
        }
        if (!strcmp(comando,"acrescenta") && leitura != 2) {
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
        if(strcmp(comando,"mostra")!=0 && strcmp(comando,"copia")!=0 && strcmp(comando,"acrescenta")!=0 && strcmp(comando,"conta")!=0 && strcmp(comando,"apaga")!=0 && strcmp(comando,"informa")!=0 && strcmp(comando,"lista")!=0){
            printf("Comando: \"%s\" não existe\n",comando);
            continue;
        }
        strcat(programa, comando);
        pid_t pid= fork();
        if (pid== 0) {
            char *args[] = {programa, ficheiro,NULL};
            execve(programa, args, NULL);
            // Se execve falhar:
            printf("execve falhou");
            exit(1);
        }else if (pid>0){
            int status;
            wait(&status);
                
            if (WIFEXITED(status)) {
                int exit_code = WEXITSTATUS(status);
                if (exit_code == 0) {
                    printf("Função executada com sucesso!\n");
                } else {
                    printf("Erro com código %d\n", exit_code);
                }
            } else {
                printf("Filho terminou de forma anormal\n");
            }      
        }else{
            perror("fork falhou");
        }
    }
}