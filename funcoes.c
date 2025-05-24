#include<unistd.h>

int ficheiroExiste(char* ficheiro){
    if(access(ficheiro,F_OK)==0){
        return 1;
    }
    return 0;
}