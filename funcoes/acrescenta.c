#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if(argc < 3){
        return 1;
    }

    char* ficheiro = argv[1];
    char* textoAdicionar = argv[2];

    int in = open(textoAdicionar, O_RDONLY);
    int out = open(ficheiro, O_WRONLY | O_APPEND); 
    if (in < 0 || out < 0) {
        printf("Erro a abrir os ficheiros\n");
        if(in >= 0) close(in);
        if(out >= 0) close(out);
        return 1;
    }

    char buf;
    while (read(in, &buf, 1) > 0) {
        write(out, &buf, 1);
    }
    close(in);
    close(out);
    return 0;
}
