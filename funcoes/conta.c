#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if(argc < 2){
        return 1;
    }

    char* ficheiro = argv[1];
    int fd = open(ficheiro, O_RDONLY);
    if (fd < 0) {
        printf("Erro a abrir o ficheiro %s\n", ficheiro);
        return 1;
    }

    char c;
    int linhas = 1;
    while (read(fd, &c, 1) > 0) {
        if (c == '\n') linhas++;
    }

    printf("Linhas: %d\n", linhas);
    close(fd);
    return 0;
}
