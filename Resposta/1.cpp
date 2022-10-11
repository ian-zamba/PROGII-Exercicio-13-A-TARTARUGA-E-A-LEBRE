#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <iomanip>
#include <fstream> //arquivo
#include <windows.h>
using namespace std;

void AtribuirValores (int v[]){
    if(v[1] <= 0){
        v[1] = 0;
    }
    if(v[1] >= 69){
        v[1] = 69;
    }
}

void ArrumarTablueiro (int t[], int a[], int num, int aux){

    a[0] = a[1];
    a[1] = a[1] + num;
    AtribuirValores(a);
    t[a[0]] = 0;
    t[a[1]] = aux;

}

int main(void) {

    int tabuleiro[70];
    int lebre[2], tartaruga[2];
    int vencedor = 0;
    int aux = 6;

    //inicializa o tabuleiro    
    for (int i = 0; i < 70; i++) {
        tabuleiro[i] = 0;
    }

    lebre[0] = 0;
    lebre[1] = 0;
    tartaruga[0] = 0;
    tartaruga[1] = 0;

    //limpa a tela
    system("cls");

    cout << "BANG!!!!" << endl;
    cout << "E LA VAO ELES!!!! " << endl;

    //imprimir tabuleiro
        cout << "LT";
        for(int i = 0; i < 70; i++){
            cout << "[ ]";
            if(i == aux){
                cout << endl;
                cout << "  ";
                aux += 7;
            }
        }

        //imprimir posicao
        cout << "Lebre: " << lebre[1] + 1 << endl;
        cout << "  Tartaruga: " << tartaruga[1] + 1 << endl;
        
        //esperar 1 segundo
        Sleep(1000);

    do{

        aux = 6;

        //gerar numero aleatorio de 1 a 10
        srand(time(NULL));
        int num = rand() % 10 + 1;

        //lebre
        if(num >= 3 && num <= 4){
            ArrumarTablueiro(tabuleiro, lebre, 9, 1);
        }else if(num == 5){
            ArrumarTablueiro(tabuleiro, lebre, -12, 1);
        }else if(num >= 6 && num <= 8){
            ArrumarTablueiro(tabuleiro, lebre, 1, 1);
        }else if(num >= 9 || num <= 10){
            ArrumarTablueiro(tabuleiro, lebre, -2, 1);
        }

        //tartaruga
        if(num >= 1 && num <= 5){
            ArrumarTablueiro(tabuleiro, tartaruga, 3, 2);
        }else if(num >= 6 && num <= 7){
            ArrumarTablueiro(tabuleiro, tartaruga, -6, 2);
        }else if(num >= 8 && num <= 10){
            ArrumarTablueiro(tabuleiro, tartaruga, 1, 2);
        }

                
        //esperar 1 segundo
        Sleep(1000);

        //limpar a tela
        system("cls");
        cout << "  ";

        //imprimir tabuleiro
        for(int i = 0; i < 70; i++){
            if(tabuleiro[i] == 1){
                if(lebre[1] == tartaruga[1]){
                    cout << "AI!";
                }else{
                    cout << "[L]";
                }
            }else if(tabuleiro[i] == 2){
                if(lebre[1] == tartaruga[1]){
                    cout << "AI!";
                }else{
                    cout << "[T]";
                }
            }else{
                cout << "[ ]";
            }
            if(i == aux){
                cout << endl;                
                cout << "  ";
                aux += 7;
            }
        }

        //imprimir posicao
        cout << "Lebre: " << lebre[1] + 1 << endl;
        cout << "  Tartaruga: " << tartaruga[1] + 1 << endl;

        
        //verificar se a tartaruga passou do limite
        if(tartaruga[1] >= 69){
            cout << "\n  TARTARUGA VENCEU!!! E ISSO AI!!!\n" << endl;
            vencedor = 1;
        }

        //verificar se a lebre passou do limite
        if(lebre[1] >= 69){
            cout << "\n  LEBRE VENCEU!!! MARMELADA!!!\n" << endl;
            vencedor = 1;
        }

    }while(vencedor == 0);

    return 0;
}


/*
                 .eeeeeeeee
                .$$$$$$$$P"
               .$$$$$$$$P
              z$$$$$$$$P
             z$$$$$$$$"
            z$$$$$$$$"
           d$$$$$$$$"
          d$$$$$$$$"
        .d$$$$$$$P
       .$$$$$$$$P
      .$$$$$$$$$.........
     .$$$$$$$$$$$$$$$$$$"
    z$$$$$$$$$$$$$$$$$P"
   -**********$$$$$$$P
             d$$$$$$"
           .d$$$$$$"
          .$$$$$$P"
         z$$$$$$P
        d$$$$$$"
      .d$$$$$$"
     .$$$$$$$"
    z$$$$$$$beeeeee
   d$$$$$$$$$$$$$*
  ^""""""""$$$$$"
          d$$$*
         d$$$"
        d$$*
       d$P"
     .$$"
    .$P"
   .$"
  .P"
 ."
/"

ZAMBA
*/