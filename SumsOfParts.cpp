/**
 * \file SumsOfParts.cpp
 * \author Stéphane Boulanger
 * \brief Let us consider this example (array written in general format):
 *		  ls = [0, 1, 3, 6, 10]
 *		  Its following parts:
 *		  ls = [0, 1, 3, 6, 10]
 *        ls = [1, 3, 6, 10]
 *		  ls = [3, 6, 10]
 *		  ls = [6, 10]
 *		  ls = [10]
 *		  ls = []
 *		  The corresponding sums are (put together in a list): [20, 20, 19, 16, 10, 0]
 *		  The function parts_sums (or its variants in other languages) will take as
 *		  parameter a list ls and return a list of the sums of its parts as defined above.
 * \version 0.1
 * \date 2021-08-03
 * \source https://www.codewars.com/kata/5ce399e0047a45001c853c2b/train/cpp
 * \copyright Copyright (c) 2021
 */


#include <iostream>
#include <vector>
#include <deque>



std::vector<unsigned long long> partsSum(const std::vector<unsigned long long>& ls)
{
	std::vector<unsigned long long> reponse; // Initialisation d'un vecteur de réponses

	unsigned long long add = 0; 
	size_t compteur = 0; 
	size_t longeur = ls.size();

	// Nouveau vecteur 
	std::vector<unsigned long long> newLs;
	newLs = ls;
	
	while (compteur < longeur)
	{
		// Additoner 
		for (size_t i = 0; i < newLs.size(); i++)
		{
			add += newLs[i];
		}

		reponse.push_back(add); // Ajouter la réponse au vecteur 
		newLs.erase(newLs.begin()); // Supprimer le premier élément
		add = 0; 
		compteur++; 
	}
	
	reponse.push_back(0);

	return reponse;
}





int main()
{
	std::vector<unsigned long long> test = {0, 1, 3, 6, 10};
	std::vector<unsigned long long> reponse = partsSum(test);

	for (auto it = reponse.begin(); it != reponse.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	return 0;
}