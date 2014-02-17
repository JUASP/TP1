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
			liste.ajouterFin(contenu);
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
			return liste.enleverPos(liste.cpt = 1);
		}
		throw std::logic_error("Defiler: la file est vide");
	}

	template <typename T>
	unsigned int File<T>::taille(){

		return liste.taille();

	}
}
