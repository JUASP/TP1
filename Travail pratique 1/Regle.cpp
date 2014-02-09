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

#include "Regle.h"

namespace tp1
{

/**
* \fn Regle:: Regle()
*/

Regle::Regle()
{
   premisses = 0;
   conclusions = 0;
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
   premisses = 0;
   conclusions = 0;
   utilisee = false;

}

/**
* \fn Regle:: Regle(const Regle&)
*
* \param[in] V Une regle
*/
Regle& Regle::operator =(const Regle& source)
{
   return (*this);
}

/**
* \fn Regle:: GetPremisses()
*
* \param[out] V Un pointeur vers premisses
*/
EnsembleFaits * Regle::GetPremisses()
{
return *premisses;
}

/**
* \fn Regle:: GetPremisses()
*
* \param[out] V Un pointeur vers premisses
*/
EnsembleFaits * Regle::GetConclusions()
{
return *conclusions;
}

/**
* \fn Regle:: GetPremisses()
*
* \param[out] V Un pointeur vers premisses
*/
bool Regle::GetUtilisee() const
{
   return *utilisee;
}
}

}
