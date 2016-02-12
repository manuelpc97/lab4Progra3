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
			

int main(int argc, char*argv[]){
	srand(time(NULL));
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
				cout<<"Su contrario cuenta con "<<submarinosContrarios(tablero2)<<" submarinos"<<endl;
				cout<<"Usted cuenta con "<<wave1<<" waves y con "<<expansive1<<" expansives"<<endl; 
				ataque=mostrarOpciones();
				if(ataque==1){

				} 
			}else if(jugador==2){
			 	cout<<"-------------------------------Sus Submarinos (Player 2)---------------------------"<<endl;
                                mostrarSubmarinos(tablero2);
                                cout<<"Su contrario cuenta con "<<submarinosContrarios(tablero1)<<" submarinos"<<endl;
				cout<<"Su contrario cuenta con "<<submarinosContrarios(tablero2)<<" submarinos"<< endl;
                                cout<<"Usted cuenta con "<<wave2<<" waves y con "<<expansive2<<" expansives"<<endl;
				ataque=mostrarOpciones();
                                if(ataque==1){

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
