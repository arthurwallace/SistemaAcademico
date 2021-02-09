#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "funcoesmatematicas.h"

int Restr_caracteres ( char num [ 4 ] )
{
    int i, a = 0;
    a = strlen ( num );
    for ( i = 0; i < a; i++ )
    {
        if ( num [ i ] < '0' || num [ i ] > '9' )
            return 0;
    }
    return 1;
}

int validarcpf (char c_pf[])
{
    int Vet_cpf [ 12 ];
    int Vet_cpf_2 [ 12 ];
    int Vet_cpf_3 [ 12 ];
    int val_cpf [ 10 ] = { 10, 9, 8, 7, 6, 5, 4, 3, 2 };
    int val_cpf_2 [ 11 ] = { 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 };
    int erro = 0;
    do
    {
        int a = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0, l = 0, o = 0,
            u = 0, cont = 0;
        do
        {
            if ( erro == 1 )
            {
            }
            cont = 0;
            for ( i = 0; c_pf [ i ] != '\0'; i = i + 1 )
            {
                if ( c_pf [ i ] )
                    cont = cont + 1;
            }
            if ( Restr_caracteres ( c_pf ) == 0 )
            {
                return 0;
            }
            if ( cont < 11 || cont > 11 )
            {
                return 0;
            }
            break;
        }
        while ( ( cont < 11 || cont > 11 ) );
        a = 0;
        while ( c_pf [ a ] != '\0' )
        {
            Vet_cpf [ a ] = c_pf [ a ] - '0';
            a++;
        }
        o = Vet_cpf [ 9 ];
        u = Vet_cpf [ 10 ];
        for ( i = 0; i < 9; i++ )
        {
            Vet_cpf_2 [ i ] = Vet_cpf [ i ] * val_cpf [ i ];
            e += Vet_cpf_2 [ i ];
        }
        f = e % 11;
        g = 11 - f;
        if ( g > 9 )
            g = 0;
        Vet_cpf [ 9 ] = g;
        for ( i = 0; i < 10; i++ )
        {
            Vet_cpf_3 [ i ] = Vet_cpf [ i ] * val_cpf_2 [ i ];
            h += Vet_cpf_3 [ i ];
        }
        j = h % 11;
        l = 11 - j;
        if ( l > 9 )
            l = 0;
        if ( g == o && l == u )
            return 1;
        else  return 0;
    }
    while ( 1 );
}

float mediaa(float notas[], int tam)
{
    float somanotas = 0;
    for (int i= 0; i < tam; i++)
    {
        somanotas+= *(notas++);
    }
    return somanotas/tam;
}

float mediap(float notas[],float pesos[], int tam)
{
    float somanotas = 0, somapesos = 0;
    for (int i= 0; i < tam; i++)
    {
        somanotas+= ((*(notas++)) * (*(pesos++)));
        somapesos+= *(pesos++);
    }
    return somanotas/somapesos;
}

float soma(float x, float y)
{
    return x + y;
}

float subtracao(float x, float y)
{
    return x - y;
}

float produto(float x, float y)
{
    return x * y;
}

float divisao(float x, float y)
{
    if (y != 0)
    {
        return x / y;
    }
    else
    {
        printf("\n Erro: Divisão por Zero");
        return 0;
    }
}

float quadrado(float x)
{
    return x * x;
}

float cubo(float x)
{
    return x * x * x;
}

int restoDivisao(int x, int y)
{
    return x % y;
}

int par(int x)
{
    if (x % 2 == 0)
        return 1;
    else
        return 0;
}

int multiplo(int x, int y)
{
    return !(x % y == 0);
}

int primo(int x)
{
    int divisores = 0;
    for (int i = 2; (i*i) <= x; i++)
    {
        if (x % i == 0)
        {
            ++divisores;
        }
        if (divisores > 0)
        {
            break;
        }
    }
    if (divisores > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int *divisores(int x)
{
    int *vetor = calloc(x, sizeof(int));
    int ind = 0;
    for(int i=1; i <= x; i++)
    {
        if (x % i == 0)
        {
            vetor[ind++] = i;
        }
    }
    return(vetor);
}
