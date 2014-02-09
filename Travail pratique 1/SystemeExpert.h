/**
 * \file SystemeExpert.h
 * \brief Classe définissant le système expert.
 * \author Mondher Bouden
 * \version 0.1
 * \date février 2014
 *
 * Ce fichier contient l'interface d'un systeme expert permettant à partir 
 * de prémisses de trouver des conclusions qui permettent finalement d'affirmer
 * ou d'infirmer des réponses.
 * Le système expert emploie les définitions de l'ensemble de règles et de
 * l'ensemble de faits.
 * A partir d'une comparaison systématique des faits aux règles connues,
 * le système peut déduire des faits nouveaux.
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
 *  Espace de nommage regroupant les classes nécessaires pour le TP1.
 */
namespace tp1
{

	/** 
	 *  \class SystemeExpert
	 *
	 *  \brief Classe représentant un système expert.
	 *
	 *  La classe gère un système expert à l'aide d'une file, d'une liste circulaire et d'un ensemble de faits.
	 */
	class SystemeExpert{

	  public:

		/**
		 *  \brief Constructeur par défaut
		 *
		 *  \post Une instance de la classe SystemeExpert est initialisée.
		 */
		SystemeExpert();

		/**
		 *  \brief Destructeur
		 *
		 *  \post L'instance de EnsembleFaits est détruite.
		 */
		~SystemeExpert();

		/*!
		 *  \brief Constructeur de copie
		 *
		 *  \post Une copie profonde du système expert source est utilisée pour initialiser la nouvelle instance.
		 *
		 *  \exception bad_alloc s'il manque de mémoire.
		 */
		SystemeExpert(const SystemeExpert &);

		/**                       
		 *  \brief Surcharge de l'opérateur = (effectue une copie profonde).
		 * 
		 *  \pre Les deux systemeExperts ont été déclarés.
		 *
		 *  \post SystemeExpert est une copie profonde du système expert donné en entrée.
		 * 
		 *  \exception bad_alloc s'il manque de mémoire.
		 */
		SystemeExpert & operator = (const SystemeExpert &);

		/**                       
		 *  \brief Affiche le système expert dans un flux de sortie.
		 *  \brief "Friend" pour permettre d'utiliser les données privées pour faire son travail.
		 * 
		 *  \pre SystemeExpert est valide.
		 *
		 *  \post SystemeExpert est inchangé.
		 *
		 *  Ne pas toucher pas à cette méthode !
		 */
		friend std::ostream & operator << (std::ostream & os, const SystemeExpert & se)
		{
			os << "Base de regles:" << std::endl << se.baseRegles;
			os << "Base de fait:" << std::endl << se.baseFaits;
			return os;
		}

		/**                       
		 *  \brief Permet d'ajouter une règle (déjà créée et initialisée) au système expert.
		 * 
		 *  \pre La règle est créée et initialisée.
		 *
		 *  \post La règle est ajoutée au système expert.
		 * 
		 *  \exception bad_alloc s'il manque de mémoire.
		 */
		void ajouterRegleSE(const Regle &);

		/**                       
		 *  \brief Permet d'ajouter un fait (déjà créé et initialisé) au système expert
		 * 
		 *  \pre Le fait est créé et initialisé.
		 *
		 *  \post Le fait est ajouté au système expert.
		 * 
		 *  \exception bad_alloc s'il manque de mémoire.
		 */
		void ajouterFaitSE(const TypeFait &);

		/**                       
		 *  \brief Permet de charger un système expert à partir d'un fichier texte.
		 * 
		 *  \pre Le fichier a été ouvert à l'aide de la méthode "open" préalablement à l'appel de la méthode.
		 *  \pre Le fichier a le bon format.
		 *
		 *  \post Le système expert est chargé.
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
		 *	Regle_1_Premisse_N		| PREMIÈRE
		 *	!>						| RÈGLE
		 *	Regle_1_Conclusion_1	|
		 *	Regle_1_Conclusion_2	|
		 *	...						|
		 *	Regle_1_Conclusion_N	|
		 *	!%
		 *	Regle_2_Premisse_1		|
		 *	...						|
		 *	Regle_2_Premisse_N		| DEUXIÈME
		 *	!>						| RÈGLE
		 *	Regle_2_Conclusion_1	|
		 *	...						|
		 *	Regle_2_Conclusion_N	|
		 *	!%
		 *	...						   ...
		 *	!%
		 *	Regle_N_Premisse_1		|
		 *	...						|
		 *	Regle_N_Premisse_N		| N ième
		 *	!>						| RÈGLE
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
		 *  \brief Permet de sauvegarder le système expert dans un fichier texte.
		 * 
		 *  \pre Le fichier a été ouvert à l'aide de la méthode "open" préalablement à l'appel de la méthode.
		 *
		 *  \post Le système expert est chargé.
		 *  \post Le fichier est encore ouvert.
		 *  \post Le fichier a le bon format.
		 *  \post Le nombre de faits établis dans le système expert est retourné.
		 *
		 *  \exception logic_error si le système expert est vide.
		 *  \exception invalid_argument si le fichier texte n'est pas correctement ouvert.
		 */
		int sauvegarderSE(std::ofstream &) const;

		/**                       
		 *  \brief Permet de saturer la base de faits du système expert en retrouvant les faits 
		 *  \brief qui peuvent être déduits de la base de faits du système et en se basant sur
		 *  \brief les règles de celui-ci.
		 *
		 *  \pre Le système expert contient des faits et des règles.
		 *
		 *  \post Une liste circulaire contenant les règles qui ont permis de déterminer de nouveaux faits est retournée.
		 *  \post La base des nouveaux faits est modifiée.
		 *
		 *  \exception logic_error si la base de faits est vide.
		 *  \exception logic_error si la base de règles est vide.
		 */
		ListeCirculaire<Regle> chainageAvant();

		/**                       
		 *  \brief Méthode récursive qui permet de démontrer la véracité d'une hypothèse donnée
		 *  \brief en se basant sur les faits et les règles du système expert. 
		 *
		 *  \pre Le système expert contient des faits et des règles.
		 *
		 *  \post Si l'hypothèse est fausse, FAUX est retournée dans le booléen.
		 *  \post Si l'hypothèse est démontrée, VRAI est retournée dans le booléen.
		 *  \post Si l'hypothèse est démontrée, une liste circulaire contenant les règles qui ont permis de déterminer de nouveaux faits est retournée.
		 *  \post Si l'hypothèse est démontrée, la base des nouveaux faits est modifiée.
		 *
		 *  \exception logic_error si la base de faits est vide.
		 *  \exception logic_error si la base de règles est vide.
		 */
		ListeCirculaire<Regle> chainageArriere (const TypeFait &, bool &);

		/**                       
		 *  \brief Accesseur pour la base de règles.
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

		ListeCirculaire<Regle> baseRegles;		//Contient toutes les règles connues du système expert
		EnsembleFaits baseFaits;				//Contient tous les faits connus du système expert
		File<TypeFait> baseNouveauxFaits;		//Contient uniquement les nouveaux faits déduits en saturant le système expert

	   //Ajouter ici des fonctions utilitaires si nécessaire.

	};

}

#endif
