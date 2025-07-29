#pragma once

#include "fereastra_principala.h"
#include<cmath>
using namespace std;
bool verificare_in_hexagon(const sf::Vector2f& point, const std::vector<sf::Vector2f>& vertices) ;


pagina_principala::pagina_principala(wstring director) {

    set_project_director(director);
    id_pagina=0;

    id_head=1;

    eroare=false;

    id_1 = 0,id_2 = 0,id_3=0,id_4=0,id_5=0;

    hex_radius = 150.f;

    hex_center_1={150.f+130.0-33,150.f+850/3.0};

    hex_center_2={150.f+520.0-33,150.f+850/3.0};

    hex_center_3={150.f+910.0-33,150.f+850/3.0};

    hex_center_4={150.f+325.0-33,150.f+850/1.6};

    hex_center_5={150.f+715.0-33,150.f+850/1.6};


    //creez o textura de dimensiunea ferestrei
    if (!renderTexture.create(static_cast<unsigned>(1300), static_cast<unsigned>(850))) {
        throw std::runtime_error("Failed to create RenderTexture");
    }


    // setare fond
    if (!font.loadFromFile(project_director+"/assets/Fonturi/seguiemj.ttf")) {
        mesaj_eroare="Eroare la încărcarea fontului!\n";
        eroare=true;
    }
    text.setFont(font);


    //calculare coordonate colturi pentru hexagonul 1, pentru a verifica daca mouse-ul se afla pe el
    for (int i = 0; i < 6; ++i) {
        // Calculăm unghiul fiecărui colț
        float angle = (float)i * 60.f * 3.14159f / 180.f;
        // Coordonata x
        float x = hex_center_1.x + hex_radius * cos(angle);
        // Coordonata y
        float y = hex_center_1.y + hex_radius * sin(angle);
        // Stocăm și coordonatele pentru verificarea mouse-ului
        vertices_1.emplace_back(x, y);
    }


    //calculare coordonate colturi pentru hexagonul 2, pentru a verifica daca mouse-ul se afla pe el
    for (int i = 0; i < 6; ++i) {
        float angle =  (float)i * 60.f * 3.14159f / 180.f;
        float x = hex_center_2.x + hex_radius * cos(angle);
        float y = hex_center_2.y + hex_radius * sin(angle);
        vertices_2.emplace_back(x, y);
    }


    //calculare coordonate colturi pentru hexagonul 3, pentru a verifica daca mouse-ul se afla pe el
    for (int i = 0; i < 6; ++i) {
        float angle =  (float)i * 60.f * 3.14159f / 180.f;
        float x = hex_center_3.x + hex_radius * cos(angle);
        float y = hex_center_3.y + hex_radius * sin(angle);
        vertices_3.emplace_back(x, y);
    }


    //calculare coordonate colturi pentru hexagonul 4, pentru a verifica daca mouse-ul se afla pe el
    for (int i = 0; i < 6; ++i) {
        float angle =  (float)i * 60.f * 3.14159f / 180.f;
        float x = hex_center_4.x + hex_radius * cos(angle);
        float y = hex_center_4.y + hex_radius * sin(angle);
        vertices_4.emplace_back(x, y);
    }


    //calculare coordonate colturi pentru hexagonul 1, pentru a verifica daca mouse-ul se afla pe el
    for (int i = 0; i < 6; ++i) {
        float angle =  (float)i * 60.f * 3.14159f / 180.f;
        float x = hex_center_5.x + hex_radius * cos(angle);
        float y = hex_center_5.y + hex_radius * sin(angle);
        vertices_5.emplace_back(x, y);
    }


    //incarcam imaginea pentru hexagonul in starea de baza(cand nu e mouse ul pe el)
    if (!hex_1.loadFromFile(project_director+"/assets/Media/Pagina_principala/hexagon.png")) {
        mesaj_eroare="Eroare la încărcarea hexagonului albastru mic!\n";
        eroare=true;
    }


    //incarcam imaginea pentru primul hexagon de trecere
    if (!hex_2.loadFromFile(project_director+"/assets/Media/Pagina_principala/hexagon7.png")) {
        mesaj_eroare="Eroare la încărcarea hexagonului albastru de trecere!\n";
        eroare=true;
    }


    //incarcam imaginea pentru hexagonul in starea cand e mouse ul pe el
    if (!hex_3.loadFromFile(project_director+"/assets/Media/Pagina_principala/hexagon2.png")) {
        mesaj_eroare="Eroare la încărcarea hexagonului rosu mare!\n";
        eroare=true;
    }


    //incarcam imaginea pentru al doilea hexagon de trecere
    if (!hex_4.loadFromFile(project_director+"/assets/Media/Pagina_principala/hexagon8.png")) {
        mesaj_eroare="Eroare la încărcarea hexagonului rosu de trecere!\n";
        eroare=true;
    }


    //incarcare background
    if (!background.loadFromFile(project_director+"/assets/Media/Pagina_principala/background.png")) {
        mesaj_eroare="Eroare la încărcare nackground/fundal!\n";
        eroare=true;
    }

    //incarcarcare dreptunghi header cand nu e mouse ul pe el
    if (!drept_1.loadFromFile(project_director+"/assets/Media/Pagina_principala/dreptunghi_3.png")) {

        mesaj_eroare="Eroare la încărcarea dreptunghi header albastru!\n";
        eroare=true;
    }

    //incarcarcare dreptunghi header cand e mouse ul pe el
    if (!drept_2.loadFromFile(project_director+"/assets/Media/Pagina_principala/dreptunghi_4.png")) {
        mesaj_eroare="Eroare la dreptunghi header rosu!\n";
        eroare=true;
    }

    //incarcarcare dreptunghi header cand e mouse ul pe el
    if (!img_hex_1.loadFromFile(project_director+"/assets/Media/Pagina_principala/img_hex_1.png")) {
        mesaj_eroare="Eroare la hexagon1!\n";
        eroare=true;
    }

    //incarcarcare dreptunghi header cand e mouse ul pe el
    if (!img_hex_2.loadFromFile(project_director+"/assets/Media/Pagina_principala/img_hex_2.png")) {
        mesaj_eroare="Eroare la hexagon2!\n";
        eroare=true;
    }

    //incarcarcare dreptunghi header cand e mouse ul pe el
    if (!img_hex_3.loadFromFile(project_director+"/assets/Media/Pagina_principala/img_hex_3.png")) {
        mesaj_eroare="Eroare la hexagon3!\n";
        eroare=true;
    }

    //incarcarcare dreptunghi header cand e mouse ul pe el
    if (!img_hex_4.loadFromFile(project_director+"/assets/Media/Pagina_principala/img_hex_4.png")) {
        mesaj_eroare="Eroare la hexagon4!\n";
        eroare=true;
    }

    //incarcarcare dreptunghi header cand e mouse ul pe el
    if (!img_hex_5.loadFromFile(project_director+"/assets/Media/Pagina_principala/img_hex_5.png")) {
        mesaj_eroare="Eroare la hexagon5!\n";
        eroare=true;
    }

    //incarcarcare dreptunghi header cand e mouse ul pe el
    if (!img_hex_6.loadFromFile(project_director+"/assets/Media/Pagina_principala/img_hex_6.png")) {
        mesaj_eroare="Eroare la hexagon6!\n";
        eroare=true;
    }

    //incarcarcare dreptunghi header cand e mouse ul pe el
    if (!img_hex_7.loadFromFile(project_director+"/assets/Media/Pagina_principala/img_hex_7.png")) {
        mesaj_eroare="Eroare la hexagon7!\n";
        eroare=true;
    }

    //incarcarcare dreptunghi header cand e mouse ul pe el
    if (!img_hex_8.loadFromFile(project_director+"/assets/Media/Pagina_principala/img_hex_8.png")) {
        mesaj_eroare="Eroare la hexagon8!\n";
        eroare=true;
    }

    //incarcarcare dreptunghi header cand e mouse ul pe el
    if (!img_hex_9.loadFromFile(project_director+"/assets/Media/Pagina_principala/img_hex_9.png")) {
        mesaj_eroare="Eroare la hexagon9!\n";
        eroare=true;
    }

    //incarcarcare dreptunghi header cand e mouse ul pe el
    if (!img_hex_10.loadFromFile(project_director+"/assets/Media/Pagina_principala/img_hex_10.png")) {
        mesaj_eroare="Eroare la hexagon10!"+project_director;
        eroare=true;
    }

}


Sprite pagina_principala::desenare(float width, float height, sf::Vector2i mousePos,Event event) {

    renderTexture.clear();


    //incarcare fundal
    Sprite aux;
    aux.setTexture(background);
    renderTexture.draw(aux);

    //vector ce contine coordonatele mouse-ului
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));


    //desenare header
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {

        if(mousePosF.x>=(1205-120)&&mousePosF.x<=(1300-120)&&mousePosF.y>=15&&mousePosF.y<=215)
        {
            id_head++;
            sleep(seconds(0.1));
            if(id_head==2)
                id_head=0;
        }
        else
            id_head=1;

    }


if(id_head%2==0)
    {

        draw_figura(renderTexture,text,drept_2,0, 0,0,"YouTube Video Downloader\n"

                                                         "                  and\n""        Video Convertor"
                ,50,345-115,30,Color::Black);
        draw_text(renderTexture,text,"YouTube Video Downloader\n"

                       "                  and\n""        Video Convertor"
                ,50,345-115,25,Color::White);
        renderTexture.draw(text);

        draw_text(renderTexture,text,"             Creator:\n"
                       "  Arseni Costel-Ionut"
                ,20,1100-120,150+15,Color::White);
        renderTexture.draw(text);
    }
else {
        draw_figura(renderTexture, text, drept_1, 0, 0, 0, "YouTube Video Downloader\n"

                                                           "                  and\n"
                                                           "        Video Convertor",
                    50, 345, 30,Color::Black);
        draw_text(renderTexture,text,"YouTube Video Downloader\n"

                       "                  and\n""        Video Convertor"
                ,50,345,25,Color::White);
        renderTexture.draw(text);
    }




    //hexagon_1 sus
    if (verificare_in_hexagon(mousePosF, vertices_1))
    {
        //verificare daca am apasat click stanga in timp ce sunt in hexagon
        if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        {
            id_pagina=1;
        }

        id_2 = 0,id_3=0,id_4=0,id_5=0;

        if(id_1<2)
        {
            draw_figura(renderTexture,text,hex_2,0.66,130-10-33-27,
                        850/3.0-18,"",0,0,0);
            id_1++;
        }
        else  if(id_1<4)
        {
            draw_figura(renderTexture,text,hex_4,0.72,130-20-33-27,
                        850/3.0-36,"",0,0,0);
            id_1++;
        }
        else
        {
            draw_figura(renderTexture,text,hex_3,0.77,130-30-33-27,
                        850/3.0-54,"",0,0,0);
            draw_figura(renderTexture,text,img_hex_6,0.65,130-33-27-5-30+30,
                        850/3.0-54+30,"",0,0,0);
        }

    }
    else
    {
        if(id_1>=2)
        {
            draw_figura(renderTexture,text,hex_4,0.72,130-20-33-18,
                        850/3.0-36,"",0,0,0);
            id_1--;
        }
        else
        if(id_1>0)
        {
            draw_figura(renderTexture,text,hex_2,0.66,130-10-33-9,
                        850/3.0-18,"",0,0,0);
            id_1--;
        }
        else
        {



            draw_figura(renderTexture,text,hex_1,0.6,130-33,
                        850/3.0,"Download\n"
                                "    Video",35,130+50-15, (float)850/3+100-9+5,Color::Black);
            draw_text(renderTexture,text,"Download\n"
                           "    Video",35,130+50-15, (float)850/3+100-9,Color::White);
            renderTexture.draw(text);
            draw_figura(renderTexture,text,img_hex_1,0.5,130-5,
                        850/3.0+36,"",0,0,0);

        }
    }


    //hexagon_2 sus
    if (verificare_in_hexagon(mousePosF, vertices_2))
    {
        //verificare daca am apasat click stanga in timp ce sunt in hexagon
        if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        {

            id_pagina=2;
        }

        id_1 = 0,id_3=0,id_4=0,id_5=0;

        if(id_2<3)
        {
            draw_figura(renderTexture,text,hex_2,0.66,
                        520-10-33, (float)850/3-18,"",0,0,0);
            id_2++;
        }
        else
        if(id_2<4)
        {
            draw_figura(renderTexture,text,hex_4,0.72,
                        520-20-33, (float)850/3-36,"",0,0,0);

            id_2++;
        }
        else
        {
            draw_figura(renderTexture,text,hex_3,0.77,
                        520-40-33, (float)850/3-54,"",0,0,0);

            draw_figura(renderTexture,text,img_hex_7,0.70,
                        520-40-33+15, (float)850/3-54+15,"",0,0,0);
        }
    }
    else
    {
        if(id_2>=2)
        {
            draw_figura(renderTexture,text,hex_4,0.72,
                        520-20-33, (float)850/3-36,"",0,0,0);
            id_2--;
        }
        else
        if(id_2>0)
        {
            draw_figura(renderTexture,text,hex_2,0.66,
                        520-10-33, (float)850/3-18,"",0,0,0);
            id_2--;
        }
        else
        {
            draw_figura(renderTexture,text,hex_1,0.6,
                        520-33, (float)850/3,"",0,0,0);
            draw_figura(renderTexture,text,img_hex_2,0.5,520+5, (float)850/3+27+5,"Webm\n"
                                                                                                "\n\n"
                                                                                                "  Mp4",35,520+15+5, (float)850/3+70+5,Color::Black);
            draw_text(renderTexture,text,"Webm\n"
                           "\n\n"
                           "  Mp4",35,520+15+5, (float)850/3+70,Color::White);
            renderTexture.draw(text);
        }
    }


    //hexagon_3 sus
    if (verificare_in_hexagon(mousePosF, vertices_3))
    {
        //verificare daca am apasat click stanga in timp ce sunt in hexagon
        if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        {
            id_pagina=3;
        }

        id_2 = 0,id_1=0,id_4=0,id_5=0;

        if(id_3<2)
        {
            draw_figura(renderTexture,text,hex_2,0.66,910-9-33,
                        850/3.0-18,"",0,0,0);
            id_3++;
        }
        else
        if(id_3<4)
        {
            draw_figura(renderTexture,text,hex_4,0.72,910-18-33,
                        850/3.0-36,"",0,0,0);
            id_3++;
        }
        else
        {
            draw_figura(renderTexture,text,hex_3,0.77,910-27-33,
                        850/3.0-54,"",0,0,0);
            draw_figura(renderTexture,text,img_hex_8,0.65,910-27-33+15+15,
                        850/3.0-54+15+15,"",0,0,0);


        }


    }
    else
    {
        if(id_3>=2)
        {
            draw_figura(renderTexture,text,hex_4,0.72,910-20-33,
                        850/3.0-36,"",0,0,0);
            id_3--;
        }
        else
        if(id_3>0)
        {
            draw_figura(renderTexture,text,hex_2,0.66,910-10-33,
                        850/3.0-18,"",0,0,0);
            id_3--;
        }
        else
        {
            draw_figura(renderTexture,text,hex_1,0.6,910-33,
                        850/3.0,"Download\n"
                                "    Audio",35,910+50-15, (float)850/3+100-9+5,Color::Black);
            draw_text(renderTexture,text,"Download\n"
                           "    Audio",35,910+50-15, (float)850/3+100-9,Color::White);
            renderTexture.draw(text);
            draw_figura(renderTexture,text,img_hex_3,0.45,910+10,
                        850/3.0+54,"",0,0,0);

        }
    }


    //hexagon_1 jos
    if (verificare_in_hexagon(mousePosF, vertices_4))
    {
        //verificare daca am apasat click stanga in timp ce sunt in hexagon
        if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
        {
            id_pagina=4;
        }

        id_1 = 0,id_3=0,id_2=0,id_5=0;

        if(id_4<2)
        {
            draw_figura(renderTexture,text,hex_2,0.66,
                        325-10-33,850/1.6-18,"",0,0,0);
            id_4++;
        }
        else
        if(id_4<4)
        {
            draw_figura(renderTexture,text,hex_4,0.72,
                        325-20-33,850/1.6-36,"",0,0,0);

            id_4++;
        }
        else
        {
            draw_figura(renderTexture,text,hex_3,0.72,
                        325-30-33,850/1.6-38,"",0,0,0);
            draw_figura(renderTexture,text,img_hex_9,0.65,
                        325-30-33+15,850/1.6-38+15,"",0,0,0);

        }


    }
    else
    {
        if(id_4>=2)
        {
            draw_figura(renderTexture,text,hex_4,0.72,
                        325-20-33,850/1.6-36,"",0,0,0);
            id_4--;
        }
        else
        if(id_4>0)
        {
            draw_figura(renderTexture,text,hex_1,0.66,
                        325-10-33,850/1.6-18,"",0,0,0);

            id_4--;
        }
        else
        {
            draw_figura(renderTexture,text,hex_1,0.6,
                        325-33,850/1.6,"",0,0,0);
            draw_figura(renderTexture,text,img_hex_4,0.5,325+5,850/1.6+27," Mp4\n"
                                                                        "\n\n"
                                                                        " Mp3",35,325+20+10, (float)850/3+325+5,Color::Black);
            draw_text(renderTexture,text," Mp4\n"
                      "\n\n"
                      " Mp3",35,325+20+10, (float)850/3+325,Color::White);
            renderTexture.draw(text);
        }
    }


    //hexagon_2 jos
    if (verificare_in_hexagon(mousePosF, vertices_5))
    {
        //verificare daca am apasat click stanga in timp ce sunt in hexagon
        if((event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left))
        {
            id_pagina=5;
        }

        id_1 = 0,id_3=0,id_2=0,id_4=0;

        if(id_5<2)
        {
            draw_figura(renderTexture,text,hex_2,0.66,
                        715-10-33,850/1.6-18,"",0,0,0);
            id_5++;
        }
        else
        if(id_5<4)
        {
            draw_figura(renderTexture,text,hex_4,0.72,
                        715-20-33,850/1.6-36,"",0,0,0);

            id_5++;
        }
        else
        {
            draw_figura(renderTexture,text,hex_3,0.72,
                        715-30-33,850/1.6-38,"",0,0,0);
            draw_figura(renderTexture,text,img_hex_10,0.65,
                        715-30-33+15,850/1.6-38+15,"",0,0,0);
        }
    }
    else
    {
        if(id_5>=2)
        {
            draw_figura(renderTexture,text,hex_4,0.72,
                        715-20-33,850/1.6-36,"",0,0,0);
            id_5--;
        }
        else
        if(id_5>0)
        {
            draw_figura(renderTexture,text,hex_1,0.66,
                        715-10-33,850/1.6-18,"",0,0,0);

            id_5--;
        }
        else
        {
            draw_figura(renderTexture,text,hex_1,0.6,
                        715-33,850/1.6,"",0,0,0);
            draw_figura(renderTexture,text,img_hex_5,0.5,715+5,850/1.6+27," Mp3\n"
                                                                        "\n\n"
                                                                        " Wav",35,715+20+10, (float)850/3+325+5,Color::Black);
            draw_text(renderTexture,text," Mp3\n"
                           "\n\n"
                           " Wav",35,715+20+10, (float)850/3+325,Color::White);
            renderTexture.draw(text);
        }
    }

    //incarcarea si returnarea tuturor modificarilor paginii
    renderTexture.display();
    sprite.setTexture(renderTexture.getTexture());
    return sprite;
}


bool verificare_in_hexagon(const sf::Vector2f& point, const std::vector<sf::Vector2f>& vertices) {
    //verificare daca mouse-ul se afla in interiorul hexagonului
    //este folosit algoritmul "Ray-Casting"

    bool inside = false;

    for (size_t i = 0, j = vertices.size() - 1; i < vertices.size(); j = i++) {
        if (((vertices[i].y > point.y) != (vertices[j].y > point.y)) &&
            (point.x < (vertices[j].x - vertices[i].x) * (point.y - vertices[i].y) / (vertices[j].y - vertices[i].y) + vertices[i].x)) {
            inside = !inside;
        }
    }

    return inside;
}
