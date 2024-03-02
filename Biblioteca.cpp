//Autor: Adriano Prates

#include <stdio.h>
#include <string.h>

//definindo valores
#define maxLivros 10
#define maxTitulo 100
#define maxAutor 100

//criando contador para o numero de livros
int contLivro = 0;

struct Livro{
    char titulo[maxTitulo];
    char autor[maxAutor];
    int numPaginas;

    //limpar buffer do teclado
    void limparBuffer() {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    void ler(){
        //limpando buffer para leitura
        limparBuffer();
        printf("Digite o titulo do livro: ");
        scanf("%[^\n]%*c", titulo);
        printf("Digite o nome do autor: ");
        scanf("%[^\n]%*c", autor);
        printf("Digite o numero de paginas: ");
        scanf("%d%*c", &numPaginas);
    }

    void imprimir(){
        printf("Titulo do livro: %s\n", titulo);
        printf("Nome do autor: %s\n", autor);
        printf("Numero de paginas: %d\n", numPaginas);
    }
};

struct Biblioteca{
    Livro livro[maxLivros];

    void limpar(){
        for (int i = 0; i < maxLivros ; i++){
            livro[i].titulo[0] = '\0';
            livro[i].autor[0] = '\0';
            livro[i].numPaginas = 0;
        }

    }
    void cadastrar(){
        if(contLivro < maxLivros){
            livro[contLivro].ler();
            contLivro++;
            printf("\nLivro cadastrado com sucesso!!\n");
        } else{
            printf("A biblioteca esta cheia, nao e possivel cadastrar mais que 10 livros.\n");
        }
    }

    void imprimirLivros(){
        if(contLivro > 0){
            for(int i = 0; i < contLivro; i++){
                printf("ID Livro: %d\n", (i+1));
                livro[i].imprimir();
                printf("- - - - - - - -\n");
            }
        } else{
            printf("Biblioteca vazia, ainda nao ha livros cadastrados.\n\n");
        }
    }

    void imprimirMaiorLivro(){
        if(contLivro > 0){
            int indiceMaior = 0;
            for(int i = 1; i < contLivro; i++){
                if(livro[i].numPaginas > livro[indiceMaior].numPaginas){
                    indiceMaior = i;
                }
            }
            printf("ID Livro: %d\n", indiceMaior);
            printf("Titulo do livro: %s\n", livro[indiceMaior].titulo);
            printf("Nome do autor: %s\n", livro[indiceMaior].autor);
            printf("Numero de paginas: %d\n", livro[indiceMaior].numPaginas);
        } else{
            printf("Nao ha livros cadastrados para definir um livro com maior numero de paginas.\n");
        }
    }
};

int main(){
    Biblioteca biblioteca;
    int escolha;

    biblioteca.limpar();

    do{
        printf("\n- - - Biblioteca - - -\n");
        printf(">        Menu        <\n");
        printf("1 - Adicionar novo livro\n");
        printf("2 - Imprimir todos os livros\n");
        printf("3 - Imprimir livro com o maior numero de paginas\n");
        printf("4 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            printf("\n- - - Cadastro - - -\n");
            biblioteca.cadastrar();
            printf(" - - - - - - - - - -\n");
            break;
        case 2:
            printf("\n- - - Livros - - -\n");
            biblioteca.imprimirLivros();
            break;
        case 3:
            printf("\n- - - Maior livro - - -\n");
            biblioteca.imprimirMaiorLivro();
            printf("- - - - - - - - - - -\n");
            break;
        case 4:
            printf("\nSaindo, volte sempre! :)");
            break;
        default:
            printf("\nOpcao invalida!\n");
            break;
        }

    }while(escolha != 4);

    return 0;
}
