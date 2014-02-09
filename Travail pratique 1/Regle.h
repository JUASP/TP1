/**
*  \file Regle.h
*  \brief Classe définissant une règle.
*  \author Mondher Bouden
*  \version 0.1
*  \date Février 2014
*
*  Cette classe définit une règle.
*  Une règle est composée d'un EnsembleFaits pour les prémisses et d'un autre pour les conclusions.
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
*  Espace de nommage regroupant les classes nécessaires pour le TP1.
*/
namespace tp1
{

	/** 
	*  \class Regle
	*
	*  \brief Classe représentant une règle.
	*
	*  La classe gère une règle en utilisant des ensemble de faits.
	*/
	class Regle{

	public:

		/**
		*  \brief Constructeur par défaut
		*
		*  \post Une instance de la classe Regle est initialisée.
		*/
		Regle();

		/*!
		*  \brief Constructeur de copie
		*
		*  \post Une copie profonde de la règle source est utilisée pour initialiser la nouvelle instance.
		*/
		Regle(const Regle&);

		/**
		*  \brief Destructeur
		*
		*  \post L'instance de Regle est détruite.
		*/
		~Regle();

		/**                       
		*  \brief Surcharge de l'opérateur = (effectue une copie profonde).
		* 
		*  \pre Les deux règles ont été déclarés.
		*  \pre Les deux règles sont du même types.
		*
		*  \post Règle est une copie profonde de la règle donnée en entrée.
		*/
		Regle& operator = (const Regle&);

		/**                       
		*  \brief Surcharge de l'opérateur == (pour comparer deux règles).
		* 
		*  \pre Les deux règles ont été déclarés.
		*  \pre Les deux règles sont du même types.
		*
		*  \post Le booléen contient true si les deux rèlges sont égales, false sinon.
		* 
		*/
		bool operator == (const Regle&);

		/**                       
		*  \brief Surcharge de l'opérateur != (pour comparer deux règles).
		* 
		*  \pre Les deux règles ont été déclarés.
		*  \pre Les deux règles sont du même types.
		*
		*  \post Le booléen contient false si les deux rèlges sont égales, true sinon.
		*
		*/
		bool operator != (const Regle&);

		/**                       
		*  \brief Affiche la règle dans un flux de sortie.
		*  \brief "Friend" pour permettre d'utiliser les données privées pour faire son travail.
		* 
		*  \pre Regle est valide.
		*
		*  \post Regle est inchangée.
		*
		*	Ne pas toucher à cette méthode
		*/
		friend std::ostream& operator << (std::ostream& os, const Regle& r)
		{
			os << "Premisses: " << std::endl << r.premisses;
			os << "Conclusions: " << std::endl << r.conclusions;

			return os;
		}



		/**                       
		*  \brief Retourne le pointeur sur les prémisses pour pouvoir les modifier.
		* 
		*  \pre Regle est valide.
		*
		*  \post Les prémisses peuvent être changées.
		*/
		EnsembleFaits * GetPremisses ();

		/**                       
		*  \brief Retourne le pointeur sur les conclusions pour pouvoir les modifier.
		* 
		*  \pre Regle est valide.
		*
		*  \post Les conclusions peuvent être changées.
		*/
		EnsembleFaits * GetConclusions ();

		/**                       
		*  \brief Retourne la valeur du booléen.
		* 
		*  \pre Regle est valide.
		*
		*  \post Regle est inchangée.
		*/
		bool GetUtilisee () const;

		/**                       
		*  \brief Permet de modifier la valeur du booléen.
		* 
		*  \pre Regle est valide.
		*
		*  \post La valeur du booléen est modifiée.
		*/ 
		void SetUtilisee (const bool & flag);

	private:

		EnsembleFaits premisses;	// L’ensemble des prémisses d’une règle
		EnsembleFaits conclusions;	// L’ensemble des conclusions d’une règle
		bool utilisee;				// Sert à marquer la règle si nécessaire

	};	// Fermeture de la classe Regle.

}	// Fermeture du namespace.

#endif