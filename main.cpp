#include <cstdlib> // para rand()
#include<windows.h>
#include <ctime>
#include<conio.h>
#include <locale.h>
#include <iostream>
#include <fstream>

using namespace std;

struct MENU {
    void exibir_sobre();
    void escolha_menu(int *opcao);
    void exibir_menu(int *opcao);
};

struct MAPA {


    void criacao_mapa(int **m, int x, int y, int l, int c) {
        COORD coord;
        coord.X = 0;
        coord.Y = 0;

        //Posiciona a escrita no início do console
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        ///Imprime o jogo: mapa e personagem.
        for (int i=0; i<l; i++){
            for (int j=0 ;j<c ;j++){
                if (i==x && j==y){
                    cout << char (2); //personagem
                }
                else {
                    switch (m[i][j]){
                        case 0: cout << " "; break; //caminho
                        case 1: cout << char (219); break; //parede
                        case 2: cout << char (207); break; //caixa
                        case 3: cout << char (155); break; //Loc para colocar caixas
                        case 4: cout << char (254); break; //Caixa na posição correta
                    }
                }
            }
            cout<<"\n";
        }
    }

    void identificar_posicao(int **m, bool linha_x, int n, int new_x, int new_y) {
        if (linha_x == true) {
        if (m[new_x + n][new_y] == 3) {
                m[new_x + n][new_y] = m[new_x][new_y];
                if (m[new_x][new_y] == 4) {
                    m[new_x][new_y] = 3;
                } else {
                    m[new_x + n][new_y] = 4;
                    m[new_x][new_y] = 0;
            }
            } else if(m[new_x][new_y] == 4) {
                if(m[new_x + n][new_y] == 3) {
                    m[new_x + n][new_y] = m[new_x][new_y];
                    m[new_x][new_y] = 3;
                } else {
                    m[new_x + n][new_y] = 2;
                    m[new_x][new_y] = 3;
                }
            } else {
                m[new_x + n][new_y] = m[new_x][new_y];
                m[new_x][new_y] = 0;
            }
        } else {
            if (m[new_x][new_y + n] == 3) {
                m[new_x][new_y + n] = m[new_x][new_y];
                if (m[new_x][new_y] == 4) {
                    m[new_x][new_y] = 3;
                } else {
                    m[new_x][new_y + n] = 4;
                    m[new_x][new_y] = 0;
            }
            } else if(m[new_x][new_y] == 4) {
                if(m[new_x][new_y + n] == 3) {
                    m[new_x][new_y + n] = m[new_x][new_y];
                    m[new_x][new_y] = 3;
                } else {
                    m[new_x][new_y + n] = 2;
                    m[new_x][new_y] = 3;
                }
            } else {
                m[new_x][new_y + n] = m[new_x][new_y];
                m[new_x][new_y] = 0;
            }
        }
    }

      bool ler_arquivo(int **m, int *x, int *y, string nome_arquivo, int l, int c)  // Função responsável por abrir o arquivo, ler as posições do jogador e escrever uma matriz do mapa
    {
        ifstream arquivo;
        arquivo.open(nome_arquivo.c_str());

        arquivo >> *x >> *y; //Informação a posição do jogador

        // Colocando a matriz do arquivo dentro de uma matriz do programa
        for (int i = 0; i < l; i++){
            for (int j = 0; j < c; j++){
                arquivo >> m[i][j];
            }
        }

        arquivo.close();
        return true;
    }

    string mapa(string nome_arquivo) {
        if (nome_arquivo == "mapa1.txt") {
            return "Sylvie 7";
        } else if (nome_arquivo == "mapa2.txt") {
            return "Richard Weston Collection: 1";
        } else if (nome_arquivo == "mapa3.txt") {
            return "Alberto Garcia 15";
        }
        return "erro";
    }


};

struct MOVIMENTO {

    MAPA mp;
    MENU mn;

    //Série de 4 funções para movimentar a caixa para cima, para baixo, para esquerda e para direita, respectivamente, juntamente a condição de movimentar apenas 1 caixa.
    void mover_cc (int **m, int new_x, int new_y){
        if((m[new_x][new_y] == 2 || m[new_x][new_y] == 4) && m[new_x -1][new_y] != 1 && m[new_x -1][new_y] != 2  && m[new_x -1][new_y] != 4){
            mp.identificar_posicao(m, true, -1, new_x, new_y);
        }
    }

    void mover_cb (int **m, int new_x, int new_y ){
        if((m[new_x][new_y] == 2 || m[new_x][new_y] == 4) && m[new_x +1][new_y] != 1 && m[new_x +1][new_y] != 2 &&  m[new_x +1][new_y] != 4){
            mp.identificar_posicao(m, true, +1, new_x, new_y);
        }
    }

    void mover_ce (int **m, int new_x, int new_y ){
        if((m[new_x][new_y] == 2 || m[new_x][new_y] == 4) && m[new_x][new_y -1] != 1 && m[new_x][new_y -1] != 2 &&  m[new_x][new_y -1] != 4){
            mp.identificar_posicao(m, false, -1, new_x, new_y);
        }
    }

    void mover_cd (int **m, int new_x, int new_y ){
        if((m[new_x][new_y] == 2 || m[new_x][new_y] == 4) && m[new_x][new_y +1] != 1 && m[new_x][new_y +1] != 2 &&  m[new_x][new_y +1] != 4){
            mp.identificar_posicao(m, false, +1, new_x, new_y);
        }

    }

     void registra_movimentos(int *x, int *y, int **m, int l, int c) {
        ofstream arquivo;
        arquivo.open("Registro de movimentos.txt", ios::app);
        arquivo << *x << " " << *y << endl;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                arquivo << m[i][j] << " ";
            }
            arquivo << endl;
        }

        arquivo.close();
    }

    void verifica_movimentacao(int **m, int *x, int *y, int new_x, int new_y, int *passos, int l, int c) {
        if (m[new_x][new_y] == 0 || m[new_x][new_y] == 3) {
            *x = new_x;
            *y = new_y;
            *passos = *passos + 1;
            registra_movimentos(x, y, m, l, c);
        }
    }

    int mover(int **m, int &x, int &y, int *opcao, int *passos, int l, int c) {
        char tecla;

        // executa os movimentos
        if (_kbhit()) {
            tecla = getch();
            int new_x = x, new_y = y; // variáveis para a nova posição
            switch (tecla) {
            case 72: case 'w': ///cima
                new_x--;
                if (m[new_x][new_y] == 2 || m[new_x][new_y] == 4){
                    mover_cc(m, new_x, new_y);
                }
                break;
            case 80: case 's': ///baixo
                new_x++;
                if (m[new_x][new_y] == 2 || m[new_x][new_y] == 4){
                    mover_cb(m, new_x, new_y);
                }
                break;
            case 75:case 'a': ///esquerda
                new_y--;
                if (m[new_x][new_y] == 2 || m[new_x][new_y] == 4){
                    mover_ce(m, new_x, new_y);
                }
                break;
            case 77: case 'd': ///direita
                new_y++;
                if (m[new_x][new_y] == 2 || m[new_x][new_y] == 4){
                    mover_cd(m, new_x, new_y);
                }
                break;
            case 27:  { // Código ASCII para a tecla "ESC"
                    system("cls");
                    mn.exibir_menu(opcao);
                    if (*opcao == 4) {
                        return 4;
                    } else if(*opcao == 5) {
                        return 5;
                    }
            }
            }

            if (tecla == 's' || tecla == 'w' || tecla == 'a' || tecla == 'd' || tecla == 77 || tecla == 75 || tecla == 80 || tecla == 72) {
                verifica_movimentacao(m, &x, &y, new_x, new_y, passos, l, c);
            }

        }
        return 0;
    }

};

struct JOGO {

    MAPA mp;
    MOVIMENTO mv;
    MENU mn;

    bool vitoria(int **mapa, int x, int y, bool *terminado, int l, int c) {
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < c; j++) {
                if (mapa[i][j] == 2) {
                    return false;
                }
            }
        }
        // Todas as caixas estão na posição correta, jogo acabou
        mp.criacao_mapa(mapa, x, y, l, c);
        cout << "Parabéns, você venceu o jogo!" << endl;
        system("pause");
        cin.clear(); // Limpa o buffer
        cin.ignore(); // Ignora o caractere digitado
        system("cls"); // Limpa a tela
        *terminado = true;
        return true;
    }

    void registro_passos (int *passos, string mapa, string nome_jogador) {
        ofstream meu_arquivo;
        if (mapa == "Sylvie 7") {
            meu_arquivo.open("Ranking Mapa Silvie 7 dados.txt", ios::app);
            meu_arquivo << *passos << " " << nome_jogador << " " << endl;
        } else if (mapa == "Richard Weston Collection: 1") {
            meu_arquivo.open("Ranking Mapa Richard Weston Collection 1 dados.txt", ios::app);
            meu_arquivo << *passos << " " << nome_jogador << " "  << endl;
        } else if (mapa == "Alberto Garcia 15") {
            meu_arquivo.open("Ranking Mapa Alberto Garcia 15 dados.txt", ios::app);
            meu_arquivo << *passos << " " << nome_jogador << " " << endl;
        }

        meu_arquivo.close();
    }

    void voltar_passos(int passo, int **m, int *x, int *y, int l, int c, int *passos) {
        system("cls");
        if (*passos != passo) {
            *passos = passo;
        }
        ifstream arquivo;
        arquivo.open("Registro de Movimentos.txt", ios::app);
        if (!arquivo.is_open()) {
            cout << "Não foi possível abrir o arquivo." << endl;
            return;
        }
        bool terminou = false;
        int passo_atual = 0;
        do {
            arquivo >> *x >> *y;
            for (int i = 0; i < l; i++) {
                for (int j = 0; j < c; j++) {
                    arquivo >> m[i][j];
                }
            }
            if (passo_atual != passo) {
                passo_atual++;
            } else {
                terminou = true;
            }
            if (arquivo.eof()) {
                terminou = true;
            }
        } while (terminou == false);
        arquivo.close();
    }

    void jogar(int **mapa, int x, int y, int *opcao, string mapa_selecionado, int l, int c) {
        string nome_jogador;
        cout<<"Digite seu Nickname: ";
        cin>> nome_jogador;
        system("cls");
        remove("Registro de Movimentos.txt");
        int passos = 0;
        bool terminou;
        mv.registra_movimentos(&x, &y, mapa, l, c);
        while (vitoria(mapa, x, y, &terminou, l, c) == false) {
                    mp.criacao_mapa(mapa, x, y, l, c);
                    int move = mv.mover(mapa, x, y, opcao, &passos, l, c);
                    if (move == 4) {
                        int passo;
                        system("cls");
                        cout << "Você esta no passo " << passos << "." << endl;
                        cout << "Para qual passo você deseja retornar? ";
                        cin >> passo;
                        if (passo <= passos) {
                            voltar_passos(passo, mapa, &x, &y, l, c, &passos);
                        } else {
                            cout << "Voce digitou um valor maior que a quantidade de passos ja dados" << endl;
                            system("pause");
                            system("cls");
                        }

                    } else if (move == 5) {
                        system("cls");
                        break;
                    }
                }
        if (terminou == true) {
            registro_passos(&passos, mapa_selecionado, nome_jogador);
        }
    }

    int quantidade_recordes(string mapa) {
        ifstream arquivo;
        arquivo.open(mapa.c_str());
        string frase;
        int tamanho = 0;
        while (arquivo.eof() == false) {
            getline(arquivo, frase);
            tamanho = tamanho + 1;
        }
        arquivo.close();
        return tamanho;
    }

    void gerar_placar() {
        string mapas[3] = {"Ranking Mapa Alberto Garcia 15 dados.txt", "Ranking Mapa Silvie 7 dados.txt", "Ranking Mapa Richard Weston Collection 1 dados.txt"};
        string mapas_ranking[3] = {"Ranking Mapa Alberto Garcia 15.txt", "Ranking Mapa Silvie 7.txt", "Ranking Mapa Richard Weston Collection 1.txt"};
        int tamanho[3];
        bool existe_arquivo[3];
        for (int i = 0; i < 3; i++) {
            fstream arquivo;
            arquivo.open(mapas[i].c_str());
            if (arquivo.is_open()) {
                tamanho[i] = quantidade_recordes(mapas[i]);
                tamanho[i] = tamanho[i] - 1;
                existe_arquivo[i] = true;
            } else {
                existe_arquivo[i] = false;
            }
            arquivo.close();
        }
        string nome_jogador;
        string numero;
        for (int i = 0; i < 3; i++) {
            if (existe_arquivo[i] == true) {
                ifstream arquivo;
                arquivo.open(mapas[i].c_str());
                string* placares = new string[100];
                string* jogadores = new string[100];
                int j = 0;
                while(arquivo.eof() == false) {
                    getline(arquivo, numero, ' ');
                    getline(arquivo, nome_jogador);
                    placares[j] = numero;
                    jogadores[j] = nome_jogador;
                    j++;
                }

                arquivo.close();
                bool ranking = false;
                string temp_mapa;
                string temp_jogador;
                do {
                ranking = true;
                for (int l = 0; l < tamanho[i] - 1; l++) {
                    if (placares[l] > placares[l + 1]) {
                        ranking = false;
                        temp_mapa = placares[l];
                        placares[l] = placares[l + 1];
                        placares[l + 1] = temp_mapa;

                        temp_jogador = jogadores[l];
                        jogadores[l] = jogadores[l + 1];
                        jogadores[l + 1] = temp_jogador;
                    }
                } } while (ranking == false);

                ofstream meu_arquivo;
                meu_arquivo.open(mapas_ranking[i].c_str());
                for (int k = 0; k < tamanho[i]; k++) {
                    meu_arquivo << "O recorde do jogador: " << jogadores[k] << " ficou em: " << k + 1 << "° posição com o total de: " << placares[k] << " movimentos." << endl;
                }

                delete[] placares;
                delete[] jogadores;

            }
        }
    }

    void novo_jogo(int *opcao) {
        int opcao_mapa = 0;
        int l;
        int c;
        while (opcao_mapa <= 0 || opcao_mapa > 5) {
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
            if(opcao_mapa == 3){
                l = 7;
                c = 6;
            }else if(opcao_mapa == 2){
                l = 10;
                c = 17;
            }else if(opcao_mapa == 1){
                l = 10;
                c = 19;
            }

            system("cls");
            int x = 0;
            int y = 0;
            int** matriz = new int*[l];
            if (opcao_mapa != 5 && opcao_mapa != 4){

                for (int i = 0; i < l; i++){
                    matriz[i] = new int[c];
                }
            }
            if (opcao_mapa >= 1 && opcao_mapa <= 3) {
                char nomeArquivo[10] = {};
                sprintf(nomeArquivo, "mapa%d.txt", opcao_mapa);
                string mapa_selecionado = mp.mapa(nomeArquivo);
                if (mp.ler_arquivo(matriz, &x, &y, nomeArquivo, l, c)) {
                    jogar(matriz, x, y, opcao, mapa_selecionado, l, c);
                }
            } else if (opcao_mapa == 4) {
                srand(time(NULL));
                system("cls");
                int mapa_aleatorio = rand() % 3 + 1;
                opcao_mapa = mapa_aleatorio;
                cout << "Mapa escolhido: Mapa " << mapa_aleatorio << "\n";
                char nomeArquivo[10] = {};
                sprintf(nomeArquivo, "mapa%d.txt", mapa_aleatorio);
                    if(opcao_mapa == 3){
                    l = 7;
                    c = 6;
                }else if(opcao_mapa == 2){
                    l = 10;
                    c = 17;
                }else if(opcao_mapa == 1){
                    l = 10;
                    c = 19;
                }
                for (int i = 0; i < l; i++){
                    matriz[i] = new int[c];
                }
                string mapa_selecionado = mp.mapa(nomeArquivo);
                if (mp.ler_arquivo(matriz, &x, &y, nomeArquivo, l, c)) {
                    jogar(matriz, x, y, opcao, mapa_selecionado, l, c);
                }
            } else if (opcao_mapa == 5) {
                cout << "\nOpção escolhida: Voltar\n";
                for (int i = 0; i < l; i++) {
                    delete[] matriz[i]; // deletando a linha i da matriz
                }
                delete[] matriz; // deletando a matriz
            } else {
                cout << "\nOpção inválida\n";
            }
        }
        mn.exibir_menu(opcao);
    }



};

    void MENU::exibir_sobre() {
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

    void MENU::escolha_menu(int *opcao) {
        JOGO j;
        switch (*opcao) {
                case 1:
                    j.novo_jogo(opcao);
                    break;
                case 2:
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    exibir_sobre();
                    cout << "\nPressione qualquer tecla para continuar...";
                    cin.ignore();
                    cin.get();
                    system("cls");
                    break;
                case 4:
                    break;
                default:
                    cout << "\nOpção invalida\n";
                    system("pause");
                    system("cls");
                    break;
            }
    }

    void MENU::exibir_menu(int *opcao) {
        if (*opcao != 5) {
            *opcao = 0;
        }
        while (*opcao <= 0 || *opcao > 5 || *opcao == 3) {
            cout << "=== MENU ===\n";
            cout << "1 - Novo Jogo\n";
            cout << "2 - Continuar\n";
            cout << "3 - Sobre\n";
            cout << "4 - Voltar passos\n";
            cout << "5 - Fim\n";
            cout << "============\n";
            cout << "Escolha uma opção: ";
            cin >> *opcao;
            if(*opcao != 5) {
            escolha_menu(opcao);
            } else if (*opcao < 0 || *opcao > 5) {
                cout << "\nOpção invalida\n";
                system("pause");
                system("cls");
            } else {
                break;
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

    int opcao = 0;
    MENU menu;
    JOGO j;

    while (opcao != 5) {
        menu.exibir_menu(&opcao);
    }

    system("cls");
    cout << "Jogo foi encerrado" << endl;
    cout << "Muito obrigado por ter jogado!!" << endl;
    j.gerar_placar();

    return 0;
}
