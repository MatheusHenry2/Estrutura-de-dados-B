#include <iostream>
#include <time.h>
using namespace std;
#define N 200000

long long  menor, trocar = 0, comparacoes = 0, troca, tempo;

void SelectSortChoice(int vet1[])
{
	trocar = 0, comparacoes = 0, tempo = 0;
	time_t inicio = time(NULL), atual;
	cout << "\n Ordenando..." << endl;
	for (int i = 0; i < N - 1; i++)
	{
		menor = i;
		for (int j = i + 1; j < N; j++)
		{
			comparacoes++;
			if (vet1[j] < vet1[menor])
				menor = j;
		}
		if (i != menor)
		{
			trocar++;
			troca = vet1[i];
			vet1[i] = vet1[menor];
			vet1[menor] = troca;
		}
	}

	atual = time(NULL), tempo = difftime(atual, inicio);
	cout << "\n O tempo de execucao e : " << tempo << "s";
	cout << "\n Numero de trocas : " << trocar;
	cout << "\n Numero de comparacoes: " << comparacoes;
}
int main()
{
	int vet1[N], opcao;

	do
	{
		cout << "\n\n -------------(ORDENACAO SELECT SORT )---------------" << endl;
		cout << "\n 1- Para ordenar o vetor aleatorio :";
		cout << "\n 2- Para ordenar o vetor ordenado :";
		cout << "\n 3- Para ordenar o vetor inversamente ordenado :";
		cout << "\n Informe sua opcao usuario :";
		cin >> opcao;

		switch (opcao)
		{
		case 1:
			for (int i = 0; i < N; i++)
				vet1[i] = rand() % 100;
			SelectSortChoice(vet1);
			break;
		case 2:
			for (int i = 0; i < N; i++)
				vet1[i] = i + 1;
			SelectSortChoice(vet1);
			break;
		case 3:
			for (int i = 0; i < N; i++)
				vet1[i] = N - i + 1;
			SelectSortChoice(vet1);
			break;
		default:
			cout << "\n Invalid code brother ";
		}
	} while (opcao != 0);
}