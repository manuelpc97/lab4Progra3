#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

void llenarMatriz(int***);
void mostrarSubmarinos(int***);
int*** declararMatriz();
int submarinosContrarios(int***);
int mostrarOpciones();
void wavexy(int***);
void wavexz(int***);
void waveyz(int***);
void normal(int***);


int main(int argc, char*argv[]){
	srand(time(NULL));
	int barcos;
	int ataque=0;
	int jugador = 1;
	bool jugar=true;
	bool seguir = true;
	int decision=0;
	int wave1=3, wave2=3;
	int expansive1=3, expansive2=3;
	int*** tablero1=declararMatriz();
	int*** tablero2 = declararMatriz();
		

	while(seguir){
		llenarMatriz(tablero1);
		llenarMatriz(tablero2);
	
		while(jugar){
			if(jugador==1){
				cout<<"-------------------------------Sus Submarinos (Player 1)---------------------------"<<endl;
				mostrarSubmarinos(tablero1);
				
				cout<<"Usted cuenta con "<<submarinosContrarios(tablero1)<<"submarinos"<<endl;
				cout<<"Su contrario cuenta con "<<submarinosContrarios(tablero2)<<" submarinos"<<endl;
				cout<<"Usted cuenta con "<<wave1<<" waves y con "<<expansive1<<" expansives"<<endl; 
				ataque=mostrarOpciones();
				if(ataque==1){
					normal(tablero2);
				} 
				if(ataque==2){
					if(wave1!=0){
                                		wavexy(tablero2);
						wave1--;
					}else if(wave1==0){
						cout<<"Usted ya no tiene waves"<<endl;
					}        
                                }
				if(ataque==3){
                                	if(wave1!=0){
                                                wavexz(tablero2);
                                                wave1--;
                                        }else if(wave1==0){
                                                cout<<"Usted ya no tiene waves"<<endl;
                                        }
	
					       
                                }
                                if(ataque==4){
					if(wave1!=0){
                                                waveyz(tablero2);
                                                wave1--;
                                        }else if(wave1==0){
                                                cout<<"Usted ya no tiene waves"<<endl;
                                        }
                                	
					        
                                }
				if(ataque==5){
                                        
                                }
				barcos = submarinosContrarios(tablero2);	
				if(barcos==0){
					cout<<"Jugador 1 ha ganado"<<endl;
					jugar=false;
				}else if(barcos>0){
					jugador=2;
				}
			}else if(jugador==2){
			 	cout<<"-------------------------------Sus Submarinos (Player 2)---------------------------"<<endl;
                                mostrarSubmarinos(tablero2);
                                cout<<"Usted cuenta con "<<submarinosContrarios(tablero2)<<" submarinos"<<endl;
				cout<<"Su contrario cuenta con "<<submarinosContrarios(tablero1)<<" submarinos"<< endl;
                                cout<<"Usted cuenta con "<<wave2<<" waves y con "<<expansive2<<" expansives"<<endl;
				ataque=mostrarOpciones();
                                if(ataque==1){
					normal(tablero1);
                                }
                                if(ataque==2){
                                 	if(wave2!=0){
                                                wavexy(tablero1);
                                                wave2--;
                                        }else if(wave2==0){
                                                cout<<"Usted ya no tiene waves"<<endl;
                                        }
       
                                }
                                if(ataque==3){
					if(wave2!=0){
                                                wavexz(tablero1);
                                                wave2--;
                                        }else if(wave2==0){
                                                cout<<"Usted ya no tiene waves"<<endl;
                                        }
                                        
                                }
                                if(ataque==4){
					if(wave2!=0){
                                                waveyz(tablero1);
                                                wave2--;
                                        }else if(wave2==0){
                                                cout<<"Usted ya no tiene waves"<<endl;
                                        }
                                        
                                }
                                if(ataque==5){
                                        
                                }
				
				barcos = submarinosContrarios(tablero1);

				if(barcos==0){
					cout<<"El jugador 2 ha ganado"<<endl;
					jugar=false;
				}else if(barcos>0){
					jugador=1;
				}
			}
		}


		cout<<"Desea seguir jugando: "
		<<endl<<"1. Si"
		<<endl<<"2. NO"
		<<endl;
		cin>>decision;

		if(decision==1)
			seguir =true;
		else
			seguir =false;		
	}	
return 0;
}


int*** declararMatriz(){
	int*** h=new int**[12];
	
	for(int i = 0; i<12; i++){
		h[i]= new int*[12];		
	}

	for(int j = 0; j<12;j++){
		for(int k=0;k<12;k++){
			h[j][k] = new int[12];
		}
	}

	return h;	

}

void llenarMatriz(int*** a){
	int numeros[3];
	int contador = 0;
	while(contador<15){
		for(int j = 0; j<3;j++){
			numeros[j]= 1+rand()%(12-1);
		}
		if(a[numeros[0]][numeros[1]][numeros[2]]==0){
			a[numeros[0]][numeros[1]][numeros[2]]=1;
			contador++;
		}
	}
}


void mostrarSubmarinos(int*** a){
	for(int x=0;x<12;x++){
		for(int y=0;y<12;y++){
			for(int z=0;z<12;z++){
					if(a[x][y][z]==1){
						cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
						
					}
			}	
		}		
	}


}
int submarinosContrarios(int*** a){
int contador=0;
	for(int x=0;x<12;x++){
			for(int y=0;y<12;y++){
				for(int z=0;z<12;z++){
						if(a[x][y][z]==1){
							contador++;					
						}
				}	
			}		
		}


	
	return contador;	
}

int mostrarOpciones(){
	int y;
	cout<<"Seleccione su ataque: "<<endl;
	cout<<"1. Ataque normal "<<endl;
	cout<<"2. Ataque wave en x y"<<endl;
	cout<<"3. Ataque wave en x z"<<endl;
	cout<<"4. Ataque wave en y z"<<endl;
	cout<<"5. Ataque expansive"<<endl;
	cin>>y;
	return y;

}
void normal(int***n){
	int x,y,z;

	cout<<"ingrese la posicion en X"<<endl;
	cin>>x;
	cout<<"ingrese la posicion en Y"<<endl;
	cin>>y;
	cout<<"ingrese la posicion en Z"<<endl;
	cin>>z;

	if(n[x][y][z]==1){
		n[x][y][z]=0;
		cout<<"en la posicion ingresada existia una nave , existiaa porqué ya no :)"<<endl;
	}else{
		cout<<"en la posicion ingresada no existe  una nave , :(  :'("<<endl;
	}

}

void wavexy(int*** b){
	int num;
	cout<<"Ingrese su coordenada en z"<<endl;
	cin>>num;

	for(int i = 0; i<12;i++){
		for(int j = 0; j<12;j++){
			if(b[i][j][num]==1){
				b[i][j][num]==0;
				cout<<"Usted ha asesinado a un barquito en la posicion ("<< i<<","<<j<<","<<num<<")"<<endl;
			}
		}
	}
}

void wavexz(int*** b){
        int num;
        cout<<"Ingrese su coordenada en y"<<endl;
        cin>>num;

        for(int i = 0; i<12;i++){
                for(int j = 0; j<12;j++){
                        if(b[i][num][j]==1){
                                b[i][num][j]==0;
                                cout<<"Usted ha asesinado a un barquito en la posicion ("<< i<<","<<num<<","<<j<<")"<<endl;
                        }
                }
        }
}

void waveyz(int*** b){
        int num;
        cout<<"Ingrese su coordenada en x"<<endl;
        cin>>num;

        for(int i = 0; i<12;i++){
                for(int j = 0; j<12;j++){
                        if(b[num][i][j]==1){
                                b[num][i][j]==0;
                                cout<<"Usted ha asesinado a un barquito en la posicion ("<< num<<","<<i<<","<<j<<")"<<endl;
                        }
                }
        }
}

void expansive(int*** n){
	int x,y,z;
	cout<<"ingrese la posicion en X"<<endl;
        cin>>x;
        cout<<"ingrese la posicion en Y"<<endl;
        cin>>y;
        cout<<"ingrese la posicion en Z"<<endl;
        cin>>z;
	if((x>=1 &&x<=10) && (y>=1 &&y<=10) && (y>=1 &&y<=10)){
		for(int i=x-1;i<x+2;i++){
			for(int j=y-1;j<y+2;j++){
				  for(int k=z-1;k<z+2;k++){
					n[i][j][k]=0;			
		                  }
			}
		}
	}else{
		cout<<"no puede ejecutar este ataque"<<endl
		
	} 

}
