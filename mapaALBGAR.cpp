#include <iostream>
#include<windows.h>
#include<conio.h>

using namespace std;

void mapa_um(int m[7][6], int x, int y) {
    COORD coord;
    coord.X = 0;
    coord.Y = 0;

    //Posiciona a escrita no início do console
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    ///Imprime o jogo: mapa e personagem.
    for(int i=0;i<7;i++){
        for(int j=0;j<6;j++){
            if(i==x && j==y){
                cout<<char(2); //personagem
            } else {
                switch (m[i][j]){
                    case 0: cout<<" "; break; //caminho
                    case 1: cout<<char(219); break; //parede
                }
            }
        }
        cout<<"\n";
    }
}

void mover(int m[7][6], int &x, int &y) {
    char tecla;

    // executa os movimentos
    if (_kbhit()) {
        tecla = getch();
        int new_x = x, new_y = y; // variáveis para a nova posição
        switch (tecla) {
        case 72: case 'w': ///cima
            new_x--;
            break;
        case 80: case 's': ///baixo
            new_x++;
            break;
        case 75:case 'a': ///esquerda
            new_y--;
            break;
        case 77: case 'd': ///direita
            new_y++;
            break;
        }

        // verifica se a nova posição é uma parede ou não
        if (m[new_x][new_y] == 0) {
            // atualiza a posição do jogador
            x = new_x;
            y = new_y;
        }
    }
}

int main() {

    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA

    int mapa[7][6]={ 
                    1,1,1,1,1,1,
                    1,1,0,0,0,1,
                    1,0,0,0,0,1,
                    1,0,0,1,0,1,
                    1,0,0,0,0,1,
                    1,0,0,0,1,1,
                    1,1,1,1,1,1};

    //Posição inicial do personagem no console
    int x=4, y=4;

    while (true) {
        mapa_um(mapa, x, y);
        mover(mapa, x, y);
    }

    return 0;
} 
