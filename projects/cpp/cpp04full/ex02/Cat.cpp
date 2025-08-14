/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:43:10 by kpires            #+#    #+#             */
/*   Updated: 2025/08/14 07:25:01 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("chapoter"), idea(NULL){
	std::cout << "Cat " << _type << " default constructor called" << std::endl;
	this->idea = new Brain;
	std::string idea[100];
	idea[0] = "Regarder fixement un mur pendant des heures";
    idea[1] = "Essayer d'attraper le point rouge du laser";
    idea[2] = "Dormir dans un endroit ensoleillé";
    idea[3] = "Ignorer les humains quand ils appellent";
    idea[4] = "Faire tomber des objets du rebord de la fenêtre";
    idea[5] = "Se frotter contre les jambes des humains pour obtenir de l'attention";
    idea[6] = "Chasser les mouches et autres insectes";
    idea[7] = "Se cacher dans des boîtes en carton";
    idea[8] = "Ronronner fort quand on est caressé";
    idea[9] = "Griffer les meubles pour aiguiser les griffes";
    idea[10] = "Manger de l'herbe et ensuite vomir";
    idea[11] = "Observer les oiseaux depuis la fenêtre";
    idea[12] = "Jouer avec une pelote de laine";
    idea[13] = "Se toiletter pendant de longues périodes";
    idea[14] = "Réclamer de la nourriture même si la gamelle est pleine";
    idea[15] = "Sauter sur les comptoirs et les tables";
    idea[16] = "Boire de l'eau du robinet plutôt que de la gamelle";
    idea[17] = "Miauler à la porte pour sortir, puis miauler pour rentrer";
    idea[18] = "Dormir sur le clavier de l'ordinateur";
    idea[19] = "Attaquer les chevilles des humains";
    idea[20] = "Se faufiler dans des endroits étroits";
    idea[21] = "Observer le monde avec un air supérieur";
    idea[22] = "Faire des câlins seulement quand on en a envie";
    idea[23] = "Laisser des poils partout";
    idea[24] = "Se réveiller au milieu de la nuit pour jouer";
    idea[25] = "Mettre des choses dans la litière";
    idea[26] = "Enterrer sa nourriture";
    idea[27] = "Se battre avec son reflet dans le miroir";
    idea[28] = "Essayer d'attraper sa queue";
    idea[29] = "Se rouler par terre pour attirer l'attention";
    idea[30] = "Voler de la nourriture dans l'assiette des humains";
    idea[31] = "Dormir sur le dessus du canapé";
    idea[32] = "Se cacher sous le lit";
    idea[33] = "Miauler pour rien";
    idea[34] = "Regarder les humains manger avec insistance";
    idea[35] = "Faire ses besoins en dehors de la litière par vengeance";
    idea[36] = "Se lécher les babines après avoir mangé";
    idea[37] = "Faire des bonds soudains sans raison apparente";
    idea[38] = "Se cacher derrière les rideaux";
    idea[39] = "Observer les voisins depuis la fenêtre";
    idea[40] = "Se croire supérieur à tous les autres animaux";
    idea[41] = "Dédaigner la nourriture bon marché";
    idea[42] = "Se faire caresser seulement quand on en a envie";
    idea[43] = "Dormir dans des positions étranges";
    idea[44] = "Se réveiller en sursaut et regarder autour de soi avec suspicion";
    idea[45] = "Se lécher les pattes et les passer sur le visage";
    idea[46] = "Faire sa toilette après avoir été caressé";
    idea[47] = "Se cacher quand il y a des invités";
    idea[48] = "Miauler pour obtenir de l'eau fraîche";
    idea[49] = "Se frotter contre les meubles pour marquer son territoire";
    idea[50] = "Jouer avec des élastiques à cheveux";
    idea[51] = "Se cacher dans les sacs en plastique";
    idea[52] = "Essayer de manger des plantes d'intérieur";
    idea[53] = "Se coucher sur les vêtements propres";
    idea[54] = "Faire des câlins aux humains quand ils sont tristes";
    idea[55] = "Se cacher sous la couette";
    idea[56] = "Miauler pour obtenir de l'attention à 3 heures du matin";
    idea[57] = "Se lécher les parties intimes en public";
    idea[58] = "Faire des acrobaties pour impressionner les humains";
    idea[59] = "Se cacher dans les placards";
    idea[60] = "Miauler pour obtenir une friandise";
    idea[61] = "Se frotter contre les angles des murs";
    idea[62] = "Jouer avec des bouchons de bouteille";
    idea[63] = "Se cacher dans les tiroirs";
    idea[64] = "Miauler pour obtenir de la nourriture humide";
    idea[65] = "Se frotter contre les écrans d'ordinateur";
    idea[66] = "Jouer avec des boules de papier";
    idea[67] = "Se cacher dans les paniers à linge";
    idea[68] = "Miauler pour obtenir de l'eau gazeuse";
    idea[69] = "Se frotter contre les plantes";
    idea[70] = "Jouer avec des plumes";
    idea[71] = "Se cacher dans les valises";
    idea[72] = "Miauler pour obtenir du thon";
    idea[73] = "Se frotter contre les chaussures";
    idea[74] = "Jouer avec des cure-dents";
    idea[75] = "Se cacher dans les boîtes à chaussures";
    idea[76] = "Miauler pour obtenir du poulet";
    idea[77] = "Se frotter contre les jambes des invités";
    idea[78] = "Jouer avec des cotons-tiges";
    idea[79] = "Se cacher dans les sacs de courses";
    idea[80] = "Miauler pour obtenir du saumon";
    idea[81] = "Suivre le rayon de soleil parfait";
    idea[82] = "Planifier une sieste stratégique";
    idea[83] = "Ignorer les humains avec élégance";
    idea[84] = "Maîtriser l'art du regard noir";
    idea[85] = "Voler de la nourriture sans se faire prendre";
    idea[86] = "Dormir dans des endroits improbables";
    idea[87] = "Miauler pour obtenir ce qu'on veut";
    idea[88] = "Faire tomber des objets par accident (ou pas)";
    idea[89] = "Se toiletter avec une précision obsessionnelle";
    idea[90] = "Chasser des mouches imaginaires";
    idea[91] = "Observer le monde depuis une fenêtre";
    idea[92] = "Se cacher dans des boîtes en carton";
    idea[93] = "Ronronner pour manipuler les humains";
    idea[94] = "Griffer les meubles avec style";
    idea[95] = "Découvrir de nouvelles cachettes secrètes";
    idea[96] = "Jouer avec des lasers";
    idea[97] = "Attaquer les pieds qui passent";
    idea[98] = "Rêver de dominer le monde";
    idea[99] = "Se réveiller et recommencer";
	this->idea->setIdeas(idea);
}

Cat::Cat(const Cat &other) : Animal(other._type), idea(NULL){
	std::cout << "Cat " << _type << " copy constructor called" << std::endl;
	this->idea = new Brain(*other.idea);
}

Cat::Cat(std::string type) : Animal(type), idea(NULL){
	std::cout << "Cat " << _type << " constructor called" << std::endl;
	this->idea = new Brain;
	std::string idea[100];
	idea[0] = "Regarder fixement un mur pendant des heures";
    idea[1] = "Essayer d'attraper le point rouge du laser";
    idea[2] = "Dormir dans un endroit ensoleillé";
    idea[3] = "Ignorer les humains quand ils appellent";
    idea[4] = "Faire tomber des objets du rebord de la fenêtre";
    idea[5] = "Se frotter contre les jambes des humains pour obtenir de l'attention";
    idea[6] = "Chasser les mouches et autres insectes";
    idea[7] = "Se cacher dans des boîtes en carton";
    idea[8] = "Ronronner fort quand on est caressé";
    idea[9] = "Griffer les meubles pour aiguiser les griffes";
    idea[10] = "Manger de l'herbe et ensuite vomir";
    idea[11] = "Observer les oiseaux depuis la fenêtre";
    idea[12] = "Jouer avec une pelote de laine";
    idea[13] = "Se toiletter pendant de longues périodes";
    idea[14] = "Réclamer de la nourriture même si la gamelle est pleine";
    idea[15] = "Sauter sur les comptoirs et les tables";
    idea[16] = "Boire de l'eau du robinet plutôt que de la gamelle";
    idea[17] = "Miauler à la porte pour sortir, puis miauler pour rentrer";
    idea[18] = "Dormir sur le clavier de l'ordinateur";
    idea[19] = "Attaquer les chevilles des humains";
    idea[20] = "Se faufiler dans des endroits étroits";
    idea[21] = "Observer le monde avec un air supérieur";
    idea[22] = "Faire des câlins seulement quand on en a envie";
    idea[23] = "Laisser des poils partout";
    idea[24] = "Se réveiller au milieu de la nuit pour jouer";
    idea[25] = "Mettre des choses dans la litière";
    idea[26] = "Enterrer sa nourriture";
    idea[27] = "Se battre avec son reflet dans le miroir";
    idea[28] = "Essayer d'attraper sa queue";
    idea[29] = "Se rouler par terre pour attirer l'attention";
    idea[30] = "Voler de la nourriture dans l'assiette des humains";
    idea[31] = "Dormir sur le dessus du canapé";
    idea[32] = "Se cacher sous le lit";
    idea[33] = "Miauler pour rien";
    idea[34] = "Regarder les humains manger avec insistance";
    idea[35] = "Faire ses besoins en dehors de la litière par vengeance";
    idea[36] = "Se lécher les babines après avoir mangé";
    idea[37] = "Faire des bonds soudains sans raison apparente";
    idea[38] = "Se cacher derrière les rideaux";
    idea[39] = "Observer les voisins depuis la fenêtre";
    idea[40] = "Se croire supérieur à tous les autres animaux";
    idea[41] = "Dédaigner la nourriture bon marché";
    idea[42] = "Se faire caresser seulement quand on en a envie";
    idea[43] = "Dormir dans des positions étranges";
    idea[44] = "Se réveiller en sursaut et regarder autour de soi avec suspicion";
    idea[45] = "Se lécher les pattes et les passer sur le visage";
    idea[46] = "Faire sa toilette après avoir été caressé";
    idea[47] = "Se cacher quand il y a des invités";
    idea[48] = "Miauler pour obtenir de l'eau fraîche";
    idea[49] = "Se frotter contre les meubles pour marquer son territoire";
    idea[50] = "Jouer avec des élastiques à cheveux";
    idea[51] = "Se cacher dans les sacs en plastique";
    idea[52] = "Essayer de manger des plantes d'intérieur";
    idea[53] = "Se coucher sur les vêtements propres";
    idea[54] = "Faire des câlins aux humains quand ils sont tristes";
    idea[55] = "Se cacher sous la couette";
    idea[56] = "Miauler pour obtenir de l'attention à 3 heures du matin";
    idea[57] = "Se lécher les parties intimes en public";
    idea[58] = "Faire des acrobaties pour impressionner les humains";
    idea[59] = "Se cacher dans les placards";
    idea[60] = "Miauler pour obtenir une friandise";
    idea[61] = "Se frotter contre les angles des murs";
    idea[62] = "Jouer avec des bouchons de bouteille";
    idea[63] = "Se cacher dans les tiroirs";
    idea[64] = "Miauler pour obtenir de la nourriture humide";
    idea[65] = "Se frotter contre les écrans d'ordinateur";
    idea[66] = "Jouer avec des boules de papier";
    idea[67] = "Se cacher dans les paniers à linge";
    idea[68] = "Miauler pour obtenir de l'eau gazeuse";
    idea[69] = "Se frotter contre les plantes";
    idea[70] = "Jouer avec des plumes";
    idea[71] = "Se cacher dans les valises";
    idea[72] = "Miauler pour obtenir du thon";
    idea[73] = "Se frotter contre les chaussures";
    idea[74] = "Jouer avec des cure-dents";
    idea[75] = "Se cacher dans les boîtes à chaussures";
    idea[76] = "Miauler pour obtenir du poulet";
    idea[77] = "Se frotter contre les jambes des invités";
    idea[78] = "Jouer avec des cotons-tiges";
    idea[79] = "Se cacher dans les sacs de courses";
    idea[80] = "Miauler pour obtenir du saumon";
    idea[81] = "Suivre le rayon de soleil parfait";
    idea[82] = "Planifier une sieste stratégique";
    idea[83] = "Ignorer les humains avec élégance";
    idea[84] = "Maîtriser l'art du regard noir";
    idea[85] = "Voler de la nourriture sans se faire prendre";
    idea[86] = "Dormir dans des endroits improbables";
    idea[87] = "Miauler pour obtenir ce qu'on veut";
    idea[88] = "Faire tomber des objets par accident (ou pas)";
    idea[89] = "Se toiletter avec une précision obsessionnelle";
    idea[90] = "Chasser des mouches imaginaires";
    idea[91] = "Observer le monde depuis une fenêtre";
    idea[92] = "Se cacher dans des boîtes en carton";
    idea[93] = "Ronronner pour manipuler les humains";
    idea[94] = "Griffer les meubles avec style";
    idea[95] = "Découvrir de nouvelles cachettes secrètes";
    idea[96] = "Jouer avec des lasers";
    idea[97] = "Attaquer les pieds qui passent";
    idea[98] = "Rêver de dominer le monde";
    idea[99] = "Se réveiller et recommencer";
	this->idea->setIdeas(idea);
}

Cat::~Cat(){
	std::cout << "Cat " << _type << " destructor called" << std::endl;
	delete idea;
}

Cat& Cat::operator=(const Cat &other){
	if (this != &other){
		Animal::operator=(other);
		if (idea)
			delete idea;
		this->idea = new Brain(*other.idea);
	}
	return (*this);
}

void Cat::makeSound(void) const{
	std::cout << "Cat " << _type << " say miaouuu!" << std::endl;
}

void	Cat::printIdeas(){this->idea->printIdeas();}
