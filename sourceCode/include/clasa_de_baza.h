#pragma once

#include "functii_draw.h"
#include "functionalitati.h"

using namespace sf;

class template_pagini
{
public:
    std::string mesaj_eroare;

    bool eroare;

    sf::RenderTexture renderTexture;

    sf::Sprite sprite;

    Text text;

    sf::Font font;

    Texture background;

    int id_pagina;

    std::wstring project_director;

public:

    virtual bool verificare_erori()
    {
        return eroare;
    }

    virtual std::string descriere_eroare()
    {
        return mesaj_eroare;
    }

    virtual void reset_id_pagine()=0;

    virtual int returen_id_pagine()
     {
         return id_pagina;
     };
    virtual void set_project_director(const std::wstring dir)
    {
        this->project_director=dir;
        wcout<<project_director<<'\n';
    }

};



class template_pagini_secundare:public template_pagini
{
protected:
    Texture poz_rotatie[10];
    //id-uri pentru mesajele de eroare
    bool id_insertie_invalida,id_locatie_invalida,id_operatie_nereusita,id_operatie_reusita;

    //deplasamentul pozitiei sagetii de download
    int poz_sag;

    //id pentru pozitie butonului de youtube, dreapta jos(0-8)
    int id_rotatie;

    //destinatia fisierului de decarcat
    std::string locatie_choose;

    //variabile pentru verificarea corectudinii lik-ului de descarcare si al destinatiei
    bool id_text_box_1,id_text_box_2;

    bool rotire;

    //cele 2 etape ale dreptunghiului mare
    Texture drept_1;

    //cele 2 etape ale dreptunghiului de exit
    Texture drept_ex_1, drept_ex_2,sag_ex;

    //cele 2 ale butonului Download
    Texture sub_1, sub_2;

    Texture ch_1, ch_2;
    //textutra sageata
    Texture sag;

    //textura cutie erori
    Texture error_box_1,error_box_2;

    //variabila pnetru procesul de decarcare al videoclipuluim true==se descarca, false==nu se descarca
    bool operatie_in_progres ;
public:
   virtual Sprite desenare(float width, float height, sf::Vector2i mousePos,const tgui::TextArea::Ptr& editBox1,const tgui::TextArea::Ptr& editBox2,Event event)=0;
    virtual  void resetare_valori(const tgui::TextArea::Ptr& editBox1,const tgui::TextArea::Ptr& editBox2)=0;
void reset_id_pagine() override
{
    id_pagina=0;
}
};



