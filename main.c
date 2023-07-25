#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numRandomico() {
    // Configura a semente do gerador de números aleatórios
    srand(time(NULL));

    // Gera um número aleatório entre 1 e 100
   int numeroAleatorio = (rand() % 100) + 1;
    
    // A função retorna o número aleatório gerado
    return numeroAleatorio;
}

int main () {
restart:
int numero, i, n;
char r;
int numCerto = numRandomico();




//Define a primeira rodada: n = 1
n = 0;
printf("Seja bem vindo ao jogo de adivinhação!\nEscolha a quantidade de tentativas:\n");
scanf("%i",&i);

    // Entra em um laço de repetição e permanece nele se o número estiver errado ou as tentativas não forem esgotadas
    while(numCerto != numero && i > 0){
        // i é o numero de tentativas. começa com 10 e após a 1ª tentativa vai para 9
        if (n == 0){
            
            printf("Você consegue adivinhar qual número eu estou pensando?\n");
            printf("Dica: É um número de 1 a 100\n");
            scanf("%i",&numero);
            i--;
            n++;
        // após a 1ª tentativa entra na condicional,     
        }else if (n > 0){
            // se o número digitado for menor que 1 ou maior que 100, avisa que o número é inválido e não desconta uma jogada
            if (numero < 1 || numero >100){
                printf("Digite um número entre 1 e 100!\n");
                printf("Tente novamente!\n");
                i++;
            }
            // se o número for maior que o número certo, o jogo avisa que o número certo é menor e desconta uma jogada
            if (numero > numCerto){
                printf("Errou! Tente um número é menor!\n");
                printf("Você tem %i tentativas!\nTente novamente: ",i);
                scanf("%i",&numero);
                i--;
                n++;
            // se o número for menor que o número certo, o jogo avisa que o número certo é maior e desconta uma jogada    
            }else if(numero < numCerto){
                printf("Errou! Tente um número é maior!\n");
                printf("Você tem %i tentativas!\nTente novamente: ",i);
                scanf("%i",&numero);
                i--;
                n++;
            }
        }
    }
    // ao sair do loop, o jogo verifica se saiu porque acertou o número ou porque esgotou as jogadas.
    //
    //Vitória! O jogo identifica a vitória e avisa qual o número e quantas jogadas foram necessárias para terminar.
    if (numCerto == numero){
        printf("Parabéns! Você acertou!\n");
        printf("Eu estava pensando no número %d\n", numCerto);
        printf("Você demorou %i tentativas para acertar!",i + n);
        return 0;
    //Derrota :( nesse caso o jogo pergunta se o jogador quer recomeçar a partida.    
    }else if(i == 0){
            printf("Você perdeu, tentativas esgotadas! Deseja começar novamente? Digite s ou n\n");
            scanf(" %c",&r);
            //enquanto não for digitado s ou n o loop permanece
            while(r != 's' && r != 'n'){ 
                printf("Caractér inválido, digite novamente s ou n: \n");
                scanf(" %c",&r);
            }
            // caso seja digitado 's', o jogo recomeça, indo para o restart, que fica logo abaixo do main().
            if(r == 's'){
                goto restart;
            // caso seja digitado 'n', o jogo termina e se despede do jogador.    
            }else if(r == 'n'){
                printf("Até logo!");
                return 0;
            }
        }
}