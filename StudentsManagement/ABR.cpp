#include "ABR.hpp"
	/* 			Définition de la classe ABREtdiants			 */
	ABREtudiants::ABREtudiants(){
		hauteur=0;
	}
	ABREtudiants::ABREtudiants(int hauteur){
		this->hauteur=hauteur;
	}
	ABREtudiants::ABREtudiants(ABREtudiants &A){
		this->hauteur=A.hauteur;
	}
	int ABREtudiants::getHauteur(){
		return hauteur;
	}
	/* 				Définition de la classe FILE			 */
	/* 				Définition de la classe Etudiants			 */
	Etudiants::getMtr(){
		return mtr;
	}
	float Etudiants::getNote(int i){
		return notes[i];
	}
	/* 				Définition de la classe ListeEtudiants			 */

	
	
