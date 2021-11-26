/*--------------------------------SISTEMA DE LOGIN E SENHA: CMD TERMINAL------------------------------------ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 600

char nome[SIZE][50];
char email[SIZE][50];
char diagnostico[SIZE][50];
char estado[SIZE][50];
char bairro[SIZE][50];
char cidade[SIZE][50];
char comorbidade[SIZE][50];
char temComorbidade[SIZE][2];
char dataNascimento[SIZE][50];
int cep[SIZE];
int cpf[SIZE];
int telefone[SIZE];
int diaNascimento[SIZE];
int mesNascimento[SIZE];
int anoNascimento[SIZE];
int anoAtual[SIZE];

int op;

void cadastro();

typedef struct {
    char login[30];
    char senha[30];
} 

pessoa; pessoa p[1]; //Nome da estrutura, diminiu o valor de pessoa para p[1];

int main() {
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
    if((strcmp(login, p[0].login)==0) && (strcmp(senha, p[0].senha)==0)) {
        printf("Usuario logado.\n");
        cadastro();
    } else {
        printf("Login e/ou senha incorretos.\n");
    }

    return 0;
}

void cadastro(){
    static int linha;
    FILE *fptr;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int anoAtual = tm.tm_year + 1900;
    printf("%d", anoAtual);

    fptr = fopen("dados.txt", "a+");
    
    do{
        printf("\nDigite o nome do paciente: ");
        scanf("%s", nome[linha]);
        char *conteudoLinha[1000];
        memset(conteudoLinha, 0, 1000);
        strcat(conteudoLinha, "Paciente: ");
        strcat(conteudoLinha, nome[linha]);
        strcat(conteudoLinha, "\n");

        printf("\nDigite o email do paciente: ");
        scanf("%s", email[linha]);
        strcat(conteudoLinha, "Email: ");
        strcat(conteudoLinha, email[linha]);
        strcat(conteudoLinha, "\n");

        printf("\nDigite o CPF do paciente: ");
        scanf("%s", &cpf[linha]);
        strcat(conteudoLinha, "CPF: ");
        strcat(conteudoLinha, &cpf[linha]);
        strcat(conteudoLinha, "\n");

        printf("\nDigite o telefone do paciente: ");
        scanf("%s", &telefone[linha]);
        strcat(conteudoLinha, "telefone: ");
        strcat(conteudoLinha, &telefone[linha]);
        strcat(conteudoLinha, "\n");

        printf("\nDigite o CEP do paciente: ");
        scanf("%s", &cep[linha]);
        strcat(conteudoLinha, "CEP: ");
        strcat(conteudoLinha, &cep[linha]);
        strcat(conteudoLinha, "\n");

        printf("\nDigite o estado do paciente: ");
        scanf("%s", &estado[linha]);
        strcat(conteudoLinha, "Estado: ");
        strcat(conteudoLinha, &estado[linha]);
        strcat(conteudoLinha, "\n");

        printf("\nDigite o bairro do paciente: ");
        scanf("%s", &bairro[linha]);
        strcat(conteudoLinha, "Bairro: ");
        strcat(conteudoLinha, &bairro[linha]);
        strcat(conteudoLinha, "\n");

        printf("\nDigite a cidade do paciente: ");
        scanf("%s", &cidade[linha]);
        strcat(conteudoLinha, "Cidade: ");
        strcat(conteudoLinha, &cidade[linha]);
        strcat(conteudoLinha, "\n");

        printf("\nDigite o dia de nascimento do paciente: ");
        scanf("%s", &diaNascimento[linha]);

        printf("\nDigite o mes de nascimento do paciente: ");
        scanf("%s", &mesNascimento[linha]); 

        printf("\nDigite o ano de nascimento do paciente: ");
        scanf("%s", &anoNascimento[linha]);
        int idade = anoAtual - &anoNascimento[linha]; // n consigo definir a idade aqui

        strcat(dataNascimento, diaNascimento);
        strcat(dataNascimento, "/");
        strcat(dataNascimento, mesNascimento);
        strcat(dataNascimento, "/");
        strcat(dataNascimento, anoNascimento);

        strcat(conteudoLinha, "idade em: ");
        strcat(conteudoLinha, idade);
        strcat(conteudoLinha, "\n");

        strcat(conteudoLinha, "Nascido em: ");
        strcat(conteudoLinha, dataNascimento);
        strcat(conteudoLinha, "\n");
        
        printf("\nDigite a data de diagnostico do paciente: ");
        scanf("%s", &diagnostico[linha]);
        strcat(conteudoLinha, "Diagnosticado em: ");
        strcat(conteudoLinha, &diagnostico[linha]);
        strcat(conteudoLinha, "\n");
        
        printf("\nO paciente tem alguma comorbidade? digite s para SIM e n para NAO: ");
        scanf("%s", &temComorbidade[linha]);
        
        if(strcmp(temComorbidade, "s") == 0) {
            printf("\nDigite a(s) comorbidade(s) do paciente: ");
            scanf("%s", &comorbidade[linha]);
            strcat(conteudoLinha, "Comorbidade(s): ");
            strcat(conteudoLinha, &comorbidade[linha]);
            strcat(conteudoLinha, "\n");
        }

        fprintf(fptr, "%s", conteudoLinha);
        fclose(fptr);
        printf("\nDigite 1 para continuar ou outro valor para sair. ");
        scanf("%d", &op);
        linha++;

    } while(op==1);
}