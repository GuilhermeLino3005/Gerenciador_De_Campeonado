#include <iostream>
#include <string>
#define TIMES_TAM 20
using namespace std;

//STRUCTS
struct Resultado{
    string name;
    int pontos;
};

//Funções de leitura
void ler_vetor(string dados[TIMES_TAM], int tam){
    for(int i = 0; i < tam; i++){
        cout << "Digite o nome do " << i + 1 << "° time: ";
        getline(cin, dados[i]); //O uso do getline permite pegar a linha inteira apesar de espaços
    }
}
void ler_matriz(int mat[TIMES_TAM][TIMES_TAM], int lin, int col, string *dados) {
    for(int i = 0; i < lin; i++) {
        for(int j=0; j < col; j++) {
            cout << "Digite o resultado do " << j + 1 << "° jogo do " << dados[i] << ": ";
            cin >> mat[i][j];
        }
    }
} 


//Funções de impressão
void imprimir_vetor(Resultado dados[TIMES_TAM], int tam){
    for(int i = 0; i < tam; i++){
        cout << dados[i].name << " | " << dados[i].pontos;
        cout << endl;
    }
    
}
void imprimir_matriz(int mat[TIMES_TAM][TIMES_TAM], int lin, int col, Resultado *dados) {
    for(int i = 0; i < lin; i++) {
        cout << dados[i].name << " | ";
        for(int j = 0; j < col; j++) {
               cout << mat[i][j] << " | ";
        }
        cout << endl;
    }
} 

//Funções diversas
void calcular (int mat[TIMES_TAM][TIMES_TAM],int lin, int col, Resultado dados[TIMES_TAM]){
    for(int i = 0; i < lin; i++){
        int calculo = 0;
        for(int j = 0; j < col; j++){
            calculo += mat[i][j];
        }
        dados[i].pontos = calculo;
    }
}
void organizar(Resultado *dados, int tam) {
    bool trocou;
    do{
        trocou = false;
        for(int i = 0; i < tam - 1; i++){
            int n1 = dados[i].pontos;
            int n2 = dados[i+1].pontos;
            if(n1 < n2) {
                //Troca
                dados[i].pontos = n2;
                dados[i].pontos = n1;
                trocou = true;
            }
        }
    } while(trocou);
}

void atribuir(Resultado *dados, string *nome, int tam){
    for(int i = 0; i < tam; i++){
        dados[i].name = nome[i];
        //dados -> name = nome[i];
    }
}

//MAIN
int main(){
    //Declaração de Variáveis
    int tabela[TIMES_TAM][TIMES_TAM];
    int linha = 3, coluna = 5;
    string nome_times[TIMES_TAM];

    //Declaração da estrutura de dados
    Resultado games[TIMES_TAM];
    
    //preenchendo o vetor "name" com os nomes dos times
    ler_vetor(nome_times, linha);
    ler_matriz(tabela, linha, coluna, nome_times);

    //calculando resultados
    atribuir(games, nome_times, linha);
    calcular(tabela, linha, coluna, games);
    organizar(games, linha);
    cout << "Organizar deu certo\n";

    //Imprimir os resultados
    cout << "\nAbaixo estah a tabela \n" << endl;
    imprimir_matriz(tabela, linha, coluna, games);
    cout << " Abaixo estah o resultado final de cada time " << " \n" << endl;
    imprimir_vetor(games, linha);
    cout << "Deu tudo certo\n";
}