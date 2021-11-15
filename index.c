/*--------------------------------SISTEMA DE LOGIN E SENHA: CMD TERMINAL------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200

char nome[SIZE][50];
char email[SIZE][50];
int cpf[SIZE];
int telefone[SIZE];
int dataNascimento[SIZE];

int op;

void cadastro();

typedef struct 
{
    char login[30];
    char senha[30];
} pessoa; pessoa p[1]; //Nome da estrutura, diminiu o valor de pessoa para p[1];




int main(){

    char login[30]; //Esse vetor só existe dentro da função Main() Por isso não existe conflito com a struct;
    char senha[30];

    /* strcpy - essa função é responsável por armazenar strings dentro de um vetor */
    strcpy(p[0].login, "Medico");
    strcpy(p[0].senha, "123");

    printf("\nlogin:"); // \t = Tab;
    scanf("%s", login);
    printf("\nsenha:");
    scanf("%s", senha);

  


    /* strcmp - essa função é responsável por comparar strings   */
    if((strcmp(login, p[0].login)==0) && (strcmp(senha, p[0].senha)==0)){
        printf("Usuário logado.\n");
        cadastro();
    }else{
        printf("Login e/ou senha incorretos.\n");
    }

    return 0;
}


void cadastro(){
    static int linha;
    do{

        printf("\nDigite o nome do paciente: ");
        scanf("%s", nome[linha]);

        printf("\nDigite o email do paciente: ");
        scanf("%s", email[linha]);

        printf("\nDigite o CPF do paciente: ");
        scanf("%d", &cpf[linha]);

        printf("\nDigite o telefone do paciente: ");
        scanf("%d", &telefone[linha]);

        printf("\nDigite a data de nascimento do paciente: ");
        scanf("%d", &dataNascimento[linha]);

        printf("\nDigite 1 para continuarou outro valor para sair.");
        scanf("%d", &op);
        linha++;

    }while(op==1);

}