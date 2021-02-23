#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "funcoesmatematicas.h"

typedef struct aluno Aluno;

struct aluno
{
    int indice, anoNascimento;
    char *nome, *cpf, *curso, *disciplina, *sexo;
    float notas[3], mediafinal;
    char status;
};


int iAlunos = 0;
Aluno alunos[10];

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
    gets(v);
    return v;
}

void clean_stdin(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

float entradafloat(char *mensagem)
{
    float n;
    printf("%s", mensagem);
    scanf("%f", &n);
    return n;
}

int entradaInt(char *mensagem)
{
    int n;
    printf("%s", mensagem);
    scanf("%d", &n);
    return n;
}

void cabecalhosFinal()
{
    saidastr("\n********* RESULTADO FINAL DOS ESTUDANTES ********\n\n\n");
    saidastr("  NOME     ||     MEDIA     ||  RESULTADO   " );

}

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

// referencia = valor para aprovacao
int *checa_aprovacao(float m, float referencia)
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
    system("color C");
    saidastr("\n\n #################### FIM ####################\n\n");
}

void inicializar()
{
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    system("color 1F");
    saidastr("#################### Sistema Acadêmico ####################\n\n\n");
    saidastr("Seja bem vindo ao Sistema Acadêmico de controle escolar\n\n");
}

void selecionarMenu()
{
    int menu;
    saidastr("\nPor favor selecione abaixo qual funcionalidade deseja acessar:\n\n");
    printf("   1 -  Alunos\n   2 -  Cursos\n   3 -  Consultas \n   4 -  Relatórios \n\n");
    printf("   ");
    scanf("%d", &menu);

    selecionarSubMenu(menu);
}

void selecionarSubMenu(int menu)
{
    system("cls");
    int op;
    switch(menu)
    {
    case 1:
        saidastr("\n----------- Alunos -----------\n");
        saidastr("\nDgite o número da opção desejada:\n");
        saidastr("\n   1 -  Cadastrar Alunos\n   2 -  Alterar Dados \n   3 -  Consultar Dados \n   4 -  Excluir \n   5 -  Voltar  \n\n");
        printf("   ");
        scanf("%d", &op);
        OperacoesAlunos(op);
        break;
    case 2:
        saidastr("\n----------- Cursos -----------\n");
        saidastr("\nDgite o número da opção desejada:\n");
        saidastr("\n   1 -  Cadastrar curso\n   2 -  cadastrar disciplinas \n   3 -  Alterar  dados \n   4 -  Consultar todos alunos matriculados \n   5 -  Excluir curso \n   6 -  Voltar \n\n");
        printf("   ");
        scanf("%d", &op);
        OperacoesCursos(op);
        break;
    case 3:
        saidastr("\n----------- Consultas -----------\n\n");
        saidastr("\nDgite o número da opção desejada:\n");
        saidastr("  *** Dados de alunos ***\n");
        saidastr("\n   1 -  Por nome\n   2 -  Por cpf \n   3 -  Alunos aprovados \n   4 -  Alunos reprovados \n\n");
        saidastr("  *** Dados de cursos/disciplinas ***\n");
        saidastr("\n   5 -  Disciplina do curso X\n   6 -  Alunos matriculados no curso X\n   7 -  Alunos aprovados na disciplina X \n\n   8 -  voltar \n\n");
        printf("   ");
        scanf("%d", &op);
        OperacoesConsultas(op);
        break;
    case 4:
        saidastr("\n----------- Relatórios -----------\n");
        saidastr("\nDgite o número da opção desejada:\n");
        saidastr("\n   1 -  Listagem de alunos por curso\n   2 -  Listagem de alunos por disciplina \n   3 -  Listagem de alunos por curso/disciplina \n   4 -  Listagem de alunos aprovados por curso/disciplinas \n   5 -  Listagem de alunos reprovados por curso/disciplinas \n   6 -  Listagem de alunos reprovados em mais de quatro disciplina \n   7 -  Listagem de alunos com maior média por disciplina \n   8 -  Percentual de alunos aprovados e reprovados por disciplina \n   9 -  Percentual de alunos aprovados e reprovados por curso \n   10 -  Voltar  \n\n");
        printf("   ");
        scanf("%d", &op);
        OperacoesRelatorios(op);
        break;
    }

}

void OperacoesAlunos(int op)
{
    system("cls");
    switch(op)
    {
    case 1:
        cadastrarAluno();
        break;

    case 2:
        alterarDadosAluno();
        break;

    case 3:
        consultarDadosAluno();
        break;

    case 4:
        excluirAluno();
        break;

    case 5:
        main();
        break;
    }

}
void OperacoesCursos(int op)
{

}
void OperacoesConsultas(int op)
{

}
void OperacoesRelatorios(int op)
{

}

void cadastrarAluno()
{
    system("cls");
    saidastr("\n*** Cadastrar Alunos ***\n");
    char add;
    int a = 0;
    // ----------------------ENTRADA DE DADOS ---------------------
    a++;
    clean_stdin();
    printf("\n-- %dº Aluno\n\n", iAlunos+1);
    alunos[iAlunos].indice = iAlunos+1;
    alunos[iAlunos].nome = entradastr("\tDigite o nome do Aluno: ");
    alunos[iAlunos].cpf = entradastr("\n\tDigite o CPF do Aluno: ");
    int valido = validarcpf(alunos[iAlunos].cpf);
    while(!valido){
        saidastr("\n\t  --- CPF Inválido! --- \n");
        alunos[iAlunos].cpf = entradastr("\n\tDigite novamente o CPF do Aluno: ");
        valido = validarcpf(alunos[iAlunos].cpf);
    }
    alunos[iAlunos].sexo = entradastr("\n\tDigite o sexo do Aluno (M/F): ");
    alunos[iAlunos].anoNascimento = entradaInt("\n\tDigite o Ano de Nascimento do Aluno: ");
    clean_stdin();
    alunos[iAlunos].curso = entradastr("\n\tDigite o curso do Aluno: ");
    alunos[iAlunos].disciplina = entradastr("\n\tDigite a disciplina do Aluno: ");
    alunos[iAlunos].notas[0] = entradafloat("\n\tDigite nota 1: ");
    alunos[iAlunos].notas[1] = entradafloat("\tDigite nota 2: ");
    alunos[iAlunos].notas[2] = entradafloat("\tDigite nota 3: ");
    alunos[iAlunos].mediafinal = mediaa(alunos[iAlunos].notas, 3);
    alunos[iAlunos].status = checa_aprovacao(alunos[iAlunos].mediafinal, 6);

    printf("\n");
    printf("\n -- Média Final:  %.2f ", alunos[iAlunos].mediafinal);
    imprime_aprovacao(alunos[iAlunos].status);


    iAlunos++;

    saidastr("\nDeseja cadastrar mais um aluno?<S/N>:  ");
    scanf("%s", &add);
    if((add == 's') || (add == 'S'))
    {
        cadastrarAluno();
    }
    else
    {
        selecionarSubMenu(1);
    }
}

void alterarDadosAluno()
{
    system("cls");
    saidastr("\n*** Alterar Dados de um Aluno ***\n");
    saidastr("\n Digite o número da chamada do aluno que deseja alterar: \n\n");

    int i, indice;

    if(iAlunos == 0)
    {
        char cad;
        saidastr("\n ---- Nenhum aluno foi encontrado! ----\n\n");
        saidastr("\nDeseja Cadastrar um aluno?<S/N>:  ");
        scanf("%s", &cad);
        if((cad == 's') || (cad == 'S'))
        {
            cadastrarAluno();
        }

    }

    for(i = 0; i < iAlunos; i++)
    {
        printf("   \n%d - ", alunos[i].indice);
        saidastr(alunos[i].nome);
    }

    printf("\n\n");
    scanf("%d", &indice);
    indice--;

    clean_stdin();
    printf("\n-- %dº Aluno\n\n", indice+1);
    alunos[indice].indice = indice+1;
    alunos[indice].nome = entradastr("\tDigite o nome do Aluno: ");
    alunos[indice].cpf = entradastr("\n\tDigite o CPF do Aluno: ");
    int valido = validarcpf(alunos[indice].cpf);
    while(!valido){
        saidastr("\n\t  --- CPF Inválido! --- \n");
        alunos[indice].cpf = entradastr("\n\tDigite novamente o CPF do Aluno: ");
        valido = validarcpf(alunos[indice].cpf);
    }
    alunos[indice].sexo = entradastr("\n\tDigite o sexo do Aluno (M/F): ");
    alunos[indice].anoNascimento = entradaInt("\n\tDigite o Ano de Nascimento do Aluno: ");
    clean_stdin();
    alunos[indice].curso = entradastr("\n\tDigite o curso do Aluno: ");
    alunos[indice].disciplina = entradastr("\n\tDigite a disciplina do Aluno: ");
    alunos[indice].notas[0] = entradafloat("\n\tDigite nota 1: ");
    alunos[indice].notas[1] = entradafloat("\tDigite nota 2: ");
    alunos[indice].notas[2] = entradafloat("\tDigite nota 3: ");
    alunos[indice].mediafinal = mediaa(alunos[indice].notas, 3);
    alunos[indice].status = checa_aprovacao(alunos[indice].mediafinal, 6);

    saidafloat("\n -- Média Final:  ",alunos[indice].mediafinal);
    imprime_aprovacao(alunos[indice].status);

    printf("\n\n Alterações realizadas com sucesso!\n\n");
    system("pause");
    selecionarSubMenu(1);

}

void consultarDadosAluno()
{
    system("cls");
    saidastr("\n*** Consultar Dados de um Aluno ***\n");
    char con;
    int i, indice;
    if(iAlunos == 0)
    {
        char cad;
        saidastr("\n ---- Nenhum aluno foi encontrado! ----\n\n");
        saidastr("\nDeseja Cadastrar um aluno?<S/N>:  ");
        scanf("%s", &cad);
        if((cad == 's') || (cad == 'S'))
        {
            cadastrarAluno();
        }

    }
    saidastr("\n Digite o número da chamada do aluno que deseja Consultar: \n\n");
    for(i = 0; i < iAlunos; i++)
    {
        printf("\n   %d - ", alunos[i].indice);
        saidastr(alunos[i].nome);
    }


    printf("\n\n");
    printf("  ");
    scanf("%d", &indice);
    indice--;

    saidastr("\nNome:  ");
    saidastr(alunos[indice].nome);
    saidastr("\nCPF:  ");
    saidastr(alunos[indice].cpf);
    saidastr("\nSexo:  ");
    saidastr(alunos[indice].sexo);
    printf("\nAno de nascimento:  %d", alunos[indice].anoNascimento);
    saidastr("\nCurso:  ");
    saidastr(alunos[indice].curso);
    saidastr("\nDisciplina:  ");
    saidastr(alunos[indice].disciplina);
    saidafloat("\nNota 1:   ",alunos[indice].notas[0]);
    saidafloat("\nNota 2:   ",alunos[indice].notas[1]);
    saidafloat("\nNota 3:   ",alunos[indice].notas[2]);
    saidafloat("\n -- Média Final:  ",alunos[indice].mediafinal);
    imprime_aprovacao(alunos[indice].status);

    saidastr("\nDeseja Consultar mais um aluno?<S/N>:  ");
    scanf("%s", &con);
    if((con == 's') || (con == 'S'))
    {
        alunos[indice].indice = indice+1;
        alunos[indice].nome = entradastr("\tDigite nome Aluno: ");
        alunos[indice].notas[0] = entradafloat("\n\tDigite nota 1: ");
        alunos[indice].notas[1] = entradafloat("\tDigite nota 2: ");
        alunos[indice].notas[2] = entradafloat("\tDigite nota 3: ");
        alunos[indice].mediafinal = mediaa(alunos[indice].notas, 3);
        alunos[indice].status = checa_aprovacao(alunos[indice].mediafinal, 6);
        system("cls");
        consultarDadosAluno();
    }
    else
    {
        selecionarSubMenu(1);
    }

}

void excluirAluno()
{
    system("cls");
    saidastr("\n*** Excluir Aluno ***\n");
    char nullStr[20] = {"\0"};

    if(iAlunos == 0)
    {
        char cad;
        saidastr("\n ---- Nenhum aluno foi encontrado! ----\n\n");
        saidastr("\nDeseja Cadastrar um aluno?<S/N>:  ");
        scanf("%s", &cad);
        if((cad == 's') || (cad == 'S'))
        {
            cadastrarAluno();
        }

    }

    saidastr("\n Digite o número da chamada do aluno que deseja Consultar: \n\n");
    char del;
    int i, indice;
    for(i = 0; i < iAlunos; i++)
    {
        printf("   \n%d - ", alunos[i].indice);
        saidastr(alunos[i].nome);
    }

    printf("\n\n");
    printf("  ");
    scanf("%d", &indice);
    indice--;

    saidastr("\n------- Dados do Aluno ------- \n");
    saidastr("\nNome:  ");
    saidastr(alunos[indice].nome);
    saidafloat("\nNota 1:   ",alunos[indice].notas[0]);
    saidafloat("\nNota 2:   ",alunos[indice].notas[1]);
    saidafloat("\nNota 3:   ",alunos[indice].notas[2]);
    saidafloat("\n -- Média Final:  ",alunos[indice].mediafinal);
    imprime_aprovacao(alunos[indice].status);

    saidastr("\nTem certeza que deseja excluir esse aluno?<S/N>:  ");
    scanf("%s", &del);
    if((del == 's') || (del == 'S'))
    {
        alunos[indice].indice = 0;
        alunos[indice].nome = nullStr;
        alunos[indice].notas[0] = 0;
        alunos[indice].notas[1] = 0;
        alunos[indice].notas[2] = 0;
        alunos[indice].mediafinal = 0;
        alunos[indice].status = 0;
        iAlunos --;
        printf("\n\n Aluno excluído com sucesso!\n\n");
        system("pause");
        selecionarSubMenu(1);
    }
    else
    {
        selecionarSubMenu(1);
    }


}

int main()
{
    inicializar();
    selecionarMenu();
    finalizar();
    return 0;
}
