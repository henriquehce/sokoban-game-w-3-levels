#include <iostream>
#include <locale.h>

using namespace std;

void exibir_menu();
void exibir_sobre();

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao = 0;

    while (opcao != 4) {
        exibir_menu();

        cin >> opcao;

        if (cin.fail()) { // Verifica se houve falha na leitura
            cin.clear(); // Limpa o buffer
            cin.ignore(); // Ignora o caractere digitado
            system("cls"); // Limpa a tela
            cout << "\nOpção inválida\n";
            continue; // Reinicia o loop
        }

        switch (opcao) {
            case 1:
                system("cls"); // Limpa a tela
                cout << "\nOpção escolhida: Novo Jogo\n";
                break;
            case 2:
                system("cls"); // Limpa a tela
                cout << "\nOpção escolhida: Continuar\n";
                break;
            case 3:
                system("cls"); // Limpa a tela
                exibir_sobre();
                break;
            case 4:
                break;
            default:
                system("cls"); // Limpa a tela
                cout << "\nOpção inválida\n";
                break;
        }

        if (opcao != 4) {
            cout << "\nPressione qualquer tecla para continuar...";
            cin.ignore();
            cin.get();
            system("cls"); // Limpa a tela
        }
    }

    return 0;
}

void exibir_menu() {
    cout << "=== MENU ===\n";
    cout << "1 - Novo Jogo\n";
    cout << "2 - Continuar\n";
    cout << "3 - Sobre\n";
    cout << "4 - Fim\n";
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
    cout << "Março 2023.\n";
}
