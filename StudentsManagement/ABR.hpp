#ifndef _ABR_
	#define _ABR_
		#include<iostream>
		#include<string.h>
		#include<conio.h>
		using namespace std;
		class ABREtudiants{
			private:
				int hauteur;
			public:
				ABREtudiants();
				ABREtudiants(int);
				ABREtudiants(ABREtudiants &);
				int getHauteur();
				void Ajouter(ABREtudiants);
				void Supprimer(int mtr);
				void Rechercher(ABREtudiants);
				void AfficherCroissant();
				void AfficherDecroissant();
				void AfficherLargeur();
				int NbreNoeds();
				int NbreFeuilles();
				int CalculerHauteur();	
		};
		
		class File{
			private:
				int Tete;
				int queue;
				int taille;
			public:
				void enfilerABREtudiantsA();
				void defiler();
				bool estVide();
				bool estPleine();
				File(int taille);
		};
		
		class Etudiants{
			private:
				int mtr;
				int mtrCourant;
				string nom;
				float notes[];
				float moy;
			public:
				int getMtr();
				float getNote(int i);
				bool Comparer(Etudiants e,int type);
				void setNote(float valeur,int i);
				string toString();
				float getMoy();
				float CalculMoy();
				Etudiants(string nom,float notes[]);
				Etudiants(Etudiants &);
		};
		
		class ListeEtudiants{
			private:
				int tailleMax;
				int taille;
			public:
				void inserer();
				void Supprimer(int mtr);
				void Rechercher(int mtr);
				void Afficher();
		};
	#endif

