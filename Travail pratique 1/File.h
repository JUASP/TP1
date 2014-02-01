/**
*  \file File.h
*  \brief Classe d�finissant une file g�n�rique.
*  \author Mondher Bouden
*  \version 0.1
*  \date F�vrier 2014
*
*  Cette classe d�finit l'interface d'une file.
*  Cette file est impl�ment�e avec une liste cha�n�e circulaire.
*  Cette liste est g�n�rique.
*/

#ifndef FILE_H_
#define FILE_H_

#include "ListeCirculaire.h"

/** 
*  \namespace tp1
*
*  Espace de nommage regroupant les classes n�cessaires pour le TP1.
*/
namespace tp1
{

	/** 
	*  \class File
	*
	*  \brief Classe repr�sentant une file g�n�rique.
	*
	*  La classe g�re une file g�n�rique � l'aide d'une liste cha�n�e circulaire.
	*/
	template<typename T>
	class File
	{
	public:

		/**
		*  \brief Constructeur par d�faut
		*
		*  \post Une instance vide de la classe File est initialis�e.
		*/
		File();

		/**                       
		*  \brief Ajoute un �l�ment � la fin de la file.
		* 
		*  \pre Il y a assez de m�moire pour ajouter l'�l�ment.
		*
		*  \post ListeCirculaire comprend un �l�ment de plus.
		*  \post Sinon, ListeCirculaire est inchang�e.
		* 
		*  \exception bad_alloc s'il manque de m�moire.
		*/
		void enfiler(const T& contenu);

		/**                       
		*  \brief Retire l'�l�ment au d�but de la file et le renvoie.
		* 
		*  \pre La file n'est pas vide.
		*
		*  \post ListeCirculaire comprend un �l�ment de moins.
		*  \post Sinon, ListeCirculaire est inchang�e.
		* 
		*  \exception logic_error si la file est vide.
		*/
		T defiler();

		/**                       
		*  \brief Retourne le nombre d'�l�ments de la file.
		* 
		*  \pre File est valide.
		*
		*  \post File est inchang�e.
		*/
		unsigned int taille();

		/**                       
		*  \brief Affiche la file dans un flux de sortie.
		*  \brief "Friend" pour permettre d'utiliser les donn�es priv�es pour faire son travail.
		* 
		*  \pre File est valide.
		*
		*  \post File est inchang�.
		*
		*	Ne pas toucher pas � cette m�thode.
		*/
		friend std::ostream& operator<<(std::ostream& os, const File<T>& file)
		{
			os << file.liste;
			return os;
		}

	private:

		ListeCirculaire<T> liste;	//La file est implant�e avec une liste circulaire.
	};

}

#include "File.inl"

#endif /* FILE_H_ */
