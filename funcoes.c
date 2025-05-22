#include<unistd.h>
#include<stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h> 
#include"funcoes.h"

int mostra(char* ficheiro){
    int f = open(ficheiro,O_RDONLY);
    char buffer[10];
    if(f==-1){
        return 0;
    }
    while (1){
        
        int resultado =read(f,buffer,9);
        buffer[9]='\0';
        printf("lido: %s\n",buffer);
        if(!resultado){
            break;
        }else if(resultado==-1){
            return -1;
        }
        printf("%d ola?",resultado);
    }
    
    
    
    close(f);
    return 1;
}

    int copia(char* ficheiro) {
    int in = open(ficheiro, O_RDONLY);
    if (in < 0) {
        write(2, "Erro ao abrir ficheiro\n", 24);
        return 1;
    }

    int out = open("ficheiro.copia", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buf[1];
    while (read(in, buf, 1) > 0) {
        write(out, buf, 1);
    }

    close(in);
    close(out);
    return 0;
}

int acrescenta(char* ficheiro) {
    int in = open(ficheiro, O_RDONLY);
    int out = open("destino.txt", O_WRONLY | O_APPEND); 
    if (in < 0 || out < 0) {
        write(2, "Erro ao abrir ficheiro\n", 24);
        return 1;
    }

    char buf[1];
    while (read(in, buf, 1) > 0) {
        write(out, buf, 1);
    }

    close(in);
    close(out);
    return 0;
}

int conta(char* ficheiro) {
    int fd = open(ficheiro, O_RDONLY);
    if (fd < 0) {
        write(2, "Erro ao abrir ficheiro\n", 24);
        return 1;
    }

    char c;
    int linhas = 0;
    while (read(fd, &c, 1) > 0) {
        if (c == '\n') linhas++;
    }

    char out[50];
    int len = snprintf(out, 50, "Linhas: %d\n", linhas);
    write(1, out, len);
    close(fd);
    return 0;
}

int apaga(char* ficheiro) {
    if (unlink(ficheiro) != 0) {
        write(2, "Erro ao apagar ficheiro\n", 25);
        return 1;
    }
    return 0;
}

int informa(char* ficheiro) {
    struct stat st;
    if (stat(ficheiro, &st) != 0) {
        write(2, "Erro ao obter info\n", 20);
        return 1;
    }

    if (S_ISREG(st.st_mode)) write(1, "Tipo: ficheiro\n", 16);
    else if (S_ISDIR(st.st_mode)) write(1, "Tipo: diretoria\n", 17);
    else write(1, "Tipo: outro\n", 13);

    return 0;
}

int listaDiretoria(char* diretoria) {
    DIR* d = opendir(diretoria ? diretoria : ".");
    if (!d) {
        write(2, "Erro ao abrir diretoria\n", 25);
        return 1;
    }

    struct dirent* ent;
    while ((ent = readdir(d)) != NULL) {
        write(1, ent->d_name, strlen(ent->d_name));
        write(1, "\n", 1);
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
int Verifica