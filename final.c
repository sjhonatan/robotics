/*##########################################################
 * Instituto Federal de Santa Catarina.                    # 
 *                                                         # 
 * Professor: Everton Luiz Ferret dos Santos.              #
 * Nome: Ana Luísa Heck Espíndula.                         #
 * Programa desenvolvido para a quarta tarefa de           #
 * Programação de Computadores I B.                        #
 *                                                         #
 * Intuito do programa :                                   #
 *                                                         #
 *     Disponibilizar um sistema para fácil cadastro de    #
 *     notas e fácil consulta de estátisticas como média   #
 *     geral da turma, menor nota, maior nota.             #
 *                                                         #
 *##########################################################
 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

//Usado para lógica na programação..
#define true 1
#define false 0

// Declarando estrutura que armazenará informações sobre os alunos.
struct Turma {
    int numeroDeRegistro;
    char nome[30];
    float nota;
};
typedef struct Turma Turma; // Agora Turma pode ser usado em vez de struct Turma.
 
// Declaração de funções.
void ajudaInicial();
void registro();
void menu();
void menuEscrever();
void menuConsultar();
void adicional();
void complementarArquivo();
void criarArquivo();
void escreverNoArquivo();
void acharRegistro(char nomeDoArquivo[30]);
void calcularMedia(char nomeDoArquivo[30]);
void maiorNota(char nomeDoArquivo[30]);
void menorNota(char nomeDoArquivo[30]);
int main(){
    // Usando setlocale para poder usar caracteres da língua portuguesa.
    setlocale(LC_CTYPE,"Portuguese");
    // Inicializando menu principal.
    menu();
}

void menu(){
    int op = -1;
    while(op != 3){
        //system("cls");
        printf("[ 0 ] Como usar esse programa\n");
        printf("[ 1 ] Escrever em arquivo\n");
        printf("[ 2 ] Consultar arquivo\n");
        printf("[ 3 ] Sair\n");
        printf("\n> ");
        scanf("%d",&op);
        switch(op){
            case 0:
                ajudaInicial();
                break;
            case 1:
                menuEscrever();
                break;
            case 2:
                menuConsultar();
                break;
            case 3:
                break;
            default:
                printf("Você não escolheu nenhuma opção válida\n");
                printf("Caso precise de ajuda para usar esse programa\n");
                printf("digite 0 e pressione enter");
                break;
        }
    }
}
void menuEscrever(){
    int op = -1;
    while(op != 3){
        system("cls");
        printf("[1] Criar novo arquivo\n");
        printf("[2] Complementar arquivo existente\n");
        printf("[3] Voltar\n");
        printf("\n> ");
        scanf("%d",&op);
        switch(op){
            case 1:
                escreverNoArquivo();
                break;
            case 2:
                complementarArquivo();
                break;
            case 3:
                break;
            default:
                printf("Você não digitou uma opção válida, caso esteja com dúvida\n");
                break;
        }
    }
}
void menuConsultar(){
    char nomeDoArquivo[30];
    int op;
    FILE *f;
    printf("Nome para o arquivo : \n");
    printf("\n> ");
    setbuf(stdin,NULL);
    scanf("%30[^\n]s",nomeDoArquivo);
    // Enquanto não for fornecido um nome válido de arquivo o programa
    // continuará pedindo por um nome de arquivo válido
    while (( f = fopen(nomeDoArquivo,"rb")) == NULL){
        printf("O arquivo não pode ser aberto\n");
        printf("> ");
        setbuf(stdin,NULL);
        scanf("%30[^\n]s",nomeDoArquivo);
    }
    //system("cls");
    printf("[1] Consultar por registro\n");
    printf("[2] Média geral da turma\n");
    printf("[3] Menor nota\n");
    printf("[4] Maior nota\n");
    printf("[5] Voltar\n");
    printf("> ");
    scanf("%d",&op);
    switch(op){
        case 1:
            acharRegistro(nomeDoArquivo);
            break;
        case 2:
            calcularMedia(nomeDoArquivo);
            break;
        case 3:
            menorNota(nomeDoArquivo);
            break;
        case 4:
            maiorNota(nomeDoArquivo);
            break;
        case 5:
            break;
    }
}
void escreverNoArquivo(){
    char nomeDoArquivo[30];
    FILE *fp;
    printf("Nome para o arquivo : \n");
    printf("\n> ");
    setbuf(stdin,NULL);
    scanf("%30[^\n]s",nomeDoArquivo);
    // Criando arquivo
    if (( fp = fopen(nomeDoArquivo,"wb")) == NULL){
        printf("O arquivo não pode ser criado\n");
    }
    else{
        printf("\nArquivo criado com sucesso!\n");
        //system("pause");
    }
    // Menu para fornecer ao usuário o que deve ser fornecido no registro
    registro();
    int numeroDeAlunos;
    int i = 0;
    Turma aluno;
    // Lendo os dados do usuário
    printf("\nQuantos alunos serão cadastrados?\n");
    printf("> ");
    scanf("%d",&numeroDeAlunos);
    for(i = 0; i < numeroDeAlunos; i++){
        printf("\nQual o nome da aluna(o)?\n");
        printf("> ");
        setbuf(stdin,NULL);
        scanf("%30[^\n]s",aluno.nome);
        printf("Qual o número de registro de %s?\n",aluno.nome);
        printf("> ");
        scanf("%d",&aluno.numeroDeRegistro);
        printf("Qual foi a nota de %s?\n",aluno.nome);
        printf("> ");
        scanf("%f",&aluno.nota);
        printf("[*] Cadastro realizado com sucesso\n");
        //system("pause");
        //system("cls");
        // Escrevendo os dados no arquivo 
        fwrite(&aluno, sizeof(Turma),1,fp);
    }
    // Fechando arquivo
    fclose(fp);
}
void complementarArquivo(){
    char nomeDoArquivo[30];
    FILE *fp;
    printf("Nome do arquivo que deseja complementar\n");
    printf("\n> ");
    setbuf(stdin,NULL);
    scanf("%30[^\n]s",nomeDoArquivo);
    // Enquanto o usuário não fornecer um arquivo válido para continuar
    // a escrever o programa continuará pedindo um nome válido
    while (( fp = fopen(nomeDoArquivo,"ab")) == NULL){
        printf("O arquivo não pode ser aberto\n");
        printf("> ");
        setbuf(stdin,NULL);
        scanf("%30[^\n]s",nomeDoArquivo);
    }
    // Menu para fornecer ao usuário o que deve ser fornecido no registro
    registro();
    int numeroDeAlunos;
    int i = 0;
    Turma aluno;
    printf("\nQuantos alunos serão cadastrados?\n");
    printf("> ");
    scanf("%d",&numeroDeAlunos);
    for(i = 0; i < numeroDeAlunos; i++){
        printf("\nQual o nome da aluna(o)?\n");
        printf("> ");
        setbuf(stdin,NULL);
        scanf("%30[^\n]s",aluno.nome);
        fflush(stdin);
        printf("Qual o número de registro de %s?\n",aluno.nome);
        printf("> ");
        scanf("%d",&aluno.numeroDeRegistro);
        printf("Qual foi a nota de %s?\n",aluno.nome);
        printf("> ");
        scanf("%f",&aluno.nota);
        printf("[*] Cadastro realizado com sucesso\n");
        //system("pause");
        //system("cls");
        // Escrevendo os dados no arquivo 
        fwrite(&aluno, sizeof(Turma),1,fp);
    // Fechando arquivo
    fclose(fp);
    }
}
void acharRegistro(char nomeDoArquivo[30]){
    FILE * f;
    int numeroReg;
    int achou = false;
    Turma aluno;
    // Abre o arquivo, como já verificamos no menu que o arquivo é válido esse 
    // teste é apenas uma redundância de segurança.
    if (( f = fopen(nomeDoArquivo,"rb")) == NULL){
        printf("O arquivo não pode ser aberto\n");
    }
    printf("Qual o número de registro que deseja localizar?\n");
    printf("> ");
    scanf("%d",&numeroReg);
    while(fread(&aluno,sizeof(Turma),1,f) == 1){
        if (numeroReg == aluno.numeroDeRegistro){
            printf("Nome : %s\n",aluno.nome);
            printf("Registro : %d\n",aluno.numeroDeRegistro);
            printf("nota : %.2f\n",aluno.nota);
            achou = true;
            break; 
        }
        if (!achou){
            printf("Registro não encontrado\n");
            system("pause");
        }
    }
    fclose(f);
}
void calcularMedia(char nomeDoArquivo[30]){
    system("clear");
    FILE *f;
    int numeroDeAlunos = 0;
    float media = 0;
    Turma aluno;
    // Abre o arquivo, como já verificamos no menu que o arquivo é válido esse 
    // teste é apenas uma redundância de segurança.
    if (( f = fopen(nomeDoArquivo,"rb")) == NULL){
        printf("O arquivo não pode ser aberto\n");
    }
    // Enquanto fread retornar 1 continuamos a ler o arquivo.
    while(fread(&aluno,sizeof(Turma),1,f) == 1){
        media+=aluno.nota;
        numeroDeAlunos++;
    }
    // Exibindo o número de alunos e a média da turma.
    printf("Número de alunos : %d\n",numeroDeAlunos);
    printf("Média geral : %.2f\n", media/numeroDeAlunos);
    // fechando o arquivo.
    fclose(f);
}
void menorNota(char nomeDoArquivo[30]){
    // como as notas são menores que 10 não teremos problema
    // de ter um valor maior que 100 que faça com que o programa
    // não ache a menor
    float menor = 100;
    FILE * f;
    Turma aluno;
    Turma infoNota;
    if (( f = fopen(nomeDoArquivo,"rb")) == NULL){
        printf("O arquivo não pode ser aberto\n");
    }
    while(fread(&aluno,sizeof(Turma),1,f) == 1){
        if (menor > aluno.nota){
            menor = aluno.nota;
            infoNota.nota = aluno.nota;
            strcpy(infoNota.nome,aluno.nome);
            infoNota.numeroDeRegistro = aluno.numeroDeRegistro;
        }
    }
    fclose(f);
    printf("Dados sobre o aluno com menor nota\n");
    printf("Nome : %s\n",infoNota.nome);
    printf("Registro : %d\n",infoNota.numeroDeRegistro);
    printf("Nota : %.2f\n",infoNota.nota);
}
void maiorNota(char nomeDoArquivo[30]){
    /* Para achar a maior nota inicializamos ela em zero
     * e checamos se a variavel "maior" possui valor menor que a nota
     * então substituimos maior pela nota atual e assim percorremos
     * todas as notas no arquivo
     */
    float maior = 0;
    FILE * f;
    Turma aluno;
    Turma infoNota;
    if (( f = fopen(nomeDoArquivo,"rb")) == NULL){
        printf("O arquivo não pode ser aberto\n");
    }
    while(fread(&aluno,sizeof(Turma),1,f) == 1){
        if (maior < aluno.nota){
            maior = aluno.nota;
            infoNota.nota = aluno.nota;
            strcpy(infoNota.nome,aluno.nome);
            infoNota.numeroDeRegistro = aluno.numeroDeRegistro;
        }
    }
    fclose(f);
    printf("Dados sobre o aluno com menor nota\n");
    printf("Nome : %s\n",infoNota.nome);
    printf("Registro : %d\n",infoNota.numeroDeRegistro);
    printf("Nota : %.2f\n",infoNota.nota);
}
void ajudaInicial(){
    //system("cls");
    system("clear");
    printf(".__  _____              \n");
    printf("|__|/ ____/______ ____  \n");
    printf("|  /   __//  ___// ___/ \n");
    printf("|  ||  |  /___ //  /__ \n");
    printf("|__||__| /____ /_____/\n\n");
    printf("[*]     Caso seja a primeira vez que você esteja usando este programa e queira criar\n");
    printf("    um novo arquivo, acesse a opção 1 do menu, você irá encontrar duas opções\n");
    printf("    a primeira, digitando 1, você criará um novo arquivo e assim poderá começar\n");
    printf("    a criar seu banco de dados com os dados dos alunos.\n");
    printf("        Caso você queria complementar o seu arquivo já existente, dentro da opção 1 você\n");
    printf("    poderá escolher a opção 2 para complementar seu arquivo\n\n"); 
    printf("[*]     Com seu arquivo já existente você pode usar a opção 2 para fazer consultas\n");
    printf("    como consultar os dados de um aluno, a média geral da turma, a maior nota, a menor nota\n\n");
    //system("pause");
    //system("cls");
}
void registro(){
    //system("cls");
    system("clear");
    printf("[*] Registro de um novo aluno, informações que você deve fornecer : \n");
    printf("          -Nome do aluno com no máximo 30 caracteres\n");
    printf("          -Número do registro do aluno\n");
    printf("          -Nota\n");
    printf("\n");
}
