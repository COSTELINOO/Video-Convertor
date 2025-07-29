#pragma once

#include "fereastra_download_video.h"

pagina_download_video::pagina_download_video(wstring director)
{
    set_project_director(director);

    //setarea valorilor
     id_insertie_invalida=false;

     id_locatie_invalida=false;

     id_operatie_nereusita=false;

     id_operatie_reusita=false;

     poz_sag=0;

     id_text_box_1=false;

     id_text_box_2=false;

     id_rotatie=1;

     rotire=false;

     id_pagina=1;

     eroare=false;

     operatie_in_progres = false;


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

    //incarcarcare dreptunghi exit albastru
    if (!drept_ex_1.loadFromFile(project_director+"/assets/Media/Download_video/dreptunghi_exit.png")) {
        mesaj_eroare="Eroare la încărcarea dreptunghiului de exit albastru!\n";
        eroare=true;
    }


    //incarcarcare dreptunghi exit rosu
    if (!drept_ex_2.loadFromFile(project_director+"/assets/Media/Download_video/dreptunghi_exit_1.png")) {
        mesaj_eroare="Eroare la încărcarea dreptunghiului de exit rosu!\n";
        eroare=true;
    }


    //incarcarcare sageata exit
    if (!sag_ex.loadFromFile(project_director+"/assets/Media/Download_video/sageata_exit.png")) {
        mesaj_eroare="Eroare la încărcarea sagetii de exit!\n";
        eroare=true;
    }


    //incarcarcare dreptunghi mare albastru
    if (!drept_1.loadFromFile(project_director+"/assets/Media/Download_video/dreptunghi.png")) {
        mesaj_eroare="Eroare la încărcarea dreptunghiului mare albastru!\n";
        eroare=true;
    }


    //incarcarcare sageata
    if (!sag.loadFromFile(project_director+"/assets/Media/Download_video/sageata.png")) {
        mesaj_eroare="Eroare la încărcarea sagetii!\n";
        eroare=true;
    }


    //incarcare logo youtube 0
    if (!poz_rotatie[0].loadFromFile(project_director+"/assets/Media/Download_video/youtube_0.png")) {
        mesaj_eroare="Eroare la incarcare logo youtube_0!\n";
        eroare=true;
    }


    //incarcare logo youtube 1
    if (!poz_rotatie[1].loadFromFile(project_director+"/assets/Media/Download_video/youtube_1.png")) {
        mesaj_eroare="Eroare la incarcare logo youtube_1!\n";
        eroare=true;
    }


    //incarcare logo youtube 2
    if (!poz_rotatie[2].loadFromFile(project_director+"/assets/Media/Download_video/youtube_2.png")) {
        mesaj_eroare="Eroare la incarcare logo youtube_2!\n";
        eroare=true;
    }


    //incarcare logo youtube 3
    if (!poz_rotatie[3].loadFromFile(project_director+"/assets/Media/Download_video/youtube_3.png")) {
        mesaj_eroare="Eroare la incarcare logo youtube_3!\n";
        eroare=true;
    }


    //incarcare logo youtube 4
    if (!poz_rotatie[4].loadFromFile(project_director+"/assets/Media/Download_video/youtube_4.png")) {
        mesaj_eroare="Eroare la incarcare logo youtube_4!\n";
        eroare=true;
    }


    //incarcare logo youtube 5
    if (!poz_rotatie[5].loadFromFile(project_director+"/assets/Media/Download_video/youtube_5.png")) {
        mesaj_eroare="Eroare la incarcare logo youtube_5!\n";
        eroare=true;
    }


    //incarcare logo youtube 6
    if (!poz_rotatie[6].loadFromFile(project_director+"/assets/Media/Download_video/youtube_6.png")) {
        mesaj_eroare="Eroare la incarcare logo youtube_6!\n";
        eroare=true;
    }


    //incarcare logo youtube 7
    if (!poz_rotatie[7].loadFromFile(project_director+"/assets/Media/Download_video/youtube_7.png")) {
        mesaj_eroare="Eroare la incarcare logo youtube_7!\n";
        eroare=true;
    }


    //incarcare logo youtube 8
    if (!poz_rotatie[8].loadFromFile(project_director+"/assets/Media/Download_video/youtube_8.png")) {
        mesaj_eroare="Eroare la incarcare logo youtube_8!\n";
        eroare=true;
    }


    //incarcare dreptunghi Download albastru
    if (!sub_1.loadFromFile(project_director+"/assets/Media/Download_video/submit_1.png")) {
        mesaj_eroare="Eroare la incarcare dreptunghi Download albastru!\n";
        eroare=true;
    }


    //incarcare dreptunghi Download rosu
    if (!sub_2.loadFromFile(project_director+"/assets/Media/Download_video/submit_2.png")) {
        mesaj_eroare="Eroare la incarcare dreptunghi Download rosu!\n";
        eroare=true;
    }


    //incarcare dreptunghi choose albastru
    if (!ch_1.loadFromFile(project_director+"/assets/Media/Download_video/choose.png")) {
        mesaj_eroare="Eroare la incarcare dreptunghi choose albastru!\n";
        eroare=true;
    }


    //incarcare dreptunghi choose rosu
    if (!ch_2.loadFromFile(project_director+"/assets/Media/Download_video/choose_1.png")) {
        mesaj_eroare="Eroare la incarcare dreptunghi choose rosu!\n";
        eroare=true;
    }


    //incarcare fundal
    if (!background.loadFromFile(project_director+"/assets/Media/Download_video/background.png")) {
        mesaj_eroare="Eroare la incarcare fundal!\n";
        eroare=true;
    }


    //incarcare cutie de erori simpla
    if (!error_box_1.loadFromFile(project_director+"/assets/Media/Download_video/error_box_1.png")) {
        mesaj_eroare="Eroare la incarcare cutiei de erori fara erori!\n";
        eroare=true;
    }


    //incarcare error_box cu erori
    if (!error_box_2.loadFromFile(project_director+"/assets/Media/Download_video/error_box.png")) {
        mesaj_eroare="Eroare la incarcare cutiei de erori!\n";
        eroare=true;
    }
}


sf::Sprite pagina_download_video:: desenare(float width, float height, sf::Vector2i mousePos,const tgui::TextArea::Ptr& editBox1,const tgui::TextArea::Ptr& editBox2,Event event) {

    renderTexture.clear();

    //incarcare fundal
    Sprite aux;
    aux.setTexture(background);
    renderTexture.draw(aux);

    //configurarea text box urilor
    if(editBox1->isFocused())
    {
        editBox1->setSize(522+54, 50+10);
        editBox1->getRenderer()->setBackgroundColor(sf::Color(110, 0, 35,100)); // Schimbă fundalul cu un roșu semi-transparent
    }
    else {
        editBox1->getRenderer()->setBackgroundColor(sf::Color(20, 42, 121,100));
        editBox1->setSize(522 + 54, 33);

    }

    if(editBox2->isFocused())
    {
        editBox2->setSize(522+54, 50+10);
        editBox2->getRenderer()->setBackgroundColor(sf::Color(110, 0, 35,100)); // Schimbă fundalul cu un roșu semi-transparent

    }
    else {
        editBox2->setSize(522 + 54, 33);

        editBox2->getRenderer()->setBackgroundColor(sf::Color(20, 42, 121,100));

    }


    editBox1->setDefaultText("Insert video link here...");
    editBox2->setDefaultText("Insert the destination here...");


    //variabila pentru pozitia mouse ului
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));



    //desenare dreptunghi exit
    if(!(mousePosF.x>=18&&mousePosF.x<=235&&mousePosF.y>=27&&mousePosF.y<=126))
    {
        draw_figura(renderTexture, text, drept_ex_1, 0,
                    18, 27, "Exit", 70, 90, 30);

        draw_figura(renderTexture, text, sag_ex, 0,
                    30, 54, "", 0, 0, 0);
    }
    else
    {
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            id_pagina=0;
            resetare_valori(editBox1,editBox2);
        }

        draw_figura(renderTexture, text, drept_ex_2, 1.1,
                    18-8, 27-4, "Exit", 70+5, 90-8, 30-4);

        draw_figura(renderTexture, text, sag_ex, 1.1,
                    30-8, 54-4, "", 0, 0, 0);
    }


    //desenare titlu pagina+drepunghi mare
    draw_figura(renderTexture,text,drept_1,0,
                252,27,"     Video\n"
                       "Downloader",83,252+180,27+36);

    //mesaj pentru text boxuri
     draw_text(renderTexture,text,"      Please enter the video link in the box below\n"
                  " (Introdu linkul videoclipului in caseta de mai jos)",31,252+72,225+54);


     draw_text(renderTexture,text," Please enter the video destination in the box below\n"
                  "(Introdu destinatia videoclipului in caseta de mai jos)",31,252+45,504);



    //desenare butron de descarcare + descarcarea videoclipului
    if(!(mousePosF.x>=504&&mousePosF.x<=807&&mousePosF.y>=679&&mousePosF.y<=787))
    {
        draw_figura(renderTexture, text, sub_1, 1,
                    486 + 36-2*18, 670 + 27 + 18-36, "Download", 60, 486 + 81-36-9, 670 + 31 );

       //in caz de am apasat in alta parte, se sterg mesajele de eroare
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
            id_insertie_invalida=false,id_locatie_invalida=false,id_operatie_nereusita=false,id_operatie_reusita=false;
        }

    }
    else
    {
        draw_figura(renderTexture, text, sub_2, 1.2,
                    486 + 36-18-2*18-9, 670 + 27 + 18-18-36, "Download", 75, 486 + 81-8-63, 670 + 31 -4-18);

        //descarcare videoclip
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {

            //se verifica daca a inceput descarcarea
            if (!operatie_in_progres) {
                operatie_in_progres = true;

                //thread pentru executarea descarcarii videoclipului in paralel
                std::thread downloadThread([&]() {

                    descarcare_video(id_text_box_1, id_text_box_2, editBox1, editBox2);

                    operatie_in_progres = false;


                    //erorile returnate dupa finalizarea, nefinalizarea descarcarii(eroare)
                    if(id_text_box_1==0&&id_text_box_2==0)

                    {
                        id_operatie_nereusita=true;
                    }
                    else if(id_text_box_2==0)
                    {
                        id_locatie_invalida=true;
                    }
                    else if(id_text_box_1==0)
                    {
                        id_insertie_invalida=true;
                    }
                    else if(id_text_box_1==1&&id_text_box_2==1)
                    {
                        id_operatie_reusita=true;

                    }

                });

                downloadThread.detach();


            }

        }
    }

//buton youtube rosu din dreptunghiul mare
    draw_figura(renderTexture,text,poz_rotatie[0],0,
                252+27,333+45-14,"",0,0,0);


//buton de choose +fereastra de alegere a directorului pentru descarcare
    if(!(mousePosF.x>=(279+18)&&mousePosF.x<=(405-18)&&mousePosF.y>=(589+9)&&mousePosF.y<=(661-18)))
    {
        draw_figura(renderTexture, text, ch_1, 0.7,
                    252 + 27+18, 603 - 14+9, "Select", 22, 292+18+3, 605+3);
    }
    else
    {

        draw_figura(renderTexture, text, ch_2, 0,
                    252 + 27, 603 - 14, "Select", 35, 292+4, 605-4);
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            //selectare director si inserare in text box
            locatie_choose= selecteazaDirector();
            editBox2->setText(locatie_choose);
        }
    }



        //animatia sagetii in timpul descarcarii
    if(operatie_in_progres||(poz_sag>7&&poz_sag+198<=624)||rotire)
    {
        draw_figura(renderTexture,text,sag,0.f,
                    1120.f,27.0f+(float)poz_sag,"",0,0,0);

        if(poz_sag+198>624)
        {
            poz_sag=0;
            rotire=true;
        }

    }
    else
    {
        draw_figura(renderTexture,text,sag,0,
                    1120,27,"",0,0,0);
        poz_sag=0;
    }
        poz_sag+=7;


    //rotirea imaginii de youtube in timpul descarcarii (dreapta jos)
    if(rotire) {
        id_rotatie++;
        if(id_rotatie>=1&&id_rotatie<6)
        {
            draw_figura(renderTexture, text, poz_rotatie[1], 0,
                        1091 - 18 - 9, 610, "", 0, 0, 0);

        }
        else if(id_rotatie>=6&&id_rotatie<11)
        {
            draw_figura(renderTexture, text, poz_rotatie[2], 0,
                        1091 - 18 - 9, 610, "", 0, 0, 0);

        }
        else if(id_rotatie>=11&&id_rotatie<16)
        {
            draw_figura(renderTexture, text, poz_rotatie[3], 0,
                        1091 - 18 - 9, 610, "", 0, 0, 0);

        }
        else if(id_rotatie>=16&&id_rotatie<21)
        {
            draw_figura(renderTexture, text, poz_rotatie[4], 0,
                        1091 - 18 - 9, 610, "", 0, 0, 0);

        }
        else if(id_rotatie>=21&&id_rotatie<26)
        {
            draw_figura(renderTexture, text, poz_rotatie[5], 0,
                        1091 - 18 - 9, 610, "", 0, 0, 0);

        }
        else if(id_rotatie>=26&&id_rotatie<31)
        {
            draw_figura(renderTexture, text, poz_rotatie[6], 0,
                        1091 - 18 - 9, 610, "", 0, 0, 0);

        }
        else if(id_rotatie>=31&&id_rotatie<38)
        {
            draw_figura(renderTexture, text, poz_rotatie[7], 0,
                        1091 - 18 - 9, 610, "", 0, 0, 0);

        }
        else if(id_rotatie>=38&&id_rotatie<=45)
        {
            draw_figura(renderTexture, text, poz_rotatie[8], 0,
                        1091 - 18 - 9, 610, "", 0, 0, 0);

        }
        else
        {
            draw_figura(renderTexture, text, poz_rotatie[1], 0,
                        1091 - 18 - 9, 610, "", 0, 0, 0);
            id_rotatie=0;
            rotire=false;

        }
    }
    else
        {
            id_rotatie=0;
            draw_figura(renderTexture, text, poz_rotatie[1], 0,
                    1091 - 18 - 9, 610, "", 0, 0, 0);
        }


    //afisarea mesujului corespunzator fiecarei erori: link inavlid, director invali, link si director invalid, alta eroare
    if(id_operatie_nereusita)

    {
        draw_figura(renderTexture, text, error_box_2, 0,
                    36, 499-18, "Error box:", 35, 63, 510+72,sf::Color::Black);

         draw_text(renderTexture,text," Download\n"
                      "      failed\n"
                      "(Descarcare\n"
                      "  nereusita)",30,36+27-5,500+7*18-10+18,sf::Color(140,0,0));



    }
    else if(id_locatie_invalida)
    {
        draw_figura(renderTexture, text, error_box_2, 0,
                    36, 499-18, "Error box:", 35, 63, 510+72,sf::Color::Black);
         draw_text(renderTexture,text,"    Invalid\n"
                      "destination\n"
                      "(Destinatie\n"
                      "  invalida)",30,36+27,500+7*18-10+18,sf::Color(140,0,0));

    }
    else if(id_insertie_invalida)
    {
        draw_figura(renderTexture, text, error_box_2, 0,
                    36, 499-18, "Error box:", 35, 63, 510+72,sf::Color::Black);
         draw_text(renderTexture,text,"Invalid\n"
                      "   link\n"
                      " (Link\n"
                      "invalid)",30,36+27+27,500+7*18-10+18,sf::Color(140,0,0));

    }
    else if(id_operatie_reusita)
    {
        draw_figura(renderTexture, text, error_box_2, 0,
                    36, 499-18, "Error box:", 35, 63, 510+72,sf::Color::Black);
         draw_text(renderTexture,text,"  Download\n"
                      "  successful\n"
                      "(Descarcare\n"
                      "    reusita)",30,36+27-5-2,500+7*18-10+18,sf::Color(1,90,22));

    }
    else
    {
        draw_figura(renderTexture, text, error_box_1, 0,
                    36, 499-18, "Error box", 40, 55, 720,sf::Color::Black);
    }


//incarcarea si returnarea tuturor modificarilor paginii
    renderTexture.display();
    sprite.setTexture(renderTexture.getTexture());
    return sprite;
}


void pagina_download_video:: resetare_valori(const tgui::TextArea::Ptr& editBox1,const tgui::TextArea::Ptr& editBox2)
{
    id_insertie_invalida=false;

    id_locatie_invalida=false;

    id_operatie_nereusita=false;

    id_operatie_reusita=false;

    poz_sag=0;

    id_text_box_1=false;

    id_text_box_2=false;

    id_rotatie=1;

    rotire=false;

    eroare=false;

    operatie_in_progres = false;

    editBox1->setText("");

    editBox2->setText("");
}

