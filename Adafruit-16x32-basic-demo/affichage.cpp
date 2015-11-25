#include "affichage.h"

char **etatJeu;
char **lettresHaut;
char **lettresBas;
char *couleursLettresHaut;
char *couleursLettresBas;
LETTERS letters;
MATRICE *matrice;
char alternateurMot = 0;
char alternateurJeu = 0;
char choixAffichage = 0;
char state = 0;

AFFICHAGE::AFFICHAGE(MATRICE *matr){
	matrice = matr;
	letters.Init();

	etatJeu = new char*[8];
	for(int i = 0; i < 8; ++i){
		etatJeu[i] = new char[32];
		for(int j = 0; j < 32; ++j){
			etatJeu[i][j] = 0;
		}
	}

	lettresHaut = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettresHaut[i] = new char[32];
		for(int j = 0; j < 32; ++j){
			lettresHaut[i][j] = 0;
		}
	}
	

	lettresBas = new char*[7];
	for(int i = 0; i < 7; ++i){
		lettresBas[i] = new char[32];
		for(int j = 0; j < 32; ++j){
			lettresBas[i][j] = 0;
		}
	}

	couleursLettresHaut = new char[5];
	couleursLettresBas = new char[5];
	for(int i = 0; i < 5; ++i){
		couleursLettresHaut[i] = 0;
		couleursLettresBas[i] = 0;
	}
}


void AFFICHAGE::majMatrice(char* lettres){
	if (lettres[1] == '1'){
		majLettresHaut(lettres);
	} else if (lettres[1] == '2'){
		majLettresBas(lettres);
	} else if (lettres[1] == '3'){
		majJeu(lettres);
	} else if (lettres[1] == '4'){
		state = 0; // lettres
	} else if (lettres[1] == '5'){
		state = 1; //jeu
	}
}

void AFFICHAGE::majLettresHaut(char* lettres){
	for(int i = 0; i < 5; ++i){
		//Trouver la matrice 7x5 representant la lettre
		char** lettre = trouverLettre(lettres[i + 2]);

		//trouver les couleurs de chaque lettre
		couleursLettresHaut[i] = lettres[i + 7];
		
		//placer les pixels allumes pour chaque lettre dans la matrice.
		for(int j = 0; j < 7; ++j){
			for(int k = 0; k < 5; ++k){
				lettresHaut[j][k + i * 6] = lettre[j][k];
			}
		}
	}
}

void AFFICHAGE::majLettresBas(char *lettres){
	for(int i = 0; i < 5; ++i){
		//Trouver la matrice 7x5 representant la lettre
		char** lettre = trouverLettre(lettres[i + 2]);

		//trouver les couleurs de chaque lettre
		couleursLettresBas[i] = lettres[i + 7];
		
		//placer les pixels allumes pour chaque lettre dans la matrice.
		for(int j = 0; j < 7; ++j){
			for(int k = 0; k < 5; ++k){
				lettresBas[j][k + i * 6] = lettre[j][k];
			}
		}
	}
}

void AFFICHAGE::majJeu(char* lettres){
	char numero = lettres[2];

	etatJeu[4][(numero - 1) * 3] = lettres[3];
	etatJeu[5][(numero - 1) * 3] = lettres[4];
	etatJeu[6][(numero - 1) * 3] = lettres[5];
	etatJeu[7][(numero - 1) * 3] = lettres[6];

	etatJeu[1][(numero - 1) * 3] = lettres[7];
	etatJeu[2][(numero - 1) * 3] = lettres[8];
	etatJeu[1][(numero - 1) * 3 + 1] = lettres[9];
	etatJeu[2][(numero - 1) * 3 + 1] = lettres[10];

}

//yPosition: 1 pour haut, 2 pour bas
void AFFICHAGE::rafraichirMatrice(){
	alterner();
	char couleurs1[5];
	char couleurs2[5];

	//determine els couleurs a allumer pour ce rafraichissement
	for(int i = 0; i < 5; ++i){
		couleurs1[i] = transformerCouleur(couleursLettresHaut[i]);
		if (state == 0){
			couleurs2[i] = transformerCouleur(couleursLettresBas[i]);
		}
		
	}

	for(int i = 0; i < 7; ++i){
		for(int j = 0; j < 30; ++j){
			matrice->Pset(j, i, couleurs1[j / 6] * (lettresHaut[i][j]));
			if (state == 0){
				matrice->Pset(j, i + 9, couleurs2[j / 6] * (lettresBas[i][j]));
			}
		}
	}
	if (state == 1){
		rafraichirJeu();
	}
}

//Pour les couleurs speciales, permet d'allumer les couleurs puissantes 1 fois sur 3
void AFFICHAGE::alterner(){
	alternateurMot = (alternateurMot + 1) % 2;
	alternateurJeu = (alternateurJeu + 1) % 3;
}

void AFFICHAGE::rafraichirJeu(){
	char couleur;
	if(alternateurJeu == 0){
		couleur = 1;
	} else if (alternateurJeu == 1){
		couleur = 2;
	} else {
		couleur = 4;
	}

	for(int i = 0; i < 8; ++i){
		for(int j = 0; j < 32; ++j){
			if ((etatJeu[i][j] & couleur) == couleur){
				matrice->Pset(j, i + 8, couleur * 1);
			} else {
				matrice->Pset(j, i + 8, couleur * 0);
			}
		}
	}
}


char AFFICHAGE::transformerCouleur(char couleurOriginale){
	char couleur = 0;;
	if (alternateurMot == 0){
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
		case ' ':
		return letters.creerEspace();

		case 'a':
		return letters.creerA();
		case 'b':
		return letters.creerB();
		case 'c':
		return letters.creerC();
		case 'd':
		return letters.creerD();
		case 'e':
		return letters.creerE();
		case 'f':
		return letters.creerF();
		case 'g':
		return letters.creerG();
		case 'h':
		return letters.creerH();
		case 'i':
		return letters.creerI();
		case 'j':
		return letters.creerJ();
		case 'k':
		return letters.creerK();
		case 'l':
		return letters.creerL();
		case 'm':
		return letters.creerM();
		case 'n':
		return letters.creerN();
		case 'o':
		return letters.creerO();
		case 'p':
		return letters.creerP();
		case 'q':
		return letters.creerQ();
		case 'r':
		return letters.creerR();
		case 's':
		return letters.creerS();
		case 't':
		return letters.creerT();
		case 'u':
		return letters.creerU();
		case 'v':
		return letters.creerV();
		case 'w':
		return letters.creerW();
		case 'x':
		return letters.creerX();
		case 'y':
		return letters.creerY();
		case 'z':
		return letters.creerZ();

		case '\0':
		return letters.creerEspace();
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

/*char AFFICHAGE::trouverCouleur(char couleur){
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
	return NOIR;
}*/