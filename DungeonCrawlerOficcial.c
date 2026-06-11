#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>

int arma  = 0;
int vidas = 3;

/* PROTOTIPOS DAS FUNCOES */
void menu();
void inexistente();
void tutorial();
void Vila();
void PrimeiroAndar();
void SegundoAndar();
void TerceiroAndar();
void telaVitoria();
void gameOver();
void realizarAtaque10(char mapa[10][10], int jogLinha, int jogColuna, char direcao);
void realizarAtaque15(char mapa[15][15], int jogLinha, int jogColuna, char direcao);
void realizarAtaque25(char mapa[25][25], int jogLinha, int jogColuna, char direcao);

/* MENU PRINCIPAL
   Exibe as opcoes do jogo na tela. */
void menu()
{
    printf("=============DUNGEON CRAWLER============\n");
    printf("1. Jogar\n2. Tutorial\n3. Sair\n\n");
}

/* INEXISTENTE
   Chama quando o jogador digita uma opção inválida no menu.*/
void inexistente()
{
    printf("Esse comando nao existe... Redirecionando de volta ao Menu...\n");
    printf("\n\n=============DUNGEON CRAWLER============\n");
    printf("1. Jogar\n2. Tutorial\n3. Sair\n\n");
}

/* TUTORIAL
   Exibe a história completa do jogo, o significado de cada
   símbolo do mapa e os comandos disponíveis para o jogador.*/
void tutorial()
{
    printf("História\n");
    printf("Se você clicou no Tutorial, quer dizer que você está afim de entender sobre as mecânicas do Game, CALMA!! Antes de tudo, vamos entender um pouco sobre a história do DUNGEON CRAWLER:\n\n");
    printf("PRÓLOGO\n");
    printf("Meu nome é Ashley Calhoun.\nMas há muito tempo ninguém me chama assim.\n\n");
    printf("Na minha vila, todos me conheciam apenas como Ash.\n\n");
    printf("Eu era a guardiã do povoado de Raven Hollow, uma pequena comunidade cercada por florestas e montanhas. Durante anos, vivi acreditando que poderia proteger aquelas pessoas de qualquer ameaça. Eu estava errada...\n\n");
    printf("Numa noite sem lua, criaturas surgiram das profundezas da Floresta Sombria.\n\n");
    printf("Elas eram lideradas por uma entidade conhecida apenas como O Devorador de Cinzas, um antigo senhor da guerra cuja existência era considerada uma lenda. Seu exército de monstros avançou sobre Raven Hollow como uma tempestade.\n\n");
    printf("Eu lutei... Lutei até minhas forças se esgotarem.\n\n");
    printf("Mas não foi suficiente. As casas foram destruídas. As ruas ficaram cobertas por fogo e ruinas. Meus amigos desapareceram. Minha família foi perdida em meio ao caos. E eu sobrevivi.\n\n");
    printf("Desde aquele dia, carrego um peso maior que qualquer armadura... A culpa.\n\n");
    printf("Anos se passaram. Enquanto vagava sem destino, ouvi uma antiga historia. Uma lenda esquecida pelo tempo.\n\n");
    printf("Diziam que, séculos atrás, um rei cruel e obcecado por poder governou estas terras. Temendo que sua maior relíquia fosse roubada, ele a escondeu nas profundezas de uma fortaleza subterrânea.\n\n");
    printf("Para protegê-la, construiu armadilhas mortais. Aprisionou criaturas monstruosas. E lancou uma maldicao sobre toda a fortaleza.\n\nA reliquia ficou conhecida como A Joia Dourada.\n\nUm artefato capaz de realizar um único desejo.\n\n");
    printf("Centenas de aventureiros tentaram encontrá-la... Mas nenhum retornou.\n\n");
    printf("Mas para mim, isso não importa.\n\n");
    printf("Se a lenda for verdadeira, ainda existe esperança. A esperança de poder restaurar Raven Hollow.\n\n");
    printf("Posso trazer de volta aqueles que perdi.\n\n");
    printf("Posso dar ao meu povo a vida que lhes foi roubada.\n\n");
    printf("Mesmo que a fortaleza seja um túmulo.\n\n");
    printf("Mesmo que monstros me aguardem em cada corredor.\n\n");
    printf("Mesmo que eu nunca mais veja a luz do sol.\n\n");
    printf("Eu seguirei em frente.\n\n");
    printf("Meu nome é Ashley Calhoun, E esta é minha última chance de corrigir o passado.\n\n");
    printf("Ok, agora que você sabe a história do jogo, o seu objetivo e chegar até a última fase da masmorra e derrotar o temido boss ###The Fallen Sovereign###.\n\n");
    printf("Simbolos\n");
    printf("Os símbolos desse jogo não são aleatórios!!! Entenda o que cada símbolo faz.\n");
    printf("Simbolo\tSignificado\n");
    printf("<\tJogador olhando para a esquerda\n");
    printf("^\tJogador olhando para cima\n");
    printf(">\tJogador olhando para a direita\n");
    printf("v\tJogador olhando para baixo\n");
    printf("*\tParede: O jogador não pode passar\n");
    printf("#\tEspinho: O jogador morre ao passar por cima\n");
    printf("k\tCaixa: O jogador não pode passar, mas pode ser destruída com ataque\n");
    printf("O\tBotao: Executa uma ação ao ser pressionado\n");
    printf("D\tPorta fechada: O jogador não pode passar\n");
    printf("@\tChave: Abre uma porta fechada ao interagir\n");
    printf("=\tPorta aberta: O jogador pode passar\n");
    printf("L\tEscada: Leva o jogador para a próxima fase\n");
    printf("X\tMonstro Tipo 1: movimento aleatório\n");
    printf("Y\tMonstro Tipo 2: persegue o jogador\n");
    printf("Z\tBoss Final: The Fallen Sovereign\n");
    printf("Comandos\n");
    printf("Tecla\tAcao\n");
    printf("w\tMove o jogador para cima\n");
    printf("a\tMove o jogador para a esquerda\n");
    printf("s\tMove o jogador para baixo\n");
    printf("d\tMove o jogador para a direita\n");
    printf("i\tInterage com o objeto que esta a frente do jogador\n");
    printf("o\tO jogador realiza um ataque\n\n\n");
    menu();
}

/* TELA DE VITORIA */
void telaVitoria()
{
    system("cls");
    printf("============================================\n");
    printf("              VOCÊ VENCEU!!!\n");
    printf("============================================\n\n");
    printf("A Joia Dourada estava lá.\n\n");
    printf("Brilhando no escuro como uma estrela caída no fundo da terra.\n\n");
    printf("Com mãos tremulas, Ashley Calhoun a segurou pela primeira vez.\n\n");
    printf("E desejou.\n\n");
    printf("Não poder. Não vingança. Não imortalidade.\n\n");
    printf("Ela desejou Raven Hollow de volta.\n\n");
    printf("As casas reerguidas. As ruas limpas.\n");
    printf("Os rostos que ela amava, sorrindo de volta pra ela.\n\n");
    printf("A Joia brilhou uma última vez.\n\n");
    printf("E o desejo foi concedido.\n\n");
    printf("\"Ash?\"\n\n");
    printf("Era a voz da sua mãe.\n\n");
    printf("Ela não precisava mais de nenhuma relíquia. Nenhuma lenda.\n");
    printf("Só precisava chegar em casa.\n\n");
    printf("E pela primeira vez em anos, Ashley Calhoun sorriu de verdade.\n\n");
    printf("============================================\n");
    printf("                   FIM\n");
    printf("The Fallen Sovereign foi derrotado.\n");
    printf("Raven Hollow foi restaurada.\n");
    printf("Ashley Calhoun voltou pra casa.\n");
    printf("============================================\n\n");
    printf("DESENVOLVIMENTO: ENZO VITOR DE LIMA MACIEL\n");
    printf("DESIGN: ENZO VITOR DE LIMA MACIEL\n\n");
    printf("MUITO OBRIGADO POR JOGAR DUNGEON CRAWLER.\n\n");
    system("pause");
}

/* TELA DE GAME OVER */
void gameOver()
{
    system("cls");
    printf("============================================\n");
    printf("               GAME OVER\n");
    printf("============================================\n\n");
    printf("A masmorra reivindicou mais uma vítima.\n\n");
    printf("A lenda da Joia Dourada permanecerá como lenda.\n\n");
    printf("Raven Hollow permanecerá em ruínas.\n\n");
    printf("E o nome de Ashley Calhoun será esquecido...\n\n");
    printf("...assim como todos os outros que tentaram antes dela.\n\n");
    printf("============================================\n");
    system("pause");
}

/* VILA - mapa 10x10
   jogadorLinha / jogadorColuna: posicao atual do jogador na matriz
   direcao: o simbolo que representa o jogador */
void Vila()
{
    int linha, coluna;
    int jogadorLinha = 5;
    int jogadorColuna = 1;
    char comando;
    int jogando = 1;
    char direcao = '>';
    char vila[10][10] =
    {
        {'*','*','*','*','*','*','*','*','*','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ','N','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*',' ',' ',' ',' ',' ',' ',' ',' ','*'},
        {'*','*','*','*','L','*','*','*','*','*'}
    };
    while(jogando)
    {
        system("cls");

        printf("Vidas: %d  |  Arma: ", vidas);
        if(arma == 0)
        {
            printf("Nenhuma ainda (fale com o NPC!)");
        }
        else if(arma == 1)
        {
            printf("Espada");
        }
        else if(arma == 2)
        {
            printf("Arco e Flecha");
        }
        else if(arma == 3)
        {
            printf("Cajado");
        }
        printf("\n");
        printf("Pressione I perto do NPC para escolher sua arma.\n");
        printf("Pressione I na entrada L para entrar na masmorra.\n\n");

        /* Desenha o mapa */
        for(linha = 0; linha < 10; linha++)
        {
            for(coluna = 0; coluna < 10; coluna++)
            {
                if(linha == jogadorLinha && coluna == jogadorColuna)
                {
                    printf("%c", direcao);
                }
                else
                {
                    printf("%c", vila[linha][coluna]);
                }
            }
            printf("\n");
        }

        /* Lê a tecla pressionada sem esperar o Enter. */
        comando = getch();

        /* Movimentacao para cima */
        if(comando == 'w' || comando == 'W')
        {
            direcao = '^';
            /* Só move se a celula de cima não for parede, NPC ou entrada */
            if(vila[jogadorLinha-1][jogadorColuna] != '*'
            && vila[jogadorLinha-1][jogadorColuna] != 'N'
            && vila[jogadorLinha-1][jogadorColuna] != 'L')
            {
                jogadorLinha--;
            }
        }
        /* Movimentacao para baixo */
        else if(comando == 's' || comando == 'S')
        {
            direcao = 'v';
            /* Só move se a célula de baixo não for parede nem entrada */
            if(vila[jogadorLinha+1][jogadorColuna] != '*'
            && vila[jogadorLinha+1][jogadorColuna] != 'L')
            {
                jogadorLinha++;
            }
        }
        /* Movimentacao para esquerda */
        else if(comando == 'a' || comando == 'A')
        {
            direcao = '<';
            if(vila[jogadorLinha][jogadorColuna-1] != '*')
            {
                jogadorColuna--;
            }
        }
        /* Movimentacao para direita */
        else if(comando == 'd' || comando == 'D')
        {
            direcao = '>';
            if(vila[jogadorLinha][jogadorColuna+1] != '*'
            && vila[jogadorLinha][jogadorColuna+1] != 'N'
            && vila[jogadorLinha][jogadorColuna+1] != 'L')
            {
                jogadorColuna++;
            }
        }
        /*Interagir com objeto*/
        else if(comando == 'i' || comando == 'I')
        {
            int respostaNPC;

            /* Calcula qual celula esta a frente do jogador
               dependendo da direcao que ele esta olhando */
            int frenteL = jogadorLinha;
            int frenteC = jogadorColuna;
            if(direcao == '^')
            {
                frenteL--;
            }
            else if(direcao == 'v')
            {
                frenteL++;
            }
            else if(direcao == '<')
            {
                frenteC--;
            }
            else if(direcao == '>')
            {
                frenteC++;
            }

            /* Se a celula a frente for o NPC */
            if(vila[frenteL][frenteC] == 'N')
            {
                /* Se ja escolheu a arma, nao deixa escolher de novo */
                if(arma != 0)
                {
                    printf("Ser misterioso\nNão seja estúpida. Voce já escolheu sua arma.\n");
                    system("pause");
                }
                else
                {
                    /* Diálogo do NPC e escolha da arma */
                    printf("Ser misterioso\n");
                    printf("Olá querida Ash, como está?\n");
                    printf("Ashley Calhoun\n");
                    printf("1. ...Bem? Quem é você?\n");
                    printf("2. Como você sabe o meu nome?\n");
                    scanf("%d", &respostaNPC);
                    if(respostaNPC == 1 || respostaNPC == 2)
                    {
                        printf("Ser misterioso\n");
                        printf("Essa informação é irrelevante, o que importa nesse momento é qual arma você deseja escolher, qual destas opções você prefere?\n");
                        printf("1. Espada\n");
                        printf("2. Arco e flecha\n");
                        printf("3. Cajado\n");
                        printf("Ashley Calhoun: ");
                        scanf("%d", &arma);
                        /*Só aceita 1, 2 ou 3 */
                        while(arma < 1 || arma > 3)
                        {
                            printf("Perdão, não entendi direito...\n");
                            scanf("%d", &arma);
                        }
                        if(arma == 1)
                        {
                            printf("Arma escolhida: Espada\n");
                        }
                        else if(arma == 2)
                        {
                            printf("Arma escolhida: Arco e flecha\n");
                        }
                        else if(arma == 3)
                        {
                            printf("Arma escolhida: Cajado\n");
                        }
                        printf("Ser misterioso\n");
                        printf("Excelente escolha, afinal de contas, independente da arma que você escolher o seu fim já está destinado.\n");
                    }
                    system("pause");
                }
            }
            /* Se a celula a frente for a entrada da masmorra */
            else if(vila[frenteL][frenteC] == 'L')
            {
                if(arma == 0)
                {
                    printf("Ash olha para a entrada...\n");
                    printf("\"Preciso de uma arma antes de entrar lá.\"\n");
                    system("pause");
                }
                else
                {
                    printf("Ash para na entrada da masmorra e respira fundo.\n");
                    printf("\"Estou vindo, Raven Hollow. Prometo.\"\n");
                    system("pause");
                    /* Sai do loop da vila, voltando para o main
                       que em seguida vai chamar o PrimeiroAndar() */
                    jogando = 0;
                }
            }
        }
    }
}

/* ATAQUE 10x10 - usado no primeiro andar
   ESPADA: ataca 3 colunas x 2 linhas

   ARCO E FLECHA: ataca 4 celulas em linha reta.
   Para na primeira celula que tem inimigo ou caixa
   Tambem para ao encontrar parede (*).

   CAJADO: ataca as 8 celulas ao redor do jogador de uma vez. */
void realizarAtaque10(char mapa[10][10], int jogLinha, int jogColuna, char direcao)
{
    int l, c, i;

    /* ===== ESPADA ===== */
    if(arma == 1)
    {
        /* Olhando para cima: ataca linhas L-1 e L-2 */
        if(direcao == '^')
        {
            for(l = jogLinha-1; l >= jogLinha-2; l--)
            {
                if(l < 0)
                {
                    break; /* nao sai do mapa */
                }
                for(c = jogColuna-1; c <= jogColuna+1; c++)
                {
                    if(c < 0 || c >= 10)
                    {
                        continue; /* pula celulas fora do mapa */
                    }
                    if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                    || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                    {
                        mapa[l][c] = 'z'; /* destroi o que estiver la */
                    }
                }
            }
        }
        /* Olhando para baixo: ataca linhas L+1 e L+2 */
        else if(direcao == 'v')
        {
            for(l = jogLinha+1; l <= jogLinha+2; l++)
            {
                if(l >= 10)
                {
                    break;
                }
                for(c = jogColuna-1; c <= jogColuna+1; c++)
                {
                    if(c < 0 || c >= 10)
                    {
                        continue;
                    }
                    if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                    || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                    {
                        mapa[l][c] = ' ';
                    }
                }
            }
        }
        /* Olhando para esquerda: ataca colunas C-1 e C-2 */
        else if(direcao == '<')
        {
            for(c = jogColuna-1; c >= jogColuna-2; c--)
            {
                if(c < 0)
                {
                    break;
                }
                for(l = jogLinha-1; l <= jogLinha+1; l++)
                {
                    if(l < 0 || l >= 10)
                    {
                        continue;
                    }
                    if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                    || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                    {
                        mapa[l][c] = ' ';
                    }
                }
            }
        }
        /* Olhando para direita: ataca colunas C+1 e C+2 */
        else if(direcao == '>')
        {
            for(c = jogColuna+1; c <= jogColuna+2; c++)
            {
                if(c >= 10)
                {
                    break;
                }
                for(l = jogLinha-1; l <= jogLinha+1; l++)
                {
                    if(l < 0 || l >= 10)
                    {
                        continue;
                    }
                    if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                    || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                    {
                        mapa[l][c] = ' ';
                    }
                }
            }
        }
    }
    /* ===== ARCO E FLECHA ===== */
    else if(arma == 2)
    {
        /* Dispara para cima: percorre ate 4 celulas, linha por linha */
        if(direcao == '^')
        {
            for(i = 1; i <= 4; i++)
            {
                if(jogLinha-i < 0)
                {
                    break; /* saiu do mapa, para */
                }
                if(mapa[jogLinha-i][jogColuna] == '*')
                {
                    break; /* bateu em parede, para */
                }
                if(mapa[jogLinha-i][jogColuna] == 'k'
                || mapa[jogLinha-i][jogColuna] == 'X'
                || mapa[jogLinha-i][jogColuna] == 'Y'
                || mapa[jogLinha-i][jogColuna] == 'Z')
                {
                    mapa[jogLinha-i][jogColuna] = ' '; /* acertou, destroi e para */
                    break;
                }
            }
        }
        /* Dispara para baixo */
        else if(direcao == 'v')
        {
            for(i = 1; i <= 4; i++)
            {
                if(jogLinha+i >= 10)
                {
                    break;
                }
                if(mapa[jogLinha+i][jogColuna] == '*')
                {
                    break;
                }
                if(mapa[jogLinha+i][jogColuna] == 'k'
                || mapa[jogLinha+i][jogColuna] == 'X'
                || mapa[jogLinha+i][jogColuna] == 'Y'
                || mapa[jogLinha+i][jogColuna] == 'Z')
                {
                    mapa[jogLinha+i][jogColuna] = ' ';
                    break;
                }
            }
        }
        /* Dispara para esquerda */
        else if(direcao == '<')
        {
            for(i = 1; i <= 4; i++)
            {
                if(jogColuna-i < 0)
                {
                    break;
                }
                if(mapa[jogLinha][jogColuna-i] == '*')
                {
                    break;
                }
                if(mapa[jogLinha][jogColuna-i] == 'k'
                || mapa[jogLinha][jogColuna-i] == 'X'
                || mapa[jogLinha][jogColuna-i] == 'Y'
                || mapa[jogLinha][jogColuna-i] == 'Z')
                {
                    mapa[jogLinha][jogColuna-i] = ' ';
                    break;
                }
            }
        }
        /* Dispara para direita */
        else if(direcao == '>')
        {
            for(i = 1; i <= 4; i++)
            {
                if(jogColuna+i >= 10)
                {
                    break;
                }
                if(mapa[jogLinha][jogColuna+i] == '*')
                {
                    break;
                }
                if(mapa[jogLinha][jogColuna+i] == 'k'
                || mapa[jogLinha][jogColuna+i] == 'X'
                || mapa[jogLinha][jogColuna+i] == 'Y'
                || mapa[jogLinha][jogColuna+i] == 'Z')
                {
                    mapa[jogLinha][jogColuna+i] = ' ';
                    break;
                }
            }
        }
    }
    /* ===== CAJADO ===== */
    else if(arma == 3)
    {
        /* Dois loops aninhados percorrem as 8 posicoes ao redor. */
        //Deslocamento de Linha e Coluna
        int dl, dc;
        for(dl = -1; dl <= 1; dl++)
        {
            for(dc = -1; dc <= 1; dc++)
            {
                if(dl == 0 && dc == 0)
                {
                    continue; /* pula a célula do jogador */
                }
                l = jogLinha + dl;
                c = jogColuna + dc;
                if(l < 0 || l >= 10 || c < 0 || c >= 10)
                {
                    continue; /* pula se estiver fora do mapa */
                }
                if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                {
                    mapa[l][c] = ' ';
                }
            }
        }
    }
}

/* ATAQUE 15x15 - usado no segundo andar
   Mesma logica do 10x10, mas o limite do mapa muda para 15. */
void realizarAtaque15(char mapa[15][15], int jogLinha, int jogColuna, char direcao)
{
    int l, c, i;

    if(arma == 1)
    {
        if(direcao == '^')
        {
            for(l = jogLinha-1; l >= jogLinha-2; l--)
            {
                if(l < 0)
                {
                    break;
                }
                for(c = jogColuna-1; c <= jogColuna+1; c++)
                {
                    if(c < 0 || c >= 15)
                    {
                        continue;
                    }
                    if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                    || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                    {
                        mapa[l][c] = ' ';
                    }
                }
            }
        }
        else if(direcao == 'v')
        {
            for(l = jogLinha+1; l <= jogLinha+2; l++)
            {
                if(l >= 15)
                {
                    break;
                }
                for(c = jogColuna-1; c <= jogColuna+1; c++)
                {
                    if(c < 0 || c >= 15)
                    {
                        continue;
                    }
                    if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                    || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                    {
                        mapa[l][c] = ' ';
                    }
                }
            }
        }
        else if(direcao == '<')
        {
            for(c = jogColuna-1; c >= jogColuna-2; c--)
            {
                if(c < 0)
                {
                    break;
                }
                for(l = jogLinha-1; l <= jogLinha+1; l++)
                {
                    if(l < 0 || l >= 15)
                    {
                        continue;
                    }
                    if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                    || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                    {
                        mapa[l][c] = ' ';
                    }
                }
            }
        }
        else if(direcao == '>')
        {
            for(c = jogColuna+1; c <= jogColuna+2; c++)
            {
                if(c >= 15)
                {
                    break;
                }
                for(l = jogLinha-1; l <= jogLinha+1; l++)
                {
                    if(l < 0 || l >= 15)
                    {
                        continue;
                    }
                    if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                    || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                    {
                        mapa[l][c] = ' ';
                    }
                }
            }
        }
    }
    else if(arma == 2)
    {
        if(direcao == '^')
        {
            for(i = 1; i <= 4; i++)
            {
                if(jogLinha-i < 0)
                {
                    break;
                }
                if(mapa[jogLinha-i][jogColuna] == '*')
                {
                    break;
                }
                if(mapa[jogLinha-i][jogColuna] == 'k'
                || mapa[jogLinha-i][jogColuna] == 'X'
                || mapa[jogLinha-i][jogColuna] == 'Y'
                || mapa[jogLinha-i][jogColuna] == 'Z')
                {
                    mapa[jogLinha-i][jogColuna] = ' ';
                    break;
                }
            }
        }
        else if(direcao == 'v')
        {
            for(i = 1; i <= 4; i++)
            {
                if(jogLinha+i >= 15)
                {
                    break;
                }
                if(mapa[jogLinha+i][jogColuna] == '*')
                {
                    break;
                }
                if(mapa[jogLinha+i][jogColuna] == 'k'
                || mapa[jogLinha+i][jogColuna] == 'X'
                || mapa[jogLinha+i][jogColuna] == 'Y'
                || mapa[jogLinha+i][jogColuna] == 'Z')
                {
                    mapa[jogLinha+i][jogColuna] = ' ';
                    break;
                }
            }
        }
        else if(direcao == '<')
        {
            for(i = 1; i <= 4; i++)
            {
                if(jogColuna-i < 0)
                {
                    break;
                }
                if(mapa[jogLinha][jogColuna-i] == '*')
                {
                    break;
                }
                if(mapa[jogLinha][jogColuna-i] == 'k'
                || mapa[jogLinha][jogColuna-i] == 'X'
                || mapa[jogLinha][jogColuna-i] == 'Y'
                || mapa[jogLinha][jogColuna-i] == 'Z')
                {
                    mapa[jogLinha][jogColuna-i] = ' ';
                    break;
                }
            }
        }
        else if(direcao == '>')
        {
            for(i = 1; i <= 4; i++)
            {
                if(jogColuna+i >= 15)
                {
                    break;
                }
                if(mapa[jogLinha][jogColuna+i] == '*')
                {
                    break;
                }
                if(mapa[jogLinha][jogColuna+i] == 'k'
                || mapa[jogLinha][jogColuna+i] == 'X'
                || mapa[jogLinha][jogColuna+i] == 'Y'
                || mapa[jogLinha][jogColuna+i] == 'Z')
                {
                    mapa[jogLinha][jogColuna+i] = ' ';
                    break;
                }
            }
        }
    }
    else if(arma == 3)
    {
        int dl, dc;
        for(dl = -1; dl <= 1; dl++)
        {
            for(dc = -1; dc <= 1; dc++)
            {
                if(dl == 0 && dc == 0)
                {
                    continue;
                }
                l = jogLinha + dl;
                c = jogColuna + dc;
                if(l < 0 || l >= 15 || c < 0 || c >= 15)
                {
                    continue;
                }
                if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                {
                    mapa[l][c] = ' ';
                }
            }
        }
    }
}

/* ATAQUE 25x25 */
void realizarAtaque25(char mapa[25][25], int jogLinha, int jogColuna, char direcao)
{
    int l, c, i;

    if(arma == 1)
    {
        if(direcao == '^')
        {
            for(l = jogLinha-1; l >= jogLinha-2; l--)
            {
                if(l < 0)
                {
                    break;
                }
                for(c = jogColuna-1; c <= jogColuna+1; c++)
                {
                    if(c < 0 || c >= 25)
                    {
                        continue;
                    }
                    if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                    || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                    {
                        mapa[l][c] = ' ';
                    }
                }
            }
        }
        else if(direcao == 'v')
        {
            for(l = jogLinha+1; l <= jogLinha+2; l++)
            {
                if(l >= 25)
                {
                    break;
                }
                for(c = jogColuna-1; c <= jogColuna+1; c++)
                {
                    if(c < 0 || c >= 25)
                    {
                        continue;
                    }
                    if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                    || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                    {
                        mapa[l][c] = ' ';
                    }
                }
            }
        }
        else if(direcao == '<')
        {
            for(c = jogColuna-1; c >= jogColuna-2; c--)
            {
                if(c < 0)
                {
                    break;
                }
                for(l = jogLinha-1; l <= jogLinha+1; l++)
                {
                    if(l < 0 || l >= 25)
                    {
                        continue;
                    }
                    if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                    || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                    {
                        mapa[l][c] = ' ';
                    }
                }
            }
        }
        else if(direcao == '>')
        {
            for(c = jogColuna+1; c <= jogColuna+2; c++)
            {
                if(c >= 25)
                {
                    break;
                }
                for(l = jogLinha-1; l <= jogLinha+1; l++)
                {
                    if(l < 0 || l >= 25)
                    {
                        continue;
                    }
                    if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                    || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                    {
                        mapa[l][c] = ' ';
                    }
                }
            }
        }
    }
    else if(arma == 2)
    {
        if(direcao == '^')
        {
            for(i = 1; i <= 4; i++)
            {
                if(jogLinha-i < 0)
                {
                    break;
                }
                if(mapa[jogLinha-i][jogColuna] == '*')
                {
                    break;
                }
                if(mapa[jogLinha-i][jogColuna] == 'k'
                || mapa[jogLinha-i][jogColuna] == 'X'
                || mapa[jogLinha-i][jogColuna] == 'Y'
                || mapa[jogLinha-i][jogColuna] == 'Z')
                {
                    mapa[jogLinha-i][jogColuna] = ' ';
                    break;
                }
            }
        }
        else if(direcao == 'v')
        {
            for(i = 1; i <= 4; i++)
            {
                if(jogLinha+i >= 25)
                {
                    break;
                }
                if(mapa[jogLinha+i][jogColuna] == '*')
                {
                    break;
                }
                if(mapa[jogLinha+i][jogColuna] == 'k'
                || mapa[jogLinha+i][jogColuna] == 'X'
                || mapa[jogLinha+i][jogColuna] == 'Y'
                || mapa[jogLinha+i][jogColuna] == 'Z')
                {
                    mapa[jogLinha+i][jogColuna] = ' ';
                    break;
                }
            }
        }
        else if(direcao == '<')
        {
            for(i = 1; i <= 4; i++)
            {
                if(jogColuna-i < 0)
                {
                    break;
                }
                if(mapa[jogLinha][jogColuna-i] == '*')
                {
                    break;
                }
                if(mapa[jogLinha][jogColuna-i] == 'k'
                || mapa[jogLinha][jogColuna-i] == 'X'
                || mapa[jogLinha][jogColuna-i] == 'Y'
                || mapa[jogLinha][jogColuna-i] == 'Z')
                {
                    mapa[jogLinha][jogColuna-i] = ' ';
                    break;
                }
            }
        }
        else if(direcao == '>')
        {
            for(i = 1; i <= 4; i++)
            {
                if(jogColuna+i >= 25)
                {
                    break;
                }
                if(mapa[jogLinha][jogColuna+i] == '*')
                {
                    break;
                }
                if(mapa[jogLinha][jogColuna+i] == 'k'
                || mapa[jogLinha][jogColuna+i] == 'X'
                || mapa[jogLinha][jogColuna+i] == 'Y'
                || mapa[jogLinha][jogColuna+i] == 'Z')
                {
                    mapa[jogLinha][jogColuna+i] = ' ';
                    break;
                }
            }
        }
    }
    else if(arma == 3)
    {
        int dl, dc;
        for(dl = -1; dl <= 1; dl++)
        {
            for(dc = -1; dc <= 1; dc++)
            {
                if(dl == 0 && dc == 0)
                {
                    continue;
                }
                l = jogLinha + dl;
                c = jogColuna + dc;
                if(l < 0 || l >= 25 || c < 0 || c >= 25)
                {
                    continue;
                }
                if(mapa[l][c] == 'k' || mapa[l][c] == 'X'
                || mapa[l][c] == 'Y' || mapa[l][c] == 'Z')
                {
                    mapa[l][c] = ' ';
                }
            }
        }
    }
}

/* PRIMEIRO ANDAR - mapa 10x10 */
void PrimeiroAndar()
{
    int linha, coluna;
    int jogadorLinha = 1;
    int jogadorColuna = 1;
    int jogando = 1;
    int temChave = 0; /* 0 = nao tem a chave   1 = tem a chave */
    char comando;
    char direcao = '>';

    char mapa[10][10] =
    {
        {'*','*','*','*','*','*','*','*','*','*'},
        {'*',' ','k',' ','k','k','k',' ',' ','*'},
        {'*','k','k','k','k','k','k','k',' ','*'},
        {'*','k','k','k','k','k','k','k',' ','*'},
        {'*','k','k','k','k','k','k','k',' ','*'},
        {'*','k','k','k','k','k','k',' ',' ','*'},
        {'*','k','k','k','k','k','k','#','#','*'},
        {'*','k','k','k','k','k','k','D','L','*'},
        {'*','@','k','k','k','k',' ','#','#','*'},
        {'*','*','*','*','*','*','*','*','*','*'}
    };

    while(jogando)
    {
        system("cls");

        printf("=== PRIMEIRO ANDAR ===\n");
        printf("Vidas: %d  |  Arma: ", vidas);
        if(arma == 1)
        {
            printf("Espada");
        }
        else if(arma == 2)
        {
            printf("Arco e Flecha");
        }
        else
        {
            printf("Cajado");
        }
        printf("  |  Chave: ");
        if(temChave)
        {
            printf("SIM");
        }
        else
        {
            printf("NÃO");
        }
        printf("\n\n");

        for(linha = 0; linha < 10; linha++)
        {
            for(coluna = 0; coluna < 10; coluna++)
            {
                if(linha == jogadorLinha && coluna == jogadorColuna)
                {
                    printf("%c", direcao);
                }
                else
                {
                    printf("%c", mapa[linha][coluna]);
                }
            }
            printf("\n");
        }

        comando = getch();

        /* ===== MOVIMENTO PARA CIMA ===== */
        if(comando == 'w' || comando == 'W')
        {
            direcao = '^';
            /* Verifica espinho antes de qualquer outra coisa */
            if(mapa[jogadorLinha-1][jogadorColuna] == '#')
            {
                vidas--;
                printf("Ash pisou nos espinhos! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return; /* sem vidas, encerra a função */
                }
                PrimeiroAndar(); /* reinicia a fase do zero */
                return;
            }
            /* Verifica se vai pisar na chave: pega automaticamente */
            if(mapa[jogadorLinha-1][jogadorColuna] == '@')
            {
                temChave = 1;
                mapa[jogadorLinha-1][jogadorColuna] = ' '; /* remove chave do mapa */
                jogadorLinha--;
                printf("Você pegou a chave!\n");
                system("pause");
            }
            /* Se nao for parede, caixa ou porta fechada, move */
            else if(mapa[jogadorLinha-1][jogadorColuna] != '*'
                 && mapa[jogadorLinha-1][jogadorColuna] != 'k'
                 && mapa[jogadorLinha-1][jogadorColuna] != 'D')
            {
                /* Se for escada, sobe para o proximo andar */
                if(mapa[jogadorLinha-1][jogadorColuna] == 'L')
                {
                    printf("Ash sobe para o segundo andar...\n");
                    system("pause");
                    jogando = 0;
                    return;
                }
                jogadorLinha--;
            }
        }
        /* ===== MOVIMENTO PARA BAIXO ===== */
        else if(comando == 's' || comando == 'S')
        {
            direcao = 'v';
            if(mapa[jogadorLinha+1][jogadorColuna] == '#')
            {
                vidas--;
                printf("Ash pisou nos espinhos! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                PrimeiroAndar();
                return;
            }
            if(mapa[jogadorLinha+1][jogadorColuna] == '@')
            {
                temChave = 1;
                mapa[jogadorLinha+1][jogadorColuna] = ' ';
                jogadorLinha++;
                printf("Você pegou a chave!\n");
                system("pause");
            }
            else if(mapa[jogadorLinha+1][jogadorColuna] != '*'
                 && mapa[jogadorLinha+1][jogadorColuna] != 'k'
                 && mapa[jogadorLinha+1][jogadorColuna] != 'D')
            {
                if(mapa[jogadorLinha+1][jogadorColuna] == 'L')
                {
                    printf("Ash sobe para o segundo andar...\n");
                    system("pause");
                    jogando = 0;
                    return;
                }
                jogadorLinha++;
            }
        }
        /* ===== MOVIMENTO PARA ESQUERDA ===== */
        else if(comando == 'a' || comando == 'A')
        {
            direcao = '<';
            if(mapa[jogadorLinha][jogadorColuna-1] == '#')
            {
                vidas--;
                printf("Ash pisou nos espinhos! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                PrimeiroAndar();
                return;
            }
            if(mapa[jogadorLinha][jogadorColuna-1] == '@')
            {
                temChave = 1;
                mapa[jogadorLinha][jogadorColuna-1] = ' ';
                jogadorColuna--;
                printf("Você pegou a chave!\n");
                system("pause");
            }
            else if(mapa[jogadorLinha][jogadorColuna-1] != '*'
                 && mapa[jogadorLinha][jogadorColuna-1] != 'k'
                 && mapa[jogadorLinha][jogadorColuna-1] != 'D')
            {
                if(mapa[jogadorLinha][jogadorColuna-1] == 'L')
                {
                    printf("Ash sobe para o segundo andar...\n");
                    system("pause");
                    jogando = 0;
                    return;
                }
                jogadorColuna--;
            }
        }
        /* ===== MOVIMENTO PARA DIREITA ===== */
        else if(comando == 'd' || comando == 'D')
        {
            direcao = '>';
            if(mapa[jogadorLinha][jogadorColuna+1] == '#')
            {
                vidas--;
                printf("Ash pisou nos espinhos! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                PrimeiroAndar();
                return;
            }
            if(mapa[jogadorLinha][jogadorColuna+1] == '@')
            {
                temChave = 1;
                mapa[jogadorLinha][jogadorColuna+1] = ' ';
                jogadorColuna++;
                printf("Você pegou a chave!\n");
                system("pause");
            }
            else if(mapa[jogadorLinha][jogadorColuna+1] != '*'
                 && mapa[jogadorLinha][jogadorColuna+1] != 'k'
                 && mapa[jogadorLinha][jogadorColuna+1] != 'D')
            {
                if(mapa[jogadorLinha][jogadorColuna+1] == 'L')
                {
                    printf("Ash sobe para o segundo andar...\n");
                    system("pause");
                    jogando = 0;
                    return;
                }
                jogadorColuna++;
            }
        }
        /* ===== INTERAGIR COM 'i' ===== */
        else if(comando == 'i' || comando == 'I')
        {
            /* Calcula a celula a frente do jogador */
            int aL = jogadorLinha;
            int aC = jogadorColuna;
            if(direcao == '^')
            {
                aL--;
            }
            else if(direcao == 'v')
            {
                aL++;
            }
            else if(direcao == '<')
            {
                aC--;
            }
            else
            {
                aC++;
            }

            /* Pega a chave com 'i' tambem (alem de pisar) */
            if(mapa[aL][aC] == '@')
            {
                temChave = 1;
                mapa[aL][aC] = ' ';
                printf("Você pegou a chave!\n");
                system("pause");
            }
            /* Tenta abrir a porta com a chave */
            else if(mapa[aL][aC] == 'D')
            {
                if(temChave)
                {
                    mapa[aL][aC] = '='; /* transforma D em porta aberta */
                    temChave = 0;       /* consome a chave */
                    printf("A porta se abre com um rangido sinistro...\n");
                    system("pause");
                }
                else
                {
                    printf("Esta porta está fechada. Você precisa de uma chave.\n");
                    system("pause");
                }
            }
        }
        /* ===== ATACAR COM 'o' ===== */
        else if(comando == 'o' || comando == 'O')
        {
            realizarAtaque10(mapa, jogadorLinha, jogadorColuna, direcao);
        }
    }
}

/* SEGUNDO ANDAR - mapa 15x15
   MONSTRO X (aleatorio):
   A cada turno, depois do jogador agir, sorteamos um número
   aleatório de 0 a 3 usando rand()%4.
   0 = cima, 1 = baixo, 2 = esquerda, 3 = direita. */
void SegundoAndar()
{
    int linha, coluna;
    int jogadorLinha = 1;
    int jogadorColuna = 2;
    int jogando = 1;
    int temChave = 0;
    char comando;
    char direcao = '>';

    /* Controle dos botoes: lógica binária */
    int botaoReal  = 0;
    int botaoBaixo = 0;

    /* Posicoes iniciais dos tres monstros X no mapa.
       Quando um monstro morre (posicao vira -1), ele some. */
    int mon1L = 3, mon1C = 5;
    int mon2L = 12, mon2C = 2;
    int mon3L = 13, mon3C = 4;

    char mapa[15][15] =
    {
    /*       0    1    2    3    4    5    6    7    8    9   10   11   12   13   14 */
    /* 0*/  {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    /* 1*/  {'*', ' ', ' ', 'k', 'O', 'k', 'O', 'k', 'k', '#', '@', '#', ' ', ' ', '*'},
    /* 2*/  {'*', 'k', 'k', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '*'},
    /* 3*/  {'*', 'k', 'k', 'k', 'k', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '*'},
    /* 4*/  {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '*'},
    /* 5*/  {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '*'},
    /* 6*/  {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '*'},
    /* 7*/  {'*', ' ', ' ', ' ', ' ', ' ', ' ', 'O', ' ', ' ', '#', ' ', ' ', ' ', '*'},
    /* 8*/  {'*', '*', '*', '*', '*', '*', '*', '*', '#', '#', 'D', '#', '*', '*', '*'},
    /* 9*/  {'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    /*10*/  {'*', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    /*11*/  {'*', ' ', ' ', '#', '@', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '*'},
    /*12*/  {'*', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', 'D', 'L', '#', '*'},
    /*13*/  {'*', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '*'},
    /*14*/  {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
    };

    /* Coloca os monstros X nas posicoes iniciais do mapa */
    mapa[mon1L][mon1C] = 'X';
    mapa[mon2L][mon2C] = 'X';
    mapa[mon3L][mon3C] = 'X';

    while(jogando)
    {
        system("cls");

        printf("=== SEGUNDO ANDAR ===\n");
        printf("Vidas: %d  |  Arma: ", vidas);
        if(arma == 1)
        {
            printf("Espada");
        }
        else if(arma == 2)
        {
            printf("Arco e Flecha");
        }
        else
        {
            printf("Cajado");
        }
        printf("  |  Chaves: %d\n\n", temChave);

        for(linha = 0; linha < 15; linha++)
        {
            for(coluna = 0; coluna < 15; coluna++)
            {
                if(linha == jogadorLinha && coluna == jogadorColuna)
                {
                    printf("%c", direcao);
                }
                else
                {
                    printf("%c", mapa[linha][coluna]);
                }
            }
            printf("\n");
        }

        comando = getch();

        /* ===== MOVIMENTO PARA CIMA ===== */
        if(comando == 'w' || comando == 'W')
        {
            direcao = '^';
            if(mapa[jogadorLinha-1][jogadorColuna] == '#')
            {
                vidas--;
                printf("Ash pisou nos espinhos! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                SegundoAndar();
                return;
            }
            if(mapa[jogadorLinha-1][jogadorColuna] == '@')
            {
                temChave++;
                mapa[jogadorLinha-1][jogadorColuna] = ' ';
                jogadorLinha--;
                printf("Você pegou uma chave! Total: %d\n", temChave);
                system("pause");
            }
            else if(mapa[jogadorLinha-1][jogadorColuna] != '*'
                 && mapa[jogadorLinha-1][jogadorColuna] != 'k'
                 && mapa[jogadorLinha-1][jogadorColuna] != 'D'
                 && mapa[jogadorLinha-1][jogadorColuna] != 'X'
                 && mapa[jogadorLinha-1][jogadorColuna] != 'O')
            {
                if(mapa[jogadorLinha-1][jogadorColuna] == 'L')
                {
                    printf("Ash sobe para o terceiro andar...\n");
                    system("pause");
                    jogando = 0;
                    return;
                }
                jogadorLinha--;
            }
        }
        /* ===== MOVIMENTO PARA BAIXO ===== */
        else if(comando == 's' || comando == 'S')
        {
            direcao = 'v';
            if(mapa[jogadorLinha+1][jogadorColuna] == '#')
            {
                vidas--;
                printf("Ash pisou nos espinhos! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                SegundoAndar();
                return;
            }
            if(mapa[jogadorLinha+1][jogadorColuna] == '@')
            {
                temChave++;
                mapa[jogadorLinha+1][jogadorColuna] = ' ';
                jogadorLinha++;
                printf("Você pegou uma chave! Total: %d\n", temChave);
                system("pause");
            }
            else if(mapa[jogadorLinha+1][jogadorColuna] != '*'
                 && mapa[jogadorLinha+1][jogadorColuna] != 'k'
                 && mapa[jogadorLinha+1][jogadorColuna] != 'D'
                 && mapa[jogadorLinha+1][jogadorColuna] != 'X'
                 && mapa[jogadorLinha+1][jogadorColuna] != 'O')
            {
                if(mapa[jogadorLinha+1][jogadorColuna] == 'L')
                {
                    printf("Ash sobe para o terceiro andar...\n");
                    system("pause");
                    jogando = 0;
                    return;
                }
                jogadorLinha++;
            }
        }
        /* ===== MOVIMENTO PARA ESQUERDA ===== */
        else if(comando == 'a' || comando == 'A')
        {
            direcao = '<';
            if(mapa[jogadorLinha][jogadorColuna-1] == '#')
            {
                vidas--;
                printf("Ash pisou nos espinhos! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                SegundoAndar();
                return;
            }
            if(mapa[jogadorLinha][jogadorColuna-1] == '@')
            {
                temChave++;
                mapa[jogadorLinha][jogadorColuna-1] = ' ';
                jogadorColuna--;
                printf("Voce pegou uma chave! Total: %d\n", temChave);
                system("pause");
            }
            else if(mapa[jogadorLinha][jogadorColuna-1] != '*'
                 && mapa[jogadorLinha][jogadorColuna-1] != 'k'
                 && mapa[jogadorLinha][jogadorColuna-1] != 'D'
                 && mapa[jogadorLinha][jogadorColuna-1] != 'X'
                 && mapa[jogadorLinha][jogadorColuna-1] != 'O')
            {
                if(mapa[jogadorLinha][jogadorColuna-1] == 'L')
                {
                    printf("Ash sobe para o terceiro andar...\n");
                    system("pause");
                    jogando = 0;
                    return;
                }
                jogadorColuna--;
            }
        }
        /* ===== MOVIMENTO PARA DIREITA ===== */
        else if(comando == 'd' || comando == 'D')
        {
            direcao = '>';
            if(mapa[jogadorLinha][jogadorColuna+1] == '#')
            {
                vidas--;
                printf("Ash pisou nos espinhos! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                SegundoAndar();
                return;
            }
            if(mapa[jogadorLinha][jogadorColuna+1] == '@')
            {
                temChave++;
                mapa[jogadorLinha][jogadorColuna+1] = ' ';
                jogadorColuna++;
                printf("Você pegou uma chave! Total: %d\n", temChave);
                system("pause");
            }
            else if(mapa[jogadorLinha][jogadorColuna+1] != '*'
                 && mapa[jogadorLinha][jogadorColuna+1] != 'k'
                 && mapa[jogadorLinha][jogadorColuna+1] != 'D'
                 && mapa[jogadorLinha][jogadorColuna+1] != 'X'
                 && mapa[jogadorLinha][jogadorColuna+1] != 'O')
            {
                if(mapa[jogadorLinha][jogadorColuna+1] == 'L')
                {
                    printf("Ash sobe para o terceiro andar...\n");
                    system("pause");
                    jogando = 0;
                    return;
                }
                jogadorColuna++;
            }
        }
        /* ===== INTERAGIR COM 'i' ===== */
        else if(comando == 'i' || comando == 'I')
        {
            int aL = jogadorLinha;
            int aC = jogadorColuna;
            if(direcao == '^')
            {
                aL--;
            }
            else if(direcao == 'v')
            {
                aL++;
            }
            else if(direcao == '<')
            {
                aC--;
            }
            else
            {
                aC++;
            }

            if(mapa[aL][aC] == '@')
            {
                temChave++;
                mapa[aL][aC] = ' ';
                printf("Você pegou uma chave! Total: %d\n", temChave);
                system("pause");
            }
            else if(mapa[aL][aC] == 'D')
            {
                if(temChave >= 1)
                {
                    mapa[aL][aC] = '=';
                    temChave--;
                    printf("A porta se abre!\n");
                    system("pause");
                }
                else
                {
                    printf("Você precisa de uma chave.\n");
                    system("pause");
                }
            }
            else if(mapa[aL][aC] == 'O')
            {
                /* Botao falso [1][4]: nao faz nada */
                if(aL == 1 && aC == 4)
                {
                    printf("*clique*\n...nada aconteceu.\n");
                    system("pause");
                }
                /* Botao real [1][6]: remove espinhos da coluna 10, linhas 2 a 7.
                   Isso libera o caminho para a chave @ em [1][10] */
                else if(aL == 1 && aC == 6)
                {
                    if(!botaoReal)
                    {
                        int r;
                        botaoReal = 1;
                        mapa[1][6] = 'o'; /* marca o botao como usado */
                        for(r = 2; r <= 7; r++)
                        {
                            if(mapa[r][10] == '#')
                            {
                                mapa[r][10] = ' ';
                            }
                        }
                        printf("*CLONK* - Os espinhos do corredor recuam!\n");
                        printf("O caminho para a chave está aberto!\n");
                        system("pause");
                    }
                    else
                    {
                        printf("Esse botão já foi ativado.\n");
                        system("pause");
                    }
                }
                /* Botao falso [7][7]: nao faz nada */
                else if(aL == 7 && aC == 7)
                {
                    printf("*clique*\n...nada aconteceu.\n");
                    system("pause");
                }
                /* Botao real [13][1]: remove os espinhos que cercam @[11][4].
                   Espinhos removidos: [10][4], [11][3], [11][5], [12][4].
                   Isso libera o acesso para pegar a segunda chave. */
                else if(aL == 13 && aC == 1)
                {
                    if(!botaoBaixo)
                    {
                        botaoBaixo = 1;
                        mapa[13][1] = 'o';
                        if(mapa[10][4] == '#')
                        {
                            mapa[10][4] = ' ';
                        }
                        if(mapa[11][3] == '#')
                        {
                            mapa[11][3] = ' ';
                        }
                        if(mapa[11][5] == '#')
                        {
                            mapa[11][5] = ' ';
                        }
                        if(mapa[12][4] == '#')
                        {
                            mapa[12][4] = ' ';
                        }
                        printf("*CLUNK* - Os espinhos da chave desapareceram!\n");
                        system("pause");
                    }
                    else
                    {
                        printf("Esse botão já foi ativado.\n");
                        system("pause");
                    }
                }
            }
        }
        /* ===== ATACAR COM 'o' ===== */
        else if(comando == 'o' || comando == 'O')
        {
            realizarAtaque15(mapa, jogadorLinha, jogadorColuna, direcao);
            /* Apos o ataque, verifica se algum monstro foi destruido.
               checamos se a celula onde o monstro estava virou ' '.
               Se virou, marcamos a posicao como -1 para indicar que morreu.*/
            if(mon1L != -1 && mapa[mon1L][mon1C] == ' ')
            {
                mon1L = -1;
                mon1C = -1;
            }
            if(mon2L != -1 && mapa[mon2L][mon2C] == ' ')
            {
                mon2L = -1;
                mon2C = -1;
            }
            if(mon3L != -1 && mapa[mon3L][mon3C] == ' ')
            {
                mon3L = -1;
                mon3C = -1;
            }
        }

        /* MOVIMENTO DO MONSTRO X1 (aleatório) */
        if(mon1L != -1)
        {
            int d = rand() % 4;
            int n1L = mon1L;
            int n1C = mon1C;
            if(d == 0)
            {
                n1L--;
            }
            else if(d == 1)
            {
                n1L++;
            }
            else if(d == 2)
            {
                n1C--;
            }
            else
            {
                n1C++;
            }
            /* So move se a celula estiver dentro do mapa e for livre */
            if(n1L >= 0 && n1L < 15 && n1C >= 0 && n1C < 15
            && (mapa[n1L][n1C] == ' ' || mapa[n1L][n1C] == '='))
            {
                mapa[mon1L][mon1C] = ' '; /* apaga o X da posição antiga */
                mon1L = n1L;
                mon1C = n1C;
                mapa[mon1L][mon1C] = 'X'; /* desenha o X na nova posição */
            }
            /* Se o monstro esta na mesma celula que o jogador */
            if(mon1L == jogadorLinha && mon1C == jogadorColuna)
            {
                vidas--;
                printf("O monstro te pegou! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                SegundoAndar();
                return;
            }
        }

        /* MOVIMENTO DO MONSTRO X2 (aleatório) */
        if(mon2L != -1)
        {
            int d    = rand() % 4;
            int n2L  = mon2L;
            int n2C  = mon2C;
            if(d == 0)
            {
                n2L--;
            }
            else if(d == 1)
            {
                n2L++;
            }
            else if(d == 2)
            {
                n2C--;
            }
            else
            {
                n2C++;
            }
            if(n2L >= 0 && n2L < 15 && n2C >= 0 && n2C < 15
            && (mapa[n2L][n2C] == ' ' || mapa[n2L][n2C] == '='))
            {
                mapa[mon2L][mon2C] = ' ';
                mon2L = n2L;
                mon2C = n2C;
                mapa[mon2L][mon2C] = 'X';
            }
            if(mon2L == jogadorLinha && mon2C == jogadorColuna)
            {
                vidas--;
                printf("O monstro te pegou! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                SegundoAndar();
                return;
            }
        }

        /* MOVIMENTO DO MONSTRO X3 (aleatório) */
        if(mon3L != -1)
        {
            int d    = rand() % 4;
            int n3L  = mon3L;
            int n3C  = mon3C;
            if(d == 0)
            {
                n3L--;
            }
            else if(d == 1)
            {
                n3L++;
            }
            else if(d == 2)
            {
                n3C--;
            }
            else
            {
                n3C++;
            }
            if(n3L >= 0 && n3L < 15 && n3C >= 0 && n3C < 15
            && (mapa[n3L][n3C] == ' ' || mapa[n3L][n3C] == '='))
            {
                mapa[mon3L][mon3C] = ' ';
                mon3L = n3L;
                mon3C = n3C;
                mapa[mon3L][mon3C] = 'X';
            }
            if(mon3L == jogadorLinha && mon3C == jogadorColuna)
            {
                vidas--;
                printf("O monstro te pegou! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                SegundoAndar();
                return;
            }
        }
    }
}

/* TERCEIRO ANDAR - mapa 25x25

   MONSTRO Y (perseguicao simples).

   BOSS Z (atravessa paredes, Prisão de caixas)

   escada aparece após o boss morrer  */
void TerceiroAndar()
{
    int linha, coluna;
    int jogadorLinha = 1;
    int jogadorColuna = 1;
    int jogando = 1;
    int temChave = 0;
    char comando;
    char direcao = '>';

    /* Controle dos botoes */
    int botaoEspinhos = 0; /* O[9][2]: remove # ao redor de @[13][4] */
    int botaoBoss     = 0; /* O[23][1]: solta o boss e remove # linhas 16-23 */

    /* Boss: preso ate botao ser pressionado
       bossVivo: 1 = vivo  0 = morto
       bossVidas: quantos hits ainda aguentam (comeca em 2)
       bossSolto: 0 = preso  1 = perseguindo */
    int bossL     = 23;
    int bossC     = 21;
    int bossVivo  = 1;
    int bossVidas = 2;
    int bossSolto = 0;

    /* Contador de turnos para a habilidade de prisao do boss */
    int turnoSpiked = 0;

    /* Monstros Y: arrays guardam posicao e estado de cada um.
       yL[i] = linha do Y numero i
       yC[i] = coluna do Y numero i
       yVivo[i] = 1 se vivo, 0 se morto */
    int yL[12], yC[12], yVivo[12];

    /* Posicoes iniciais dos 12 monstros Y espalhados pelo mapa */
    yL[0]  = 10; yC[0]  = 9;  yVivo[0]  = 1;
    yL[1]  = 11; yC[1]  = 17; yVivo[1]  = 1;
    yL[2]  = 15; yC[2]  = 17; yVivo[2]  = 1;
    yL[3]  = 17; yC[3]  = 15; yVivo[3]  = 1;
    yL[4]  = 18; yC[4]  = 5;  yVivo[4]  = 1;
    yL[5]  = 20; yC[5]  = 4;  yVivo[5]  = 1;
    yL[6]  = 20; yC[6]  = 21; yVivo[6]  = 1;
    yL[7]  = 13; yC[7]  = 23; yVivo[7]  = 1;
    yL[8]  = 22; yC[8]  = 9;  yVivo[8]  = 1;
    yL[9]  = 21; yC[9]  = 8;  yVivo[9]  = 1;
    yL[10] = 2;  yC[10] = 18; yVivo[10] = 1; /* guarda @[4][23] */
    yL[11] = 2;  yC[11] = 22; yVivo[11] = 1; /* guarda @[4][23] */

    char mapa[25][25] =
    {
/*       0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15   16   17   18   19   20   21   22   23   24 */
/*  0 */{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
/*  1 */{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
/*  2 */{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', '@', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
/*  3 */{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
/*  4 */{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '@', '*'},
/*  5 */{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
/*  6 */{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
/*  7 */{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
/*  8 */{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', 'D', '*'},
/*  9 */{'*', ' ', 'O', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
/* 10 */{'*', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
/* 11 */{'*', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
/* 12 */{'*', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
/* 13 */{'*', ' ', '#', '#', '@', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
/* 14 */{'*', '*', 'D', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
/* 15 */{'*', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
/* 16 */{'*', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '*'},
/* 17 */{'*', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '*'},
/* 18 */{'*', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '*'},
/* 19 */{'*', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '*'},
/* 20 */{'*', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '*'},
/* 21 */{'*', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '*'},
/* 22 */{'*', '#', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', '#', '*'},
/* 23 */{'*', 'O', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '*'},
/* 24 */{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
    };

    while(jogando)
    {
        system("cls");

        printf("=== TERCEIRO ANDAR - A CAMARA DO FALLEN SOVEREIGN ===\n");
        printf("Vidas: %d  |  Arma: ", vidas);
        if(arma == 1)
        {
            printf("Espada");
        }
        else if(arma == 2)
        {
            printf("Arco e Flecha");
        }
        else
        {
            printf("Cajado");
        }
        printf("  |  Chaves: %d  |  Boss: ", temChave);
        if(bossVivo)
        {
            printf("VIVO (vidas: %d)%s", bossVidas, bossSolto ? " [PERSEGUINDO]" : " [PRESO]");
        }
        else
        {
            printf("DERROTADO");
        }
        printf("\n\n");

        /* Desenha o mapa.
           A logica e: jogador > simbolo de direcao.
                       boss vivo na posicao (bossL, bossC) > imprime 'Z'.
                       monstro Y vivo na posicao > imprime 'Y'.
                       qualquer outra celula > imprime o simbolo do mapa. */
        for(linha = 0; linha < 25; linha++)
        {
            for(coluna = 0; coluna < 25; coluna++)
            {
                if(linha == jogadorLinha && coluna == jogadorColuna)
                {
                    printf("%c", direcao);
                }
                else if(bossVivo && linha == bossL && coluna == bossC)
                {
                    printf("Z");
                }
                else
                {
                    /* Verifica se tem algum Y vivo nessa celula */
                    int temY = 0;
                    int idx;
                    for(idx = 0; idx < 12; idx++)
                    {
                        if(yVivo[idx] && linha == yL[idx] && coluna == yC[idx])
                        {
                            temY = 1;
                        }
                    }
                    if(temY)
                    {
                        printf("Y");
                    }
                    else
                    {
                        printf("%c", mapa[linha][coluna]);
                    }
                }
            }
            printf("\n");
        }

        comando = getch();

        /* ===== MOVIMENTO PARA CIMA ===== */
        if(comando == 'w' || comando == 'W')
        {
            direcao = '^';
            /* Espinho mata */
            if(mapa[jogadorLinha-1][jogadorColuna] == '#')
            {
                vidas--;
                printf("Ash pisou nos espinhos! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                TerceiroAndar();
                return;
            }
            /* Pega chave ao pisar */
            if(mapa[jogadorLinha-1][jogadorColuna] == '@')
            {
                temChave++;
                mapa[jogadorLinha-1][jogadorColuna] = ' ';
                jogadorLinha--;
                printf("Você pegou uma chave! Total: %d\n", temChave);
                system("pause");
            }
            else if(mapa[jogadorLinha-1][jogadorColuna] != '*'
                 && mapa[jogadorLinha-1][jogadorColuna] != 'k'
                 && mapa[jogadorLinha-1][jogadorColuna] != 'D')
            {
                /* Escada: so deixa entrar se o boss estiver morto */
                if(mapa[jogadorLinha-1][jogadorColuna] == 'L')
                {
                    if(!bossVivo)
                    {
                        printf("Ash encontra a Joia Dourada...\n");
                        system("pause");
                        jogando = 0;
                        return;
                    }
                    else
                    {
                        printf("O Fallen Sovereign ainda vive!\n");
                        system("pause");
                    }
                }
                else
                {
                    jogadorLinha--;
                }
            }
        }
        /* ===== MOVIMENTO PARA BAIXO ===== */
        else if(comando == 's' || comando == 'S')
        {
            direcao = 'v';
            if(mapa[jogadorLinha+1][jogadorColuna] == '#')
            {
                vidas--;
                printf("Ash pisou nos espinhos! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                TerceiroAndar();
                return;
            }
            if(mapa[jogadorLinha+1][jogadorColuna] == '@')
            {
                temChave++;
                mapa[jogadorLinha+1][jogadorColuna] = ' ';
                jogadorLinha++;
                printf("Você pegou uma chave! Total: %d\n", temChave);
                system("pause");
            }
            else if(mapa[jogadorLinha+1][jogadorColuna] != '*'
                 && mapa[jogadorLinha+1][jogadorColuna] != 'k'
                 && mapa[jogadorLinha+1][jogadorColuna] != 'D')
            {
                if(mapa[jogadorLinha+1][jogadorColuna] == 'L')
                {
                    if(!bossVivo)
                    {
                        printf("Ash encontra a Joia Dourada...\n");
                        system("pause");
                        jogando = 0;
                        return;
                    }
                    else
                    {
                        printf("O Fallen Sovereign ainda vive!\n");
                        system("pause");
                    }
                }
                else
                {
                    jogadorLinha++;
                }
            }
        }
        /* ===== MOVIMENTO PARA ESQUERDA ===== */
        else if(comando == 'a' || comando == 'A')
        {
            direcao = '<';
            if(mapa[jogadorLinha][jogadorColuna-1] == '#')
            {
                vidas--;
                printf("Ash pisou nos espinhos! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                TerceiroAndar();
                return;
            }
            if(mapa[jogadorLinha][jogadorColuna-1] == '@')
            {
                temChave++;
                mapa[jogadorLinha][jogadorColuna-1] = ' ';
                jogadorColuna--;
                printf("Você pegou uma chave! Total: %d\n", temChave);
                system("pause");
            }
            else if(mapa[jogadorLinha][jogadorColuna-1] != '*'
                 && mapa[jogadorLinha][jogadorColuna-1] != 'k'
                 && mapa[jogadorLinha][jogadorColuna-1] != 'D')
            {
                if(mapa[jogadorLinha][jogadorColuna-1] == 'L')
                {
                    if(!bossVivo)
                    {
                        printf("Ash encontra a Joia Dourada...\n");
                        system("pause");
                        jogando = 0;
                        return;
                    }
                    else
                    {
                        printf("O Fallen Sovereign ainda vive!\n");
                        system("pause");
                    }
                }
                else
                {
                    jogadorColuna--;
                }
            }
        }
        /* ===== MOVIMENTO PARA DIREITA ===== */
        else if(comando == 'd' || comando == 'D')
        {
            direcao = '>';
            if(mapa[jogadorLinha][jogadorColuna+1] == '#')
            {
                vidas--;
                printf("Ash pisou nos espinhos! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                TerceiroAndar();
                return;
            }
            if(mapa[jogadorLinha][jogadorColuna+1] == '@')
            {
                temChave++;
                mapa[jogadorLinha][jogadorColuna+1] = ' ';
                jogadorColuna++;
                printf("Você pegou uma chave! Total: %d\n", temChave);
                system("pause");
            }
            else if(mapa[jogadorLinha][jogadorColuna+1] != '*'
                 && mapa[jogadorLinha][jogadorColuna+1] != 'k'
                 && mapa[jogadorLinha][jogadorColuna+1] != 'D')
            {
                if(mapa[jogadorLinha][jogadorColuna+1] == 'L')
                {
                    if(!bossVivo)
                    {
                        printf("Ash encontra a Joia Dourada...\n");
                        system("pause");
                        jogando = 0;
                        return;
                    }
                    else
                    {
                        printf("O Fallen Sovereign ainda vive!\n");
                        system("pause");
                    }
                }
                else
                {
                    jogadorColuna++;
                }
            }
        }
        
        else if(comando == 'i' || comando == 'I')
        {
            int aL = jogadorLinha;
            int aC = jogadorColuna;
            if(direcao == '^')
            {
                aL--;
            }
            else if(direcao == 'v')
            {
                aL++;
            }
            else if(direcao == '<')
            {
                aC--;
            }
            else
            {
                aC++;
            }

            if(mapa[aL][aC] == '@')
            {
                temChave++;
                mapa[aL][aC] = ' ';
                printf("Você pegou uma chave! Total: %d\n", temChave);
                system("pause");
            }
            else if(mapa[aL][aC] == 'D')
            {
                if(temChave >= 1)
                {
                    mapa[aL][aC] = '=';
                    temChave--;
                    printf("A porta se abre!\n");
                    system("pause");
                }
                else
                {
                    printf("Você precisa de uma chave.\n");
                    system("pause");
                }
            }
            else if(mapa[aL][aC] == 'L')
            {
                if(!bossVivo)
                {
                    printf("Ash encontra a Joia Dourada...\n");
                    system("pause");
                    jogando = 0;
                    return;
                }
                else
                {
                    printf("O Fallen Sovereign ainda vive!\n");
                    system("pause");
                }
            }
            else if(mapa[aL][aC] == 'O')
            {
                /* BOTAO [9][2]: remove os '#' ao redor de @[13][4].
                   Os '#' estao nas bordas do quadrado linhas 10-13, colunas 2-5.
                   Remove cada um individualmente para liberar o acesso. */
                if(aL == 9 && aC == 2)
                {
                    if(!botaoEspinhos)
                    {
                        int c2;
                        botaoEspinhos = 1;
                        mapa[9][2] = 'o'; /* marca como usado */
                        /* linha 10: remove '#' das colunas 2 a 5 */
                        for(c2 = 2; c2 <= 5; c2++)
                        {
                            if(mapa[10][c2] == '#')
                            {
                                mapa[10][c2] = ' ';
                            }
                        }
                        /* linhas 11, 12, 13: remove bordas */
                        if(mapa[11][2] == '#')
                        {
                            mapa[11][2] = ' ';
                        }
                        if(mapa[11][5] == '#')
                        {
                            mapa[11][5] = ' ';
                        }
                        if(mapa[12][2] == '#')
                        {
                            mapa[12][2] = ' ';
                        }
                        if(mapa[12][5] == '#')
                        {
                            mapa[12][5] = ' ';
                        }
                        if(mapa[13][2] == '#')
                        {
                            mapa[13][2] = ' ';
                        }
                        if(mapa[13][5] == '#')
                        {
                            mapa[13][5] = ' ';
                        }
                        printf("*CLONK* - Os espinhos ao redor da chave desaparecem!\n");
                        system("pause");
                    }
                    else
                    {
                        printf("Esse botão já foi ativado.\n");
                        system("pause");
                    }
                }
                /* BOTAO [23][1]: solta o boss E remove todos '#' linhas 16-23. */
                else if(aL == 23 && aC == 1)
                {
                    if(!botaoBoss)
                    {
                        int r, c2;
                        botaoBoss = 1;
                        bossSolto = 1; /* o boss começa a perseguir */
                        mapa[23][1] = 'o';
                        for(r = 16; r <= 23; r++)
                        {
                            for(c2 = 0; c2 < 25; c2++)
                            {
                                if(mapa[r][c2] == '#')
                                {
                                    mapa[r][c2] = ' ';
                                }
                            }
                        }
                        printf("*BOOM* - O chão estremece! Os espinhos desaparecem!\n");
                        printf("The Fallen Sovereign foi solto!!!\n");
                        system("pause");
                    }
                    else
                    {
                        printf("Esse botão já foi ativado.\n");
                        system("pause");
                    }
                }
                else
                {
                    printf("*clique*\n...nada aconteceu.\n");
                    system("pause");
                }
            }
        }
        /*  ATACAR COM 'o'  */
        else if(comando == 'o' || comando == 'O')
        {
            realizarAtaque25(mapa, jogadorLinha, jogadorColuna, direcao);

            /* Verifica se algum Y foi atingido pelo ataque */
            int idx;
            for(idx = 0; idx < 12; idx++)
            {
                if(!yVivo[idx])
                {
                    continue; /* pula os que ja estao mortos */
                }
                int hit = 0;
                /* Espada: area 3x2 na frente */
                if(arma == 1)
                {
                    int l2, c2;
                    if(direcao == '^')
                    {
                        for(l2 = jogadorLinha-2; l2 <= jogadorLinha-1 && !hit; l2++)
                        {
                            for(c2 = jogadorColuna-1; c2 <= jogadorColuna+1 && !hit; c2++)
                            {
                                if(l2 == yL[idx] && c2 == yC[idx])
                                {
                                    hit = 1;
                                }
                            }
                        }
                    }
                    else if(direcao == 'v')
                    {
                        for(l2 = jogadorLinha+1; l2 <= jogadorLinha+2 && !hit; l2++)
                        {
                            for(c2 = jogadorColuna-1; c2 <= jogadorColuna+1 && !hit; c2++)
                            {
                                if(l2 == yL[idx] && c2 == yC[idx])
                                {
                                    hit = 1;
                                }
                            }
                        }
                    }
                    else if(direcao == '>')
                    {
                        for(l2 = jogadorLinha-1; l2 <= jogadorLinha+1 && !hit; l2++)
                        {
                            for(c2 = jogadorColuna+1; c2 <= jogadorColuna+2 && !hit; c2++)
                            {
                                if(l2 == yL[idx] && c2 == yC[idx])
                                {
                                    hit = 1;
                                }
                            }
                        }
                    }
                    else if(direcao == '<')
                    {
                        for(l2 = jogadorLinha-1; l2 <= jogadorLinha+1 && !hit; l2++)
                        {
                            for(c2 = jogadorColuna-2; c2 <= jogadorColuna-1 && !hit; c2++)
                            {
                                if(l2 == yL[idx] && c2 == yC[idx])
                                {
                                    hit = 1;
                                }
                            }
                        }
                    }
                }
                /* Arco: 4 celulas em linha reta, para na primeira coisa */
                else if(arma == 2)
                {
                    int i2;
                    if(direcao == '^')
                    {
                        for(i2 = 1; i2 <= 4; i2++)
                        {
                            int nl = jogadorLinha - i2;
                            if(nl < 0)
                            {
                                break;
                            }
                            if(mapa[nl][jogadorColuna] == '*')
                            {
                                break;
                            }
                            if(nl == yL[idx] && jogadorColuna == yC[idx])
                            {
                                hit = 1;
                                break;
                            }
                        }
                    }
                    else if(direcao == 'v')
                    {
                        for(i2 = 1; i2 <= 4; i2++)
                        {
                            int nl = jogadorLinha + i2;
                            if(nl >= 25)
                            {
                                break;
                            }
                            if(mapa[nl][jogadorColuna] == '*')
                            {
                                break;
                            }
                            if(nl == yL[idx] && jogadorColuna == yC[idx])
                            {
                                hit = 1;
                                break;
                            }
                        }
                    }
                    else if(direcao == '>')
                    {
                        for(i2 = 1; i2 <= 4; i2++)
                        {
                            int nc = jogadorColuna + i2;
                            if(nc >= 25)
                            {
                                break;
                            }
                            if(mapa[jogadorLinha][nc] == '*')
                            {
                                break;
                            }
                            if(jogadorLinha == yL[idx] && nc == yC[idx])
                            {
                                hit = 1;
                                break;
                            }
                        }
                    }
                    else if(direcao == '<')
                    {
                        for(i2 = 1; i2 <= 4; i2++)
                        {
                            int nc = jogadorColuna - i2;
                            if(nc < 0)
                            {
                                break;
                            }
                            if(mapa[jogadorLinha][nc] == '*')
                            {
                                break;
                            }
                            if(jogadorLinha == yL[idx] && nc == yC[idx])
                            {
                                hit = 1;
                                break;
                            }
                        }
                    }
                }
                /* Cajado: 8 celulas ao redor */
                else if(arma == 3)
                {
                    int dl2, dc2;
                    for(dl2 = -1; dl2 <= 1 && !hit; dl2++)
                    {
                        for(dc2 = -1; dc2 <= 1 && !hit; dc2++)
                        {
                            if(dl2 == 0 && dc2 == 0)
                            {
                                continue;
                            }
                            if(jogadorLinha+dl2 == yL[idx]
                            && jogadorColuna+dc2 == yC[idx])
                            {
                                hit = 1;
                            }
                        }
                    }
                }
                /* Se atingiu, mata o Y */
                if(hit)
                {
                    yVivo[idx] = 0;
                }
            }

            /* Verifica se o boss foi atingido pelo ataque */
            if(bossVivo)
            {
                int hit = 0;
                if(arma == 1)
                {
                    int l2, c2;
                    if(direcao == '^')
                    {
                        for(l2 = jogadorLinha-2; l2 <= jogadorLinha-1; l2++)
                        {
                            for(c2 = jogadorColuna-1; c2 <= jogadorColuna+1; c2++)
                            {
                                if(l2 == bossL && c2 == bossC)
                                {
                                    hit = 1;
                                }
                            }
                        }
                    }
                    else if(direcao == 'v')
                    {
                        for(l2 = jogadorLinha+1; l2 <= jogadorLinha+2; l2++)
                        {
                            for(c2 = jogadorColuna-1; c2 <= jogadorColuna+1; c2++)
                            {
                                if(l2 == bossL && c2 == bossC)
                                {
                                    hit = 1;
                                }
                            }
                        }
                    }
                    else if(direcao == '>')
                    {
                        for(l2 = jogadorLinha-1; l2 <= jogadorLinha+1; l2++)
                        {
                            for(c2 = jogadorColuna+1; c2 <= jogadorColuna+2; c2++)
                            {
                                if(l2 == bossL && c2 == bossC)
                                {
                                    hit = 1;
                                }
                            }
                        }
                    }
                    else if(direcao == '<')
                    {
                        for(l2 = jogadorLinha-1; l2 <= jogadorLinha+1; l2++)
                        {
                            for(c2 = jogadorColuna-2; c2 <= jogadorColuna-1; c2++)
                            {
                                if(l2 == bossL && c2 == bossC)
                                {
                                    hit = 1;
                                }
                            }
                        }
                    }
                }
                else if(arma == 2)
                {
                    int i2;
                    if(direcao == '^')
                    {
                        for(i2 = 1; i2 <= 4; i2++)
                        {
                            if(jogadorLinha-i2 < 0)
                            {
                                break;
                            }
                            if(jogadorLinha-i2 == bossL && jogadorColuna == bossC)
                            {
                                hit = 1;
                                break;
                            }
                        }
                    }
                    else if(direcao == 'v')
                    {
                        for(i2 = 1; i2 <= 4; i2++)
                        {
                            if(jogadorLinha+i2 >= 25)
                            {
                                break;
                            }
                            if(jogadorLinha+i2 == bossL && jogadorColuna == bossC)
                            {
                                hit = 1;
                                break;
                            }
                        }
                    }
                    else if(direcao == '>')
                    {
                        for(i2 = 1; i2 <= 4; i2++)
                        {
                            if(jogadorColuna+i2 >= 25)
                            {
                                break;
                            }
                            if(jogadorLinha == bossL && jogadorColuna+i2 == bossC)
                            {
                                hit = 1;
                                break;
                            }
                        }
                    }
                    else if(direcao == '<')
                    {
                        for(i2 = 1; i2 <= 4; i2++)
                        {
                            if(jogadorColuna-i2 < 0)
                            {
                                break;
                            }
                            if(jogadorLinha == bossL && jogadorColuna-i2 == bossC)
                            {
                                hit = 1;
                                break;
                            }
                        }
                    }
                }
                else if(arma == 3)
                {
                    int dl2, dc2;
                    for(dl2 = -1; dl2 <= 1; dl2++)
                    {
                        for(dc2 = -1; dc2 <= 1; dc2++)
                        {
                            if(dl2 == 0 && dc2 == 0)
                            {
                                continue;
                            }
                            if(jogadorLinha+dl2 == bossL && jogadorColuna+dc2 == bossC)
                            {
                                hit = 1;
                            }
                        }
                    }
                }

                if(hit)
                {
                    bossVidas--;
                    if(bossVidas <= 0)
                    {
                        /* BOSS MORREU: coloca a escada L no mapa agora. */
                        bossVivo = 0;
                        mapa[23][22] = 'L';
                        printf("THE FALLEN SOVEREIGN FOI DERROTADO!!!\n");
                        printf("A maldição se dissolve... A escada L apareceu!\n");
                        system("pause");
                    }
                    else
                    {
                        printf("Você acertou o Fallen Sovereign! Vidas do boss: %d\n", bossVidas);
                        system("pause");
                    }
                }
            }
        }

        /*  MONSTROS Y - PERSEGUICAO SIMPLES  */
        {
            int idx;
            for(idx = 0; idx < 12; idx++)
            {
                if(!yVivo[idx])
                {
                    continue;
                }

                /* Diferenca de posicao (jogador - monstro) */
                int dL = jogadorLinha - yL[idx];
                int dC = jogadorColuna - yC[idx];
                /* Valor absoluto da diferenca */
                int absDL = dL < 0 ? -dL : dL;
                int absDC = dC < 0 ? -dC : dC;

                int novoL = yL[idx];
                int novoC = yC[idx];

                /* Move no eixo que tem maior distancia ate o jogador */
                if(absDL >= absDC)
                {
                    if(dL > 0)
                    {
                        novoL++;
                    }
                    else if(dL < 0)
                    {
                        novoL--;
                    }
                }
                else
                {
                    if(dC > 0)
                    {
                        novoC++;
                    }
                    else if(dC < 0)
                    {
                        novoC--;
                    }
                }

                /* Verifica se a celula destino e livre antes de mover */
                if(novoL >= 0 && novoL < 25 && novoC >= 0 && novoC < 25)
                {
                    char dest = mapa[novoL][novoC];
                    /* Y e bloqueado por parede, caixa, porta e espinho */
                    if(dest != '*' && dest != 'k' && dest != 'D' && dest != '#')
                    {
                        /* Verifica se nao tem outro Y na celula destino */
                        int temOutroY = 0;
                        int idx2;
                        for(idx2 = 0; idx2 < 12; idx2++)
                        {
                            if(idx2 != idx && yVivo[idx2]
                            && yL[idx2] == novoL && yC[idx2] == novoC)
                            {
                                temOutroY = 1;
                            }
                        }
                        if(!temOutroY)
                        {
                            yL[idx] = novoL;
                            yC[idx] = novoC;
                        }
                    }
                    /* Se bloqueado, Y fica parado neste turno */
                }

                /* Verifica colisao com o jogador apos mover */
                if(yVivo[idx] && yL[idx] == jogadorLinha && yC[idx] == jogadorColuna)
                {
                    vidas--;
                    printf("Um monstro Y te pegou! Vidas: %d\n", vidas);
                    system("pause");
                    if(vidas <= 0)
                    {
                        jogando = 0;
                        return;
                    }
                    TerceiroAndar();
                    return;
                }
            }
        }

        /* BOSS Z - THE FALLEN SOVEREIGN */
        if(bossVivo && bossSolto)
        {
            int dL    = jogadorLinha - bossL;
            int dC    = jogadorColuna - bossC;
            int absDL = dL < 0 ? -dL : dL;
            int absDC = dC < 0 ? -dC : dC;

            /* Move 1 casa no eixo de maior distancia, sem checar obstaculos */
            if(absDL >= absDC)
            {
                if(dL > 0)
                {
                    bossL++;
                }
                else if(dL < 0)
                {
                    bossL--;
                }
            }
            else
            {
                if(dC > 0)
                {
                    bossC++;
                }
                else if(dC < 0)
                {
                    bossC--;
                }
            }

            /* Verifica colisao boss com jogador */
            if(bossL == jogadorLinha && bossC == jogadorColuna)
            {
                vidas--;
                printf("THE FALLEN SOVEREIGN TE GOLPEOU! Vidas: %d\n", vidas);
                system("pause");
                if(vidas <= 0)
                {
                    jogando = 0;
                    return;
                }
                TerceiroAndar();
                return;
            }

            /* Habilidade especial: a cada 3 turnos, cria prisao de caixas.
               turnoSpiked conta os turnos desde que o boss foi solto.
               Quando chega a 3, ativa a habilidade e reseta o contador. */
            turnoSpiked++;
            if(turnoSpiked >= 3)
            {
                turnoSpiked = 0;

                /* As 4 posicoes ortogonais ao jogador: cima, baixo, esq, dir */
                int pL[4] = {jogadorLinha-1, jogadorLinha+1, jogadorLinha,   jogadorLinha  };
                int pC[4] = {jogadorColuna,  jogadorColuna,  jogadorColuna-1, jogadorColuna+1};

                /* Sorteia qual das 4 ficara aberta (sem caixa) */
                int abertura = rand() % 4;
                int i;

                for(i = 0; i < 4; i++)
                {
                    if(i == abertura)
                    {
                        continue; /* deixa essa livre */
                    }
                    int nl = pL[i];
                    int nc = pC[i];
                    if(nl < 0 || nl >= 25 || nc < 0 || nc >= 25)
                    {
                        continue; /* fora do mapa */
                    }
                    /* So coloca caixa em celula vazia */
                    if(mapa[nl][nc] == ' ')
                    {
                        mapa[nl][nc] = 'k';
                    }
                }
                printf("The Fallen Sovereign lança um Box Jail!\n");
                printf("Quebre a caixa para escapar!\n");
                system("pause");
            }
        }
    }
}

/* Quando o jogador escolhe Jogar (1), o fluxo e:
   Vila() -> PrimeiroAndar() -> SegundoAndar() -> TerceiroAndar()
   Depois verifica o resultado: gameOver() ou telaVitoria(). */
int main()
{
    setlocale(LC_ALL, "");  
    srand(time(NULL));      /* inicializa o gerador aleatorio com a hora atual
                               sem isso, rand() sempre geraria a mesma sequencia */
    int usuario;
    menu();

    while(1)
    {
        scanf("%d", &usuario);
        system("cls");

        if(usuario == 1)
        {
            /* Reseta as variaveis globais para comecar uma partida nova */
            arma  = 0;
            vidas = 3;

            printf("Iniciando o jogo...\n\n");
            printf("Ashley Calhoun fica parada na entrada de Raven Hollow.\n");
            printf("O vento uiva entre as ruínas. Ela olha pra frente. Respira.\n");
            printf("E dá o primeiro passo.\n\n");
            system("pause");

            /* Fluxo do jogo: cada fase so roda se o jogador ainda tiver vidas */
            Vila();
            if(vidas > 0)
            {
                PrimeiroAndar();
            }
            if(vidas > 0)
            {
                SegundoAndar();
            }
            if(vidas > 0)
            {
                TerceiroAndar();
            }

            /* Resultado final */
            if(vidas <= 0)
            {
                gameOver();
            }
            else
            {
                telaVitoria();
            }

            /* Reseta para poder jogar de novo sem fechar o programa */
            arma  = 0;
            vidas = 3;
            menu();
        }
        else if(usuario == 2)
        {
            tutorial();
        }
        else if(usuario == 3)
        {
            break; /* sai do while, vai para os creditos e encerra */
        }
        else
        {
            inexistente();
        }
    }

    system("cls");
    printf("DESENVOLVIMENTO: ENZO VITOR DE LIMA MACIEL\tDESIGN: ENZO VITOR DE LIMA MACIEL\n\t\tMUITO OBRIGADO POR JOGAR DUNGEON CRAWLER.\n");
    return 0;
}