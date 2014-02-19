/**
 * \file Principal.cpp
 * \brief Ce fichier contient un main permettant de tester le syst�me expert 
 * \brief en utilisant un menu contenant des choix propos�s � l'utilisateur.
 * \author Mondher Bouden
 * \version 0.1
 * \date f�vrier 2014
 * 
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "SystemeExpert.h"

/**
 *  \fn int main (void)
 *  \brief Fonction principale.
 *
 *  Un main() pour utiliser le syst�me expert.
 *  \return 0 - Arr�t normal du programme.
 */

int main()
{
	int nb = 1;					//Choix de l'utilisateur dans le menu initialis� � 1.
	tp1::SystemeExpert se1;		//Le syst�me expert utilis� pour les les tests de base.
	tp1::SystemeExpert se2;		//Le syst�me expert utilis� principalement pour le cha�nage avant.
	tp1::SystemeExpert se3;		//Le syst�me expert utilis� principalement pour le cha�nage arri�re.
	tp1::Regle re;				//Une r�gle pour envoyer � ajouterRegleSE.
	tp1::TypeFait fait;			//Un fait pour envoyer � ajouterEnsFaits.
	ifstream EntreeFichier1, EntreeFichier2;	//Flux d'entr�e
	ofstream SortieFichier1, SortieFichier2;	//Flux de sortie
	tp1::ListeCirculaire<tp1::Regle> er;	//Une liste de r�gle pour le retour des cha�nages (avant et arri�re).
	//bool test = false;	// Pour tester la v�racit� d'une hypoth�se par cha�nage arri�re

	//Affichage du menu
	cout << "------------------ Menu --------------------------------" << endl;
	cout << "1 - Ajouter une regle au systeme expert." << endl;
	cout << "2 - Ajouter un fait a analyser au systeme expert." << endl;
	cout << "3 - Supprimer une regle du systeme expert." << endl;
	cout << "4 - Supprimer un fait du systeme expert." << endl;
	cout << "5 - Charger un systeme expert depuis un fichier texte." << endl;
	cout << "6 - Tirer des conclusions a partir de la base de faits." << endl;
	cout << "7 - Verifier une hypothese a partir de la base de regles." << endl;
	cout << "8 - Ecrire la base de faits dans un fichier texte" << endl;
	cout << "9 - Copier un systeme expert dans un autre" << endl;
	cout << "10- Sauvegarder un systeme expert dans un fichier texte" << endl;
	cout << "0 - Quitter." << endl;
	cout << "--------------------------------------------------------" << endl;

	while (nb != 0)
	{
		do
		{
			cout << endl;
			cout << "Entrer s.v.p. votre choix (0 a 10):? ";
			cin >> nb;
			if(nb <0 || nb>10)
			{
				cout << "***Option invalide!***\n";
			}
		}while(nb <0 || nb>10);

		try
		{
			switch (nb) 
			{
				case 1:
					//Ajouter une r�gle au systeme expert.
					re.GetPremisses()->ajouterEnsFaits("a des poils",1);
					re.GetConclusions()->ajouterEnsFaits("est un mammifere",1);
					se1.ajouterRegleSE(re);
					cout << "La regle suivante a ete ajoutee:" << endl; 
					cout << "Si Animal <<a des poils>>, alors Animal <<est un mammifere>>" << endl;
					cout << "Nombre de premisses de cette regle: " << re.GetPremisses()->cardinaliteEnsFaits() << endl;;
					cout << "Nombre de conclusions de cette regle: " << re.GetConclusions()->cardinaliteEnsFaits() << endl;
					cout << "Affichage du systeme expert:" << endl << se1 << endl;
					break;

				case 2:
					//Ajouter un fait � analyser au systeme expert.
					fait = "a des poils";
					se1.ajouterFaitSE(fait);
					cout <<"Le fait suivant a ete ajoute: " << fait << endl;
					cout << "Nombre de faits dans la base de faits: " << se1.getBaseFaits()->cardinaliteEnsFaits() << endl;
					cout << "Affichage du systeme expert:" << endl << se1 << endl;
					break;

				case 3:
					//Supprimer une regle du systeme expert.
					se1.getBaseRegles()->enleverPos(1);
					cout << "La regle suivante a ete supprimee:" << endl; 
					cout << "Si Animal <<a des poils>>, alors Animal <<est un mammifere>>" << endl;
					cout << "Affichage du systeme expert:" << endl << se1 << endl;
					break;

				case 4:
					//Supprimer un fait du systeme expert.
					se1.getBaseFaits()->enleverEl(fait);
					cout <<"Le fait suivant a ete supprime: " << fait << endl;
					cout << "Affichage du systeme expert:" << endl << se1 << endl;
					break;

				case 5:
					//Charger un systeme expert depuis un fichier texte.
					EntreeFichier1.open("Animaux.txt", ios::in);
					if(EntreeFichier1.is_open())
					{
						se2.chargerSE(EntreeFichier1);
						cout << "Le systeme expert a ete charge, voici son contenu:" << endl << se2 << endl;
						cout << "Nombre de regles dans la base de regles: " << se2.getBaseRegles()->taille() << endl;
						cout << "Nombre de faits dans la base de faits: " << se2.getBaseFaits()->cardinaliteEnsFaits() << endl;
					}
					else
						cout << "ERREUR: Fichier introuvable!" << endl;
					EntreeFichier1.close();
					
					break;

				case 6:
					//Tirer des conclusions a partir de la base de faits.
					er= se2.chainageAvant();
					cout << "Le systeme expert a ete sature, voici son contenu:" << endl << se2 << endl;
					cout << "Voici la liste des regles utilises: " << endl << er << endl;
					cout << "Voici la liste des faits ajoutes: " << endl << *(se2.getBaseNouveauxFaits()) << endl;
					cout << "Nombre de regles utilises: " << er.taille() << endl;
					cout << "Nombre de faits ajoutes: " << se2.getBaseNouveauxFaits()->taille() << endl;

					break;

				/*case 7:
					//Verifier une hypothese a partir de la base de regles.

					//Commencer par charger un systeme expert depuis un fichier texte.
					EntreeFichier2.open("Pingouin.txt", ios::in);
					if(EntreeFichier2.is_open())
					{
						se3.chargerSE(EntreeFichier2);
						er = se3.chainageArriere("est un pingouin", test);
						if (test == true)
						{
							cout << "L'hypothese (est un pingouin) est vraie" << endl;
							cout << "En voici la preuve:" << endl << er << endl;
						}
						else
							cout << "L'hypothese (est un pingouin) n'est pas vraie" << endl;
					}
					else
						cout << "ERREUR: Fichier introuvable!" << endl;
					EntreeFichier2.close();

					break;*/

				case 8:
					//Ecrire la base de faits dans un fichier texte.
					SortieFichier1.open("BaseFaits.txt", ios::out);
					if(SortieFichier1.is_open())
					{
						se2.getBaseFaits()->ecrireEnsFaits(SortieFichier1);
						cout << "La base de faits a ete ecrite dans le fichier: BaseFaits.txt" << endl;
					}
					else
						cout << "ERREUR: Probleme d'ouverture du fichier!" << endl;
					SortieFichier1.close();

					break;

				case 9:
					//Copier un systeme expert dans un autre.
					cout << "Affichage du systeme expert avant la copie:" << endl << se1 << endl;
					cout << "Nombre de faits dans la base de nouveaux faits: " << se1.getBaseNouveauxFaits()->taille() << endl;
					se1 = se2;
					cout << "Affichage du systeme expert apres la copie:" << endl << se1 << endl;
					cout << "Nombre de faits dans la base de nouveaux faits: " << se1.getBaseNouveauxFaits()->taille() << endl;		

					break;

				case 10:
					//Sauvegarder le systeme expert dans un fichier texte.
					SortieFichier2.open("SystemeExpert.txt", ios::out);
					if(SortieFichier2.is_open())
					{
						se1.sauvegarderSE(SortieFichier2);
						cout << "Le systeme expert a ete sauvegarde dans le fichier: SystemeExpert.txt" << endl;
					}
					else
						cout << "ERREUR: Probleme d'ouverture du fichier!" << endl;
					SortieFichier2.close();			

					break;
			}
		}
		catch(const exception & e)
		{
			//On rattrape les exceptions standards de tous types
			cerr << "ERREUR: " << e.what() << endl;
		}
		catch(...)
		{
			cerr << "Probl�me grave non identifiable!" << endl;
		}
	}

	cout << "***Merci et au revoir !***" << endl;

	return 0;
}
