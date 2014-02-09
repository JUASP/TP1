/**
*  \file EnsembleFaits.h
*  \brief Classe définissant un ensemble de faits.
*  \author Mondher Bouden
*  \version 0.1
*  \date Février 2014
*
*  Cette classe définit un ensemble de faits.
*  Cet ensemble est implémenté avec une liste doublement chaînée.
*  Chaque fait est une chaîne de caractères.
*/

#ifndef _ENSEMBLEFAITS_H
#define _ENSEMBLEFAITS_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

/** 
*  \namespace tp1
*
*  Espace de nommage regroupant les classes nécessaires pour le TP1.
*/
namespace tp1
{
	/*! 
	*  \typedef typedef string TypeFait
	*  \brief TypeFait définit le type d'un fait. 
	*
	*  Le type 'TypeFait' est utilisé pour définir un fait. Ce type contient simplement une chaîne de caractères.
	*/
	typedef std::string TypeFait;

	/** 
	*  \class EnsembleFaits
	*
	*  \brief Classe représentant un ensemble de faits.
	*
	*  La classe gère un ensemble de faits à l'aide d'une liste doublement chaînée.
	*/
	class EnsembleFaits{

	public:

		/**
		*  \brief Constructeur par défaut
		*
		*  \post Une instance de la classe EnsembleFaits est initialisée.
		*/
		EnsembleFaits();

		/*!
		*  \brief Constructeur de copie
		*
		*  \post Une copie profonde de l'ensemble de faits source est utilisée pour initialiser la nouvelle instance.
		*
		*  \exception bad_alloc s'il manque de mémoire.
		*/
		EnsembleFaits(const EnsembleFaits&);

		/**
		*  \brief Destructeur
		*
		*  \post L'instance de EnsembleFaits est détruite.
		*/
		~EnsembleFaits();

		/**                       
		*  \brief Ajoute un nouvel élément dans EnsembleFaits.
		* 
		*  \pre Il y a assez de mémoire pour ajouter le fait.
		*  \pre La position d'ajout est comprise entre 1 et |L|+1.
		*
		*  \post EnsembleFaits comprend un élément de plus.
		*  \post Sinon, EnsembleFaits est inchangé.
		* 
		*  \exception range_error si la position est erronée.
		*  \exception bad_alloc s'il manque de mémoire.
		*/
		void ajouterEnsFaits(const TypeFait& fait, int position);

		/**                       
		*  \brief Enlève la première occurence d'un élément donné.
		* 
		*  \pre L'élément donné est compris dans l'ensemble.
		*
		*  \post EnsembleFaits comprend un élément de moins.
		*  \post Sinon, EnsembleFaits est inchangé.
		* 
		*  \exception logic_error si l'élément n'est pas présent dans la liste.
		*/
		void enleverEl(const TypeFait&);

		/**                       
		*  \brief Enlève un élément à une position précise.
		* 
		*  \pre La position donnée est comprise entre 1 et |L|.
		*
		*  \post EnsembleFaits comprend un élément de moins.
		*  \post Sinon, EnsembleFaits est inchangé.
		* 
		*  \exception logic_error si l'ensemble est déjà vide.
		*  \exception range_error si la position est hors borne.
		*/
		void enleverPosEnsFaits(int position);

		/**                       
		*  \brief Retourne le nombre d'éléments dans l'ensemble de faits.
		*
		*  \post EnsembleFaits est inchangé.
		*/
		int cardinaliteEnsFaits() const;

		/**                       
		*  \brief Vérifie si l'ensemble de faits est vide.
		*
		*  \post Retourne true si l'ensemble est vide, false sinon.
		*  \post EnsembleFaits est inchangé.
		*/
		bool videEnsFaits() const;

		/**                       
		*  \brief Vérifie si un élément est dans la liste.
		*
		*  \post Retourne true si l'élément est dans la liste, false sinon.
		*  \post EnsembleFaits est inchangé.
		*/
		bool appartientEnsFaits(const TypeFait&) const;

		/**                       
		*  \brief Retourne le fait à une position précise.
		* 
		*  \pre La position donnée est comprise entre 1 et |L|.
		*
		*  \post EnsembleFaits est inchangé.
		* 
		*  \exception range_error si la position est hors borne.
		*/
		TypeFait elementEnsFaits(int) const;

		/**                       
		*  \brief Retourne la position de la première occurence d'un fait précis dans la liste.
		* 
		*  \pre Le fait donné est dans la liste.
		*
		*  \post EnsembleFaits est inchangé.
		* 
		*  \exception logic_error si l'ensemble est vide.
		*  \exception logic_error si l'élément n'est pas présent dans la liste.
		*/
		int positionEnsFaits(const TypeFait&) const;

		/**                       
		*  \brief Surcharge de l'opérateur = (effectue une copie profonde).
		* 
		*  \pre Les deux ensembleFaits ont été déclarés.
		*
		*  \post EnsembleFaits est une copie profonde de l'ensembleFaits donné en entrée.
		* 
		*  \exception bad_alloc s'il manque de mémoire.
		*/
		EnsembleFaits& operator = (const EnsembleFaits&);

		/**                       
		*  \brief Surcharge de l'opérateur == (pour comparer deux EnsembleFaits).
		* 
		*  \pre Les deux EnsembleFaits ont été déclarés.
		*  \pre Les deux EnsembleFaits sont du même types.
		*
		*  \post Le booléen contient true si les deux EnsembleFaits sont égales, false sinon.
		* 
		*/
		bool operator == (const EnsembleFaits&);

		/**                       
		*  \brief Surcharge de l'opérateur != (pour comparer deux EnsembleFaits).
		* 
		*  \pre Les deux EnsembleFaits ont été déclarés.
		*  \pre Les deux EnsembleFaits sont du même types.
		*
		*  \post Le booléen contient false si les deux EnsembleFaits sont égales, true sinon.
		*
		*/
		bool operator != (const EnsembleFaits&);

		/**                       
		*  \brief Affiche la liste doublement chaînée dans un flux de sortie.
		*  \brief "Friend" pour permettre d'utiliser les données privées pour faire son travail.
		* 
		*  \pre EnsembleFaits est valide.
		*
		*  \post EnsembleFaits est inchangé.
		*
		*	Ne pas toucher à cette méthode.
		*/
		friend std::ostream& operator <<(std::ostream& os, const EnsembleFaits& ef)
		{
			if (ef.videEnsFaits())
				os << "L'ensemble de faits est vide" << std::endl;
			else{
				elem courant = ef.sommetG;
				while (courant != 0){
					os << courant->fait << std::endl;
					courant = courant->suivant;
				}
			}
			return os;
		}

		/**                       
		*  \brief Permet d'écrire le contenu de l’ensemble de faits dans un fichier text.
		*  \brief Le format du fichier est le même que pour le chargement d’un système expert en ce qui concerne les faits.
		*  \brief Retourne le nombre de faits écrits.
		* 
		*  \pre Le fichier reçu est déjà ouvert.
		*
		*  \post Le fichier reçu est encore ouvert.
		*  \post EnsembleFaits est inchangé.
		*  \post Retourne le nombre de faits sauvegardés dans le fichier.
		* 
		*  \exception invalid_argument si le fichier de sortie n'est pas ouvert.
		*/
		int ecrireEnsFaits(std::ofstream & SortieFichier) const;

	private:
		//Noeud typique pour une liste doublement chainée.
		class Noeud
		{
		public:
			TypeFait fait;		// Contient la description du fait
			Noeud * suivant;	// Pointe sur le fait suivant
			Noeud * precedent;	// Pointe sur le fait précédent

			//Constructeur.
			Noeud (const TypeFait& data_item, Noeud * next_ptr = 0, Noeud * pred_ptr =0):
			fait(data_item), suivant(next_ptr), precedent(pred_ptr){}
		};

		typedef Noeud * elem;
		elem sommetG;		//Pointeur vers le sommet à gauche
		elem sommetD;		//Pointeur vers le sommet droit
		int cpt;			//Cardinalité de l'ensemble de faits

	};	// Fermeture de la classe EnsembleFaits.

}	// Fermeture du namespace

#endif