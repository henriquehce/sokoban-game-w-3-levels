#include <iostream>
#include <cstdlib> // para rand()
#include<windows.h>
#include<conio.h>
#include <locale.h>
#include "funcoes.cpp"

using namespace std;


//-------------------------------------------------------------------------------
int main() {
    //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA

    int opcao;

    while ((opcao != 3)) {
        opcao = 0;
        exibir_menu();

        cin >> opcao;

        if (cin.fail()) { // Verifica se houve falha na leitura
            cin.clear(); // Limpa o buffer
            cin.ignore(); // Ignora o caractere digitado
            system("cls"); // Limpa a tela
            cout << "\nOpção invalida\n";
            continue; // Reinicia o loop
        }

        switch (opcao) {
            case 1:
                novo_jogo();
                break;
            case 2:
                exibir_sobre();
                cout << "\nPressione qualquer tecla para continuar...";
                cin.ignore();
                cin.get();
                system("cls");
                break;
            case 3:
                break;
            default:
                cout << "\nOpção invalida\n";
                break;
        }

    }

    return 0;
}