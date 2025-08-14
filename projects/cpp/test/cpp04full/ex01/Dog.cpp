/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:09:26 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 07:25:37 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() : Animal("unknow"){
	std::cout << "Dog " << _type << " default constructor called" << std::endl;
	this->idea = new Brain;
	std::string idea[100];
	idea[0] = "Chasser les écureuils dans le parc";
    idea[1] = "Creuser un trou dans le jardin";
    idea[2] = "Aboyer après le facteur";
    idea[3] = "Manger des croquettes";
    idea[4] = "Remuer la queue quand le maître rentre à la maison";
    idea[5] = "Dormir sur le canapé";
    idea[6] = "Lécher le visage du maître";
    idea[7] = "Jouer avec une balle";
    idea[8] = "Courir après les voitures";
    idea[9] = "Renifler les autres chiens";
    idea[10] = "Garder la maison";
    idea[11] = "Manger des os";
    idea[12] = "Se rouler dans la boue";
    idea[13] = "Creuser des trous dans le sable";
    idea[14] = "Nager dans la rivière";
    idea[15] = "Dormir dans le panier";
    idea[16] = "Manger des restes de table";
    idea[17] = "Accompagner le maître en promenade";
    idea[18] = "Faire des câlins";
    idea[19] = "Protéger le maître";
    idea[20] = "Manger des friandises";
    idea[21] = "Creuser des trous dans la neige";
    idea[22] = "Courir après les oiseaux";
    idea[23] = "Renifler les arbres";
    idea[24] = "Garder la voiture";
    idea[25] = "Manger de la viande";
    idea[26] = "Se rouler dans l'herbe";
    idea[27] = "Creuser des trous dans la forêt";
    idea[28] = "Nager dans le lac";
    idea[29] = "Dormir dans le lit du maître";
    idea[30] = "Manger des légumes";
    idea[31] = "Accompagner le maître au travail";
    idea[32] = "Faire des léchouilles";
    idea[33] = "Protéger la maison";
    idea[34] = "Manger des fruits";
    idea[35] = "Creuser des trous dans le champ";
    idea[36] = "Courir après les lapins";
    idea[37] = "Renifler les fleurs";
    idea[38] = "Garder le jardin";
    idea[39] = "Manger du poisson";
    idea[40] = "Se rouler dans les feuilles";
    idea[41] = "Creuser des trous dans la montagne";
    idea[42] = "Nager dans la mer";
    idea[43] = "Dormir sur le tapis";
    idea[44] = "Manger des céréales";
    idea[45] = "Accompagner le maître en voyage";
    idea[46] = "Faire des câlins aux enfants";
    idea[47] = "Protéger les enfants";
    idea[48] = "Manger des biscuits";
    idea[49] = "Creuser des trous dans le désert";
    idea[50] = "Courir après les lézards";
    idea[51] = "Renifler les cactus";
    idea[52] = "Garder le troupeau";
    idea[53] = "Manger des œufs";
    idea[54] = "Se rouler dans la poussière";
    idea[55] = "Creuser des trous dans la jungle";
    idea[56] = "Nager dans la piscine";
    idea[57] = "Dormir dans la niche";
    idea[58] = "Manger du fromage";
    idea[59] = "Accompagner le maître à la pêche";
    idea[60] = "Faire des câlins aux personnes âgées";
    idea[61] = "Protéger les personnes âgées";
    idea[62] = "Manger des gâteaux";
    idea[63] = "Creuser des trous dans la toundra";
    idea[64] = "Courir après les rennes";
    idea[65] = "Renifler la glace";
    idea[66] = "Garder le traîneau";
    idea[67] = "Manger du yaourt";
    idea[68] = "Se rouler dans la neige fraîche";
    idea[69] = "Creuser des trous dans la savane";
    idea[70] = "Nager dans l'oasis";
    idea[71] = "Dormir sur le coussin";
    idea[72] = "Manger de la soupe";
    idea[73] = "Accompagner le maître à la chasse";
    idea[74] = "Faire des câlins aux animaux";
    idea[75] = "Protéger les animaux";
    idea[76] = "Manger des bonbons";
    idea[77] = "Creuser des trous dans le volcan";
    idea[78] = "Courir après les chauves-souris";
    idea[79] = "Renifler la lave";
    idea[80] = "Garder la grotte";
    idea[81] = "Suivre une odeur intéressante";
    idea[82] = "Attendre patiemment une friandise";
    idea[83] = "Essayer de voler de la nourriture sur la table";
    idea[84] = "Se faire gratter le ventre";
    idea[85] = "Accompagner le maître aux toilettes";
    idea[86] = "Pleurnicher pour attirer l'attention";
    idea[87] = "Se blottir contre le maître pendant les orages";
    idea[88] = "Faire des tours pour impressionner les invités";
    idea[89] = "Se cacher sous le lit quand il y a du bruit";
    idea[90] = "Accueillir le maître avec enthousiasme à chaque retour";
    idea[91] = "Chercher des jouets cachés";
    idea[92] = "Protéger le territoire contre les intrus";
    idea[93] = "Dormir profondément et rêver de grandes aventures";
    idea[94] = "Être le meilleur ami de l'homme";
    idea[95] = "Apprendre de nouveaux tours";
    idea[96] = "Partager des moments de joie avec le maître";
    idea[97] = "Être toujours là pour réconforter";
    idea[98] = "Aimer inconditionnellement";
    idea[99] = "Vivre chaque jour pleinement avec le maître";
	this->idea->setIdeas(idea);
}

Dog::Dog(std::string type) : Animal(type){
	std::cout << "Dog " << _type << " constructor called" << std::endl;
	this->idea = new Brain;
	std::string idea[100];
	idea[0] = "Chasser les écureuils dans le parc";
    idea[1] = "Creuser un trou dans le jardin";
    idea[2] = "Aboyer après le facteur";
    idea[3] = "Manger des croquettes";
    idea[4] = "Remuer la queue quand le maître rentre à la maison";
    idea[5] = "Dormir sur le canapé";
    idea[6] = "Lécher le visage du maître";
    idea[7] = "Jouer avec une balle";
    idea[8] = "Courir après les voitures";
    idea[9] = "Renifler les autres chiens";
    idea[10] = "Garder la maison";
    idea[11] = "Manger des os";
    idea[12] = "Se rouler dans la boue";
    idea[13] = "Creuser des trous dans le sable";
    idea[14] = "Nager dans la rivière";
    idea[15] = "Dormir dans le panier";
    idea[16] = "Manger des restes de table";
    idea[17] = "Accompagner le maître en promenade";
    idea[18] = "Faire des câlins";
    idea[19] = "Protéger le maître";
    idea[20] = "Manger des friandises";
    idea[21] = "Creuser des trous dans la neige";
    idea[22] = "Courir après les oiseaux";
    idea[23] = "Renifler les arbres";
    idea[24] = "Garder la voiture";
    idea[25] = "Manger de la viande";
    idea[26] = "Se rouler dans l'herbe";
    idea[27] = "Creuser des trous dans la forêt";
    idea[28] = "Nager dans le lac";
    idea[29] = "Dormir dans le lit du maître";
    idea[30] = "Manger des légumes";
    idea[31] = "Accompagner le maître au travail";
    idea[32] = "Faire des léchouilles";
    idea[33] = "Protéger la maison";
    idea[34] = "Manger des fruits";
    idea[35] = "Creuser des trous dans le champ";
    idea[36] = "Courir après les lapins";
    idea[37] = "Renifler les fleurs";
    idea[38] = "Garder le jardin";
    idea[39] = "Manger du poisson";
    idea[40] = "Se rouler dans les feuilles";
    idea[41] = "Creuser des trous dans la montagne";
    idea[42] = "Nager dans la mer";
    idea[43] = "Dormir sur le tapis";
    idea[44] = "Manger des céréales";
    idea[45] = "Accompagner le maître en voyage";
    idea[46] = "Faire des câlins aux enfants";
    idea[47] = "Protéger les enfants";
    idea[48] = "Manger des biscuits";
    idea[49] = "Creuser des trous dans le désert";
    idea[50] = "Courir après les lézards";
    idea[51] = "Renifler les cactus";
    idea[52] = "Garder le troupeau";
    idea[53] = "Manger des œufs";
    idea[54] = "Se rouler dans la poussière";
    idea[55] = "Creuser des trous dans la jungle";
    idea[56] = "Nager dans la piscine";
    idea[57] = "Dormir dans la niche";
    idea[58] = "Manger du fromage";
    idea[59] = "Accompagner le maître à la pêche";
    idea[60] = "Faire des câlins aux personnes âgées";
    idea[61] = "Protéger les personnes âgées";
    idea[62] = "Manger des gâteaux";
    idea[63] = "Creuser des trous dans la toundra";
    idea[64] = "Courir après les rennes";
    idea[65] = "Renifler la glace";
    idea[66] = "Garder le traîneau";
    idea[67] = "Manger du yaourt";
    idea[68] = "Se rouler dans la neige fraîche";
    idea[69] = "Creuser des trous dans la savane";
    idea[70] = "Nager dans l'oasis";
    idea[71] = "Dormir sur le coussin";
    idea[72] = "Manger de la soupe";
    idea[73] = "Accompagner le maître à la chasse";
    idea[74] = "Faire des câlins aux animaux";
    idea[75] = "Protéger les animaux";
    idea[76] = "Manger des bonbons";
    idea[77] = "Creuser des trous dans le volcan";
    idea[78] = "Courir après les chauves-souris";
    idea[79] = "Renifler la lave";
    idea[80] = "Garder la grotte";
    idea[81] = "Suivre une odeur intéressante";
    idea[82] = "Attendre patiemment une friandise";
    idea[83] = "Essayer de voler de la nourriture sur la table";
    idea[84] = "Se faire gratter le ventre";
    idea[85] = "Accompagner le maître aux toilettes";
    idea[86] = "Pleurnicher pour attirer l'attention";
    idea[87] = "Se blottir contre le maître pendant les orages";
    idea[88] = "Faire des tours pour impressionner les invités";
    idea[89] = "Se cacher sous le lit quand il y a du bruit";
    idea[90] = "Accueillir le maître avec enthousiasme à chaque retour";
    idea[91] = "Chercher des jouets cachés";
    idea[92] = "Protéger le territoire contre les intrus";
    idea[93] = "Dormir profondément et rêver de grandes aventures";
    idea[94] = "Être le meilleur ami de l'homme";
    idea[95] = "Apprendre de nouveaux tours";
    idea[96] = "Partager des moments de joie avec le maître";
    idea[97] = "Être toujours là pour réconforter";
    idea[98] = "Aimer inconditionnellement";
    idea[99] = "Vivre chaque jour pleinement avec le maître";
	this->idea->setIdeas(idea);
}

Dog::Dog(const Dog &other) : Animal(other._type){
	std::cout << "Dog " << _type << " copy constructor called" << std::endl;
	this->idea = new Brain(*other.idea);
}

Dog::~Dog(){
	std::cout << "Dog " << _type << " destructor called" << std::endl;
	delete idea;
}

Dog& Dog::operator=(const Dog &other){
	if (this != &other){
		Animal::operator=(other);
		delete idea;
		this->idea = new Brain(*other.idea);
	}
	return (*this);
}

void Dog::makeSound(void) const{
	std::cout << "Dog " << _type << " say OUAAAFFF!" << std::endl;
}

void	Dog::printIdeas(){this->idea->printIdeas();}
