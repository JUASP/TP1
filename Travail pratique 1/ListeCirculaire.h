/**
*  \file ListeCirculaire.h
*  \brief Classe définissant une liste circulaire générique.
*  \author Mondher Bouden
*  \version 0.1
*  \date Février 2014
*
*  Cette classe définit l'interface d'une liste ordonnée.
*  Cette liste est implémentée avec une liste chaînée circulaire.
*  Cette liste est générique.
*/

#ifndef _LISTECIRCULAIRE_H
#define _LISTECIRCULAIRE_H

#include <iostream>
#include <stdexcept>
#include <string>

/** 
*  \namespace tp1
*
*  Espace de nommage regroupant les classes nécessaires pour le TP1.
*/
namespace tp1
{
	/** 
	*  \class ListeCirculaire
	*
	*  \brief Classe représentant une liste circulaire générique.
	*
	*  La classe gère une liste circulaire générique à l'aide d'une liste chaînée circulaire.
	*/
	template<typename T>
	class ListeCirculaire{

	public:

		/**
		*  \brief Constructeur par défaut
		*
		*  \post Une instance vide de la classe ListeCirculaire est initialisée.
		*/
		ListeCirculaire();

		/*!
		*  \brief Constructeur de copie
		*
		*  \post Une copie profonde de la liste circulaire source est utilisée pour initialiser la nouvelle instance.
		*
		*  \exception bad_alloc s'il manque de mémoire.
		*/
		ListeCirculaire(const ListeCirculaire&);

		/**
		*  \brief Destructeur
		*
		*  \post L'instance de ListeCirculaire est détruite.
		*/
		~ListeCirculaire();

		/**                       
		*  \brief Ajoute un nouvel élément dans la liste circulaire.
		* 
		*  \pre Il y a assez de mémoire pour ajouter le l'élément.
		*  \pre La position d'ajout est comprise entre 1 et |L|+1.
		*
		*  \post ListeCirculaire comprend un élément de plus.
		*  \post Sinon, ListeCirculaire est inchangée.
		* 
		*  \exception range_error si la position est hors borne.
		*  \exception bad_alloc s'il manque de mémoire.
		*/
		void ajouter(const T& element, int position);

		/**                       
		*  \brief Ajoute un nouvel élément à la fin de la liste circulaire.
		* 
		*  \pre Il y a assez de mémoire pour ajouter l'élément.
		*
		*  \post ListeCirculaire comprend un élément de plus.
		*  \post Sinon, ListeCirculaire est inchangée.
		* 
		*  \exception bad_alloc s'il manque de mémoire.
		*/
		void ajouterFin(const T& element);

		/**                       
		*  \brief Enlève la première occurence d'un élément donné.
		* 
		*  \pre L'élément est contenu dans la liste circulaire.
		*
		*  \post ListeCirculaire comprend un élément de moins.
		*  \post Sinon, ListeCirculaire est inchangée.
		* 
		*  \exception logic_error si la liste est déjà vide.
		*  \exception logic_error si l'élément n'est pas présent dans la liste.
		*/
		void enleverEl(const T&);

		/**                       
		*  \brief Enlève un élément à une position précise.
		* 
		*  \pre La position donnée est valide.
		*
		*  \post ListeCirculaire comprend un élément de moins.
		*  \post Sinon, ListeCirculaire est inchangée.
		* 
		*  \exception logic_error si la liste est déjà vide.
		*  \exception range_error si la position est hors borne.
		*/
		void enleverPos(int position);

		/**                       
		*  \brief Retourne le nombre d'éléments de la liste circulaire.
		* 
		*  \pre La liste existe.
		*
		*  \post ListeCirculaire est inchangée.
		*/
		int taille() const;

		/**                       
		*  \brief Retourne true si la liste est vide, false sinon.
		* 
		*  \pre La liste existe.
		*
		*  \post ListeCirculaire est inchangée.
		*/
		bool estVide() const;

		/**                       
		*  \brief Vérifie si un élément est dans la liste.
		* 
		*  \pre On prend pour acquis que l'opérateur '==' s'applique au type d'élément.
		*
		*  \post ListeCirculaire est inchangée.
		*
		*/
		bool appartient(const T&) const;

		/**                       
		*  \brief Retourne l'élément à une position donnée.
		* 
		*  \pre La position donnée est comprise entre 1 et |L|.
		*
		*  \post ListeCirculaire est inchangée.
		* 
		*  \exception  std::range_error si la position est hors borne.
		*/
		T element(int) const;

		/**                       
		*  \brief Retourne la position de la première occurence d'un élément donné.
		* 
		*  \pre L'élément donné est dans la liste.
		*
		*  \post ListeCirculaire est inchangée.
		* 
		*  \exception logic_error si la liste est vide.
		*  \exception logic_error si l'élément n'est pas présent dans la liste.
		*/
		int position(const T&) const;

		/**                       
		*  \brief Surcharge de l'opérateur = (effectue une copie profonde).
		* 
		*  \pre Les deux listes circulaires ont été déclarés.
		*  \pre Les deux listes circulaires sont du même types.
		*
		*  \post ListeCirculaire est une copie profonde de la liste circulaire donnée en entrée.
		* 
		*  \exception bad_alloc s'il manque de mémoire.
		*/
		ListeCirculaire<T>& operator =(const ListeCirculaire<T>&);

		/**                       
		*  \brief Affiche la liste circulaire générique dans un flux de sortie.
		*  \brief "Friend" pour permettre d'utiliser les données privées pour faire son travail.
		* 
		*  \pre ListeCirculaire est valide.
		*
		*  \post ListeCirculaire est inchangé.
		*
		*Ne pas toucher à cette méthode
		*/
		friend std::ostream& operator <<(std::ostream& os, const ListeCirculaire<T>& l)
		{
			if (l.dernier == 0)
				os << "La liste est vide" << std::endl;
			else
			{   int nb = 1;
			elem courant = l.dernier->suivant;
			while (courant != l.dernier){
				os << "Element numero " << nb << ": " << std::endl;	
				os << courant->element << std::endl;
				courant = courant->suivant;
				nb++;
			}
			os << "Element numero " << nb << ": " << std::endl;
			os << l.dernier->element;
			}
			return os;
		}

	private:
		//Noeud typique pour une liste circulaire.
		class Noeud
		{
		public:

			T element;	//L'élément contenu dans le noeud.

			Noeud * suivant;	//Un pointeur vers le noeud suivant de la liste.

			//Constructeur.
			Noeud(const T& data_item, Noeud * next_ptr = 0):
			element(data_item), suivant(next_ptr){}
		};

		typedef Noeud * elem;

		elem dernier;	//Pour une liste circulaire, on utilise un pointeur sur le dernier élément de la liste.
		int cpt;		//Cardinalité de la liste


		//Methode privee
	   /**
	    *  \brief Detruire une liste
	    */
	   void  _detruire();

	};	// Fermeture de la classe.

}	// Fermeture du namespace.

#include "ListeCirculaire.inl"

#endif
