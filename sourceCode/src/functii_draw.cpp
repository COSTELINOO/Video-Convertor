#pragma once
#include "functii_draw.h"

using namespace sf;
using namespace std;
namespace fs = std::filesystem;


void draw_text(sf::RenderTexture &renderTexture,Text &text,const char *txt,int size,float x,float y)
{
   
    //textul
    text.setString(txt);

    //dimensiunea
    text.setCharacterSize(size);

    //culoarea
    text.setFillColor(sf::Color::White);

    //pozitiile
    text.setPosition(x, y);
    //incarcare in textura textul
    renderTexture.draw(text);
}


void draw_text(sf::RenderTexture &renderTexture,Text & text,const char *txt,int size,float x,float y,Color culoare)
{
   
    //textul
    text.setString(txt);

    //dimensiunea
    text.setCharacterSize(size);

    //culoarea
    text.setFillColor(culoare);

    //pozitiile
    text.setPosition(x, y);
    renderTexture.draw(text);
}


void draw_figura(sf::RenderTexture &renderTexture,Text &text,Texture fig,float scale,float poz_x_fig,float poz_y_fig,const char *txt,int size,float x,float y)
{
    //desenem figurii
    Texture figg=fig;
    sf::Sprite sprite_aux(figg);

    if(scale!=0)
        sprite_aux.setScale(scale, scale);

    sprite_aux.setPosition(poz_x_fig, poz_y_fig);
    renderTexture.draw(sprite_aux);


    if(txt!=nullptr)
    {
        //scriem textul pe figura
        draw_text(renderTexture,text,txt,size,x,y);


    }
}


void draw_figura(RenderTexture &renderTexture,sf::Text &text,sf::Texture fig,float scale,float poz_x_fig,float poz_y_fig,const char *txt,int size,float x,float y,Color culoare)
{
    //desenem figurii
    Texture figg=fig;
    sf::Sprite sprite_aux(figg);

    if(scale!=0)
        sprite_aux.setScale(scale, scale);

    sprite_aux.setPosition(poz_x_fig, poz_y_fig);
    renderTexture.draw(sprite_aux);


    if(txt!=nullptr)
    {
        //scriem textul pe figura
        draw_text(renderTexture,text,txt,size,x,y,culoare);

        //incarcare in textura textul
    }
}