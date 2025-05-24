#include <sys/stat.h>
#include <stdio.h>
#include <pwd.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if(argc < 2){
        return 1;
    }

    char* ficheiro = argv[1];
    struct stat st;
    if (stat(ficheiro, &st) != 0) {
        printf("Erro a obter informação do ficheiro %s\n", ficheiro);
        return 1;
    }

    printf("Tipo de ficheiro: ");
    if (S_ISREG(st.st_mode))
        printf("Ficheiro normal\n");
    else if (S_ISDIR(st.st_mode))
        printf("Diretoria\n");
    else if (S_ISLNK(st.st_mode))
        printf("Link simbólico\n");
    else if (S_ISCHR(st.st_mode))
        printf("Dispositivo de caractere\n");
    else if (S_ISBLK(st.st_mode))
        printf("Dispositivo de bloco\n");
    else if (S_ISFIFO(st.st_mode))
        printf("FIFO (pipe)\n");
    else if (S_ISSOCK(st.st_mode))
        printf("Socket\n");
    else
        printf("Desconhecido\n");

    printf("i-node: %ld\n", (long) st.st_ino);

    struct passwd *pw = getpwuid(st.st_uid);
    printf("Utilizador dono: %s\n", pw ? pw->pw_name : "desconhecido");

    char buf[20];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&st.st_atime));
    printf("Último acesso: %s\n", buf);

    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&st.st_mtime));
    printf("Última modificação: %s\n", buf);

    return 0;
}
