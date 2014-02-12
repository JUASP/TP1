/**
 * \file EnsembleFaits.cpp
 * \brief Ce fichier contient une implantation des m�thodes de la classe EnsembeFaits
 * \author ?
 * \version 0.1
 * \date f�vrier 2014
 *
 *  Impl�mentation de la classe EnsembleFaits.
 */

#include "EnsembleFaits.h"


namespace tp1
{
/**
   *  \fn EnsembleFaits::EnsembleFaits()
   *  \brief Constructeur par d�faut
   *
   *  \post Une instance de la classe EnsembleFaits est initialis�e.
   *
   */
EnsembleFaits::EnsembleFaits(){
    sommetG = 0;     //Pointeur vers le sommet � gauche
    sommetD = 0;     //Pointeur vers le sommet droit
    cpt=0; // compteur pour la grosseur du tableau
}




/*!
   *  \fn EnsembleFaits::EnsembleFaits(const EnsembleFaits&)
   *  \brief Constructeur de copie
   *
   *  \pre recois un objet valide
   *  \param source est une référence vers un objet de type EnsembleFaits
   *  \post Une copie profonde de l'ensemble de faits source est utilis�e pour initialiser la nouvelle instance.
   *
   *  \exception bad_alloc s'il manque de m�moire. *Gere par la fonction prive _copier()
   */
EnsembleFaits::EnsembleFaits(const EnsembleFaits& source)
{
   cpt = source.cpt;
   if (source.cpt== 0)// la liste originale est vide
   {
      sommetG = 0;
      sommetD = 0;
   }// fin if
   else
      _copier(source.sommetG); // gere les erreurs de bad alloc.

}//fin constructeur de copie




/**
 *    \fn EnsembleFaits::~EnsembleFaits()
   *  \brief Destructeur
   *
   *  \post L'instance de EnsembleFaits est d�truite.
   */
EnsembleFaits::~EnsembleFaits(){
   _detruire();
}




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
void EnsembleFaits::ajouterEnsFaits(const TypeFait& fait, int position)
{
   try
   {

      // ici on verifie le range de position
      if(position<1 || position > cpt+1) throw std::range_error("ajouterEnsFaits:la position est invalide!");


      elem  nouveau;
      nouveau = new Noeud(fait); //on appelle le constructeur de la classe unNoeud
      nouveau->suivant = 0; // init les valeurs par defaults
      nouveau->precedent = 0; // init les valeurs par defaults


      if(cpt==0) //le cas ou la liste est vide.
      {
         sommetG = nouveau;
         sommetD = nouveau;
         cpt++;//incremente le compteur de la taille
         return;
      }

      if(position==1) //Cas ou position egale 1
      {
         nouveau->suivant=sommetG;
         sommetG->precedent = nouveau;
         sommetG = nouveau;
         cpt++; //incremente le compteur de la taille
         return;
      }

      if(position==cpt+1)// cas ou position est a la fin
      {
         sommetD->suivant=nouveau;
         nouveau->precedent = sommetD;
         sommetD = nouveau;
         cpt++;
         return ;
      }
      //Ajout dans une autre quelconque position
      elem  courant;
      courant = sommetG;   //on se place au debut de la liste
      int i = 1;
      while (i < position - 1) //permet de se deplacer dans la liste a la position avant le nouveau.
      {
         courant=courant->suivant;  //iterateur
         i++;                //on increment la boucle
      }
      // ici on met a jour nos pointer pour bien se positionner a la valeur entre en parametre
      nouveau->suivant = courant->suivant;
      courant->suivant->precedent =  nouveau;
      nouveau->precedent = courant;
      courant->suivant = nouveau;
      cpt++;
   }// fin try
   catch(std::exception& e){
       std::cerr << "ERREUR: " << e.what() << std::endl;
       throw;//On relance alors l'exception pour indiquer qu'une erreur est survenue
   }

}




/**
*  \fn void EnsembleFaits::enleverEl(const TypeFait& element)
*  \brief enleve la premiere occurence d'un element donne
*
*  \pre L'�l�ment donn� est compris dans l'ensemble.
*  \param element est un element de type TypeFait donner ne reference
*
*  \post EnsembleFaits comprend un �l�ment de moins.
*  \post Sinon, EnsembleFaits est inchang�.
*
*  \exception logic_error si l'�l�ment n'est pas pr�sent dans la liste.
*/
void EnsembleFaits::enleverEl(const TypeFait& element)
{
   elem trouve = sommetG;
   elem pred;
   while (trouve != 0 && trouve->fait != element ) // ici on parcours la liste
   {
      pred = trouve;
      trouve = trouve->suivant;
   }

   if (trouve == 0)
   {
      throw std::logic_error("EnleverEl:l'element n'existe pas dans la liste"); // lance une erreur
   }
   else
      {
         if(cpt == 1) // cas ou on a un seul element dans la liste
         {
            sommetG = 0;
            sommetD = 0;
         }
         if (sommetG == trouve) // cas ou l'element est le premier
         {
            sommetG = sommetG->suivant;
            sommetG->precedent = 0;
            trouve->suivant = 0;
         }
         else if (sommetD == trouve)// cas ou l'element est le dernier
         {
            sommetD = sommetD->precedent;
            sommetD->suivant = 0;
            trouve->precedent = 0;
         }

         else // cas ou il est ailleur
         {
            pred->suivant = trouve->suivant;
         }

         trouve->suivant = 0;
         delete trouve;
         cpt--; // on décremente la taille
      }
}




/**
 * \fn  void EnsembleFaits::enleverPosEnsFaits(int position)
*  \brief Enl�ve un �l�ment � une position pr�cise.
*
*  \pre La position donn�e est comprise entre 1 et |L|.
*  \param position est un element de type int.
*
*  \post EnsembleFaits comprend un �l�ment de moins.
*  \post Sinon, EnsembleFaits est inchang�.
*
*  \exception logic_error si l'ensemble est d�j� vide.
*  \exception range_error si la position est hors borne.
*/
void EnsembleFaits::enleverPosEnsFaits(int position)
{
   elem trouve;
   if (cpt == 0)
   {
      throw std::logic_error("enleverPosEnsFaits:l'element n'existe pas dans la liste"); // lance une erreur
   }
   if(position<1 || position > cpt)
   {
      throw std::range_error("enleverPosEnsFaits:Position pour l'enlevement est erron�e");
   }

   if(position == 1)// cas ou pos = 1
   {
      trouve = sommetG;
      sommetG = sommetG->suivant; // on change notre sommetG
      if (cpt!=1)
      {
         sommetG->precedent = 0;
      }
      trouve->suivant = 0;
      }
      else if (position == cpt) // cas ou position est a la fin
      {
         trouve = sommetD;
         sommetD = sommetD->precedent;
         sommetD->suivant = 0;
         trouve->precedent = 0;
      }
      else
      {
         int i =1;
         elem courant = sommetG; //on se positionne au debut de la liste
         while (i< position - 1) //parcours les element de la liste
         {
            courant=courant->suivant;  //on se deplace
            i++;                  //on incremente la boucle
         }
         trouve = courant->suivant;
         courant->suivant = trouve->suivant;
         trouve->suivant = 0;
         trouve->precedent = 0;
      }
      delete trouve; // free la memoire
      cpt--; // decremente la taille
}




/**
   *  \fn int EnsembleFaits::cardinaliteEnsFaits() const
   *  \brief Retourne le nombre d'�l�ments dans l'ensemble de faits.
   *
   *  \post EnsembleFaits est inchang�.
   *  \return cpt qui correspond a la taille de la liste
   */
int EnsembleFaits::cardinaliteEnsFaits() const {
   return cpt;
}




/**
   *  \fn bool EnsembleFaits::videEnsFaits() const
   *  \brief V�rifie si l'ensemble de faits est vide.
   *
   *  \post Retourne true si l'ensemble est vide, false sinon.
   *  \post EnsembleFaits est inchang�.
   *  \return true ou false selon le calcul de cpt==0
   */
bool EnsembleFaits::videEnsFaits() const{
   return cpt==0; // return true or false depend de la valeur de cpt
}



/**
      *  \fn bool EnsembleFaits::appartientEnsFaits(const TypeFait& source) const
      *  \brief V�rifie si un �l�ment est dans la liste.
      *
      *  \post Retourne true si l'�l�ment est dans la liste, false sinon.
      *  \post EnsembleFaits est inchang�.
      *  \return false si le TypeFait source n'est pas dans la liste
      *  \return True si il l'est.
      */
bool EnsembleFaits::appartientEnsFaits(const TypeFait& source) const{
   elem  courant = sommetG; // on se positionne au debut de la liste
   while (courant!=0) // tant que ne ne somme pas a la fin
   {
      if (courant->fait == source)
      {
         return true;
      }
         courant = courant->suivant;
    }// fin while
      return false;
}




/**
   *  \fn TypeFait EnsembleFaits::elementEnsFaits(int) const
   *  \brief Retourne le fait � une position pr�cise.
   *
   *  \pre La position donn�e est comprise entre 1 et |L|.
   *
   *  \post EnsembleFaits est inchang�.
   *
   *  \exception range_error si la position est hors borne.
   *  \return courant->fait on retourne un type TypeFait
   */
TypeFait EnsembleFaits::elementEnsFaits(int position) const
{
   if(position <1 || position > cpt) throw std::range_error("elementEnsFaits:Position est invalide");

   elem courant = sommetG; // on se positionne au debut de la liste
   int i =1;
   while (i< position)      //pour pour parcourir
   {
      courant=courant->suivant;  //on se deplace dans la liste
      i++;                //on incremente la boucle
   }
   return courant->fait;
 }






/**
 * \fn Liste<T>:: _copier(Noeud * sn)
 * \brief fonction prive qui permet de copier un objet.
 * \pre objet est valide
 *
 *
 * \param[in] sn Le pointeur sur le d�but de la liste source
 * \post la copie se fait bien
 * \exception bad_alloc s'il manque de m�moire.
 */
void EnsembleFaits:: _copier(Noeud * source)
{
   try{
      sommetG = new Noeud(source->fait); // copie le premier noeud
      sommetG->precedent = 0;

      sommetD = sommetG; // copie le reste de la liste
      for (elem temp = source->suivant;temp != 0; temp = temp->suivant )
      {
         sommetD->suivant = new Noeud(temp->fait);
         sommetD->suivant->precedent = sommetD;
         sommetD =sommetD->suivant;
         sommetD->suivant = 0;
      }//fin for

      sommetD->suivant = 0; // on signal la fin de la liste en pointant sur 0
   }catch(std::exception&){
      _detruire(); // si une erreur survient on annule les actions prècedente
      throw;//on relance l'erreur
   }
}

/**
 * \fn void Liste<T>:: _detruire()
 * \brief fonctione prive qui permet de détruire l'objet courant. et de liberer la memoire.
 * \post tout est detruit comme prevu
 */
void EnsembleFaits:: _detruire()
{
   elem courant = sommetG; // courant se place au debut de la liste
   while(courant!=0)
   {
      sommetG=sommetG->suivant;
      delete courant;
      courant=sommetG;
   }
}


}
