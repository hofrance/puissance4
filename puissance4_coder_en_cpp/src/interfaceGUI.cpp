#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

// Définition de la classe Button pour créer des boutons interactifs
class Button {
public:
    sf::RectangleShape shape;
    sf::Text text;

    // Constructeur de la classe Button
    Button(float x, float y, float width, float height, const sf::Font& font, const std::string& str,
           const sf::Color& normalColor = sf::Color::White, const sf::Color& hoverColor = sf::Color::Green) {
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(normalColor);

        text.setFont(font);
        text.setString(str);
        text.setCharacterSize(24); // Taille du texte
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text.setPosition(sf::Vector2f(x + width / 2.0f, y + height / 2.0f));
        text.setFillColor(sf::Color::Black);

        this->normalColor = normalColor;
        this->hoverColor = hoverColor;
    }

    // Dessine le bouton dans la fenêtre
    void drawTo(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }

    // Met à jour l'apparence du bouton en fonction du survol de la souris
    void update(const sf::Vector2f& mousePos) {
        if (shape.getGlobalBounds().contains(mousePos)) {
            shape.setFillColor(hoverColor);
        } else {
            shape.setFillColor(normalColor);
        }
    }

    // Vérifie si le bouton est cliqué
    bool isClicked(const sf::Vector2f& mousePos) {
        return shape.getGlobalBounds().contains(mousePos);
    }

private:
    sf::Color normalColor, hoverColor;
};

const int LIGNES = 6;
const int COLONNES = 7;
const float TAILLE_JETON = 100.f;
const float ESPACE = 10.f;
const sf::Vector2f ORIGINE(100.f, 100.f);

std::vector<std::vector<int>> plateau(LIGNES, std::vector<int>(COLONNES, 0));
int joueurActuel = 1; // Alternance entre le joueur 1 et 2 ou l'IA
bool jeuContreIA = false; // Indique si le jeu est contre l'IA

// Réinitialise le plateau pour une nouvelle partie
void reinitialiserPartie() {
    for (auto& ligne : plateau) {
        std::fill(ligne.begin(), ligne.end(), 0);
    }
    joueurActuel = 1; // Commence toujours par le joueur 1
    jeuContreIA = false; // Réinitialise également le choix du mode de jeu
}

// Ajoute un jeton dans la colonne sélectionnée si possible
bool ajouterJeton(int joueur, int colonne) {
    for (int i = LIGNES - 1; i >= 0; --i) {
        if (plateau[i][colonne] == 0) {
            plateau[i][colonne] = joueur;
            return true;
        }
    }
    return false; // La colonne est pleine
}

// Dessine le plateau de jeu avec les jetons actuels
void dessinerPlateau(sf::RenderWindow& window) {
    for (int i = 0; i < LIGNES; ++i) {
        for (int j = 0; j < COLONNES; ++j) {
            sf::CircleShape jeton(TAILLE_JETON / 2);
            jeton.setFillColor(plateau[i][j] == 0 ? sf::Color::White : (plateau[i][j] == 1 ? sf::Color::Red : sf::Color::Yellow));
            jeton.setPosition(ORIGINE.x + j * (TAILLE_JETON + ESPACE), ORIGINE.y + i * (TAILLE_JETON + ESPACE));
            window.draw(jeton);
        }
    }
}

int main() {
    // Chargement de la police pour les textes des boutons
    sf::Font font;
    if (!font.loadFromFile("chemin/vers/la/police.ttf")) {
        std::cerr << "Error loading font\n";
        return -1;
    }

    // Initialisation des boutons
    Button btnHumain(100, 50, 200, 50, font, "Humain", sf::Color::White, sf::Color::Green);
    Button btnIA(100, 120, 200, 50, font, "IA", sf::Color::White, sf::Color::Green);
    Button btnReset(100, 190, 200, 50, font, "Reset", sf::Color::White, sf::Color::Red);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Puissance 4 - SFML");

    while (window.isOpen()) {
        sf::Event event;
        sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(window));
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            
            // Mise à jour de l'état des boutons (couleur, clics)
            btnHumain.update(mousePos);
            btnIA.update(mousePos);
            btnReset.update(mousePos);

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                if (btnHumain.isClicked(mousePos)) {
                    jeuContreIA = false;
                    reinitialiserPartie();
                } else if (btnIA.isClicked(mousePos)) {
                    jeuContreIA = true;
                    reinitialiserPartie();
                } else if (btnReset.isClicked(mousePos)) {
                    reinitialiserPartie();
                }
            }
        }

        window.clear(sf::Color::Black);
        dessinerPlateau(window);
        // Dessiner les boutons
        btnHumain.drawTo(window);
        btnIA.drawTo(window);
        btnReset.drawTo(window);
        window.display();
    }

    return 0;
}
