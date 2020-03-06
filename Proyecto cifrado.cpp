#include <iostream>
#include<fstream>
#include<math.h>
#include<stdio.h>

using namespace std;

int main()
{
    ifstream archivoEntrada;
    ofstream archivoSalida;
    archivoEntrada.open("entrada2.txt");
    archivoSalida.open("datosSalida.txt");
    string codex;
    string num1, operador, num2;
    int y,mayor,z,num1acum,x,longitudNum2,longitudNum1;
    while(getline(archivoEntrada,codex))
        {

            while(archivoEntrada>> num1 >> operador >> num2){
                longitudNum1=num1.length(); // estas dos lineas sirven para saber cuál es el temaño de la primera y segunda cifra en cada linea
                longitudNum2=num2.length();

                if(longitudNum1>=longitudNum2) //me identifica cuantas veces se tiene que repetir el reeemplazo de cada simbolo por un digito (string) para que se cambien todos
                {
                    mayor=longitudNum1;
                }
                else{
                    mayor=longitudNum2;
                }

                for(int h=0; h<mayor;h++){ //ciclo para repetir la sustitución las veces que sean necesario y todos los valores se cambien


                z=operador.find(codex[20]);
                if(z>=0){
                operador.erase(z,1);
                operador.insert(z,"+");
                }

                z=operador.find(codex[22]);
                if(z>=0){
                operador.erase(z,1);
                operador.insert(z,"-");
                }

                z=operador.find(codex[24]);
                if(z>=0){
                operador.erase(z,1);
                operador.insert(z,"*");
                }

                z=operador.find(codex[26]); // Me identifica el operador de la operación en cada linea
                if(z>=0){
                operador.erase(z,1);
                operador.insert(z,"/");
                }

                x=num1.find(codex[0]);//Encuentra el caracter codificado con valor cero de la primer cifra
                if(x>=0){
                num1.erase(x,1);      //borra ese caracter del string
                num1.insert(x,"0"); } //inserta el caracter cero en el string del primer numero


                x=num1.find(codex[2]);
                if(x>=0){
                num1.erase(x,1);
                num1.insert(x,"1");}

                x=num1.find(codex[4]);
                if(x>=0){
                num1.erase(x,1);
                num1.insert(x,"2");
                }

                x=num1.find(codex[6]);
                  if(x>=0){
                num1.erase(x,1);
                num1.insert(x,"3");}

                x=num1.find(codex[8]);
                  if(x>=0){
                num1.erase(x,1);
                num1.insert(x,"4");}

                x=num1.find(codex[10]);
                  if(x>=0){
                num1.erase(x,1);
                num1.insert(x,"5");}

                x=num1.find(codex[12]);
                  if(x>=0){
                num1.erase(x,1);
                num1.insert(x,"6");
                  }

                x=num1.find(codex[14]);
                  if(x>=0){
                num1.erase(x,1);
                num1.insert(x,"7");
                  }

                x=num1.find(codex[16]);
                  if(x>=0){
                num1.erase(x,1);
                num1.insert(x,"8");
                  }

                x=num1.find(codex[18]);
                  if(x>=0){
                num1.erase(x,1);
                num1.insert(x,"9");
                  }

                //Descifrando el segundo numero
                y=num2.find(codex[0]); //Encuentra el caracter codificado con valor cero de la segunda cifra
                if(y>=0){
                num2.erase(y,1);      //borra ese caracter del string
                num2.insert(y,"0"); } //inserta el caracter cero en el string del primer numero


                y=num2.find(codex[2]);
                if(y>=0){
                num2.erase(y,1);
                num2.insert(y,"1");}

                y=num2.find(codex[4]);
                if(y>=0){
                num2.erase(y,1);
                num2.insert(y,"2");
                }

                y=num2.find(codex[6]);
                  if(y>=0){
                num2.erase(y,1);
                num2.insert(y,"3");}

                y=num2.find(codex[8]);
                  if(y>=0){
                num2.erase(y,1);
                num2.insert(y,"4");}

                y=num2.find(codex[10]);
                  if(y>=0){
                num2.erase(y,1);
                num2.insert(y,"5");}

                y=num2.find(codex[12]);
                  if(y>=0){
                num2.erase(y,1);
                num2.insert(y,"6");
                  }

                y=num2.find(codex[14]);
                  if(y>=0){
                num2.erase(y,1);
                num2.insert(y,"7");
                  }

                y=num2.find(codex[16]);
                  if(y>=0){
                num2.erase(y,1);
                num2.insert(y,"8");
                  }

                y=num2.find(codex[18]);
                  if(y>=0){
                num2.erase(y,1);
                num2.insert(y,"9");
                  }
                }//llave que cierra el ciclo para que decodifique todos los digitos

                num1acum=0; //empieza la conversión de caracteres a digitos
                int g,v;
                for(( g=0, v=longitudNum1-1); (g<longitudNum1,v>=0);(g++,v--)){ //este ciclo me sirve para convertir la primer cifra string a enteros.
                        num1acum+=((num1[g]-48)*pow(10,v)); //este es el algoritmo. Funciona sabiendo que un numero es una suma de una base elevado a cada posición.
                }
                int num2acum=0;
                int r,w;
                for(( r=0, w=longitudNum2-1); (r<longitudNum2,w>=0);(r++,w--)){//este ciclo me sirve para convertir la segunda cifra string a enteros.
                        num2acum+=((num2[r]-48)*pow(10,w));
                }
               /* for(int a=0;a<longitudNum1;a++)
                    {
                        cout << num1[a];             //Este ciclo me sirvió para comparar el numero original caracter con el numero entero generado
                    }

                    cout <<" " << operador << " ";

                   for(int f=0;f<longitudNum2;f++)
                    {
                        cout << num2[f];
                    }
               */
                                if(operador=="+") //Serie de discriminantes para poder hacer la operación con los enteros. Identifica que simbolo tiene el string y reemplaza la operación por la operación correspondiente.
                                {
                                    //cout << endl << num1acum << operador  << num2acum << " = " << num1acum+num2acum;
                                    archivoSalida<< num1acum << operador << num2acum << " = " << num1acum+num2acum << endl;
                                }
                                if(operador=="-")
                                {
                                    //cout << endl << num1acum << operador  << num2acum << " = " << num1acum-num2acum;
                                    archivoSalida<< num1acum << operador << num2acum << " = " << num1acum-num2acum << endl;
                                }
                                if(operador=="*")
                                {
                                    //cout << endl << num1acum << operador  << num2acum << " = " << num1acum*num2acum;
                                    archivoSalida<< num1acum << operador << num2acum << " = " << num1acum*num2acum << endl;
                                }
                                if(operador=="/")
                                {
                                    //cout << endl << num1acum << operador  << num2acum << " = " << num1acum/num2acum;
                                    archivoSalida<< num1acum << operador << num2acum << " = " << num1acum/num2acum << endl;
                                }





                                cout << endl;//comando para saltar de linea y lea una nueva operación



            }//llave para cerrar while
        }

    archivoEntrada.close();
    archivoSalida.close();
    return 0;
        }

