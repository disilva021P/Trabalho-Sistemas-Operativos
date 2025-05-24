#include <stdio.h>
#include <dirent.h>

int main(int argc, char* argv[]) {
    char* diretoria = NULL;
    if(argc==1){
        diretoria=".";
    }
    else if(argc == 2){
        diretoria = argv[1];
    }else{
        return 1;
    }

    DIR* d = opendir(diretoria);
    if (!d) {
        printf("Erro a abrir a diretoria %s\n", diretoria);
        return 1;
    }
    struct dirent* ent;
    while ((ent = readdir(d)) != NULL) {
        printf("%s\n", ent->d_name);
    }
    closedir(d);
    return 0;
}
