#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "buton.h"

void rollDice(sf::Sprite &sprite1, sf::Sprite &sprite2, sf::Texture &diceTexture1, sf::Texture &diceTexture2, sf::Texture &diceTexture3, sf::Texture &diceTexture4, sf::Texture &diceTexture5, sf::Texture &diceTexture6) 
{
    //dam primului zar valori la intamplare de la 0 la 5
    int diceFace1 = std::rand() % 6;
    //dam celui de al doilea zar valori la intamplare de la 0 la 5
    int diceFace2 = std::rand() % 6;
    


    // atribuim primului zar valori de la 0 la 5 
    switch (diceFace1) 
    {
        case 0: sprite1.setTexture(diceTexture1); break;
        case 1: sprite1.setTexture(diceTexture2); break;
        case 2: sprite1.setTexture(diceTexture3); break;
        case 3: sprite1.setTexture(diceTexture4); break;       
        case 4: sprite1.setTexture(diceTexture5); break;
        case 5: sprite1.setTexture(diceTexture6); break;
    }
                                                                    
    // atribuim celui de al doilea zar valori de la 0 la 5 
    switch (diceFace2) 
    {
        case 0: sprite2.setTexture(diceTexture1); break;
        case 1: sprite2.setTexture(diceTexture2); break;
        case 2: sprite2.setTexture(diceTexture3); break;
        case 3: sprite2.setTexture(diceTexture4); break;
        case 4: sprite2.setTexture(diceTexture5); break;
        case 5: sprite2.setTexture(diceTexture6); break;
    }
}


int main()
{
    //cream fereastra
    sf::RenderWindow window(sf::VideoMode(800,800), "Dice Simulator");

    //introducem fontul 
    sf::Font font;
    if (!font.loadFromFile("verdana.ttf"))
    {
        return -1; 
    }

    
    sf::Text text;
                
    //punem iconita proiectului nostru
    sf::Image icon;
    icon.loadFromFile("download.jpg");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //ii dam butonului atributiile baza (nume, dimensiune buton / text, culoare, pozitie, font text)
    Button butonJoc("Arunca Zarurile", {200, 50}, 15, sf::Color::White, sf::Color::Black);
    butonJoc.setPosition({300, 500});
    butonJoc.setFont(font);

    //adaugam pozele cu cele 6 fete ale zarului
    sf::Texture diceTexture1, diceTexture2, diceTexture3, diceTexture4, diceTexture5, diceTexture6;
    
    
    //le incarcam pe rand in proiect
    if (!diceTexture1.loadFromFile("zar_1.png"))
    {
        return -1;
    }
    if (!diceTexture2.loadFromFile("zar_2.png"))
    {
        return -1;
    }
    if (!diceTexture3.loadFromFile("zar_3.png"))
    {
        return -1;
    }
    if (!diceTexture4.loadFromFile("zar_4.png"))
    {
        return -1;
    }
    if (!diceTexture5.loadFromFile("zar_5.png"))
    {
        return -1;
    }
    if (!diceTexture6.loadFromFile("zar_6.png"))
    {
        return -1;
    }

    
    sf::Sprite diceSprite;

    std::srand(time(0));

    int diceFace = std::rand() % 6;
    int cnt = 0;

    //atribuim zarului din stanga toate pozele cu cele 6 fete ale acestuia
    switch (diceFace)
    {
        case 0:
            diceSprite.setTexture(diceTexture1);
            break;
        case 1:
            diceSprite.setTexture(diceTexture2);
            break;
        case 2:
            diceSprite.setTexture(diceTexture3);
            break;
        case 3:
            diceSprite.setTexture(diceTexture4);
            break;
        case 4:
            diceSprite.setTexture(diceTexture5);
            break;
        case 5:
            diceSprite.setTexture(diceTexture6);
            break;
    }

    // ii dam o pozitie si marime convenabila zarului din stanga
    diceSprite.setPosition(90,200);
    diceSprite.setScale(0.4f, 0.4f);
    
    sf::Sprite diceSprite1;


    std::srand(time(0));
    bool mergeZarul = false;
    int numarulRotirilor = 0;       
    int rotiriMaxime = 800;   

    sf::Text numele;
    numele.setFont(font);
    numele.setCharacterSize(14);
    numele.setFillColor(sf::Color::Red);
    numele.setString("Realizat de: Nita Adelin-Alexandru");
    numele.setPosition(550,0);

    sf::Text sumaZaruri;
    sumaZaruri.setFont(font);
    sumaZaruri.setCharacterSize(18);
    sumaZaruri.setFillColor(sf::Color::Red);
    sumaZaruri.setPosition(375, 435);
    sumaZaruri.setString("suma");

    sf::VertexArray rectangle(sf::LinesStrip, 5);

    rectangle[0].position = sf::Vector2f(350.f, 420.f); 
    rectangle[1].position = sf::Vector2f(450.f, 420.f); 
    rectangle[2].position = sf::Vector2f(450.f, 480.f); 
    rectangle[3].position = sf::Vector2f(350.f, 480.f); 
    rectangle[4].position = sf::Vector2f(350.f, 420.f); 

    int diceFace1 = std::rand() % 6;

    switch (diceFace1)
    {
        case 0:
            diceSprite1.setTexture(diceTexture1);
            break;
        case 1:
            diceSprite1.setTexture(diceTexture2);
            break;
        case 2:
            diceSprite1.setTexture(diceTexture3);
            break;
        case 3:
            diceSprite1.setTexture(diceTexture4);
            break;
        case 4:
            diceSprite1.setTexture(diceTexture5);
            break;
        case 5:
            diceSprite1.setTexture(diceTexture6);
            break;
    }

    
    diceSprite1.setPosition(500,200);
    diceSprite1.setScale(0.4f, 0.4f);
    
     


    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
             {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.control && event.key.code == sf::Keyboard::W) 
                    {
                        window.close();
                        break;
                    }

                case sf::Event::MouseMoved:
                    if (butonJoc.isMouseOver(window)) 
                    {
                        butonJoc.setBackColor(sf::Color::Red);
                    } 
                    else 
                    {
                        butonJoc.setBackColor(sf::Color::White);
                    }
                break;
                case sf::Event::MouseButtonPressed:
                    if (butonJoc.isMouseOver(window))
                    {
                       mergeZarul = true;
                       numarulRotirilor = 0;
                                 
                    }
                    break;
               
        default:
        break;
             }
        }
            if (mergeZarul && numarulRotirilor < rotiriMaxime)
            {
                numarulRotirilor++;
                rollDice(diceSprite, diceSprite1, diceTexture1, diceTexture2, diceTexture3, diceTexture4, diceTexture5, diceTexture6);
                 
            }
            else if (numarulRotirilor >= rotiriMaxime)
                    mergeZarul = false;

                        
                
        // stergem fereastra
        window.clear();

        // aratam continutul
        butonJoc.draw(window);
        window.draw(text);
        window.draw(diceSprite);
        window.draw(diceSprite1);
        window.draw(numele);
        //window.draw(rectangle);
        //window.draw(sumaZaruri);
        window.display();
    }
}