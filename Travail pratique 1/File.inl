/**
 * \file File.inl
 * \brief Ce fichier contient une implantation des m�thodes de la classe File
 * \author ?
 * \version 0.1
 * \date f�vrier 2014
 *
 */



namespace tp1
{
	template <typename T>
	File<T>::File(){
	}

	template <typename T>
	void File<T>::enfiler(const T& contenu)
	{
		try
		{
			liste.ajouter(contenu,1); // on ajoute au debut de la liste circulaire.
		}
		catch(std::exception& e)
		{
	        std::cerr << "ERREUR: " << e.what() << std::endl;
	        throw;//On relance alors l'exception pour indiquer qu'une erreur est survenue
		}
	}

	template <typename T>
	T File<T>::defiler()
	{
		if(!liste.estVide())
		{
		   T temporaire;
		   temporaire = liste.element(liste.taille()); // on met l'element qui se trouve a la fin de la liste circulaire dans Temporaire.
			liste.enleverPos(liste.taille()); // on retire l'élement qui est a la fin de la file. avec l'indice de la taille.
			return temporaire; // on retourne l'element de type T.
		}
		throw std::logic_error("Defiler: la file est vide");
	}

template <typename T>
 int File<T>::taille() const{

		return liste.taille();

	}
}
