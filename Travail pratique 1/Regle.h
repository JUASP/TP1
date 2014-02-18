/**
*  \file Regle.h
*  \brief Classe d�finissant une r�gle.
*  \author Mondher Bouden
*  \version 0.1
*  \date F�vrier 2014
*
*  Cette classe d�finit une r�gle.
*  Une r�gle est compos�e d'un EnsembleFaits pour les pr�misses et d'un autre pour les conclusions.
*/

#ifndef _REGLE_H
#define _REGLE_H

#include <iostream>
#include <stdexcept>
#include <string>
#include "EnsembleFaits.h"

/** 
*  \namespace tp1
*
*  Espace de nommage regroupant les classes n�cessaires pour le TP1.
*/
namespace tp1
{

	/** 
	*  \class Regle
	*
	*  \brief Classe repr�sentant une r�gle.
	*
	*  La classe g�re une r�gle en utilisant des ensemble de faits.
	*/
	class Regle{

	public:

		/**
		*  \brief Constructeur par d�faut
		*
		*  \post Une instance de la classe Regle est initialis�e.
		*/
		Regle();

		/*!
		*  \brief Constructeur de copie
		*
		*  \post Une copie profonde de la r�gle source est utilis�e pour initialiser la nouvelle instance.
		*/
		Regle(const Regle&);

		/**
		*  \brief Destructeur
		*
		*  \post L'instance de Regle est d�truite.
		*/
		~Regle();

		/**                       
		*  \brief Surcharge de l'op�rateur = (effectue une copie profonde).
		* 
		*  \pre Les deux r�gles ont �t� d�clar�s.
		*  \pre Les deux r�gles sont du m�me types.
		*
		*  \post R�gle est une copie profonde de la r�gle donn�e en entr�e.
		*/
		Regle& operator = (const Regle&);

		/**                       
		*  \brief Surcharge de l'op�rateur == (pour comparer deux r�gles).
		* 
		*  \pre Les deux r�gles ont �t� d�clar�s.
		*  \pre Les deux r�gles sont du m�me types.
		*
		*  \post Le bool�en contient true si les deux r�lges sont �gales, false sinon.
		* 
		*/
		bool operator == (const Regle&);

		/**                       
		*  \brief Surcharge de l'op�rateur != (pour comparer deux r�gles).
		* 
		*  \pre Les deux r�gles ont �t� d�clar�s.
		*  \pre Les deux r�gles sont du m�me types.
		*
		*  \post Le bool�en contient false si les deux r�lges sont �gales, true sinon.
		*
		*/
		bool operator != (const Regle&);

		/**                       
		*  \brief Affiche la r�gle dans un flux de sortie.
		*  \brief "Friend" pour permettre d'utiliser les donn�es priv�es pour faire son travail.
		* 
		*  \pre Regle est valide.
		*
		*  \post Regle est inchang�e.
		*
		*	Ne pas toucher � cette m�thode
		*/
		friend std::ostream& operator << (std::ostream& os, const Regle& r)
		{
			os << "Premisses: " << std::endl << r.premisses;
			os << "Conclusions: " << std::endl << r.conclusions;

			return os;
		}



		/**                       
		*  \brief Retourne le pointeur sur les pr�misses pour pouvoir les modifier.
		* 
		*  \pre Regle est valide.
		*
		*  \post Les pr�misses peuvent �tre chang�es.
		*/
		EnsembleFaits * GetPremisses ();

		/**                       
		*  \brief Retourne le pointeur sur les conclusions pour pouvoir les modifier.
		* 
		*  \pre Regle est valide.
		*
		*  \post Les conclusions peuvent �tre chang�es.
		*/
		EnsembleFaits * GetConclusions ();

		/**                       
		*  \brief Retourne la valeur du bool�en.
		* 
		*  \pre Regle est valide.
		*
		*  \post Regle est inchang�e.
		*/
		bool GetUtilisee () const;

		/**                       
		*  \brief Permet de modifier la valeur du bool�en.
		* 
		*  \pre Regle est valide.
		*
		*  \post La valeur du bool�en est modifi�e.
		*/ 
		void SetUtilisee (const bool & flag);

	private:

		EnsembleFaits premisses;	// L�ensemble des pr�misses d�une r�gle
		EnsembleFaits conclusions;	// L�ensemble des conclusions d�une r�gle
		bool utilisee;				// Sert � marquer la r�gle si n�cessaire

	};	// Fermeture de la classe Regle.

}	// Fermeture du namespace.

#endif
