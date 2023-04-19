#include <iostream>
#include <cstdlib> // para rand()
#include<windows.h>
#include <ctime>
#include<conio.h>
#include <locale.h>

#include "mapa.cpp"

using namespace std;


void criacao_mapa(int m[10][19], int x, int y) {
    COORD coord;
    coord.X = 0;
    coord.Y = 0;

    //Posiciona a escrita no início do console
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    ///Imprime o jogo: mapa e personagem.
    for (int i=0;i<10;i++){
        for (int j=0;j<19;j++){
            if (i==x && j==y){
                cout << char (2); //personagem
            }
            else {
                switch (m[i][j]){
                    case 0: cout << " "; break; //caminho
                    case 1: cout << char (219); break; //parede
                    case 3: cout << char (207); break; //caixa
                    case 4: cout << char (155); break; //Loc para colocar caixas
                    case 5: cout << char (254); break; //Caixa na posição correta
                }
            }
        }
        cout<<"\n";
    }
}

void identificar_posicao(int m[10][19], bool linha_x, int n, int new_x, int new_y) {
    if (linha_x == true) {
    if (m[new_x + n][new_y] == 4) {
            m[new_x + n][new_y] = m[new_x][new_y];
            if (m[new_x][new_y] == 5) {
                m[new_x][new_y] = 4;
            } else {
                m[new_x + n][new_y] = 5;
                m[new_x][new_y] = 0;
        }
        } else if(m[new_x][new_y] == 5) {
            if(m[new_x + n][new_y] == 4) {
                m[new_x + n][new_y] = m[new_x][new_y];
                m[new_x][new_y] = 4;
            } else {
                m[new_x + n][new_y] = 3;
                m[new_x][new_y] = 4;
            }
        } else {
            m[new_x + n][new_y] = m[new_x][new_y];
            m[new_x][new_y] = 0;
        }
    } else {
        if (m[new_x][new_y + n] == 4) {
            m[new_x][new_y + n] = m[new_x][new_y];
            if (m[new_x][new_y] == 5) {
                m[new_x][new_y] = 4;
            } else {
                m[new_x][new_y + n] = 5;
                m[new_x][new_y] = 0;
        }
        } else if(m[new_x][new_y] == 5) {
            if(m[new_x][new_y + n] == 4) {
                m[new_x][new_y + n] = m[new_x][new_y];
                m[new_x][new_y] = 4;
            } else {
                m[new_x][new_y + n] = 3;
                m[new_x][new_y] = 4;
            }
        } else {
            m[new_x][new_y + n] = m[new_x][new_y];
            m[new_x][new_y] = 0;
        }
    }
}

//Série de 4 funções para movimentar a caixa para cima, para baixo, para esquerda e para direita, respectivamente, juntamente a condição de movimentar apenas 1 caixa.
void mover_cc (int m[10][19], int new_x, int new_y){

    if((m[new_x][new_y] == 3 || m[new_x][new_y] == 5) && m[new_x -1][new_y] != 1 && m[new_x -1][new_y] != 3  && m[new_x -1][new_y] != 5){
        identificar_posicao(m, true, -1, new_x, new_y);
    }
}
void mover_cb (int m[10][19], int new_x, int new_y ){
    if((m[new_x][new_y] == 3 || m[new_x][new_y] == 5) && m[new_x +1][new_y] != 1 && m[new_x +1][new_y] != 3 &&  m[new_x +1][new_y] != 5){
        identificar_posicao(m, true, +1, new_x, new_y);
    }
}
void mover_ce (int m[10][19], int new_x, int new_y ){
    if((m[new_x][new_y] == 3 || m[new_x][new_y] == 5) && m[new_x][new_y -1] != 1 && m[new_x][new_y -1] != 3 &&  m[new_x][new_y -1] != 5){
        identificar_posicao(m, false, -1, new_x, new_y);
    }
}
void mover_cd (int m[10][19], int new_x, int new_y ){
    if((m[new_x][new_y] == 3 || m[new_x][new_y] == 5) && m[new_x][new_y +1] != 1 && m[new_x][new_y +1] != 3 &&  m[new_x][new_y +1] != 5){
        identificar_posicao(m, false, +1, new_x, new_y);
    }

}

void exibir_menu_pausa() {
    system("cls");
    cout << "Jogo pausado\n\n";
    cout << "1. Reiniciar o jogo\n";
    cout << "2. Continuar o jogo\n";
    cout << "3. Sair\n";
}

int mover(int m[10][19], int &x, int &y) {
    char tecla;

    // executa os movimentos
    if (_kbhit()) {
        tecla = getch();
        int new_x = x, new_y = y; // variáveis para a nova posição
        switch (tecla) {
        case 72: case 'w': ///cima
            new_x--;
            if (m[new_x][new_y] == 3 || m[new_x][new_y] == 5){
                mover_cc(m, new_x, new_y);
            }
            break;
        case 80: case 's': ///baixo
            new_x++;
            if (m[new_x][new_y] == 3 || m[new_x][new_y] == 5){
                mover_cb(m, new_x, new_y);
            }
            break;
        case 75:case 'a': ///esquerda
            new_y--;
            if (m[new_x][new_y] == 3 || m[new_x][new_y] == 5){
                mover_ce(m, new_x, new_y);
            }
            break;
        case 77: case 'd': ///direita
            new_y++;
            if (m[new_x][new_y] == 3 || m[new_x][new_y] == 5){
                mover_cd(m, new_x, new_y);
            }
            break;
        case 27:  { // Código ASCII para a tecla "ESC"
                system("cls");
                exibir_menu_pausa();
                char opcao_pausa = getch();
                switch (opcao_pausa) {
                case '1':
                    return 1;
                case '2':
                    return 2;
                case '3':
                    return 3;
                }
        }
        }

        // verifica se a nova posição é uma parede ou não
        if (m[new_x][new_y] == 0 || m[new_x][new_y] == 4) {
            // atualiza a posição do jogador
            x = new_x;
            y = new_y;
        }


}
    return 0;
}

bool vitoria(int mapa[10][19], int x, int y) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 19; j++) {
            if (mapa[i][j] == 3) {
                return false;
            }
        }
    }
    // Todas as caixas estão na posição correta, jogo acabou
     criacao_mapa(mapa, x, y);
    cout << "Parabéns, você venceu o jogo!" << endl;
    system("pause");
    cin.clear(); // Limpa o buffer
    cin.ignore(); // Ignora o caractere digitado
    system("cls"); // Limpa a tela
    return true;
    }


void exibir_menu() {
    cout << "=== MENU ===\n";
    cout << "1 - Novo Jogo\n";
    cout << "2 - Sobre\n";
    cout << "3 - Fim\n";
    cout << "============\n";
    cout << "Escolha uma opção: ";
}

void exibir_sobre() {
    cout << "\n=== SOBRE ===\n";
    cout << "Alunos: Fernando Galvão Willemann, Henrique Borovicz Reis, Henrique Cipriani Ertal\n";
    cout << "Professor: Thiago Felski Pereira\n";
    cout << "Regras do jogo Sokoban:\n";
    cout << "- O jogador movimenta o personagem para empurrar as caixas até os locais indicados no mapa.\n";
    cout << "- O jogo termina quando todas as caixas estiverem nos locais indicados.\n";
    cout << "- O personagem não pode empurrar mais de uma caixa ao mesmo tempo.\n";
    cout << "- O personagem não pode puxar as caixas.\n";
    cout << "- O personagem não pode passar através das caixas.\n";
    cout << "- O personagem não pode passar através das paredes.\n";
    cout << "Março de 2023.\n";
}


void novo_jogo() {
    cout << "\n Novo Jogo iniciado\n";


    int opcao_mapa = 0;

    while (opcao_mapa == false) {
        cin.clear(); // Limpa o buffer
        cin.ignore(); // Ignora o caractere digitado
        system("cls"); // Limpa a tela
        cout << "\nEscolha o mapa:\n";
        cout << "1 - Mapa 1\n";
        cout << "2 - Mapa 2\n";
        cout << "3 - Mapa 3\n";
        cout << "4 - Aleatório\n";
        cout << "5 - Voltar\n";
        cout << "============\n";
        cout << "Escolha uma opção: ";

        cin >> opcao_mapa;

        switch (opcao_mapa) {
            case 1: {
                opcao_mapa = true;
                cout << "\nMapa escolhido: Mapa 1\n";
                system("cls");
                int mapa[10][19] = {0};
                mapa1(mapa);

                //Posição inicial do personagem no console
                int x=3, y=7;
                while (vitoria(mapa, x, y) == false) {
                        criacao_mapa(mapa, x, y);
                        mover_cc(mapa, x, y);
                        mover_cb(mapa, x, y);
                        mover_ce(mapa, x, y);
                        mover_cd(mapa, x, y);
                        int move = mover(mapa,x , y);
                        if (move == 1) {
                            mapa1(mapa);
                            x = 3;
                            y = 7;
                        }else if(move == 3) {
                            system("cls");
                            break;

                        }
                }
                cin.clear(); // Limpa o buffer
                cin.ignore(); // Ignora o caractere digitado
                system("cls"); // Limpa a tela
                break;
            }
            case 2:{
                opcao_mapa = true;
                cout << "\nMapa escolhido: Mapa 2\n";
                system("cls");
                int mapa[10][19] = {0};
                mapa2(mapa);

                //Posição inicial do personagem no console
                int x=1, y=1;
                while ((vitoria(mapa, x, y) == false)) {
                        criacao_mapa(mapa, x, y);
                        mover_cc(mapa, x, y);
                        mover_cb(mapa, x, y);
                        mover_ce(mapa, x, y);
                        mover_cd(mapa, x, y);
                        int move = mover(mapa,x , y);
                        if (move == 1) {
                            mapa2(mapa);
                            x = 1;
                            y = 1;
                        }else if(move == 3) {
                            system("cls");
                            break;
                }
                break;
            }
        }
            case 3: {
                opcao_mapa = true;
                 cout << "\nMapa escolhido: Mapa 3\n";
                system("cls");
                int mapa[10][19] = {0};
                mapa3(mapa);

                //Posição inicial do personagem no console
                int x=5, y=9;
                while (vitoria(mapa, x, y) == false) {
                        criacao_mapa(mapa, x, y);
                        mover_cc(mapa, x, y);
                        mover_cb(mapa, x, y);
                        mover_ce(mapa, x, y);
                        mover_cd(mapa, x, y);
                        int move = mover(mapa,x , y);
                        if (move == 1) {
                            mapa3(mapa);
                            x = 5;
                            y = 9;
                        }else if(move == 3) {
                            system("cls");
                            break;

                }
                break;
            }
        }
            case 4: {
                opcao_mapa = true;
                srand(time(NULL));
                system("cls");
                int mapa_aleatorio = rand() % 3 + 1;
                cout << "\n\n\n\n\n\n\n\n\n\n\nMapa escolhido: Mapa " << mapa_aleatorio << "\n";
                if (mapa_aleatorio ==1){

                    int mapa[10][19] = {0};
                    mapa1(mapa);


                    //Posição inicial do personagem no console
                    int x=3, y=7;
                    while (vitoria(mapa, x, y) == false) {
                        criacao_mapa(mapa, x, y);
                        mover_cc(mapa, x, y);
                        mover_cb(mapa, x, y);
                        mover_ce(mapa, x, y);
                        mover_cd(mapa, x, y);
                        int move = mover(mapa,x , y);
                        if (move == 1) {
                            mapa1(mapa);
                            x = 3;
                            y = 7;
                        }else if(move == 3) {
                            system("cls");
                            break;

                    }
                }
                }
                else if(mapa_aleatorio == 2){

                    int mapa[10][19] = {0};
                    mapa2(mapa);


                     //Posição inicial do personagem no console
                     int x=1, y=1;
                     while (vitoria(mapa, x, y) == false) {
                        criacao_mapa(mapa, x, y);
                        mover_cc(mapa, x, y);
                        mover_cb(mapa, x, y);
                        mover_ce(mapa, x, y);
                        mover_cd(mapa, x, y);
                        int move = mover(mapa,x , y);
                        if (move == 1) {
                            mapa2(mapa);
                            x = 1;
                            y = 1;
                        }else if(move == 3) {
                            system("cls");
                            break;

                        }
                 }
                }
                else{

                    int mapa[10][19] = {0};
                    mapa3(mapa);

                    //Posição inicial do personagem no console
                    int x=5, y=9;
                    while (vitoria(mapa, x, y) == false) {
                        criacao_mapa(mapa, x, y);
                        mover_cc(mapa, x, y);
                        mover_cb(mapa, x, y);
                        mover_ce(mapa, x, y);
                        mover_cd(mapa, x, y);
                        int move = mover(mapa,x , y);
                        if (move == 1) {
                            mapa3(mapa);
                            x = 5;
                            y = 9;
                        }else if(move == 3) {
                            system("cls");
                            break;

                    }
                }

                break;
            }
          }
            case 5:
                opcao_mapa = true;
                cout << "\nOpção escolhida: Voltar\n";
                break;
            default:
                cout << "\nOpção inválida\n";
                break;
        }
        }

    }
