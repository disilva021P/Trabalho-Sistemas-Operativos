#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if(argc < 2){
        return 1;
    }

    char* ficheiro = argv[1];
    int in = open(ficheiro, O_RDONLY);
    if (in < 0) {
        printf("Erro a abrir o ficheiro %s\n", ficheiro);
        return 1;
    }
    strcat(ficheiro,"(COPIA)");
    int out = open(ficheiro, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out < 0) {
        printf("Erro a criar o ficheiro de copia\n");
        close(in);
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
