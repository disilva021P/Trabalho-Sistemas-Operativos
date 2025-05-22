#include<unistd.h>
#include<stdio.h>
#include <fcntl.h> 
#include"funcoes.h"
int mostra(char* ficheiro){
    int f = open(ficheiro,O_RDONLY);
    char buffer[10];
    if(f==-1){
        return 0;
    }
    while (1){
        
        int resultado =read(f,buffer,9);
        buffer[9]='\0';
        printf("lido: %s\n",buffer);
        if(!resultado){
            break;
        }else if(resultado==-1){
            return -1;
        }
        printf("%d ola?",resultado);
    }
    
    
    
    close(f);
    return 1;
}
int copia(char* ficheiro){
    
}
int acrescenta(char* ficheiro){
    
}
int conta(char* ficheiro){
    
}
int apaga(char* ficheiro){
    
}
int informa(char* ficheiro){
    
}
int listaDiretoria(char* diretoria){
    
}
int ficheiroExiste(char* ficheiro){
    if(access(ficheiro,F_OK)==0){
        return 1;
    }
    return 0;
}
int Verifica