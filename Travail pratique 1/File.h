/**
*  \file File.h
*  \brief Classe définissant une file générique.
*  \author Mondher Bouden
*  \version 0.1
*  \date Février 2014
*
*  Cette classe définit l'interface d'une file.
*  Cette file est implémentée avec une liste chaînée circulaire.
*  Cette liste est générique.
*/

#ifndef FILE_H_
#define FILE_H_

#include "ListeCirculaire.h"

/** 
*  \namespace tp1
*
*  Espace de nommage regroupant les classes nécessaires pour le TP1.
*/
namespace tp1
{

	/** 
	*  \class File
	*
	*  \brief Classe représentant une file générique.
	*
	*  La classe gère une file générique à l'aide d'une liste chaînée circulaire.
	*/
	template<typename T>
	class File
	{
	public:

		/**
		*  \brief Constructeur par défaut
		*
		*  \post Une instance vide de la classe File est initialisée.
		*/
		File();

		/**                       
		*  \brief Ajoute un élément à la fin de la file.
		* 
		*  \pre Il y a assez de mémoire pour ajouter l'élément.
		*
		*  \post ListeCirculaire comprend un élément de plus.
		*  \post Sinon, ListeCirculaire est inchangée.
		* 
		*  \exception bad_alloc s'il manque de mémoire.
		*/
		void enfiler(const T& contenu);

		/**                       
		*  \brief Retire l'élément au début de la file et le renvoie.
		* 
		*  \pre La file n'est pas vide.
		*
		*  \post ListeCirculaire comprend un élément de moins.
		*  \post Sinon, ListeCirculaire est inchangée.
		* 
		*  \exception logic_error si la file est vide.
		*/
		T defiler();

		/**                       
		*  \brief Retourne le nombre d'éléments de la file.
		* 
		*  \pre File est valide.
		*
		*  \post File est inchangée.
		*/
		unsigned int taille();

		/**                       
		*  \brief Affiche la file dans un flux de sortie.
		*  \brief "Friend" pour permettre d'utiliser les données privées pour faire son travail.
		* 
		*  \pre File est valide.
		*
		*  \post File est inchangé.
		*
		*	Ne pas toucher pas à cette méthode.
		*/
		friend std::ostream& operator<<(std::ostream& os, const File<T>& file)
		{
			os << file.liste;
			return os;
		}

	private:

		ListeCirculaire<T> liste;	//La file est implantée avec une liste circulaire.
	};

}

#include "File.inl"

#endif /* FILE_H_ */
