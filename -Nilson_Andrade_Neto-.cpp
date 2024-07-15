#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
using namespace std;
                                        //LINK APRESENTACAO DO GAME: https://youtu.be/I8_KnaOOjYY


int main(){
    srand(time(NULL));
    int colunas=30, linhas=110, bomba=2000;// DEIXEI O INT INVES DO CONST INT PARA A MATRIZ PODER MUDAR na dificuldade
    char matriz1[linhas][colunas], matriz2[linhas][colunas];
    int l, c, x, y, cont, pl, pc;
    int Nlinha, Ncoluna, nbomba=0, chance=0;
    int alternativa,dificuldade;
    do{

        system("Color f");
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<""<<endl;
        cout<<"                                      _______________________________________________  "<<endl;
        cout<<"                                      | |                                         | | "<<endl;
        cout<<"                                      | |________________________________________ | |  "<<endl;
        cout<<"                                      | |                                         | | "<<endl;
        cout<<"                                      | |              CAMPO MINADO               | | "<<endl;
        cout<<"                                      | |                                         | | "<<endl;
        cout<<"                                      | |               1-JOGAR                   | | "<<endl;
        cout<<"                                      | |                                         | | "<<endl;
        cout<<"                                      | |                                         | | "<<endl;
        cout<<"                                      | |               2-SOBRE                   | | "<<endl;
        cout<<"                                      | |                                         | | "<<endl;
        cout<<"                                      | |                                         | | "<<endl;
        cout<<"                                      | |               3-SAIR                    | | "<<endl;
        cout<<"                                      | |                                         | | "<<endl;
        cout<<"                                      | |                                         | | "<<endl;
        cout<<"                                      | |                                         | | "<<endl;
        cout<<"                                      | |_________________________________________| | "<<endl;
        cout<<"                                      | |                                         | | "<<endl;
        cout<<"                                      | |_________________________________________| | "<<endl;

        cout<<">>";cin>> alternativa;
        system("cls");
        switch (alternativa) {// utilizei somente um switch e coloquei a dificuldades dentro do jogar
        system("cls");

        case 1:  //local para selecionar a dificuldade do game
            cout<<""<<endl;
            cout<<""<<endl;
            cout<<""<<endl;
            cout<<""<<endl;
            cout<<""<<endl;
            cout<<"                                   _____________________________________________  "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |________________________________________ | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |       SELECIONE SUA DIFICULDADE         | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |               1-FACIL                   | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |               2-MEDIO                   | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |               3-DIFICIL                 | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |_________________________________________| | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |_________________________________________| | "<<endl;
            cout << ">>"; cin >> dificuldade;
            // coloquei um if cada dificuldade do game cada if contem o tamanho da matriz e o numero de bombas
            if (dificuldade == 1) {
                colunas=9;
                linhas=9;
                bomba=3;
            }
            if(dificuldade==2){
                colunas=15;
                linhas=20;
                bomba=100;
            }
            if(dificuldade==3){}
            system("cls");
            cout <<" informe um linha de 0 a "<<linhas-1<<" e uma coluna de 0 a "<<colunas-1<<endl;


            //local para gerar o numeros da colunas
            system("COLOR E");
            cout<<"\t   ";
            for(Ncoluna=0; Ncoluna<colunas; Ncoluna++){
                cout<<Ncoluna<<"  ";
            }
            cout<<endl<<endl;
            cout<<"\t";

            Nlinha=1;
            cout<<"0  ";
            //loop para gerar as posicoes da matriz inicial
            for(l=0;l<linhas;l++){
                for(c=0; c<colunas;c++) {
                    matriz2[l][c]='=';
                    cout<<matriz2[l][c]<<"  ";
                }// numeros de referente as linhas
                cout<<endl<<"\t";
                if(Nlinha<linhas){
                    cout<<Nlinha<<"  ";
                    Nlinha++;
                }
            }
            cout<<endl;
            // loop para zerar a matriz.
            for(l=0;l<linhas;l++){
                for(c=0;c<colunas;c++){
                    matriz1[l][c]='0';
                }
            }

            cont=0;
            //loop para gerar posicao aleatoria das bombas
            do{

                l=rand()%linhas; //rand para uma linha aleatoria
                c=rand()%colunas; //rand para coluna aleatoria
                if(matriz1[l][c]!='x'){ //caso nao houver bomba no local e adicionada um
                    matriz1[l][c]='x';

                    x=l;
                    y=c;  // variaveis para armazerna o local da bomba

                    for(l=x-1; l<=x+1;l++){
                        for(c=y-1; c<=y+1; c++){
                            if(matriz1[l][c]!='x' && l>=0 && l<linhas && c>=0 && c<colunas){
                                matriz1[l][c]++;
                            }
                        }
                    }
                    cont++;
                }
            }while(cont<bomba); //loop repete enquanto o contador for menor que a quantidade de bombas
            /*
            for(l=0;l<linhas;l++){
                for(c=0;c<colunas;c++){
                    cout<<matriz1[l][c]<<"  ";  //local de teste para saber a localizacao das bombas
                }
                cout<<endl;
            }
*/

            do{
                do{
                    cout<<"Digite uma Linha:";
                    cin>>pl;
                    cout<<"Digite uma Coluna:";
                    cin>>pc;
                    cout<<endl;
                    //local caso o jogador digite um numero fora do tamanho da matriz
                    if(pl>=linhas || pc>=colunas || pl<0 || pc<0){
                        cout<<"por favor tente novamente  digite uma linha de 0 a "<<linhas-1<<" e uma coluna 0 a "<< colunas-1<<endl;
                    }
                    //loop para verificar se a cordenada digitada e valida
                }while(pl>=linhas || pc>=colunas || pl<0 || pc<0);
                bomba++;
                chance++;
                system("cls");
                cout<<"\t    ";
                //local pra exibir as colunas
                for(Ncoluna=0; Ncoluna<colunas; Ncoluna++){
                    cout<<Ncoluna<<"  ";
                }
                cout<<endl<<endl;
                cout<<"\t";

                Nlinha=1;
                cout<<"0   ";

                for(l=0;l<linhas;l++){
                    for(c=0;c<colunas;c++){
                        if(pl==l && pc==c){
                            cout<<matriz1[l][c]<<"  "; //Exibe o valor na coordenada digitada
                            matriz2[l][c]=matriz1[l][c];
                        }else{
                            cout<<matriz2[l][c]<<"  "; //caso nao for a coordenada escolhida o programa continuar exibindo os valores da matriz
                        }
                    }
                    cout<<endl<<"\t";
                    if(Nlinha<linhas){
                        cout<<Nlinha<<"   ";
                        Nlinha++;;
                    }
                }
                cout<<endl;
            }while(matriz2[pl][pc]!='x' && nbomba<linhas*colunas-bomba); //O loop enquanto  nao houver escolhido a coordenada nao contem uma bomba
            system("cls");

            if(matriz2[pl][pc]=='x'){ //Se a posicao escolhida conter uma bomba

                cout<<"BOOM, Voce perdeu tente novamente"<<endl;
                cout<<"Numero de jogadas: "<<chance-1<<endl;
                system("Color 4");
                cout<<""<<endl;
                cout<<""<<endl;
                cout<<""<<endl;
                cout<<""<<endl;
                cout<<""<<endl;
                cout<<""<<endl;
                cout<<"                                              _.-^^---....,,--       "<<endl;
                cout<<"                                          _-- --_             --  -- "<<endl;
                cout<<"                                          < >)                 (< >  "<<endl;
                cout<<"                                          | |                    | | "<<endl;
                cout<<"                                           \._ _./                /  "<<endl;
                cout<<"                                              ```--. . , ; .--'''    "<<endl;
                cout<<"                                                    | | |            "<<endl;
                cout<<"                                                 .-=|| | |=-.        "<<endl;
                cout<<"                                                 `-=#$%&%$#=-'       "<<endl;
                cout<<"                                                    | ; :|           "<<endl;
                cout<<"                                           _____.,-#%&$@%#&#~,._____ "<<endl;
            }else{
                cout<<"Parabens voce ganhouuu "<<endl;
                cout<<"Numero de jogadas: "<<chance<<endl;
                system("COLOR A");
                cout<<"           .* *. `o`o`                                          "<<endl;
                cout<<"                     *. .* o`o`o`o ^,^,^                        "<<endl;
                cout<<"                  * \`o`o` ^,^,^,^,^                            "<<endl;
                cout<<"                     \ *** | ^,^,^,^,^                          "<<endl;
                cout<<"                      \ ***** | /^,^,^                          "<<endl;
                cout<<"                       \ *** | /                                "<<endl;
                cout<<"            ~@~*~@~ \ \ | /                                     "<<endl;
                cout<<"          ~*~@~*~@~*~ \ \ | /                                   "<<endl;
                cout<<"           ~*~@smd@~*~ \ \ | / #$#$# .`'.;.                     "<<endl;
                cout<<"            ~*~@~*~@~*~ \ \ | / #$#$#$# 00 .`,.',               "<<endl;
                cout<<"               ~@~*~@~ \ \ \ | / /#$#$# /||| `.,'               "<<endl;
                cout<<"           _\________/___/____|_/______/_________|\/\___||______"<<endl;

            }

            system("pause");
            system("cls");

            break;

        case 2://irformacao sobre o criador..
            cout<<""<<endl;
            cout<<""<<endl;
            cout<<""<<endl;
            cout<<""<<endl;
            cout<<""<<endl;
            cout<<"                                   _____________________________________________  "<<endl;
            cout<<"                                  | |               TRABALHO M3               | |"<<endl;
            cout<<"                                  | |________________________________________ | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |          ______CRIADOR_______           | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |           NILSON ANDRADE NETO           | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |      MESTRE:EDUARDO ALVES DA SILVA      | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |                                         | | "<<endl;
            cout<<"                                  | |_________________________________________| | "<<endl;
            cout<<"                                  | |                         DATA:11/2022    | | "<<endl;
            cout<<"                                  | |_________________________________________| | "<<endl;
            cout<<""<<endl;
            cout<<""<<endl;
            system("pause");
            system("cls");

            break;
        }

    }while (alternativa!=3);//final do loop principal caso , a alternativa do inicio for 3 o jogo finaliza caso contrario o jogo continua no loop
    return 0;
}





