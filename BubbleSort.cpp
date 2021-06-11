#include <iostream>
using namespace std;
#include <time.h>
#include <sys/time.h>
#define N 200000

//VARIVEIS GLOBAL PARA COMPARACAO E TROCA
long comparacao1 = 0, troca1 = 0;
long comparacao2 = 0, troca2 = 0;
long comparacao3 = 0, troca3 = 0;

void BubleRandom(int vet[])
{
	int aux;
	float tempo;

	time_t inicio, atual;

	for (int i = 0; i < N; i++)
		vet[i] = rand() % 100;

	inicio = time(NULL);

	cout << "\n Ordenando...." << endl;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = N - 2; j >= i; j--)
		{
			comparacao1++;
			if (vet[j] > vet[j + 1])
			{
				troca1++;
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
			}
		}
	}

	atual = time(NULL);
	tempo = difftime(atual, inicio);

	cout << " \n Tempo de execucao em segundos: " << tempo << "s";
	cout << "\n A quantidade de trocas foi :" << troca1;
	cout << "\n A quantidade de compaaracoes:" << comparacao1;
}

void BubleSalary(int vet2[])
{
	int aux;
	float tempo;

	time_t inicio, atual;

	for (int i = 0; i < N; i++)
		vet2[i] = i + 1;

	inicio = time(NULL);

	cout << "\n Ordenando...." << endl;

	for (int i = 0; i < N - 1; i++)
	{
		comparacao2++;
		for (int j = N - 2; j >= i; j--)
		{
			if (vet2[j] > vet2[j + 1])
			{
				troca2++;
				aux = vet2[j];
				vet2[j] = vet2[j + 1];
				vet2[j + 1] = aux;
			}
		}
	}

	atual = time(NULL);
	tempo = difftime(atual, inicio);

	cout << " \n Tempo de execucao em segundos: " << tempo << "s";
	cout << "\n A quantidade de trocas foi :" << troca2;
	cout << "\n A quantidade de compaaracoes:" << comparacao2;
}

void BubleInversely(int vet3[])
{
	int aux;
	float tempo;

	time_t inicio, atual;

	for (int i = 0; i < N; i++)
		vet3[i] = 200000 - i;

	inicio = time(NULL);

	cout << "\n Ordenando...." << endl;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = N - 2; j >= 1; j--)
		{
			comparacao3++;
			if (vet3[j] > vet3[j + 1])
			{
				troca3++;
				aux = vet3[j];
				vet3[j] = vet3[j + 1];
				vet3[j + 1] = aux;
			}
		}
	}

	atual = time(NULL);
	tempo = difftime(atual, inicio);

	cout << " \n Tempo de execucao em segundos: " << tempo << "s";
	cout << "\n A quantidade de trocas foi :" << troca3;
	cout << "\n A quantidade de compaaracoes:" << comparacao3;
}

int main()
{
	int vet[N], vet2[N], vet3[N], opcao;

	do
	{
		cout << "\n\n 1- Para ordenar o vetor Aleatorio :";
		cout << "\n 2- Para ordenar o vetor previamente ordenado:";
		cout << "\n 3- Para ordenar o vetor inversamente ordenado:";
		cout << "\n Informe sua opcao 0 for exit:";
		cin >> opcao;

		switch (opcao)
		{
		case 1:
			BubleRandom(vet);
			break;
		case 2:
			BubleSalary(vet2);
			break;
		case 3:
			BubleInversely(vet3);
			break;
		}

	} while (opcao != 0);
}