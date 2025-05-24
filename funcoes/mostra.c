#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    if(argc < 2){
        return 1;
    }

    char* ficheiro = argv[1];
    int f = open(ficheiro, O_RDONLY);
    char buffer[255];

    if(f == -1){
        printf("Erro a abrir o ficheiro %s\n", ficheiro);
        return 1;
    }
    while (1){    
        int resultado = read(f, buffer, 9);

        if(resultado == 0){
            printf("\n");
            break;
        } else if(resultado == -1){
            close(f);
            return -1;
        } else {
            buffer[resultado] = '\0';
            printf("%s", buffer);
        }
    }
    close(f);
    return 0;
}
