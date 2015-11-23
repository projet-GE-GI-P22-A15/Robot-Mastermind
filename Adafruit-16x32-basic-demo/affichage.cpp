#include "affichage.h"

char **etatJeu;
char **lettresHaut;
char **lettresBas;
char* couleursLettresHaut;
char* couleurLettresBas;
LETTERS letters;
MATRICE *matrice;
int alternateur = 0;


void AFFICHAGE::Init(MATRICE* matr){
	matrice = matr;
	letters.Init();

	int hauteur = 8;
	int largeur = 32;

	etatJeu = new char*[10];
	for(int i = 0; i < 10; ++i){
		etatJeu[i] = new char[8];

	}

	lettresHaut = new char*[hauteur];
	for(int i = 0; i < hauteur; ++i){
		lettresHaut[i] = new char[largeur];
		
	}
	for(int j = 0; j < largeur; ++j){
			lettresHaut[7][j] = 0;
		}

	lettresBas = new char*[hauteur];
	for(int i = 0; i < hauteur; ++i){
		lettresBas[i] = new char[largeur];
	}
	for(int j = 0; j < largeur; ++j){
			lettresHaut[7][j] = 0;
		}

	couleursLettresHaut = new char[5];
	couleursLettresBas = new char[5];	
}

void AFFICHAGE::majTableauMot(char lettres[]){
	int hauteur = 8;
	int largeur = 32;

	for(int i = 0; i < 5; ++i){
		char** lettre = trouverLettre(lettres[i + 2]);
		if (lettres[1] == '1'){
			lettresHaut[7][j + (i-7) * 6] = trouverCouleur(lettres[i]);
		} else if (lettres[1] == '2'){
			lettresBas[j][k + (i) * 6] = lettre[j][k];
		}
		
		
		for(int j = 0; j < hauteur - 1; ++j){
			for(int k = 0; k < 5; ++k){
				if (lettres[1] == '1'){
					lettresHaut[j][k + (i) * 6] = lettre[j][k];
				} else if (lettres[1] == '2'){
					lettresBas[j][k + (i) * 6] = lettre[j][k];
				}
			}
		}
	}

	for(int i = 7; i < 12; ++i){
		for(int j = 0; j < 5; ++j){
			if (lettres[1] == '1'){
				
			} else if (lettres[1] == '2'){
				lettresBas[7][j + (i-7) * 6] = trouverCouleur(lettres[i]);
			}
		}
	}
}

void AFFICHAGE::afficherMot(int yPosition){
	alterner();
	int hauteur = 8;
	int largeur = 32;
	char couleurs[32];

	for(int i = 0; i < largeur; ++i){
		if (yPosition == 1){
			couleurs[i] = transformerCouleur(lettresHaut[7][i]);
		} else if (yPosition == 2){
			couleurs[i] = transformerCouleur(lettresBas[7][i]);
		}
	}


	for(int i = 0; i < hauteur - 1; ++i){
		for(int j = 0; j < largeur; ++j){
			if (yPosition == 1){
				matrice->Pset(j, i, couleurs[j] * (lettresHaut[i][j]));
			} else if (yPosition == 2){
				matrice->Pset(j, i + hauteur, couleurs[j] * (lettresBas[i][j]));
			}
		}
	}
}

void AFFICHAGE::alterner(){
	alternateur = (alternateur + 1) % 3;
}


char AFFICHAGE::transformerCouleur(char couleurOriginale){
	char couleur = 0;;
	if (alternateur == 0){
		couleur = couleur | (couleurOriginale & 1);
		couleur = couleur | (couleurOriginale & 2);
		couleur = couleur | (couleurOriginale & 4);
		couleur = couleur << 3;
	}
	couleur = couleur | (couleurOriginale & 8);
	couleur = couleur | (couleurOriginale & 16);
	couleur = couleur | (couleurOriginale & 32);
	couleur = couleur >> 3;

	return couleur;
}

char AFFICHAGE::trouverCouleur(char couleur){
	switch (couleur){
		case 'a':
		return INDIGO;
		case 'b':
		return BLEU;
		case 'c':
		return FORET;
		case 'd':
		return TURQUOISE;
		case 'e':
		return CIEL;
		case 'f':
		return VERT;
		case 'g':
		return CORAIL;
		case 'h':
		return CYAN;
		case 'i':
		return BOURGOGNE;
		case 'j':
		return POURPRE;
		case 'k':
		return MAUVE;
		case 'l':
		return VOMIT;
		case 'm':
		return GRIS;
		case 'n':
		return ACIER;
		case 'o':
		return FLUO;
		case 'p':
		return HOPITAL;
		case 'q':
		return POUDRE;
		case 'r':
		return ROUGE;
		case 's':
		return ROSE;
		case 't':
		return MAGENTA;
		case 'u':
		return ORANGE;
		case 'v':
		return CHAIR;
		case 'w':
		return GOMME;
		case 'x':
		return JAUNE;
		case 'y':
		return CREME;
		case 'z':
		return 	BLANC;
	}
}

char** AFFICHAGE::trouverLettre(char lettre){
	switch(lettre){
		case 'A':
		return letters.creerA();
		case 'B':
		return letters.creerB();
		case 'C':
		return letters.creerC();
		case 'D':
		return letters.creerD();
		case 'E':
		return letters.creerE();
		case 'F':
		return letters.creerF();
		case 'G':
		return letters.creerG();
		case 'H':
		return letters.creerH();
		case 'I':
		return letters.creerI();
		case 'J':
		return letters.creerJ();
		case 'K':
		return letters.creerK();
		case 'L':
		return letters.creerL();
		case 'M':
		return letters.creerM();
		case 'N':
		return letters.creerN();
		case 'O':
		return letters.creerO();
		case 'P':
		return letters.creerP();
		case 'Q':
		return letters.creerQ();
		case 'R':
		return letters.creerR();
		case 'S':
		return letters.creerS();
		case 'T':
		return letters.creerT();
		case 'U':
		return letters.creerU();
		case 'V':
		return letters.creerV();
		case 'W':
		return letters.creerW();
		case 'X':
		return letters.creerX();
		case 'Y':
		return letters.creerY();
		case 'Z':
		return letters.creerZ();

		case '0':
		return letters.creer0();
		case '1':
		return letters.creer1();
		case '2':
		return letters.creer2();
		case '3':
		return letters.creer3();
		case '4':
		return letters.creer4();
		case '5':
		return letters.creer5();
		case '6':
		return letters.creer6();
		case '7':
		return letters.creer7();
		case '8':
		return letters.creer8();
		case '9':
		return letters.creer9();
	}
	return 0;
}

char** AFFICHAGE::getEtatJeu(){
	return etatJeu;
}

char** AFFICHAGE::getLettresHaut(){
	return lettresHaut;
}

char** AFFICHAGE::getLettresBas(){
	return lettresBas;
}