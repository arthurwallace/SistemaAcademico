#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "funcoesmatematicas.h"

#define QTD 3

typedef struct aluno Aluno;
struct aluno
{
    char *nome, *cpf;
    float notas[3], mediafinal;
    char status;  // 1 = aprovado  0 = reprovado
};


//____________________variaveis globais

// ***** melhor não ter***
//______________________________________


//_______Headers________________________
void saidastr(char *mensagem);
void saidafloat(char *mensagem, float valor);
char *entradastr(char *mensagem);
float entradafloat(char *mensagem);
void imprime_aprovacao(char status);
int checa_aprovacao(float m, float referencia);
//______________________________________


void saidastr(char *mensagem)
{
    printf("%s", mensagem);
}

void saidafloat(char *mensagem, float valor)
{
    printf("%s%.2f", mensagem, valor);
}

char *entradastr(char *mensagem)
{
    char *v = (char *) malloc((sizeof(char) * sizeof(v)));
    printf("%s", mensagem);
    scanf(" %60[^\n]",v);
    return v;
}

float entradafloat(char *mensagem)
{
    float n;
    printf("%s", mensagem);
    scanf("%f", &n);
    return n;
}

// referencia = valor para aprovacao   *********
void imprime_aprovacao(char status)
{
    if (status)
    {
        saidastr("\n => status = APROVADO\n\n\n");
    }
    else
    {
        saidastr("\n => status = REPROVADO\n\n\n");
    }
}

int checa_aprovacao(float m, float referencia)
{
    if (m >= referencia)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void finalizar()
{
    system("cls");
    system("color 2E");
    saidastr("\n\n #################### FIM ####################\n\n");
}

void inicializar()
{
    setlocale(LC_ALL, "Portuguese");
    system("cls"); // system("clear"); linux
    system("color 1F");
    saidastr("#################### Exemplo Notas Alunos ####################\n\n\n");
}


void gerente()
{
    Aluno alunos[QTD];
    int a = 0, i;
    // ----------------------ENTRADA DE DADOS ---------------------
    for (i=0; i < QTD; i++)
    {
        a++;
        printf("#Aluno: %d\n", a);
        alunos[i].nome = entradastr("\tDigite nome Aluno: ");
        alunos[i].notas[0] = entradafloat("\n\tDigite nota 1: ");
        alunos[i].notas[1] = entradafloat("\tDigite nota 2: ");
        alunos[i].notas[2] = entradafloat("\tDigite nota 3: ");
        alunos[i].mediafinal = mediaa(alunos[i].notas, 3);
        alunos[i].status = checa_aprovacao(alunos[i].mediafinal, 6);
        system("cls");
    }
    // ----------------------SAIDA DE DADOS ---------------------
    saidastr("\n-------------RELATÓRIO-------------------");
    a = 0;
    for (i=0; i < QTD; i++)
    {
        a++;
        printf("\n#Aluno: %d\n", a);
        saidafloat("\n Média Final= ", alunos[i].mediafinal);
        saidastr("\n  ALUNO: ");
        saidastr(alunos[i].nome);
        imprime_aprovacao(alunos[i].status);
        system("pause");
    }
    float maiormedia = 0;
    for (i=0; i < QTD; i++)
    {
        if (alunos[i].mediafinal > maiormedia)
        {
            maiormedia = alunos[i].mediafinal;
            a = i;
        }
    }
    saidastr("\n\n__________________________");
    saidastr("\n Maior média: ");
    saidastr(alunos[a].nome);
    saidafloat("\n---Média= ", alunos[a].mediafinal);
    saidastr("\n\n__________________________");

    system("pause");
}

int main()
{
    inicializar();
    gerente();
    finalizar();
    return 0;
}

