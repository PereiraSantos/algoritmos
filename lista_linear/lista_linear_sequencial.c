#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;

} REGISTRO;

typedef struct
{
    REGISTRO A[MAX + 1];
    int nroElem;
} LISTA;

void inicializarLista(LISTA *l)
{
    l->nroElem = 0;
}

int tamanho(LISTA *l)
{
    return l->nroElem;
}

void exebirLista(LISTA *l)
{
    int i;
    printf("Lista: \" ");
    for (i = 0; i < l->nroElem; i++)
        printf("%i", l->A[i].chave);

    printf("\"\n");
}

int buscaSequencial(LISTA *l, TIPOCHAVE ch)
{
    int i = 0;
    while (i < l->nroElem)
    {
        if (ch == l->A[i].chave)
            return i;
        else
            i++;
    }

    return -1;
}

int buscaSentinela(LISTA *l, TIPOCHAVE ch)
{
    int i = 0;
    l->A[l->nroElem].chave = ch;
    while (l->A[i].chave != ch)
    {
        i++;
    }

    if (i == l->nroElem)
        return -1;
    else
        return i;
}

bool inserirElementLista(LISTA *l, REGISTRO reg, int i)
{
    int j;
    if ((l->nroElem == MAX) || (i < 0) || (i > l->nroElem))
        return false;
    for (j = l->nroElem; j > i; j--)
        l->A[j] = l->A[j - 1];
    l->A[i] = reg;
    l->nroElem++;
    return true;
}

bool inserirElemListOrd(LISTA *l, REGISTRO reg)
{
    if (l->nroElem >= MAX)
        return false;

    int pos = l->nroElem;

    while (pos > 0 && l->A[pos - 1].chave > reg.chave)
    {
        l->A[pos] = l->A[pos - 1];
        pos--;
    }
    l->A[pos] = reg;
    l->nroElem++;
}

int buscaBinaria(LISTA *l, TIPOCHAVE ch)
{
    int esq, dir, meio;
    esq = 0;
    dir = l->nroElem - 1;

    while (esq <= dir)
    {
        meio = ((esq + dir) / 2);
        if (l->A[meio].chave == ch)
            return meio;
        else
        {
            if (l->A[meio].chave < ch)
            {
                esq = meio + 1;
            }
            else
            {
                dir = meio - 1;
            }
        }
    }

    return -1;
}

bool excluirElemetLista(TIPOCHAVE ch, LISTA *l)
{
    int pos, j;
    // pos = buscaSequencial(l, ch);
    pos = buscaBinaria(l, ch);
    if (pos == -1)
        return false;
    for (j = pos; j < l->nroElem - 1; j++)
        l->A[j] = l->A[j + 1];

    l->nroElem--;
    return true;
}

void reInicializarLista(LISTA *l)
{
    l->nroElem = 0;
}
