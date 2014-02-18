/**
 * \file SystemeExpert.cpp
 * \brief Ce fichier contient une implantation des m�thodes de la classe SystemeExpert
 * \author ?
 * \version 0.1
 * \date f�vrier 2014
 *
 */

#include "SystemeExpert.h"

namespace tp1
{
/**
 * \fn SystemeExpert::SystemeExpert()
 *  \brief Constructeur par d�faut
 *
 *  \post Une instance de la classe SystemeExpert est initialis�e.
 */
SystemeExpert::SystemeExpert(){
}





/**
    *  \fn SystemeExpert::~SystemeExpert()
    *  \brief Destructeur
    *
    *  \post L'instance de EnsembleFaits est d�truite.
    */
SystemeExpert::~SystemeExpert(){
}





/*!
 *  \fn SystemeExpert::SystemeExpert(const SystemeExpert &)
 *  \brief Constructeur de copie
 *  \pre on recoit un objet valide
 *  \param source un objet de type SystemeExpert
 *  \post Une copie profonde du syst�me expert source est utilis�e pour initialiser la nouvelle instance.
 *
 *  \exception bad_alloc s'il manque de m�moire.
 */
SystemeExpert::SystemeExpert(const SystemeExpert & source){
   baseRegles=source.baseRegles; // on fais appelle a la surchage de l'operateur = de la classe ListeCirculaire.
   baseFaits=source.baseFaits; // on fais appelle a la surchage de l'operateur = de la classe EnsembleFaits.
   // bad_alloc sera retourner par les méthodes de surchage des type plushaut.
}






/**
 *  \fn SystemeExpert & SystemeExpert::operator = (const SystemeExpert & source)
 *  \brief Surcharge de l'op�rateur = (effectue une copie profonde).
 *
 *  \pre Les deux systemeExperts ont �t� d�clar�s.
 *
 *  \post SystemeExpert est une copie profonde du syst�me expert donn� en entr�e.
 *
 *  \exception bad_alloc s'il manque de m�moire.
 */
SystemeExpert & SystemeExpert::operator = (const SystemeExpert & source){
   baseRegles=source.baseRegles; // on fais appelle a la surchage de l'operateur = de la classe ListeCirculaire.
   baseFaits=source.baseFaits; // on fais appelle a la surchage de l'operateur = de la classe EnsembleFaits.
   // bad_alloc sera retourner par les méthodes de surchage des type plushaut.
   return (*this);
}





/**
       *  \fn void SystemeExpert::ajouterRegleSE(const Regle & source)
       *  \brief Permet d'ajouter une r�gle (d�j� cr��e et initialis�e) au syst�me expert.
       *
       *  \pre La r�gle est cr��e et initialis�e.
       *  \param source est de type Regle
       *
       *  \post La r�gle est ajout�e au syst�me expert.
       *
       *  \exception bad_alloc s'il manque de m�moire.
       */
 void SystemeExpert::ajouterRegleSE(const Regle & element){
         baseRegles.ajouterFin(element); // On ajoute une règle au systeme expert! la regle est ajouter a la fin de la listeCirculaire.
         // la gestion du bad_alloc est traité dans la méthode ajouterFin()
 }





 /**
     *  \fn   void SystemeExpert::ajouterFaitSE(const TypeFait & element)
     *  \brief Permet d'ajouter un fait (d�j� cr�� et initialis�) au syst�me expert
     *
     *  \pre Le fait est cr�� et initialis�.
     *  \param element est de type TypeFait.
     *
     *  \post Le fait est ajout� au syst�me expert.
     *
     *  \exception bad_alloc s'il manque de m�moire.
     */
void SystemeExpert::ajouterFaitSE(const TypeFait & element){
   baseFaits.ajouterEnsFaits(element,1); // on ajoute l'element de TypeFait en position 1 de la liste.
   // la gestion du bad_alloc est traité dans la méthode ajouterFin()
}





/**
       *  \fn void SystemeExpert::chargerSE(std::ifstream &)
       *  \brief Permet de charger un syst�me expert � partir d'un fichier texte.
       *
       *  \pre Le fichier a �t� ouvert � l'aide de la m�thode "open" pr�alablement � l'appel de la m�thode.
       *  \pre Le fichier a le bon format.
       *
       *  \post Le syst�me expert est charg�.
       *  \post Le fichier est encore ouvert.
       *
       *  \exception logic_error si le fichier texte est vide.
       *  \exception invalid_argument si le fichier texte n'est pas correctement ouvert.
       *
       * Voici le format du fichier texte:
       *
       * Regle_1_Premisse_1      |
       * Regle_1_Premisse_2      |
       * ...                  |
       * Regle_1_Premisse_N      | PREMI�RE
       * !>                | R�GLE
       * Regle_1_Conclusion_1 |
       * Regle_1_Conclusion_2 |
       * ...                  |
       * Regle_1_Conclusion_N |
       * !%
       * Regle_2_Premisse_1      |
       * ...                  |
       * Regle_2_Premisse_N      | DEUXI�ME
       * !>                | R�GLE
       * Regle_2_Conclusion_1 |
       * ...                  |
       * Regle_2_Conclusion_N |
       * !%
       * ...                     ...
       * !%
       * Regle_N_Premisse_1      |
       * ...                  |
       * Regle_N_Premisse_N      | N i�me
       * !>                | R�GLE
       * Regle_N_Conclusion_1 |
       * ...                  |
       * Regle_N_Conclusion_N |
       * !!
       * Fait_1               |
       * Fait_2               | BASE DE
       * ...                  | FAITS
       * Fait_3               |
      */
void SystemeExpert::chargerSE(std::ifstream & file){
   if(file.peek() == std::ifstream::traits_type::eof()){
      throw std::logic_error("chargerSE:logic_error le fichier texte est vide!");
   }
   if(file)
   {
       Regle regleLue;// regle temporaire qui va represente la regle N.
       std::string ligne;
       int indice = 0; // 0 pour les premisses 1 pour les conclusions et 2 pour les faits.
       while (getline(file,ligne))
       {
          if(ligne == "!>"){ // indice pour commencer les conclusions
             indice = 1;
             continue;
          }// fin if
          if(ligne == "!%"){// indice pour les premisses
             indice = 0;
             baseRegles.ajouter(regleLue,1); // ajoute la règle N a baseRegles
             regleLue.~Regle(); // une fois la règle ajoute a baseRegles on la supprime.
             Regle regleLue; // declare une nouvelle regle.
             continue;
          }//fin if
          if (ligne ==  "!!"){// indice pour les faits.
             indice = 2;
             baseRegles.ajouter(regleLue,1); // ajoute la règle N a baseRegles
             regleLue.~Regle();
             continue;
          }// fin if
          switch(indice)
          {
            case 0: regleLue.GetPremisses()->ajouterEnsFaits(ligne,1);
                    break;
            case 1: regleLue.GetConclusions()->ajouterEnsFaits(ligne,1);
                    break;
            case 2: baseFaits.ajouterEnsFaits(ligne,1);
                    break;
          }// fin switch

      }// fin while
   }//fin if
   else
   {
      throw std::invalid_argument("chargerSE:le fichier texte n'est pas correctement ouvert");
   }// fin else
}// fin chargeSE()





/**
 *  \fn int SystemeExpert::sauvegarderSE(std::ofstream &) const
 *  \brief Permet de sauvegarder le syst�me expert dans un fichier texte.
 *
 *  \pre Le fichier a �t� ouvert � l'aide de la m�thode "open" pr�alablement � l'appel de la m�thode.
 *  \param SortieFichier on recoit un fichier ouvert.
 *  \post Le syst�me expert est charg�.
 *  \post Le fichier est encore ouvert.
 *  \post Le fichier a le bon format.
 *  \post Le nombre de faits �tablis dans le syst�me expert est retourn�.
 *
 *  \exception logic_error si le syst�me expert est vide.
 *  \exception invalid_argument si le fichier texte n'est pas correctement ouvert.
 */
int SystemeExpert::sauvegarderSE(std::ofstream & SortieFichier) const{
  /* if (baseRegles==0 && baseFaits==0 && baseNouveauxFaits==0)
   {
      throw std::logic_error("sauvegarderSE:le systeme expert est vide!");
   }*/
   if(SortieFichier)
   {
     for (int i=1; i <= baseRegles.taille(); i++)// boucle qui parcours tous les elements de baseRegles.
     {
           baseRegles.element(i).GetPremisses()->ecrireEnsFaits(SortieFichier);
           SortieFichier << "!>" << std::endl; // marque la fin des premisses pour la regle N.
           baseRegles.element(i).GetConclusions()->ecrireEnsFaits(SortieFichier);
           SortieFichier << "!%" << std::endl; // marque la fin des conclusions pour la regle N.
     }
     SortieFichier << "!!" << std::endl; // marque la fin des regles.
     baseFaits.ecrireEnsFaits(SortieFichier); // on ecrit dans le fichier tous les elements de la baseFaits.

   }
   else{
      throw std::invalid_argument("sauvegarderSE:le fichier texte n'est pas correctement ouvert");
   }
   return 0;
}





/**
 *  \fn ListeCirculaire<Regle> SystemeExpert::chainageAvant()
 *  \brief Permet de saturer la base de faits du syst�me expert en retrouvant les faits
 *  \brief qui peuvent �tre d�duits de la base de faits du syst�me et en se basant sur
 *  \brief les r�gles de celui-ci.
 *
 *  \pre Le syst�me expert contient des faits et des r�gles.
 *
 *  \post Une liste circulaire contenant les r�gles qui ont permis de d�terminer de nouveaux faits est retourn�e.
 *  \post La base des nouveaux faits est modifi�e.
 *
 *  \exception logic_error si la base de faits est vide.
 *  \exception logic_error si la base de r�gles est vide.
 */
ListeCirculaire<Regle> SystemeExpert::chainageAvant(){
   if (baseRegles.estVide())//gestion d'erreur
   {
         throw std::logic_error("chainageAvant:la base de regles est vide");
   }
   if (baseFaits.videEnsFaits())//gestion d'erreur
   {
          throw std::logic_error("chainageAvant:la base de faits est vide");
   }
   ListeCirculaire<Regle> reglesQuiOntPermis;
   for(int i=1; i<=baseRegles.taille() ; i++)// parcours toutes les règles
   {
      for(int j=1; j<=baseRegles.element(i).GetPremisses()->cardinaliteEnsFaits(); j++)  // parcours toutes les premisses
      {
         TypeFait courant = baseRegles.element(i).GetPremisses()->elementEnsFaits(j); // on donne la valeur courante de type Fait a courant.
         if(baseFaits.appartientEnsFaits(courant))// compare les premisses avec les la base de fait.
         {
            if(j<baseRegles.element(i).GetPremisses()->cardinaliteEnsFaits()) // on continue le parcours !
            {
               continue;
            }
         }
         else
         {
            break; // pour sortir du parcours des premisses. jump vers la prochaine regle.
         }
         TypeFait assertion = baseRegles.element(i).GetPremisses()->elementEnsFaits(i);
         for(int k=1; k <= baseNouveauxFaits.taille(); k++){
            if(baseNouveauxFaits.defiler() == assertion){

            }
         }

         //if(!baseNouveauxFaits.liste.appartient(assertion))// on vérifie si l'assertion appartient deja a la liste.
         {
            baseNouveauxFaits.enfiler(assertion); // enfile le nouveauFaits dans la file.
            reglesQuiOntPermis.ajouter(baseRegles.element(i),1);
         }
      }// fin for qui parcours toutes les elements de premisses.
   }// fin for qui parcours toutes les règles


   return baseRegles;
}

}
