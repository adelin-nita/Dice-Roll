#ifndef BUTON_H
#define BUTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
private:
    sf::RectangleShape shape;
    sf::Text text;

public:
    // Constructor
    Button(const std::string& str, sf::Vector2f size, int charSize,
           sf::Color bgColor, sf::Color textColor)
    {
        shape.setSize(size);
        shape.setFillColor(bgColor);

        text.setString(str);
        text.setCharacterSize(charSize);
        text.setFillColor(textColor);
    }

    // Setează fontul
    void setFont(const sf::Font& font)
    {
        text.setFont(font);
    }

    // Setează poziția butonului
    void setPosition(sf::Vector2f pos)
    {
        shape.setPosition(pos);

        // Centrare aproximativă a textului în buton
        text.setPosition(
            pos.x + (shape.getSize().x - text.getLocalBounds().width) / 2.f,
            pos.y + (shape.getSize().y - text.getCharacterSize()) / 2.f - 5.f
        );
    }

    // Schimbă culoarea de fundal
    void setBackColor(sf::Color color)
    {
        shape.setFillColor(color);
    }

    // Desenează butonul
    void draw(sf::RenderWindow& window)
    {
        window.draw(shape);
        window.draw(text);
    }

    // Verifică dacă mouse-ul este deasupra butonului
    bool isMouseOver(sf::RenderWindow& window)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f btnPos = shape.getPosition();
        sf::Vector2f btnSize = shape.getSize();

        return (
            mousePos.x >= btnPos.x && mousePos.x <= btnPos.x + btnSize.x &&
            mousePos.y >= btnPos.y && mousePos.y <= btnPos.y + btnSize.y
        );
    }
};

#endif
