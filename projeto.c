#include <stdio.h>
#include <stdlib.h>

void imp_tab(char tab[3][3]) {
  system("clear"); //terminal
  printf(" %c | %c | %c\n", tab[0][0],tab[0][1],tab[0][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", tab[1][0],tab[1][1],tab[1][2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c\n", tab[2][0],tab[2][1],tab[2][2]);
  return;//estrutura do tabuleiro
}

int main() {
  char tab[3][3],jogador;//matriz
  int coluna,ganhou,rodada,a,b,linha;

  for (a = 0; a < 3; a++) {
    for (b = 0; b < 3; b++) {
      tab[a][b] = ' ';//zera tabuleiro
    }
  }
  
  imp_tab(tab);//imprime na tela o tabuleiro

  ganhou = 0;//ngm ganhou ainda

  for (rodada = 1; rodada <= 9 && ganhou == 0; rodada++) {//define as 9 rodadas ou ate a variavel win diferente de 0

if (rodada % 2 == 1) {//se rodada impar rodada % 2 == 1 / se rodada par rodada % 2 == 0
      jogador = 'X';
    }
    else {
      jogador = 'O';
    }

    do {
      printf("Onde quer jogar ? (de 1 a 3) '%c': ", jogador);
      scanf("%d %d", &linha, &coluna);
    } while(linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tab[linha-1][coluna-1] != ' '); // le as jogadas
    
    tab[linha-1][coluna-1] = jogador; //registra a jogada

  imp_tab(tab);//mostra o tabuleiro atualizado


  if (tab[linha-1][0] == tab[linha-1][1] && tab[linha-1][1] == tab[linha-1][2]) {
      ganhou = 1;
    }
    else {


      if (tab[0][coluna-1] == tab[1][coluna-1] && tab[1][coluna-1] == tab[2][coluna-1]) {
	ganhou = 1;
      }

      else {

	
	if (linha == coluna && tab[0][0] == tab[1][1] && tab [1][1] == tab[2][2]) {
	  ganhou = 1;
	}
	else {
	 
	  if (linha + coluna == 4 && tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0]) {
	    ganhou = 1;
	  }
	}
      }
    }

  }// verifica as possiveis combinacoes de vitoria e troca a variavel ganhou para 1 sinalizando vitoria
  
  if (ganhou == 0) {
    printf("\nDeu velha!\n"); //se finalizar o loop e a variavel ganhou = 0 printa deu velha 
  }
  else {
    printf("\nO jogador '%c' ganhou!\n", jogador);// se ganhou = 1 printa o jogador vencedor
  }
  
  return(0);
}
