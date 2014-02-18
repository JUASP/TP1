/**
 * \file SystemeExpert.h
 * \brief Classe d�finissant le syst�me expert.
 * \author Mondher Bouden
 * \version 0.1
 * \date f�vrier 2014
 *
 * Ce fichier contient l'interface d'un systeme expert permettant � partir 
 * de pr�misses de trouver des conclusions qui permettent finalement d'affirmer
 * ou d'infirmer des r�ponses.
 * Le syst�me expert emploie les d�finitions de l'ensemble de r�gles et de
 * l'ensemble de faits.
 * A partir d'une comparaison syst�matique des faits aux r�gles connues,
 * le syst�me peut d�duire des faits nouveaux.
*/

#ifndef _SYSTEMEEXPERT_H
#define _SYSTEMEEXPERT_H

#include "EnsembleFaits.h"
#include "Regle.h"
#include "ListeCirculaire.h"
#include "File.h"

/** 
 *  \namespace tp1
 *
 *  Espace de nommage regroupant les classes n�cessaires pour le TP1.
 */
namespace tp1
{

	/** 
	 *  \class SystemeExpert
	 *
	 *  \brief Classe repr�sentant un syst�me expert.
	 *
	 *  La classe g�re un syst�me expert � l'aide d'une file, d'une liste circulaire et d'un ensemble de faits.
	 */
	class SystemeExpert{

	  public:

		/**
		 *  \brief Constructeur par d�faut
		 *
		 *  \post Une instance de la classe SystemeExpert est initialis�e.
		 */
		SystemeExpert();

		/**
		 *  \brief Destructeur
		 *
		 *  \post L'instance de EnsembleFaits est d�truite.
		 */
		~SystemeExpert();

		/*!
		 *  \brief Constructeur de copie
		 *
		 *  \post Une copie profonde du syst�me expert source est utilis�e pour initialiser la nouvelle instance.
		 *
		 *  \exception bad_alloc s'il manque de m�moire.
		 */
		SystemeExpert(const SystemeExpert &);

		/**                       
		 *  \brief Surcharge de l'op�rateur = (effectue une copie profonde).
		 * 
		 *  \pre Les deux systemeExperts ont �t� d�clar�s.
		 *
		 *  \post SystemeExpert est une copie profonde du syst�me expert donn� en entr�e.
		 * 
		 *  \exception bad_alloc s'il manque de m�moire.
		 */
		SystemeExpert & operator = (const SystemeExpert &);

		/**                       
		 *  \brief Affiche le syst�me expert dans un flux de sortie.
		 *  \brief "Friend" pour permettre d'utiliser les donn�es priv�es pour faire son travail.
		 * 
		 *  \pre SystemeExpert est valide.
		 *
		 *  \post SystemeExpert est inchang�.
		 *
		 *  Ne pas toucher pas � cette m�thode !
		 */
		friend std::ostream & operator << (std::ostream & os, const SystemeExpert & se)
		{
			os << "Base de regles:" << std::endl << se.baseRegles;
			os << "Base de fait:" << std::endl << se.baseFaits;
			return os;
		}

		/**                       
		 *  \brief Permet d'ajouter une r�gle (d�j� cr��e et initialis�e) au syst�me expert.
		 * 
		 *  \pre La r�gle est cr��e et initialis�e.
		 *
		 *  \post La r�gle est ajout�e au syst�me expert.
		 * 
		 *  \exception bad_alloc s'il manque de m�moire.
		 */
		void ajouterRegleSE(const Regle &);

		/**                       
		 *  \brief Permet d'ajouter un fait (d�j� cr�� et initialis�) au syst�me expert
		 * 
		 *  \pre Le fait est cr�� et initialis�.
		 *
		 *  \post Le fait est ajout� au syst�me expert.
		 * 
		 *  \exception bad_alloc s'il manque de m�moire.
		 */
		void ajouterFaitSE(const TypeFait &);

		/**                       
		 *  \brief Permet de charger un syst�me expert � partir d'un fichier texte.
		 * 
		 *  \pre Le fichier a �t� ouvert � l'aide de la m�thode "open" pr�alablement � l'appel de la m�thode.
		 *  \pre Le fichier a le bon format.
		 *
		 *  \post Le syst�me expert est charg�.
		 *  \post Le fichier est encore ouvert.
		 * 
		 *  \exception logic_error si le fichier texte est vide.
		 *  \exception invalid_argument si le fichier texte n'est pas correctement ouvert.
		 *
		 *	Voici le format du fichier texte:
		 *
		 *	Regle_1_Premisse_1		|
		 *	Regle_1_Premisse_2		|
		 *	...						|
		 *	Regle_1_Premisse_N		| PREMI�RE
		 *	!>						| R�GLE
		 *	Regle_1_Conclusion_1	|
		 *	Regle_1_Conclusion_2	|
		 *	...						|
		 *	Regle_1_Conclusion_N	|
		 *	!%
		 *	Regle_2_Premisse_1		|
		 *	...						|
		 *	Regle_2_Premisse_N		| DEUXI�ME
		 *	!>						| R�GLE
		 *	Regle_2_Conclusion_1	|
		 *	...						|
		 *	Regle_2_Conclusion_N	|
		 *	!%
		 *	...						   ...
		 *	!%
		 *	Regle_N_Premisse_1		|
		 *	...						|
		 *	Regle_N_Premisse_N		| N i�me
		 *	!>						| R�GLE
		 *	Regle_N_Conclusion_1	|
		 *	...						|
		 *	Regle_N_Conclusion_N	|
		 *	!!
		 *	Fait_1					|
		 *	Fait_2					| BASE DE
		 *	...						| FAITS
		 *	Fait_3					|
		*/
		void chargerSE(std::ifstream &);

		/**                       
		 *  \brief Permet de sauvegarder le syst�me expert dans un fichier texte.
		 * 
		 *  \pre Le fichier a �t� ouvert � l'aide de la m�thode "open" pr�alablement � l'appel de la m�thode.
		 *
		 *  \post Le syst�me expert est charg�.
		 *  \post Le fichier est encore ouvert.
		 *  \post Le fichier a le bon format.
		 *  \post Le nombre de faits �tablis dans le syst�me expert est retourn�.
		 *
		 *  \exception logic_error si le syst�me expert est vide.
		 *  \exception invalid_argument si le fichier texte n'est pas correctement ouvert.
		 */
		int sauvegarderSE(std::ofstream &) const;

		/**                       
		 *  \brief Permet de saturer la base de faits du syst�me expert en retrouvant les faits 
		 *  \brief qui peuvent �tre d�duits de la base de faits du syst�me et en se basant sur
		 *  \brief les r�gles de celui-ci.
		 *
		 *  \pre Le syst�me expert contient des faits et des r�gles.
		 *
		 *  \post Une liste circulaire contenant les r�gles qui ont permis de d�terminer de nouveaux faits est retourn�e.
		 *  \post La base des nouveaux faits est modifi�e.
		 *
		 *  \exception logic_error si la base de faits est vide.
		 *  \exception logic_error si la base de r�gles est vide.
		 */
		ListeCirculaire<Regle> chainageAvant();

		/**                       
		 *  \brief M�thode r�cursive qui permet de d�montrer la v�racit� d'une hypoth�se donn�e
		 *  \brief en se basant sur les faits et les r�gles du syst�me expert. 
		 *
		 *  \pre Le syst�me expert contient des faits et des r�gles.
		 *
		 *  \post Si l'hypoth�se est fausse, FAUX est retourn�e dans le bool�en.
		 *  \post Si l'hypoth�se est d�montr�e, VRAI est retourn�e dans le bool�en.
		 *  \post Si l'hypoth�se est d�montr�e, une liste circulaire contenant les r�gles qui ont permis de d�terminer de nouveaux faits est retourn�e.
		 *  \post Si l'hypoth�se est d�montr�e, la base des nouveaux faits est modifi�e.
		 *
		 *  \exception logic_error si la base de faits est vide.
		 *  \exception logic_error si la base de r�gles est vide.
		 */
		ListeCirculaire<Regle> chainageArriere (const TypeFait &, bool &);

		/**                       
		 *  \brief Accesseur pour la base de r�gles.
		 */
		ListeCirculaire<Regle> * getBaseRegles () {return &baseRegles;}

		/**                       
		 *  \brief Accesseur pour la base de faits.
		 */
		EnsembleFaits * getBaseFaits () {return &baseFaits;}

		/**                       
		 *  \brief Accesseur pour la base de nouveaux faits.
		 */
		File<TypeFait> * getBaseNouveauxFaits () {return &baseNouveauxFaits;}



	  private:

		ListeCirculaire<Regle> baseRegles;		//Contient toutes les r�gles connues du syst�me expert
		EnsembleFaits baseFaits;				//Contient tous les faits connus du syst�me expert
		File<TypeFait> baseNouveauxFaits;		//Contient uniquement les nouveaux faits d�duits en saturant le syst�me expert

	   //Ajouter ici des fonctions utilitaires si n�cessaire.

	};

}

#endif
