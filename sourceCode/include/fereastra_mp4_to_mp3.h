#pragma once

#include "clasa_de_baza.h"

class pagina_mp4_to_mp3:public template_pagini_secundare
{
    wstring locatie_fisier;
public:
    pagina_mp4_to_mp3(wstring director);
    Sprite  desenare(float width, float height, sf::Vector2i mousePos,const tgui::TextArea::Ptr& editBox1,const tgui::TextArea::Ptr& editBox2,Event event) override ;
    void resetare_valori(const tgui::TextArea::Ptr& editBox1,const tgui::TextArea::Ptr& editBox2) override;
    void reset_id_pagine() override
    {
        id_pagina=4;
    };
};



