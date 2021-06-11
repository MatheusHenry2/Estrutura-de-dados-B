#include <iostream>
#include <ctime>
using namespace std;
#define N 200000

long long swap1, comp;

void quick(int v[], int esq, int dir)
{
  int i, j, pivo, aux;

  i = esq;
  j = dir;
  pivo = v[(esq + dir) / 2];

  do
  {
    while (v[i] < pivo)
    {
      i++;
      comp++;
    }
    while (v[j] > pivo)
    {
      j--;
      comp++;
    }

    comp++;
    if (i <= j)
    {
      swap1++;
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
      i++;
      j--;
    }
  } while (i < j);

  if (esq < j)
    quick(v, esq, j);
  if (i < dir)
    quick(v, i, dir);
}

int main()
{

  int vet[N], op;
  double duracao;

  do
  {
    cout << "\n (1) Random (2)ordenado (3) inverso (0) exit" << endl;
    cin >> op;

    if (op == 1)
    {
      for (int i = 0; i < N; i++)
        vet[i] = rand() % 1000;
    }
    else if (op == 2)
    {
      for (int i = 0; i < N; i++)
        vet[i] = i + 1;
    }
    else if (op == 3)
    {
      for (int i = 0; i < N; i++)
        vet[i] = N - i + 1;
    }

    clock_t start = clock();

    quick(vet, 0, N - 1);

    clock_t finish = clock();

    duracao = (double)(finish - start) / CLOCKS_PER_SEC;

    cout << " O tempo e " << duracao << "s";
    cout << "\n Total de trocas :" << swap1;
    cout << "\n Total de comparacoes:" << comp;
  } while (op != 0);
}