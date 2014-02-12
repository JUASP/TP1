/**
*  \file EnsembleFaits.h
*  \brief Classe d�finissant un ensemble de faits.
*  \author Mondher Bouden
*  \version 0.1
*  \date F�vrier 2014
*
*  Cette classe d�finit un ensemble de faits.
*  Cet ensemble est impl�ment� avec une liste doublement cha�n�e.
*  Chaque fait est une cha�ne de caract�res.
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
*  Espace de nommage regroupant les classes n�cessaires pour le TP1.
*/
namespace tp1
{
	/*! 
	*  \typedef typedef string TypeFait
	*  \brief TypeFait d�finit le type d'un fait. 
	*
	*  Le type 'TypeFait' est utilis� pour d�finir un fait. Ce type contient simplement une cha�ne de caract�res.
	*/
	typedef std::string TypeFait;

	/** 
	*  \class EnsembleFaits
	*
	*  \brief Classe repr�sentant un ensemble de faits.
	*
	*  La classe g�re un ensemble de faits � l'aide d'une liste doublement cha�n�e.
	*/
	class EnsembleFaits{

	public:

		/**
		*  \brief Constructeur par d�faut
		*
		*  \post Une instance de la classe EnsembleFaits est initialis�e.
		*/
		EnsembleFaits();

		/*!
		*  \brief Constructeur de copie
		*
		*  \post Une copie profonde de l'ensemble de faits source est utilis�e pour initialiser la nouvelle instance.
		*
		*  \exception bad_alloc s'il manque de m�moire.
		*/
		EnsembleFaits(const EnsembleFaits&);

		/**
		*  \brief Destructeur
		*
		*  \post L'instance de EnsembleFaits est d�truite.
		*/
		~EnsembleFaits();

		/**                       
		*  \brief Ajoute un nouvel �l�ment dans EnsembleFaits.
		* 
		*  \pre Il y a assez de m�moire pour ajouter le fait.
		*  \pre La position d'ajout est comprise entre 1 et |L|+1.
		*
		*  \post EnsembleFaits comprend un �l�ment de plus.
		*  \post Sinon, EnsembleFaits est inchang�.
		* 
		*  \exception range_error si la position est erron�e.
		*  \exception bad_alloc s'il manque de m�moire.
		*/
		void ajouterEnsFaits(const TypeFait& fait, int position);

		/**                       
		*  \brief Enl�ve la premi�re occurence d'un �l�ment donn�.
		* 
		*  \pre L'�l�ment donn� est compris dans l'ensemble.
		*
		*  \post EnsembleFaits comprend un �l�ment de moins.
		*  \post Sinon, EnsembleFaits est inchang�.
		* 
		*  \exception logic_error si l'�l�ment n'est pas pr�sent dans la liste.
		*/
		void enleverEl(const TypeFait&);

		/**                       
		*  \brief Enl�ve un �l�ment � une position pr�cise.
		* 
		*  \pre La position donn�e est comprise entre 1 et |L|.
		*
		*  \post EnsembleFaits comprend un �l�ment de moins.
		*  \post Sinon, EnsembleFaits est inchang�.
		* 
		*  \exception logic_error si l'ensemble est d�j� vide.
		*  \exception range_error si la position est hors borne.
		*/
		void enleverPosEnsFaits(int position);

		/**                       
		*  \brief Retourne le nombre d'�l�ments dans l'ensemble de faits.
		*
		*  \post EnsembleFaits est inchang�.
		*/
		int cardinaliteEnsFaits() const;

		/**                       
		*  \brief V�rifie si l'ensemble de faits est vide.
		*
		*  \post Retourne true si l'ensemble est vide, false sinon.
		*  \post EnsembleFaits est inchang�.
		*/
		bool videEnsFaits() const;

		/**                       
		*  \brief V�rifie si un �l�ment est dans la liste.
		*
		*  \post Retourne true si l'�l�ment est dans la liste, false sinon.
		*  \post EnsembleFaits est inchang�.
		*/
		bool appartientEnsFaits(const TypeFait&) const;

		/**                       
		*  \brief Retourne le fait � une position pr�cise.
		* 
		*  \pre La position donn�e est comprise entre 1 et |L|.
		*
		*  \post EnsembleFaits est inchang�.
		* 
		*  \exception range_error si la position est hors borne.
		*/
		TypeFait elementEnsFaits(int) const;

		/**                       
		*  \brief Retourne la position de la premi�re occurence d'un fait pr�cis dans la liste.
		* 
		*  \pre Le fait donn� est dans la liste.
		*
		*  \post EnsembleFaits est inchang�.
		* 
		*  \exception logic_error si l'ensemble est vide.
		*  \exception logic_error si l'�l�ment n'est pas pr�sent dans la liste.
		*/
		int positionEnsFaits(const TypeFait&) const;

		/**                       
		*  \brief Surcharge de l'op�rateur = (effectue une copie profonde).
		* 
		*  \pre Les deux ensembleFaits ont �t� d�clar�s.
		*
		*  \post EnsembleFaits est une copie profonde de l'ensembleFaits donn� en entr�e.
		* 
		*  \exception bad_alloc s'il manque de m�moire.
		*/
		EnsembleFaits& operator = (const EnsembleFaits&);

		/**                       
		*  \brief Surcharge de l'op�rateur == (pour comparer deux EnsembleFaits).
		* 
		*  \pre Les deux EnsembleFaits ont �t� d�clar�s.
		*  \pre Les deux EnsembleFaits sont du m�me types.
		*
		*  \post Le bool�en contient true si les deux EnsembleFaits sont �gales, false sinon.
		* 
		*/
		bool operator == (const EnsembleFaits&);

		/**                       
		*  \brief Surcharge de l'op�rateur != (pour comparer deux EnsembleFaits).
		* 
		*  \pre Les deux EnsembleFaits ont �t� d�clar�s.
		*  \pre Les deux EnsembleFaits sont du m�me types.
		*
		*  \post Le bool�en contient false si les deux EnsembleFaits sont �gales, true sinon.
		*
		*/
		bool operator != (const EnsembleFaits&);

		/**                       
		*  \brief Affiche la liste doublement cha�n�e dans un flux de sortie.
		*  \brief "Friend" pour permettre d'utiliser les donn�es priv�es pour faire son travail.
		* 
		*  \pre EnsembleFaits est valide.
		*
		*  \post EnsembleFaits est inchang�.
		*
		*	Ne pas toucher � cette m�thode.
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
		*  \brief Permet d'�crire le contenu de l�ensemble de faits dans un fichier text.
		*  \brief Le format du fichier est le m�me que pour le chargement d�un syst�me expert en ce qui concerne les faits.
		*  \brief Retourne le nombre de faits �crits.
		* 
		*  \pre Le fichier re�u est d�j� ouvert.
		*
		*  \post Le fichier re�u est encore ouvert.
		*  \post EnsembleFaits est inchang�.
		*  \post Retourne le nombre de faits sauvegard�s dans le fichier.
		* 
		*  \exception invalid_argument si le fichier de sortie n'est pas ouvert.
		*/
		int ecrireEnsFaits(std::ofstream & SortieFichier) const;

	private:
		//Noeud typique pour une liste doublement chain�e.
		class Noeud
		{
		public:
			TypeFait fait;		// Contient la description du fait
			Noeud * suivant;	// Pointe sur le fait suivant
			Noeud * precedent;	// Pointe sur le fait pr�c�dent

			//Constructeur.
			Noeud (const TypeFait& data_item, Noeud * next_ptr = 0, Noeud * pred_ptr =0):
			fait(data_item), suivant(next_ptr), precedent(pred_ptr){}
		};

		typedef Noeud * elem;
		elem sommetG;		//Pointeur vers le sommet � gauche
		elem sommetD;		//Pointeur vers le sommet droit
		int cpt;			//Cardinalit� de l'ensemble de faits
	   void _copier( Noeud *); // fonction prive pour copier
	   void _detruire(); // fonction prive pouir détruire la liste

	};	// Fermeture de la classe EnsembleFaits.

}	// Fermeture du namespace

#endif
