#include "Git.h"

int main(){
    char *quit = "quit";
    int cond = 1;
    hash *branch = inicia_hash();
    header *dados_pull = cria_header();
    guarda_info_hash(branch, "Master");
    hash *commits = inicia_hash();
    guarda_info_commit_hash(commits, "FirstCommit", "Master");
    int brach_atual = -1;

    while(cond == 1){
        char *comando = (char*) malloc(50 * sizeof(char));

        printf("User@PC:$ ");
        gets(comando);
        
        if(strcmp(comando, quit) == 0){
            break;
        }

        header *linha = separa_string(comando);

        verifica_comando(linha, branch, commits, &brach_atual, &dados_pull);

        limpa(linha);

        printf("\n");
    }
    limpa_hash(branch);
    limpa_hash(commits);
    printf("Finalizando programa...\n");
    
    return 0;
}