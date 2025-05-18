#include<unistd.h>
#include <fcntl.h> 
#include"funcoes.h"
int mostra(char* ficheiro){
    int f = open(ficheiro,O_RDONLY);
    if(f==-1){
        return 0;
    }
    write(1,"ola123",6);
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