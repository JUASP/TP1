/**
* \file Regle.cpp
* \brief Ce fichier contient une implantation des m�thodes de la classe Regle
* \author ?
* \version 0.1
* \date f�vrier 2014
*
*/

#include "Regle.h"

namespace tp1
{

/**
* \fn Regle:: Regle()
*/

Regle::Regle()
{
   utilisee = false;
}

/**
* \fn Regle:: Regle(const Regle&)
*
* \param[in] V Une regle
*/
Regle::Regle(const Regle& source)
{
   premisses = source.premisses;
   conclusions = source.conclusions;
   utilisee = source.utilisee;

}

/**
* \fn Regle:: ~Regle()
*/
Regle::~Regle()
{
   utilisee = false;
}

/**
* \fn Regle:: Regle(const Regle&)
*
* \param[in] V Une regle
*/
Regle& Regle::operator =(const Regle& source)
{
   premisses = source.premisses; // utilise la surchage du type EnsembleFaits.
   conclusions = source.conclusions;// utilise la surchage du type EnsembleFaits.
   utilisee = source.utilisee;// utilise la surchage du type booléan.
   return (*this);
}

/**
* \fn Regle:: GetPremisses()
*
* \param[out] V Un pointeur vers premisses
*/
EnsembleFaits * Regle::GetPremisses()
{
   return &premisses;
}

/**
* \fn Regle:: GetPremisses()
*
* \param[out] V Un pointeur vers premisses
*/
EnsembleFaits * Regle::GetConclusions()
{
   return &conclusions;
}

/**
* \fn Regle:: GetPremisses()
*
* \param[out] V Un pointeur vers premisses
*/
bool Regle::GetUtilisee() const
{
   return utilisee;
}
/**
   *  \fn bool Regle::operator == (const Regle& source)
   *  \brief Surcharge de l'op�rateur == (pour comparer deux r�gles).
   *
   *  \pre Les deux r�gles ont �t� d�clar�s.
   *  \pre Les deux r�gles sont du m�me types.
   *  \pre l'objet Regle est valide.
   *  \param source est un objet de type Regle.   *
   *  \post Le bool�en contient true si les deux r�lges sont �gales, false sinon.
   *  \return true si la la source et le courant sont les memes.
   *  \return false dans la cas contraire.
   *
   */
bool Regle::operator == (const Regle& source){
   if( premisses == source.premisses && conclusions == source.conclusions){
      return true;
   }
   else return false;
}


/**
      *  \fn bool Regle::operator != (const Regle& source)
      *  \brief Surcharge de l'op�rateur != (pour comparer deux r�gles).
      *
      *  \pre Les deux r�gles ont �t� d�clar�s.
      *  \pre Les deux r�gles sont du m�me types.
      *  \pre objet recu est valide.
      *  \param source est un objet de type Regle.
      *
      *  \post Le bool�en contient false si les deux r�lges sont �gales, true sinon.
      *  \return true si la la source et le courant sont les memes.
      *  \return false dans la cas contraire.
      *
      */
bool Regle::operator != (const Regle& source){
   if( premisses != source.premisses && conclusions != source.conclusions){
      return true;
   }
   else return false;
}

/**
      *  \fn void Regle::SetUtilisee (const bool & flag)
      *  \brief Permet de modifier la valeur du bool�en.
      *
      *  \pre Regle est valide.
      *  \pre flag est valide
      *  \param flag est de type bool.
      *
      *  \post La valeur du bool�en est modifi�e.
      */
void Regle::SetUtilisee (const bool & flag){
   utilisee=flag;
}

}// fin namespace


