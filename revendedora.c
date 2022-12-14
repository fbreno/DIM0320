// Componentes
// Aluno 1
// Aluno 2
#include <stdio.h>
#include <string.h>

enum comb
{
    alcool ,
    diesel ,
    flex ,
    gasolina
};

typedef struct
{
    char marca[21];
    char modelo[21];
    float motorizacao;
    int ano;
    char cor[21];
    int quilometragem;
    float preco;
    enum comb combustivel;

} Carro;

void imprime_carro(int i);
void imprime_carros_ano(int ano);
void imprime_carros_marca(char *marca);
void imprime_carros_preco(float preco_inf, float preco_sup);
void imprime_carros_km(float km_inf, float km_sup);

int num_registros;
Carro estoque[50];

void le_banco_de_dados()
{
    FILE *fp;
    int i = 0;
    fp = fopen("estoque.txt", "r");
    fscanf(fp, "%d", &num_registros);
    for (i = 0; i < num_registros; i++)
    {
        fscanf(fp, "%s", &estoque[i].marca);
        fscanf(fp, "%s", &estoque[i].modelo);
        fscanf(fp, "%s", &estoque[i].cor);
        fscanf(fp, "%d", &estoque[i].ano);
        fscanf(fp, "%f", &estoque[i].motorizacao);
        fscanf(fp, "%d", &estoque[i].quilometragem);
        fscanf(fp, "%f", &estoque[i].preco);
        fscanf(fp, "%d", &estoque[i].combustivel);
        imprime_carro(i);
    }
}

void imprime_carro(int i)
{
    printf("%s %s %s %d %.1f\n", estoque[i].marca, estoque[i].modelo,
           estoque[i].cor, estoque[i].ano, estoque[i].motorizacao);
    switch (estoque[i].combustivel)
    {
    case alcool:
        printf("álcool ");
        break;
    case diesel:
        printf("diesel ");
        break;
    case flex:
        printf("flex ");
        break;
    case gasolina:
        printf("gasolina ");
    }
    printf("%d %.2f\n\n", estoque[i].quilometragem, estoque[i].preco);
}
void imprime_carros_ano(int ano){
    int i;
    for(i=0;i<num_registros;i++){
        if(estoque[i].ano == ano){
            imprime_carro(i);
        }
    }
    printf("=====================================\n");
}

void imprime_carros_marca(char *marca){
    int i;
    for(i=0;i<num_registros;i++){
        if(strcmp(estoque[i].marca,marca) == 0){
            imprime_carro(i);
        }
    }
    printf("=====================================\n");
}

void imprime_carros_preco(float preco_inf, float preco_sup){
    int i;
    for(i=0;i<num_registros;i++){
        if(estoque[i].preco >= preco_inf && estoque[i].preco <= preco_sup){
            imprime_carro(i);
        }
    }
    printf("=====================================\n");
}

void imprime_carros_km(float km_inf, float km_sup){
    int i;
    for(i=0;i<num_registros;i++){
        if(estoque[i].quilometragem >= km_inf && estoque[i].quilometragem <= km_sup){
            imprime_carro(i);
        }
    }
    printf("=====================================\n");
}

int main()
{
    le_banco_de_dados();
    int menu;
    int anoSelecionado;
    char marcaSelecionada[21];
    float precoInicial;
    float precoFinal;
    float kmInicial;
    float kmFinal;    

    do
    {
        printf("Selecione uma opcao:\n");
        printf("0 - Sair do Programa\n");
        printf("1 - Imprime carros de um ano especifico\n");
        printf("2 - Imprime carros de uma marca especifica\n");
        printf("3 - Imprime carros de uma faixa de precos especifica\n");
        printf("4 - Imprime carros de uma faixa de quilometragem especifica\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            printf("\e[1;1H\e[2J");
            printf("Saindo do programa...\n");
            break;
        case 1:
            
            printf("\e[1;1H\e[2J");
            printf("Digite o ano para imprimir os carros: \n");
            scanf("%d", &anoSelecionado);
            printf("=====================================\n");
            imprime_carros_ano(anoSelecionado);
            break;
        case 2:
            printf("\e[1;1H\e[2J");
            printf("Imprime carros de uma marca especifica\n");
            scanf("%s", marcaSelecionada);
            printf("=====================================\n");
            imprime_carros_marca(marcaSelecionada);
            break;
        case 3:
            printf("\e[1;1H\e[2J");
            printf("Imprime carros de uma faixa de precos especifica\n");
            scanf("%f %f", &precoInicial, &precoFinal);
            printf("=====================================\n");
            imprime_carros_preco(precoInicial, precoFinal);
            break;
        case 4:
            printf("\e[1;1H\e[2J");
            printf("Imprime carros de uma faixa de quilometragem especifica\n");
            scanf("%f %f", &kmInicial, &kmFinal);
            printf("=====================================\n");
            imprime_carros_km(kmInicial, kmFinal);
            break;
        default:
            printf("\e[1;1H\e[2J");
            printf("Opcao invalida tente novamente\n");
            break;
        }
    } while (menu != 0);
    return 0;
}