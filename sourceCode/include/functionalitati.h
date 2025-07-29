#pragma once
#define NOMINMAX
#include <commdlg.h>
#include <cwchar>
#include <cstdlib>
#include <locale>
#include <codecvt>
#include <windows.h>
#include <ctime>
#include <iomanip>
#include <TGUI/TGUI.hpp>
#include <TGUI\Widgets\TextArea.hpp>
#include <TGUI/Backends/SFML/GuiSFML.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <filesystem>
#include <thread>
#include <shlobj.h>

using namespace sf;
using namespace std;

namespace fs = std::filesystem;

void scaleGUI(tgui::Gui& gui, float scale_x, float scale_y);
void init_project_directory(wstring path);

void convert_x_to_y(bool &id_fis, bool &id_dir, const tgui::TextArea::Ptr& editBox1, const tgui::TextArea::Ptr& editBox2, const wchar_t* x_1, const wchar_t* y_1);


void descarcare_video(bool &id_link,bool &id_dir,const tgui::TextArea::Ptr& editBox1,const tgui::TextArea::Ptr& editBox2);


void descarcare_audio(bool &id_link, bool &id_dir, const tgui::TextArea::Ptr& editBox1, const tgui::TextArea::Ptr& editBox2);

std::string selecteazaDirector();

std::wstring selecteazaFisier(const std::string& fileExtension);