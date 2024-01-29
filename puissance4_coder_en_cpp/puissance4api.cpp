#include "puissance4api.hh"
#include <iostream>
#include <stdexcept>
#include <fstream>

void p4initialiser(p4plateau & p) {
	for (std::size_t l=0; l<p4hauteur; ++l)
		for (std::size_t c=0; c<p4largeur; ++c)
			p[c][l]=' ';
}

void p4afficher(p4plateau p) {
	for (std::size_t c=0; c<p4largeur; ++c)
		std::cout << (c+1);
	std::cout << "\n";
	for (std::size_t l=0; l<p4hauteur; ++l) {
		for (std::size_t c=0; c<p4largeur; ++c)
			std::cout << p[c][l];
		std::cout << "\n";
	}
}

/* Ne cherchez pas à comprendre l'instruction throw (on vous expliquera cela
 * l'année prochaine). Dites-vous simplement que le throw provoque une fin du
 * programme avec l'affichage du message d'erreur Colonne invalide ou pleine.
 */
void p4jouer(p4plateau & p, std::size_t col, p4jeton j) {
	if (col > p4largeur)
		throw std::invalid_argument("Colonne invalide " + std::to_string(col));
	if (p[col][0] != ' ')
		throw std::invalid_argument("Colonne pleine " + std::to_string(col));
	std::size_t l=p4hauteur-1;
	while (p[col][l] != ' ')
		--l;
	p[col][l] = j;
}







