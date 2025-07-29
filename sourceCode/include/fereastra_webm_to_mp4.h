#pragma once
#include "functii_draw.h"
#include "functionalitati.h"
#include "clasa_de_baza.h"


class pagina_webm_to_mp4:public template_pagini_secundare
{
    wstring locatie_fisier;
public:
    pagina_webm_to_mp4(wstring director);
    Sprite  desenare(float width, float height, sf::Vector2i mousePos,const tgui::TextArea::Ptr& editBox1,const tgui::TextArea::Ptr& editBox2,Event event) override ;
    void resetare_valori(const tgui::TextArea::Ptr& editBox1,const tgui::TextArea::Ptr& editBox2) override;
    void reset_id_pagine() override
    {
        id_pagina=2;
    };
};