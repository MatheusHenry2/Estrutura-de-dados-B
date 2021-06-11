#include <iostream>
using namespace std;

struct node
{
    int codigo;
    struct node *left, *right;
};

int n;

void insere(int n, node **raiz)
{
    if ((*raiz) == NULL)
    {
        (*raiz) = (node *)malloc(sizeof(node));
        (*raiz)->codigo = n;
        (*raiz)->left = NULL;
        (*raiz)->right = NULL;
    }
    else if (n < (*raiz)->codigo)
        insere(n, &(*raiz)->left);
    else if (n > (*raiz)->codigo)
        insere(n, &(*raiz)->right);
}

int consulta(int n, node *raiz)
{
    if (raiz == NULL)
        return 0;
    else if (raiz->codigo == n)
        cout << "\n Elemento encontrado" << n << "Parabens" << endl;
    else if (n < raiz->codigo)
        return (consulta(n, raiz->left));
    else if (n > raiz->codigo)
        return (consulta(n, raiz->right));
}

void pre(node *raiz)
{
    if (raiz != NULL)
    {
        pre(raiz->left);
        cout << raiz->codigo;
        pre(raiz->right);
    }
}

void ordem(node *raiz)
{
    if (raiz != NULL)
    {
        ordem(raiz->left);
        cout << raiz->codigo;
        ordem(raiz->right);
    }
}

void posordem(node *raiz)
{
    if (raiz != NULL)
    {
        posordem(raiz->right);
        cout << raiz->codigo;
        posordem(raiz->left);
    }
}

int main()
{
    node *raiz = NULL;
    int opcao;

    do
    {
        cout << "\n (1) Para inserir na arvore (2) consulta (3)preORDEM (4)ordem (5)posordem" << endl;
        cout << "\n Informe sua opcao:";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "\n Informe um valor para ser inserido:";
            cin >> n;
            insere(n, &raiz);
            break;
        case 2:
            cout << "\n Informe o N a ser buscado:";
            cin >> n;
            consulta(n, raiz);
            break;
        case 3:
            pre(raiz);
            break;
        case 4:
            ordem(raiz);
            break;
        case 5:
            posordem(raiz);
            break;
        }

    } while (opcao != 0);
}
