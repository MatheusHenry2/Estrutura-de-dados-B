#include <iostream>
#include <math.h>
using namespace std;

#define N 1023
#define M 32765

int main()
{
    int x, y, vet[N], vetor[M], cont1 = 0, cont2 = 0;
    int pivo, start = 0, end = N - 1, dado, cb = 0;
    int pivo2, start2 = 0, end2 = M - 1, dado2, cb2 = 0;

    for (int i = 0; i < N; i++)
        vet[i] = i;

    cout << "\n Digite o elemento a ser buscado  SEQUENCIAL 0 a 1022 :";
    cin >> x;

    for (int i = 0; i < N; i++)
    {
        cont1++;
        if (x == vet[i])
            cout << " Elemento encontrado com (" << cont1 << " comparacoes ! )";
    }

    for (int i = 0; i < M; i++)
        vetor[i] = i;

    cout << "\n\n Digite o elemento a ser buscado SEQUENCIAL 0 a 32764 ";
    cin >> y;

    for (int i = 0; i < M; i++)
    {
        cont2++;
        if (y == vetor[i])
            cout << " Elemento encontrado com ( " << cont2 << "comparacoes )";
    }

    cout << "\n\n Digite o elemento a ser buscado BINARIO 0 A 1022 :";
    cin >> dado;

    while (start <= end)
    {
        cb++;
        pivo = (start + end) / 2;

        if (dado == vet[pivo])
        {
            cout << " Elemento encontrado com (" << cb << "comparacoes )";
            break;
        }

        else if (dado < vet[pivo])
            end = pivo - 1;

        else if (dado > vet[pivo])
            start = pivo + 1;
    }

    cout << "\n\n Digite o elemento a ser buscado BINARIO 0 A 32764 :";
    cin >> dado2;

    while (start2 <= end2)
    {
        cb2++;
        pivo2 = (start2 + end2) / 2;

        if (dado2 == vetor[pivo2])
        {
            cout << " Elemento encontrado com (" << cb2 << " comparacoes )";
            break;
        }

        else if (dado2 < vetor[pivo2])
            end2 = pivo2 - 1;

        else if (dado2 > vetor[pivo2])
            start2 = pivo2 + 1;
    }

    return 0;
}