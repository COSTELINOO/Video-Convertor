#pragma once

#include "clasa_de_baza.h"

class pagina_principala:public template_pagini
{

    int id_head;

    int id_1,id_2,id_3,id_4,id_5;

    float hex_radius;

    //centre hexagoane
    sf::Vector2f hex_center_1;
    sf::Vector2f hex_center_2;
    sf::Vector2f hex_center_3;
    sf::Vector2f hex_center_4;
    sf::Vector2f hex_center_5;

    //pozitii colturi pentru fiecare hexagon
    std::vector<sf::Vector2f> vertices_1,vertices_2,vertices_3,vertices_4,vertices_5;

    //cele 4 etape ale hexagonului
    Texture hex_1,hex_2,hex_3,hex_4;

    //cele 2 etape ale dreptunghiului header
    Texture drept_1, drept_2;

    Texture img_hex_1,img_hex_2,img_hex_3,img_hex_4,img_hex_5,img_hex_6,img_hex_7,img_hex_8,img_hex_9,img_hex_10;



public:

    pagina_principala(wstring director);


    Sprite desenare(float width, float height, sf::Vector2i mousePos,Event event);


    bool verificare_erori() override
    {
        return eroare;
    }


    std::string descriere_eroare() override
    {
        return mesaj_eroare;
    }


    void reset_id_pagine() override
    {
        id_pagina=0;
    }


    int returen_id_pagine() override
    {
        return id_pagina;
    }

};