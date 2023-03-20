#include <iostream>
#include <locale.h>
#include <cstdlib> // para rand()

using namespace std;

void exibir_menu();
void exibir_sobre();
void novo_jogo();

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
                novo_jogo();
                break;
            case 2:
                cout << "\nOpção escolhida: Continuar\n";
                break;
            case 3:
                exibir_sobre();
                break;
            case 4:
                cout << "\nOpção escolhida: Fim\n";
                break;
            default:
                cout << "\nOpção inválida\n";
                break;
        }

        if (opcao != 4) {
            cout << "\nPressione qualquer tecla para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
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
    cout << "- Boa sorte e divirta-se!\n";
    cout << "Informações do mês de março de 2023.\n";
}

void novo_jogo() {
    cout << "\nOpção escolhida: Novo Jogo\n";

    int opcao_mapa = 0;

    while (opcao_mapa != 5) {
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
            case 1:
                cout << "\nMapa escolhido: Mapa 1\n";
                break;
            case 2:
                cout << "\nMapa escolhido: Mapa 2\n";
                break;
            case 3:
                cout << "\nMapa escolhido: Mapa 3\n";
                break;
            case 4:
                cout << "\nMapa escolhido: Aleatório\n";
                break;
            case 5:
                cout << "\nOpção escolhida: Voltar\n";
                break;
            default:
                cout << "\nOpção inválida\n";
                break;
        }

        if (opcao_mapa != 5) {
            cout << "\nPressione qualquer tecla para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
        }
        if (cin.fail()) { 
            cin.clear(); 
            cin.ignore(); 
            system("cls"); 
            cout << "\nOpção inválida\n";
            continue; 
        }
    }
}
