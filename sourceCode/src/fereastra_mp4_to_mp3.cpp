#pragma once
#include "fereastra_mp4_to_mp3.h"



pagina_mp4_to_mp3::pagina_mp4_to_mp3(wstring director)
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

    id_pagina=4;

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
    if (!drept_ex_1.loadFromFile(project_director+"/assets/Media/mp4_to_mp3/dreptunghi_exit.png")) {
        mesaj_eroare="Eroare la încărcarea dreptunghiului de exit albastru!\n";
        eroare=true;
    }


    //incarcarcare dreptunghi exit rosu
    if (!drept_ex_2.loadFromFile(project_director+"/assets/Media/mp4_to_mp3/dreptunghi_exit_1.png")) {
        mesaj_eroare="Eroare la încărcarea dreptunghiului de exit rosu!\n";
        eroare=true;
    }


    //incarcarcare sageata exit
    if (!sag_ex.loadFromFile(project_director+"/assets/Media/mp4_to_mp3/sageata_exit.png")) {
        mesaj_eroare="Eroare la încărcarea sagetii de exit!\n";
        eroare=true;
    }


    //incarcarcare dreptunghi mare albastru
    if (!drept_1.loadFromFile(project_director+"/assets/Media/mp4_to_mp3/dreptunghi.png")) {
        mesaj_eroare="Eroare la încărcarea dreptunghiului mare albastru!\n";
        eroare=true;
    }


    //incarcarcare sageata
    if (!sag.loadFromFile(project_director+"/assets/Media/mp4_to_mp3/sageata.png")) {
        mesaj_eroare="Eroare la încărcarea sagetii!\n";
        eroare=true;
    }


    //incarcare logo youtube
    if (!poz_rotatie[0].loadFromFile(project_director+"/assets/Media/mp4_to_mp3/mp3_0.png")) {
        mesaj_eroare="Eroare la incarcare logo mp3_0!\n";
        eroare=true;
    }


    //incarcare logo MP3 1
    if (!poz_rotatie[1].loadFromFile(project_director+"/assets/Media/mp4_to_mp3/mp3_1.png")) {
        mesaj_eroare="Eroare la incarcare logo mp3_1!\n";
        eroare=true;
    }


    //incarcare logo MP3 2
    if (!poz_rotatie[2].loadFromFile(project_director+"/assets/Media/mp4_to_mp3/mp3_2.png")) {
        mesaj_eroare="Eroare la incarcare logo mp3_2!\n";
        eroare=true;
    }


    //incarcare logo MP3 3
    if (!poz_rotatie[3].loadFromFile(project_director+"/assets/Media/mp4_to_mp3/mp3_3.png")) {
        mesaj_eroare="Eroare la incarcare logo mp3_3!\n";
        eroare=true;
    }


    //incarcare logo MP3 4
    if (!poz_rotatie[4].loadFromFile(project_director+"/assets/Media/mp4_to_mp3/mp3_4.png")) {
        mesaj_eroare="Eroare la incarcare logo mp3_4!\n";
        eroare=true;
    }


    //incarcare logo MP3 5
    if (!poz_rotatie[5].loadFromFile(project_director+"/assets/Media/mp4_to_mp3/mp3_5.png")) {
        mesaj_eroare="Eroare la incarcare logo mp3_5!\n";
        eroare=true;
    }


    //incarcare logo MP3 6
    if (!poz_rotatie[6].loadFromFile(project_director+"/assets/Media/mp4_to_mp3/mp3_6.png")) {
        mesaj_eroare="Eroare la incarcare logo mp3_6!\n";
        eroare=true;
    }


    //incarcare logo MP3 7
    if (!poz_rotatie[7].loadFromFile(project_director+"/assets/Media/mp4_to_mp3/mp3_7.png")) {
        mesaj_eroare="Eroare la incarcare logo mp3_7!\n";
        eroare=true;
    }


    //incarcare logo MP3 8
    if (!poz_rotatie[8].loadFromFile(project_director+"/assets/Media/mp4_to_mp3/mp3_8.png")) {
        mesaj_eroare="Eroare la incarcare logo mp3_8!\n";
        eroare=true;
    }


    //incarcare dreptunghi convert albastru
    if (!sub_1.loadFromFile(project_director+"/assets/Media/mp4_to_mp3/submit_1.png")) {
        mesaj_eroare="Eroare la incarcare dreptunghi Download albastru!\n";
        eroare=true;
    }


    //incarcare dreptunghi convert rosu
    if (!sub_2.loadFromFile(project_director+"/assets/Media/mp4_to_mp3/submit_2.png")) {
        mesaj_eroare="Eroare la incarcare dreptunghi Download rosu!\n";
        eroare=true;
    }


    //incarcare dreptunghi choose albastru
    if (!ch_1.loadFromFile(project_director+"/assets/Media/mp4_to_mp3/choose.png")) {
        mesaj_eroare="Eroare la incarcare dreptunghi choose albastru!\n";
        eroare=true;
    }


    //incarcare dreptunghi choose rosu
    if (!ch_2.loadFromFile(project_director+"/assets/Media/mp4_to_mp3/choose_1.png")) {
        mesaj_eroare="Eroare la incarcare dreptunghi choose rosu!\n";
        eroare=true;
    }


    //incarcare fundal
    if (!background.loadFromFile(project_director+"/assets/Media/mp4_to_mp3/background.png")) {
        mesaj_eroare="Eroare la incarcare fundal!\n";
        eroare=true;
    }


    //incarcare cutie de erori simpla
    if (!error_box_1.loadFromFile(project_director+"/assets/Media/mp4_to_mp3/error_box_1.png")) {
        mesaj_eroare="Eroare la incarcare cutiei de erori fara erori!\n";
        eroare=true;
    }


    //incarcare error_box cu erori
    if (!error_box_2.loadFromFile(project_director+"/assets/Media/mp4_to_mp3/error_box.png")) {
        mesaj_eroare="Eroare la incarcare cutiei de erori!\n";
        eroare=true;
    }
}


Sprite pagina_mp4_to_mp3:: desenare(float width, float height, sf::Vector2i mousePos,const tgui::TextArea::Ptr& editBox1,const tgui::TextArea::Ptr& editBox2,Event event) {

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


    editBox1->setDefaultText("Insert the \".mp4\" file here...");
    editBox2->setDefaultText("Insert the destination here...");


    //variabila pentru pozitia mouse ului
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));



    //desenare dreptunghi exit
    if(!(mousePosF.x>=18&&mousePosF.x<=234&&mousePosF.y>=27&&mousePosF.y<=126))
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
                252,27,"     Convert\n"
                       " Mp4 to Mp3",83,252+180-36-9,27+36);

    //mesaj pentru text boxuri
     draw_text(renderTexture,text,"   Please enter the \".mp4\" file in the box below\n"
                   "   (Introdu fisierul \".mp4\" in caseta de mai jos)",29,252+72+18,225+54);
    renderTexture.draw(text);

     draw_text(renderTexture,text,"Please enter the \".mp3\" file destination in the box below\n"
                   " (Introdu destinatia fisierului \".mp3\" in caseta de mai jos)",29,252+45,504);




    //desenare butron de convertire + convertire
    if(!(mousePosF.x>=504&&mousePosF.x<=807&&mousePosF.y>=679&&mousePosF.y<=787))
    {
        draw_figura(renderTexture, text, sub_1, 1,
                    486 + 36-2*18, 670 + 27 + 18-36, "  Convert", 60, 486 + 81-36-9-5, 670 + 31 -9);

        //in caz de am apasat in alta parte, se sterg mesajele de eroare
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
            id_insertie_invalida=false,id_locatie_invalida=false,id_operatie_nereusita=false,id_operatie_reusita=false;
        }

    }
    else
    {
        draw_figura(renderTexture, text, sub_2, 1.2,
                    486 + 36-18-2*18-9, 670 + 27 + 18-18-36, "  Convert", 75, 486 + 81-8-63-5, 670 + 31 -4-18);

        //descarcare audio
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {

            //se verifica daca a inceput convertirea
            if (!operatie_in_progres) {
                operatie_in_progres = true;

                //thread pentru executarea convertirii melodiei in paralel
                std::thread convertThread([&]() {

                    convert_x_to_y(id_text_box_1, id_text_box_2, editBox1, editBox2,L".mp4",L".mp3");

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

                convertThread.detach();


            }

        }
    }

//buton choose de la alegerea fisierului/directorului

    if(!(mousePosF.x>=(279+18)&&mousePosF.x<=(405-18)&&mousePosF.y>=(362+9)&&mousePosF.y<=(434-18)))//45
    {
        draw_figura(renderTexture, text, ch_1, 0.7,
                    252 + 27+18, 378 - 14+9, "Select", 22, 292+18+3, 378+3);
    }
    else
    {

        draw_figura(renderTexture, text, ch_2, 0,
                    252 + 27, 376 - 14, "Select", 35, 292+4, 378-4);
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            //selectare fisier si inserare in text box
            locatie_fisier= selecteazaFisier(".mp4");
            editBox1->setText(locatie_fisier);
        }
    }

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


    //animatia sagetii in timpul convertirii
    if(operatie_in_progres||(poz_sag>7&&poz_sag+198<=507)||rotire)
    {
        draw_figura(renderTexture,text,sag,0,
                    1120,180-18+poz_sag,"",0,0,0);

        if(poz_sag+198>507)
        {
            poz_sag=0;
            rotire=true;
        }
        poz_sag+=7;
    }
    else
    {

        poz_sag=0;
    }

    //imagine youtube, dreapta sus

    draw_figura(renderTexture,text,poz_rotatie[0],0,
                1091 - 18 - 9,27-54,"",0,0,0);

    //rotirea imaginii de MP3 in timpul convertirii (dreapta jos)
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
        else if(id_rotatie>=31&&id_rotatie<36)
        {
            draw_figura(renderTexture, text, poz_rotatie[7], 0,
                        1091 - 18 - 9, 610, "", 0, 0, 0);

        }
        else if(id_rotatie>=36&&id_rotatie<=41)
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


    //afisarea mesujului corespunzator fiecarei erori: fisier inavlid, director invalid, fisier si director invalid, alta eroare
    if(id_operatie_nereusita)

    {
        draw_figura(renderTexture, text, error_box_2, 0,
                    36, 499, "Error box:", 35, 63, 510+72+18,sf::Color::Black);

         draw_text(renderTexture,text,"   Convert\n"
                       "     failed\n"
                       "(Convertire\n"
                       "  nereusita)",30,36+27-5,500+7*18-10+18+18,sf::Color(140,0,0));



    }
    else if(id_locatie_invalida)
    {
        draw_figura(renderTexture, text, error_box_2, 0,
                    36, 499, "Error box:", 35, 63, 510+72+18,sf::Color::Black);
         draw_text(renderTexture,text,"    Invalid\n"
                       "destination\n"
                       "(Destinatie\n"
                       "  invalida)",30,36+27,500+7*18-10+18+18,sf::Color(140,0,0));

    }
    else if(id_insertie_invalida)
    {
        draw_figura(renderTexture, text, error_box_2, 0,
                    36, 499, "Error box:", 35, 63, 510+72+18,sf::Color::Black);
         draw_text(renderTexture,text,"Invalid\n"
                       "   file\n"
                       " (Fisier\n"
                       "invalid)",30,36+27+27,500+7*18-10+18+18,sf::Color(140,0,0));

    }
    else if(id_operatie_reusita)
    {
        draw_figura(renderTexture, text, error_box_2, 0,
                    36, 499, "Error box:", 35, 63, 510+72+18,sf::Color::Black);
         draw_text(renderTexture,text,"   Convert\n"
                       "  successful\n"
                       "(Convertire\n"
                       "    reusita)",30,36+27-5-2,500+7*18-10+18+18,sf::Color(1,90,22));

    }
    else
    {
        draw_figura(renderTexture, text, error_box_1, 0,
                    36, 499, "Error box", 40, 55, 720+18,sf::Color::Black);
    }


//incarcarea si returnarea tuturor modificarilor paginii
    renderTexture.display();
    sprite.setTexture(renderTexture.getTexture());
    return sprite;
}


void pagina_mp4_to_mp3:: resetare_valori(const tgui::TextArea::Ptr& editBox1,const tgui::TextArea::Ptr& editBox2)
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



