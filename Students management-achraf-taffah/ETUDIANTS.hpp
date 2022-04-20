	#ifndef _ETUDIANTS_
	#define _ETUDIANTS_
	#include<string.h>
    using namespace std;
	class Etudiants{
			public:
//				string getNom();
				int getMtr();
				float getNote(int i);
				bool Comparer(Etudiants e,Etudiants e2);
				void setNote(float valeur,int i);
//				string toString();
				float getMoy();
				float CalculMoy();
				Etudiants(string &nom,float notes[]);
				Etudiants(Etudiants &);
				~Etudiants();
			private:
				int mtr;
				int mtrCourant;
				string nom;
				float notes[];
	};
	int Etudiants::getMtr(){
		return mtr;
	}
	float Etudiants::getNote(int i){
		assert(i>=0 && i<8);
		return notes[i];
	}
	float Etudiants::getMoy(){
		float sum;
		for(int k=0;k<8;k++)
			sum=sum+notes[k];
		return (float)(sum/8);
	}
	bool Etudiants::Comparer(Etudiants e,Etudiants e2){
		if(e.getNom()==e2.getNom()){
			if(e.getMtr()==e2.getMtr()){
				if(e.getMoy()==e2.getMoy()){
					int i=0;
					for(i;i<8;i++){
						if(e.getNote(i)!=e2.getNote(i)){
							return false;
						}
					}
					return true;
				}
			}
		}
		return false;
	}
	void Etudiants::setNotes(float valeure,int i){
		assert(i>=0 && i<8);
		notes[i]=valaure;
	}
	string toString(){
		string st="Matricule : "+mtr+"\n Nom : "+mtr+"\n Moyenne : "+moy+"\n Notes : ";
		for(i=0;i<8;i++)
			st=st+"N1 : "+notes[i]+"\n";
		return st;
	}
	Etudiants::Etudiants(){
		mtr=mtrCourant++;
		nom=" ";
		for(i=0;i<8;i++)
			notes[i]=0;
	}
	Etudiants::Etudiants( string nom,float notes[]){
		mtr=mtrCourant++;
		this->nom=nom;
		for(int i=0;i<8;i++)
			this->notes[i]=notes[i];
	}
	Etudiants::Etudiants(Etudiants &e){
		mtr=mtrCourant++;
		this->nom=e->nom;
		for(int i=0;i<8;i++)
			notes[i]=e->notes[i];
	}
	Etudiants::~Etudiants(){
		cout << "\n\t...Destruction...\n";
	}
	#endif
