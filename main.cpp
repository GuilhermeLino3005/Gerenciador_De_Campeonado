/*GERENCIADOR DE CAMPEONATOS (GDC)
Projeto feito por: 
José Guilherme Lino de Sá
José Samuel Pinho Clementino
Kayke Nícolas Ferreira Gonçalves Campos
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#define TIMES_TAM 20 //Tamanho máximo de times
#define JOGOS_TAM 38 //Tamanho máximo de jogos

//Estrutura de dados.
struct Resultado{
    string name;
    int pontos;
};

//Funções Variadas
void linha(){
    cout << "----------------------------------\n";
}

void calcular(int mat[TIMES_TAM][JOGOS_TAM],int lin, int col, Resultado *dados){
    //Função que calcula a pontuação final dos times
    for(int i = 0; i < lin; i++){
        int calculo = 0;
        for(int j = 0; j < col; j++){
            calculo += mat[i][j];
        }
        dados[i].pontos = calculo;
    }
}

void ordenar_vetor(Resultado *dados, int tam) {
    //Função para ordernar o vetor.
    bool trocou;
    do{
        trocou = false;
        for(int i=0; i < tam-1; i++){
            int p = dados[i].pontos;
            int p1 = dados[i+1].pontos;
            //Verificou se o próximo número é maior que o atual
            if(p < p1) { //Se for, mude a ordem
                string n = dados[i].name;
                string n1 = dados[i+1].name;
                // swap
                dados[i].pontos = p1;
                dados[i+1].pontos = p;
                dados[i].name = n1;
                dados[i+1].name = n;

                trocou = true;
            }
        }
    } while(trocou);
}

void atribuir_nome(Resultado *dados, string *nome, int tam){
    //Colocando os nomes dos times na strutura de dados.
    for(int i = 0; i < tam; i++){
        dados[i].name = nome[i];
    }
}


//Funções de leitura.
void ler_vetor(string *nomes, int tam){
    for(int i = 0; i < tam; i++){
        cout << "Digite o nome do " << i + 1 << "° time: ";
        getline(cin, nomes[i]); //O uso do getline permite pegar a linha inteira apesar de espaços.
    }
    linha();
}

void ler_matriz(int mat[TIMES_TAM][JOGOS_TAM], int lin, int col, string *times) {
    for(int i = 0; i < lin; i++) {
        for(int j=0; j < col; j++) {
            cout << "Digite o resultado do " << j + 1 << " jogo do " << times[i] << ": ";
            cin >> mat[i][j];
        }
    }
    linha();
}

void ler_matriz_aleatoria(int mat[TIMES_TAM][JOGOS_TAM], int lin, int col){
    //Pega valores aleatórios entre 0, 1 e 3
    int num;
    srand(time(NULL));
    for(int i = 0; i < lin; i++) {
        for(int j=0; j < col; j++) {
            do{
                num = rand() % 4;
                mat[i][j] = num;
            } while(num == 2);
        }
    }
    linha();
}


//Funções de impressão.
void imprimir_vetor(Resultado dados[TIMES_TAM], int tam){
    for(int i = 0; i < tam; i++){
        cout.width(15); cout << left << dados[i].name << " | " << dados[i].pontos;
        cout << endl;
    }  
}

//MAIN
int main(){
    //Declarações
    int matriz[TIMES_TAM][JOGOS_TAM];
    Resultado *tabela;
    string times[TIMES_TAM]; //Armazena o nome dos times
	string name_camp, digitar;

    //Introdução
    system("cls");
	cout << "Seja bem-vindo(a) ao gerenciador de camponatos GDC!\n";
	cout << "Digite o nome do seu campeonato: ";
	getline(cin, name_camp);
    linha();

    //Passo 1: Entrada de dados
	cout << "Digite o nome dos times participates\n";
    ler_vetor(times, TIMES_TAM);

    //Passo 2: Registro de pontuações
    cout << "Voce pretender digitar os resultados dos jogos? [S/N]: ";
    cin >> digitar;
    if(digitar == "S"){
        cout << "Digite o resultado de cada jogo:\n";
        ler_matriz(matriz, TIMES_TAM, JOGOS_TAM, times);
    } else{
        ler_matriz_aleatoria(matriz, TIMES_TAM, JOGOS_TAM);
    }
	
    //Passo 3: Cálculo das pontuações finais
    tabela = new Resultado[TIMES_TAM];
    atribuir_nome(tabela, times, TIMES_TAM); //Passando o nome dos times do vetor para a base de dados.
    calcular(matriz, TIMES_TAM, JOGOS_TAM, tabela);

    //Passo 4: Apresentação dos resultados
    ordenar_vetor(tabela, TIMES_TAM);
    cout << "Resultado do " << name_camp << "!" << endl;
    cout << "     TIMES      |      RESULTADO" << endl;
    imprimir_vetor(tabela, TIMES_TAM); //Resultado final
}