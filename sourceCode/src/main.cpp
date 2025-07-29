#define NOMINMAX
#include "fereastra_principala.h"
#include "fereastra_download_video.h"
#include "fereastra_download_audio.h"
#include "fereastra_webm_to_mp4.h"
#include "fereastra_mp4_to_mp3.h"
#include "fereastra_mp3_to_wav.h"
#include "functionalitati.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //obtinem directorul curent unde se afla aplicatia
    wstring project_dir = fs::current_path().wstring();
    string cmd=SOURCE_ROOT;
    cmd=cmd+"\\buildTool";

    init_project_directory(std::wstring(cmd.begin(), cmd.end()));

    //obtinem dimensiunile ecranului dispozitivului curent
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    unsigned int screenWidth = desktop.width;
    unsigned int screenHeight = desktop.height;

    //scale-ul ferestrei in functie de dispozitiv
   float scale_x=(float)screenWidth/1920.f;
    float scale_y=(float)screenHeight/1080.f;

    float scale_mouse_x=1;
    float scale_mouse_y=1;

    //seteaza programul pentru a folosi caractere unicode
    std::locale::global(std::locale(""));

    //id pagini
    int id_ferestre=0;

    //initializare fereastra
    RenderWindow window(sf::VideoMode((unsigned int)(1300*scale_x), (unsigned int)(850*scale_y)), "Video Converter");

    //incarcare iconita aplicatie
    Image icon;
    if (!icon.loadFromFile(project_dir+"/assets/Media/Pagina_principala/iconita_4.png"))
    {

        MessageBox(nullptr, "Eroare la incarcarea iconitei!", "Eroare", MB_ICONERROR | MB_OK);
        return -1;
    }

    //setare iconita
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //setarea ferestrei paginii pe mijlocul ecranului
    window.setPosition(
            sf::Vector2i(
                    static_cast<int>((static_cast<float>(desktop.width) - 1300.f * scale_x) / 2.f),
                    static_cast<int>((static_cast<float>(desktop.height) - 850.f * scale_y) / 2.f)
            )
    );


    //setare frame-uri aplicati, fiind o aplicatie cu putine evenimente pe ecran, se pot pune mai putine frame uri
    window.setFramerateLimit(60);

    //pagini
    pagina_principala p1(project_dir);
//p1.set_project_director(project_dir);
    pagina_download_video p2(project_dir);
    //p2.set_project_director(project_dir);

    pagina_webm_to_mp4 p3(project_dir);
   // p3.set_project_director(project_dir);

    pagina_download_audio p4(project_dir);
   // p4.set_project_director(project_dir);

    pagina_mp4_to_mp3 p5(project_dir);
   // p5.set_project_director(project_dir);

    pagina_mp3_to_wav p6(project_dir);

    //p6.set_project_director(project_dir);

    //interfata grafica pentru text box uri
    tgui::Gui gui1(window),gui2(window);

    // creare text box uri
    auto editBox_1 =  tgui::TextArea::create();
    auto editBox_2 =  tgui::TextArea::create();
    
    editBox_1->setPosition((252+126+36)*scale_x, (333+45+3)*scale_y);
    editBox_2->setPosition((252+126+36)*scale_x, (558+45+3)*scale_y);

    gui1.add(editBox_1);
    gui2.add(editBox_2);
    
    auto renderer1 = editBox_1->getRenderer();
    auto renderer2 = editBox_2->getRenderer();

    //configurare casete:culoare borduri, text si font
    renderer1->setBorderColor(sf::Color::Black);
    renderer2->setBorderColor(sf::Color::Black);

    renderer1->setTextColor(sf::Color::White);
    renderer2->setTextColor(sf::Color::White);

editBox_1->setTextSize((unsigned int)(24*scale_x));
editBox_2->setTextSize((unsigned int)(24*scale_y));


    sf::Sprite resize_to_scale;
    while (window.isOpen())
    {

        sleep(seconds(0.01));
        window.clear();

        sf::Event event{};

        //verifica evenimentele: de la tastature, sau de la mouse
       if (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               window.close();
           
           gui1.handleEvent(event);
           gui2.handleEvent(event);
               
           while (event.mouseButton.button != sf::Mouse::Left&&window.pollEvent(event))
           {

               if (event.type == sf::Event::Closed)
                   window.close();

               gui1.handleEvent(event);
               gui2.handleEvent(event);

           }

      }

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
       
       scale_mouse_x=((float)window.getSize().x/(1300.f));
        scale_mouse_y=((float)window.getSize().y/(850.f));
        
        mousePosition.x=static_cast<int>(static_cast<float>(mousePosition.x)/scale_mouse_x);
        mousePosition.y=static_cast<int>(static_cast<float>(mousePosition.y)/scale_mouse_y);


        if(id_ferestre==0) {
            //se verifica daca s-a produs o eroare la desenarea paginii principala
            //in special la incarcarea imaginilor(lipsesc sau calea catre ele este gresita)
            //iar in caz contrat(nu exista erori), se incarca pagina
            if (p1.verificare_erori() )
            {
                //returneaza erorile aplicatie
                MessageBox(nullptr, p1.descriere_eroare().c_str(), "Eroare", MB_ICONERROR | MB_OK);
                return -1;
            }
            else {

                resize_to_scale=(p1.desenare(1300, 850, mousePosition,event) );
                
                //se modifica id-ul paginii in caz de a fost apasat pe o optiune(pe un hexagon)
                id_ferestre=p1.returen_id_pagine();
                
                //defocusam casetele de text
                if(id_ferestre!=0)
                {

                    editBox_1->setFocused(false);
                    editBox_2->setFocused(false);

                }
                
                p1.reset_id_pagine();
            }
        }
        else
        if(id_ferestre==1)
        {
            if (p2.verificare_erori())
            {
                MessageBox(nullptr, p2.descriere_eroare().c_str(), "Eroare", MB_ICONERROR | MB_OK);
                return -1;
            }
            else {
                resize_to_scale=(   (p2.desenare(1300, 850, mousePosition,editBox_1,editBox_2,event) ));
                
                id_ferestre=p2.returen_id_pagine();
                
                p2.reset_id_pagine();
            }
        }
        else
        if(id_ferestre==2)
        {
            if (p3.verificare_erori())
            {
                MessageBox(nullptr, p3.descriere_eroare().c_str(), "Eroare", MB_ICONERROR | MB_OK);
                return -1;
            }
            else {
                resize_to_scale=(   (p3.desenare(1300, 850, mousePosition,editBox_1,editBox_2,event) ));
                
                id_ferestre=p3.returen_id_pagine();
                
                p3.reset_id_pagine();
            }
        }
        else
        if(id_ferestre==3)
        {
            if (p4.verificare_erori() )
            {
                MessageBox(nullptr, p4.descriere_eroare().c_str(), "Eroare", MB_ICONERROR | MB_OK);
                return -1;
            }
            else {
                resize_to_scale=(   (p4.desenare(1300, 850, mousePosition,editBox_1,editBox_2,event) ));
                
                id_ferestre=p4.returen_id_pagine();
                
                p4.reset_id_pagine();
            }
        }
        else
        if(id_ferestre==4)
        {
            if (p5.verificare_erori())
            {
                MessageBox(nullptr, p5.descriere_eroare().c_str(), "Eroare", MB_ICONERROR | MB_OK);
                return -1;
            }
            else {
                resize_to_scale=(   (p5.desenare(1300, 850, mousePosition,editBox_1,editBox_2,event) ));
                
                id_ferestre=p5.returen_id_pagine();
                
                p5.reset_id_pagine();
            }
        }
        else
        if(id_ferestre==5)
        {
            if (p6.verificare_erori() )
            {
                MessageBox(nullptr, p6.descriere_eroare().c_str(), "Eroare", MB_ICONERROR | MB_OK);
                return -1;
            }
            else {
                resize_to_scale=(   (p6.desenare(1300, 850, mousePosition,editBox_1,editBox_2,event) ));
                
                id_ferestre=p6.returen_id_pagine();
                
                p6.reset_id_pagine();
            }
        }
        else
        {
        return -1;
        }

        resize_to_scale.setScale(scale_x,scale_y);
        window.draw(resize_to_scale);
            if(id_ferestre!=0)
        {
            //modificam configuratia casetelor de text in functie de dimensiunea ferestrei  
            editBox_1->setPosition((252+126+36)*scale_mouse_x, (333+45+3)*scale_mouse_y);
            editBox_2->setPosition((252+126+36)*scale_mouse_x, (558+45+3)*scale_mouse_y);

      editBox_1->setTextSize((unsigned int)(24*(scale_mouse_x+scale_mouse_y)/2));
editBox_2->setTextSize((unsigned int)(24*(scale_mouse_x+scale_mouse_y)/2));

            
            scaleGUI(gui1, scale_mouse_x, scale_mouse_y);
            scaleGUI(gui2,scale_mouse_x, scale_mouse_y);
            
            //desenam casetele de text 
            gui1.draw();
            gui2.draw();
}

        window.display();

    }
    return 0;
}