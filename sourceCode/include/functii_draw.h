#pragma once

#include <TGUI\Widgets\TextArea.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backends/SFML/GuiSFML.hpp>
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include <filesystem>
#include <thread>
#include <windows.h>
#include <shlobj.h>

using namespace sf;
using namespace std;
namespace fs = std::filesystem;


void draw_text(sf::RenderTexture &renderTexture,Text &text,const char *txt,int size,float x,float y);


void draw_text(sf::RenderTexture &renderTexture,Text & text,const char *txt,int size,float x,float y,Color culoare);


void draw_figura(sf::RenderTexture &renderTexture,Text &text,Texture fig,float scale,float poz_x_fig,float poz_y_fig,const char *txt,int size,float x,float y);

void draw_figura(RenderTexture &renderTexture,sf::Text &text,sf::Texture fig,float scale,float poz_x_fig,float poz_y_fig,const char *txt,int size,float x,float y,Color culoare);
