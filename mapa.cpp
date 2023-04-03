#include <iostream>
#include<windows.h>
#include<conio.h>

using namespace std;





int mapa2(int m[10][19]) {

    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA



 int matriz[10][19] =
                    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
                     1,4,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,
                     1,0,0,0,0,0,3,0,1,0,3,0,3,0,3,0,1,0,0,
                     1,0,3,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,
                     1,1,1,0,1,0,1,1,0,4,4,4,4,4,4,4,1,0,0,
                     1,1,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,
                     1,4,0,0,1,1,1,0,1,1,0,3,0,0,3,0,1,0,0,
                     1,4,0,0,0,0,0,3,0,1,0,3,0,0,3,0,1,0,0,
                     1,4,3,0,1,1,0,0,0,1,0,0,0,0,0,0,1,0,0,
                     1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,
                     };
 for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 19; j++) {
        m[i][j] = matriz[i][j];
    }
 }



    return 0;
}

int mapa1(int m[10][19]) {

    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA



    int matriz[10][19]{
                    0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,
                    0,0,1,1,1,1,1,0,0,4,4,4,1,0,0,0,0,0,0,
                    0,0,1,0,0,0,1,0,0,1,0,1,1,0,0,0,0,0,0,
                    0,1,1,3,0,3,1,0,3,1,0,1,1,1,1,1,1,1,1,
                    1,1,0,3,0,0,1,3,0,3,0,0,0,3,0,3,0,0,1,
                    1,0,0,3,0,0,0,0,3,0,0,3,0,0,0,0,0,0,1,
                    1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1,1,1,1,
                    1,0,3,0,0,3,1,1,1,1,1,1,0,4,4,4,4,4,1,
                    1,1,1,1,0,0,1,0,0,0,0,1,0,4,4,4,4,4,1,
                    0,0,0,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 19; j++) {
            m[i][j] = matriz[i][j];
        }
    }



    return 0;
}

int mapa3(int m[10][19]) {

    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA



    int matriz[10][19]{
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,1,0,0,3,0,1,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,1,4,3,1,4,1,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,1,0,0,3,0,1,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,1,0,0,4,0,1,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 19; j++) {
            m[i][j] = matriz[i][j];
        }
    }



    return 0;
}