/**
 * \file ListeCirculaire.inl
 * \brief Ce fichier contient une implantation des méthodes de la classe ListeCirculaire
 * \author Julien Aspirot JUASP 111 006 179,
 * \version 0.1
 * \date Fevrier 2014
 *
 */

namespace tp1
{

/**
  \fn ListeCirculaire <T>:: ListeCiruclaire()

   \brief constructeur par défault
   \post Le pointeur dernier pointe vers null.
   \post le compteur cpt = 0 puisque la liste est vide.
*/
template <typename T>
ListeCirculaire <T>:: ListeCirculaire()
{
   dernier = 0;
   cpt=0;
}




/**
  \fn ListeCirculaire <T>:: ListeCirculaire(const ListeCirculaire&)

   \brief constructeur de copie.
   \pre recoit un Objet valide.
   \param source objet ListeCirculaire en référence.
   \post L'objet a bel et bien été copier.
   \exception bad_alloc s'il manque de mémoire.

*/
template <typename T>
ListeCirculaire <T>:: ListeCirculaire(const ListeCirculaire& source)
{
   try{
      if (source.dernier == 0){  // si l'objet est vide on initialise le nouveau a vide aussi
         dernier = 0;
         cpt = 0;
      }//fin if
      else{
         operator=(source);// On copie tous les élements.
      }// fin else
   }//fin try
   catch(std::exception& e){
         std::cerr << "ERREUR: " << e.what() << std::endl;
          throw;//On relance alors l'exception pour indiquer qu'une erreur est survenue
   }//Fin catch
}




/**
  \fn ListeCirculaire<T>:: ~ListeCirculaire()

   \brief destructeur de l'objet
   \pre recoit un Objet valide
   \post L'objet a bel et bien été copier.

*/
template <typename T>
ListeCirculaire<T>:: ~ListeCirculaire()
{
   if(dernier !=0){
      elem courant = dernier->suivant; // se positione au début
      elem aSuprimmer = courant;
      while(courant!=dernier){         // parcours la liste
         courant=courant->suivant;     // se déplace dans la liste
         delete aSuprimmer;            // supprime un élément
         aSuprimmer=courant;
       }// fin while
       delete dernier;
   }//fin if
}// fin destructeur




/**
 *  \fn ListeCirculaire<T>& ListeCirculaire<T>:: operator =(const ListeCirculaire<T>& source)
    \brief Surcharge de l'opérateur = (effectue une copie profonde).

    \pre Les deux listes circulaires ont été déclarés.
    \pre Les deux listes circulaires sont du même types.
    \param source objet ListeCirculaire en référence.
    \post ListeCirculaire est une copie profonde de la liste circulaire donnée en entrée.
    \exception bad_alloc s'il manque de mémoire.
*/
template <typename T>
ListeCirculaire<T>& ListeCirculaire<T>:: operator =(const ListeCirculaire<T>& source)
{
   //nettoyage
   if(this != &source){
         // On vide la liste actuel
         delete this;
   }// fin if
   if (source.dernier == 0){
      dernier = 0;  // la liste originale est vide
   }// fin if
   else{
      try{
      cpt = source.cpt;
            dernier = new Noeud(source.dernier->element);
                  // copie le reste de la liste
                  elem nouveau = dernier;
                  for (elem temp = source.dernier->suivant; temp != source.dernier; temp = temp->suivant )
                  {
                     nouveau->suivant = new Noeud(temp->element);
                     nouveau = nouveau->suivant;
                     nouveau->suivant = dernier;
                  }// fin for
                  nouveau->suivant = dernier;
         }// Fin try
      catch(std::exception&){
         delete this;
            //On relance alors l'exception pour indiquer qu'une erreur est survenue
         throw;
         }//Fin catch
   }//Fin else

   return (*this);
}// fin operator =




/**
   \fn int ListeCirculaire<T>:: taille() const
   \brief Retourne le nombre d'éléments de la liste circulaire
   \pre La liste existe.
   \post ListeCirculaire est inchangée.
   \return le valeur int de cpt.
*/
template <typename T>
int ListeCirculaire<T>:: taille() const
{
   return cpt;
}




/**
   \fn void ListeCirculaire<T>:: ajouter(const T& element, int pos)
   \brief permet d'Ajouter des elements a une position donnée.
   \pre on recoit une position et un element valide selon le type
   \pre Il y a assez de mémoire pour ajouter l'élément.
   \param element contient une valeur de type T qui sera ajouter dans la liste de type T.
   \param pos valeur numerique de la position souhaiter.
   \post ListeCirculaire comprend un élément de plus.
   \post Sinon, ListeCirculaire est inchangée.
   \exception range_error si la position est hors borne.
   \exception bad_alloc s'il manque de mémoire.

*/
template <typename T>
void ListeCirculaire<T>:: ajouter(const T& element, int pos)
{
   try{
      elem  courant; //pointeur de service pour se promener dans la liste
      elem  nouveau; //pour l'adresse de la nouvelle structure pour entreposer l'element
      cpt++;     //Puisque nous ajoutons une valeur on incremente le compteur.

      //La position
      if(pos<1 || pos > taille() +1) throw std::range_error("Ajouter:Position d'ajout erronee");

      //La memoire
      nouveau = new Noeud(element);
      nouveau->suivant = nouveau;

      if(dernier == 0) // cas ou la liste est vide
      {
         dernier = nouveau;
         return;
      }

      if(pos == 1)// cas ou on place au début de la liste
      {
         nouveau->suivant = dernier->suivant; // Pointe nouveau-suivant vers l'ancien premier element
         dernier->suivant = nouveau;
         return;
      }

      //Ajout dans une autre quelconque position
      courant = dernier->suivant;   //on se positionne au debut de la liste
      int i = 1;
      while (i < pos - 1)   //boucle pour positionner courant sur la structure d'avant le nouvel ajout
      {
         courant=courant->suivant;  //on passe a la structure suivante..
         i++;                  // on augmente la position courante
      }
      //Ici courant pointe sur le noeud avant celui de la position quon souhaite inserer

      nouveau->suivant = courant->suivant;   //on chaine la nouvelle structure avec celle qui sera sa suivante
      courant->suivant =  nouveau;        //on chaine la structure qui doit pr�c�der avec celle point�e par nouveau
   }// Fin try
   catch(std::exception& e){
      std::cerr << "ERREUR: " << e.what() << std::endl;//On relance alors l'exception pour indiquer qu'une erreur est survenue
       throw;
   }//Fin catch
}




/**
    \fn  void ListeCirculaire<T>:: ajouterFin(const T& element)
    \brief Ajoute un nouvel élément à la fin de la liste circulaire.
    \pre Il y a assez de mémoire pour ajouter l'élément.
    \param element contient une valeur de type T qui sera ajouter dans la liste de type T.
    \post ListeCirculaire comprend un élément de plus a la fin.
    \post Sinon, ListeCirculaire est inchangée.
    \exception bad_alloc s'il manque de mémoire.
   */
template <typename T>
void ListeCirculaire<T>:: ajouterFin(const T& element){
      try{
         elem  nouveau; //pour l'adresse de la nouvelle structure pour entreposer l'element
         nouveau = new Noeud(element);
         nouveau->suivant=dernier->suivant;
         dernier->suivant = nouveau;
         dernier = nouveau;
         cpt++; // On incrémente le compteur
      }// fin try
      catch(std::exception& e){
         std::cerr << "ERREUR: " << e.what() << std::endl;
         throw;//On relance alors l'exception pour indiquer qu'une erreur est survenue
      }// fin catch
}// fin ajouterFin()




/**
   \fn void ListeCirculaire<T>::enleverEl(const T& element)
   \brief Enlève la première occurence d'un élément donné.

   \pre L'élément est contenu dans la liste circulaire.
   \param element contient une valeur de type T qui sera retirer dans la liste.
   \post ListeCirculaire comprend un élément de moins.
   \post Sinon, ListeCirculaire est inchangée.
   \exception logic_error si la liste est déjà vide.
   \exception logic_error si l'élément n'est pas présent dans la liste.
 */
template <typename T>
void ListeCirculaire<T>::enleverEl(const T& element){

   if(dernier == 0){
      throw std::logic_error ("EnleverEl:Liste vide)"); // Signal un erreur si la liste est vide
   }//fin if

   elem trouve = dernier->suivant; // on se positionne au debut de la liste
   elem pred; // on va en avoir besoin pour mettre a jour nos pointeur

   while (trouve != dernier && trouve->element != element )// Boucle pour parcourir les éléments
   {
      pred = trouve;
      trouve = trouve->suivant;
   }// fin while

   if (trouve->element != element){
      throw std::logic_error("EnleverEl:L'element non trouve!");
   }//fin if
   else{
      if(this->taille() == 1){
         dernier = 0;  // on remet le pointeur a null
      }// fin if
      else if (dernier == trouve){ // si l'element est a la fin de la liste
         pred->suivant = dernier->suivant;
         dernier = pred; // on transforme le precedent en dernier.
      }// fin else if
      else{
         pred->suivant = trouve->suivant;
      }// fin else

      trouve->suivant = 0;   // remet le pointeur a null
      delete trouve; // on supprime le noeud
      cpt--;
   }
}




/**
     \fn void ListeCirculaire<T>::enleverPos(int position)
     \brief Enlève un élément à une position précise.

     \pre La position donnée est valide.
     \param pos contient une valeur de type int.
     \post ListeCirculaire comprend un élément de moins.
     \post Sinon, ListeCirculaire est inchangée.
     \exception logic_error si la liste est déjà vide.
     \exception range_error si la position est hors borne.
 */
template <typename T>
void ListeCirculaire<T>::enleverPos(int pos){
   elem trouve;
   if(pos<1 || pos > taille()){
      throw std::range_error("EnleverPos:La position recu est incorrect");
   } //fin if

   if(pos == 1){ // cas debut de la liste
      trouve = dernier->suivant;
      dernier->suivant = dernier->suivant->suivant;
      if(trouve == dernier){
         dernier = 0;
      }
   }
   else{
      int i = 1;
      elem courant = dernier->suivant; //on se pos au debut
      while (i< pos - 1){ //boucle pour positionner courant sur la structure d'avant celui � enlever

            courant=courant->suivant;  //on se deplace dans la liste
            i++;                  //on incrémente la l'indice de position
      }//fin while
      trouve = courant->suivant;
      courant->suivant = trouve->suivant;// pointe sur le noeud apres trouve
      if(trouve ==  dernier){
         dernier = courant;
      }//fin if
   }//fin else
   trouve->suivant = 0;     // pointeur vers null
   delete trouve; // supprime le noeud
   cpt--; // décremente la taille
}




/**
     \fn bool ListeCirculaire<T>::appartient(const T& element) const
     \brief Vérifie si un élément est dans la liste.
     \param element contient une valeur de type T.
     \pre On prend pour acquis que l'opérateur '==' s'applique au type d'élément.   *
     \post ListeCirculaire est inchangée.
*/
template <typename T>
bool ListeCirculaire<T>::appartient(const T& element) const{
   if(dernier == 0){// si la liste est vide on retourne faux
      return false;
    }

    elem courant = dernier->suivant; // on se positionne au debut de la liste

    while(courant!=dernier){
       if(courant->element == element){
          return true;
       }//fin if
        courant=courant->suivant; // on bouge dans la liste
    }// fin while

    if(dernier->element == element){// cas ou l'element se trouve a la fin
       return true;
    }//fin if
      return false;
}




/**
        \fn T ListeCirculaire<T>:: element(int pos) const
        \brief Retourne l'élément à une position donnée.

        \pre La position donnée est comprise entre 1 et |L|.
        \param pos contient une valeur de type int.
        \post ListeCirculaire est inchangée.
        \post on a retourner un element de type T
        \exception  std::range_error si la position est hors borne.
        \return un element de type T
*/
template <typename T>
T ListeCirculaire<T>:: element(int pos) const{
   int i = 1;
   if(dernier == 0) // cas ou la liste est vide
    {
        throw std::logic_error ("Element:liste vide!");
   }
   if(pos < 1 || pos > taille())// on s'assure que la précondition est respecté
   {
      throw std::range_error("Element:Position est invalide");
   }// fin if

   elem courant = dernier->suivant; // on se place au début de la liste
   while (i < pos) // on parcours la liste
   {
      courant=courant->suivant;  // on se déplace dans la liste
      i++;                 // on incrémente la compteur
   }// fin while
   return courant->element;
}// fin element()




/**
     \fn  bool ListeCirculaire<T>:: estVide() const
     \brief Retourne true si la liste est vide, false sinon.
     \pre La liste existe.
     \post ListeCirculaire est inchangée.
     \return True ou False
*/
template <typename T>
bool ListeCirculaire<T>:: estVide() const
{
   return dernier==0;
}// fin estVide()




/**
  \fn int ListeCirculaire<T>::position(const T&) const
  \brief Retourne la position de la première occurence d'un élément donné.

  \pre L'élément donné est dans la liste.
  \param element contient une valeur de type T.
  \post ListeCirculaire est inchangée.
  \exception logic_error si la liste est vide.
  \exception logic_error si l'élément n'est pas présent dans la liste.
  \return une valeur de type T qui correspond a la position d'une valeur
*/
template <typename T>
int ListeCirculaire<T>::position(const T& element) const{
   if(dernier == 0) // cas ou la liste est vide
   {
      throw std::logic_error ("Position:liste vide!");
   }
   int i = 1;

   if(dernier->element == element){ // cas ou l'element se trouve a la derniere position.
       return i;
    }

   elem courant = dernier->suivant;// se position au début

   while (courant != dernier && courant->element != element )
   {
      courant = courant->suivant;
      i++; // on incrémente le i
   }

   if (courant->element !=element ){ // si apres la boucle on a toujours pas l'element on donne l'erreur.
      throw std::logic_error("Position:L'element n'est pas dans la liste");
   }

   return i;// notre i est le compteur. Permet de donner la position.
}
}// fin namespace


