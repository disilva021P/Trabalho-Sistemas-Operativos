#include <unistd.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if(argc < 2){
        return 1;
    }

    char* ficheiro = argv[1];

    if (unlink(ficheiro) != 0) {
        printf("Erro a apagar o ficheiro %s\n", ficheiro);
        return 1;
    }
    return 0;
}
