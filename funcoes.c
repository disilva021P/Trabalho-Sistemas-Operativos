#include<unistd.h>
#include<stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pwd.h> //nome do utilizador
#include <time.h> // para passar o tempo para texto
#include <dirent.h>
#include"funcoes.h"
#include<string.h>
int mostra(char* ficheiro){
    int f = open(ficheiro,O_RDONLY);
    char buffer[255];
    if(f==-1){
        return 0;
    }
    while (1){    
        int resultado =read(f,buffer,9);

        if(!resultado){
            printf("\n");
            break;
        }else if(resultado==-1){
            return -1;
        }else{
            buffer[resultado]='\0';
            printf("%s",buffer);
        }
    }
    close(f);
    return 1;
}

int copia(char* ficheiro) {
    int in = open(ficheiro, O_RDONLY);
    if (in < 0) {
        printf("Erro a abrir o ficheiro\n");
        return 1;
    }
    int out = open("ficheiro.copia", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buf;
    while (read(in, &buf, 1) > 0) {
        write(out, &buf, 1);
    }
    close(in);
    close(out);
    return 0;
}

int acrescenta(char* ficheiro, char* textoAdicionar) {
    int in = open(textoAdicionar, O_RDONLY);
    int out = open(ficheiro, O_WRONLY | O_APPEND); 
    if (in < 0 || out < 0) {
        printf("Erro a abrir o ficheiro\n");
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

int conta(char* ficheiro) {
    int fd = open(ficheiro, O_RDONLY);
    if (fd < 0) {
        printf("Erro a abrir o ficheiro\n");
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

int apaga(char* ficheiro) {
    if (unlink(ficheiro) != 0) {
        printf("Erro a apagar o ficheiro\n");
        return 1;
    }
    return 0;
}

int informa(char* ficheiro) {
    struct stat st;
    if (stat(ficheiro, &st) != 0) {
        printf("Erro a obter informação\n");
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

int listaDiretoria(char* diretoria) {
    DIR* d = opendir(diretoria ? diretoria : ".");
    if (!d) {
        printf("Erro a abrir a diretoria\n");
        return 1;
    }
    struct dirent* ent;
    while ((ent = readdir(d)) != NULL) {
        printf("%s\n",ent->d_name);
    }

    closedir(d);
    return 0;
}

int ficheiroExiste(char* ficheiro){
    if(access(ficheiro,F_OK)==0){
        return 1;
    }
    return 0;
}