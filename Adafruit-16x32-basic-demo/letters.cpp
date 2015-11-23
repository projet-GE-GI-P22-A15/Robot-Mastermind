#include "letters.h"


void LETTERS::Init() {
}

char** LETTERS::creer1(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 0;
	lettre[0][1] = 0;
	lettre[0][2] = 0;
	lettre[0][3] = 0;
	lettre[0][4] = 1;

	lettre[1][0] = 0;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 1;
	lettre[1][4] = 1;

	lettre[2][0] = 0;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 0;
	lettre[3][1] = 0;
	lettre[3][2] = 0;
	lettre[3][3] = 0;
	lettre[3][4] = 1;

	lettre[4][0] = 0;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 0;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 0;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 0;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creer2(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 1;

	lettre[1][0] = 0;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 0;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 0;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 0;

	lettre[6][0] = 1;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creer3(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 1;

	lettre[1][0] = 0;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 0;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 1;

	lettre[4][0] = 0;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 0;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creer4(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 0;
	lettre[0][2] = 0;
	lettre[0][3] = 0;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 1;

	lettre[4][0] = 0;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 0;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 0;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 0;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creer5(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 0;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 0;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 1;

	lettre[4][0] = 0;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 0;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creer6(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 0;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 0;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creer7(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 1;

	lettre[1][0] = 0;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 0;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 0;
	lettre[3][1] = 0;
	lettre[3][2] = 0;
	lettre[3][3] = 0;
	lettre[3][4] = 1;

	lettre[4][0] = 0;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 0;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 0;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 0;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creer8(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creer9(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 1;

	lettre[4][0] = 0;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 0;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 0;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 0;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creer0(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 0;
	lettre[3][2] = 0;
	lettre[3][3] = 0;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creerQ(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 0;
	lettre[3][2] = 0;
	lettre[3][3] = 0;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 1;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 1;
	lettre[5][2] = 1;
	lettre[5][3] = 1;
	lettre[5][4] = 0;

	lettre[6][0] = 0;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 1;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creerW(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 0;
	lettre[0][2] = 0;
	lettre[0][3] = 0;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 0;
	lettre[3][2] = 1;
	lettre[3][3] = 0;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 1;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 1;
	lettre[5][2] = 1;
	lettre[5][3] = 1;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creerE(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 0;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 0;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 0;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 0;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 0;

	lettre[6][0] = 1;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creerR(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 0;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 0;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 1;
	lettre[4][4] = 0;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 0;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creerT(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 1;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 0;
	lettre[2][1] = 0;
	lettre[2][2] = 1;
	lettre[2][3] = 0;
	lettre[2][4] = 0;

	lettre[3][0] = 0;
	lettre[3][1] = 0;
	lettre[3][2] = 1;
	lettre[3][3] = 0;
	lettre[3][4] = 0;

	lettre[4][0] = 0;
	lettre[4][1] = 0;
	lettre[4][2] = 1;
	lettre[4][3] = 0;
	lettre[4][4] = 0;

	lettre[5][0] = 0;
	lettre[5][1] = 0;
	lettre[5][2] = 1;
	lettre[5][3] = 0;
	lettre[5][4] = 0;

	lettre[6][0] = 0;
	lettre[6][1] = 0;
	lettre[6][2] = 1;
	lettre[6][3] = 0;
	lettre[6][4] = 0;

	return lettre;
}
char** LETTERS::creerY(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 0;
	lettre[0][2] = 0;
	lettre[0][3] = 0;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 0;
	lettre[2][1] = 1;
	lettre[2][2] = 0;
	lettre[2][3] = 1;
	lettre[2][4] = 0;

	lettre[3][0] = 0;
	lettre[3][1] = 1;
	lettre[3][2] = 0;
	lettre[3][3] = 1;
	lettre[3][4] = 0;

	lettre[4][0] = 0;
	lettre[4][1] = 0;
	lettre[4][2] = 1;
	lettre[4][3] = 0;
	lettre[4][4] = 0;

	lettre[5][0] = 0;
	lettre[5][1] = 0;
	lettre[5][2] = 1;
	lettre[5][3] = 0;
	lettre[5][4] = 0;

	lettre[6][0] = 0;
	lettre[6][1] = 0;
	lettre[6][2] = 1;
	lettre[6][3] = 0;
	lettre[6][4] = 0;

	return lettre;
}
char** LETTERS::creerU(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 0;
	lettre[0][2] = 0;
	lettre[0][3] = 0;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 0;
	lettre[3][2] = 0;
	lettre[3][3] = 0;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 0;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 0;

	return lettre;
}
char** LETTERS::creerI(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 1;

	lettre[1][0] = 0;
	lettre[1][1] = 0;
	lettre[1][2] = 1;
	lettre[1][3] = 0;
	lettre[1][4] = 0;

	lettre[2][0] = 0;
	lettre[2][1] = 0;
	lettre[2][2] = 1;
	lettre[2][3] = 0;
	lettre[2][4] = 0;

	lettre[3][0] = 0;
	lettre[3][1] = 0;
	lettre[3][2] = 1;
	lettre[3][3] = 0;
	lettre[3][4] = 0;

	lettre[4][0] = 0;
	lettre[4][1] = 0;
	lettre[4][2] = 1;
	lettre[4][3] = 0;
	lettre[4][4] = 0;

	lettre[5][0] = 0;
	lettre[5][1] = 0;
	lettre[5][2] = 1;
	lettre[5][3] = 0;
	lettre[5][4] = 0;

	lettre[6][0] = 1;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creerO(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 0;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 0;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 0;
	lettre[3][2] = 0;
	lettre[3][3] = 0;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 0;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 0;

	return lettre;
}
char** LETTERS::creerP(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 0;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 0;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 0;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 0;

	lettre[6][0] = 1;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 0;
	lettre[6][4] = 0;

	return lettre;
}
char** LETTERS::creerA(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 0;
	lettre[0][1] = 0;
	lettre[0][2] = 1;
	lettre[0][3] = 0;
	lettre[0][4] = 0;

	lettre[1][0] = 0;
	lettre[1][1] = 1;
	lettre[1][2] = 0;
	lettre[1][3] = 1;
	lettre[1][4] = 0;

	lettre[2][0] = 0;
	lettre[2][1] = 1;
	lettre[2][2] = 0;
	lettre[2][3] = 1;
	lettre[2][4] = 0;

	lettre[3][0] = 1;
	lettre[3][1] = 0;
	lettre[3][2] = 0;
	lettre[3][3] = 0;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 1;
	lettre[4][2] = 1;
	lettre[4][3] = 1;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 0;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creerS(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 0;
	lettre[0][3] = 0;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 1;
	lettre[1][3] = 1;
	lettre[1][4] = 0;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 0;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 1;

	lettre[4][0] = 0;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 0;
	lettre[5][1] = 1;
	lettre[5][2] = 1;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 1;
	lettre[6][4] = 0;

	return lettre;
}
char** LETTERS::creerD(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 0;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 0;
	lettre[3][2] = 0;
	lettre[3][3] = 0;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 0;

	return lettre;
}
char** LETTERS::creerF(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 0;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 0;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 0;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 0;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 0;

	lettre[6][0] = 1;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 0;
	lettre[6][4] = 0;

	return lettre;
}
char** LETTERS::creerG(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 0;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 0;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 0;

	lettre[3][0] = 1;
	lettre[3][1] = 0;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 0;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 0;

	return lettre;
}
char** LETTERS::creerH(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 0;
	lettre[0][2] = 0;
	lettre[0][3] = 0;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 0;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creerJ(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 0;
	lettre[0][1] = 0;
	lettre[0][2] = 0;
	lettre[0][3] = 0;
	lettre[0][4] = 1;

	lettre[1][0] = 0;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 0;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 0;
	lettre[3][1] = 0;
	lettre[3][2] = 0;
	lettre[3][3] = 0;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 0;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 0;

	return lettre;
}
char** LETTERS::creerK(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 0;
	lettre[0][2] = 0;
	lettre[0][3] = 0;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 1;
	lettre[1][4] = 0;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 1;
	lettre[2][3] = 0;
	lettre[2][4] = 0;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 0;
	lettre[3][3] = 0;
	lettre[3][4] = 0;

	lettre[4][0] = 1;
	lettre[4][1] = 1;
	lettre[4][2] = 1;
	lettre[4][3] = 0;
	lettre[4][4] = 0;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 1;
	lettre[5][3] = 1;
	lettre[5][4] = 0;

	lettre[6][0] = 1;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 1;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creerL(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 0;
	lettre[0][2] = 0;
	lettre[0][3] = 0;
	lettre[0][4] = 0;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 0;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 0;

	lettre[3][0] = 1;
	lettre[3][1] = 0;
	lettre[3][2] = 0;
	lettre[3][3] = 0;
	lettre[3][4] = 0;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 0;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creerZ(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 0;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 1;
	lettre[2][4] = 1;

	lettre[3][0] = 0;
	lettre[3][1] = 0;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 0;

	lettre[4][0] = 0;
	lettre[4][1] = 1;
	lettre[4][2] = 1;
	lettre[4][3] = 0;
	lettre[4][4] = 0;

	lettre[5][0] = 1;
	lettre[5][1] = 1;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creerX(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 0;
	lettre[0][2] = 0;
	lettre[0][3] = 0;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 0;
	lettre[2][1] = 1;
	lettre[2][2] = 0;
	lettre[2][3] = 1;
	lettre[2][4] = 0;

	lettre[3][0] = 0;
	lettre[3][1] = 0;
	lettre[3][2] = 1;
	lettre[3][3] = 0;
	lettre[3][4] = 0;

	lettre[4][0] = 0;
	lettre[4][1] = 1;
	lettre[4][2] = 0;
	lettre[4][3] = 1;
	lettre[4][4] = 0;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 0;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creerC(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 0;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 0;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 0;

	lettre[3][0] = 1;
	lettre[3][1] = 0;
	lettre[3][2] = 0;
	lettre[3][3] = 0;
	lettre[3][4] = 0;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 0;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 0;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 0;

	return lettre;
}
char** LETTERS::creerV(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 0;
	lettre[0][2] = 0;
	lettre[0][3] = 0;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 0;
	lettre[3][3] = 1;
	lettre[3][4] = 1;

	lettre[4][0] = 0;
	lettre[4][1] = 1;
	lettre[4][2] = 0;
	lettre[4][3] = 1;
	lettre[4][4] = 0;

	lettre[5][0] = 0;
	lettre[5][1] = 1;
	lettre[5][2] = 1;
	lettre[5][3] = 1;
	lettre[5][4] = 0;

	lettre[6][0] = 0;
	lettre[6][1] = 0;
	lettre[6][2] = 1;
	lettre[6][3] = 0;
	lettre[6][4] = 0;

	return lettre;
}
char** LETTERS::creerB(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 1;
	lettre[0][2] = 1;
	lettre[0][3] = 1;
	lettre[0][4] = 0;

	lettre[1][0] = 1;
	lettre[1][1] = 0;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 0;
	lettre[2][2] = 0;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 1;
	lettre[3][2] = 1;
	lettre[3][3] = 1;
	lettre[3][4] = 0;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 1;
	lettre[6][2] = 1;
	lettre[6][3] = 1;
	lettre[6][4] = 0;

	return lettre;
}
char** LETTERS::creerN(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 0;
	lettre[0][2] = 0;
	lettre[0][3] = 0;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 1;
	lettre[1][2] = 0;
	lettre[1][3] = 0;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 1;
	lettre[2][2] = 1;
	lettre[2][3] = 0;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 0;
	lettre[3][2] = 1;
	lettre[3][3] = 0;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 1;
	lettre[4][3] = 1;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 1;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 0;
	lettre[6][4] = 1;

	return lettre;
}
char** LETTERS::creerM(){

	char** lettre;
	lettre = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettre[i] = new char[5];
	}
	lettre[0][0] = 1;
	lettre[0][1] = 0;
	lettre[0][2] = 0;
	lettre[0][3] = 0;
	lettre[0][4] = 1;

	lettre[1][0] = 1;
	lettre[1][1] = 1;
	lettre[1][2] = 0;
	lettre[1][3] = 1;
	lettre[1][4] = 1;

	lettre[2][0] = 1;
	lettre[2][1] = 1;
	lettre[2][2] = 1;
	lettre[2][3] = 1;
	lettre[2][4] = 1;

	lettre[3][0] = 1;
	lettre[3][1] = 0;
	lettre[3][2] = 1;
	lettre[3][3] = 0;
	lettre[3][4] = 1;

	lettre[4][0] = 1;
	lettre[4][1] = 0;
	lettre[4][2] = 0;
	lettre[4][3] = 0;
	lettre[4][4] = 1;

	lettre[5][0] = 1;
	lettre[5][1] = 0;
	lettre[5][2] = 0;
	lettre[5][3] = 0;
	lettre[5][4] = 1;

	lettre[6][0] = 1;
	lettre[6][1] = 0;
	lettre[6][2] = 0;
	lettre[6][3] = 0;
	lettre[6][4] = 1;

	return lettre;
}