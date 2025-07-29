#pragma once
#define NOMINMAX
#include <windows.h>
#include <commdlg.h>

#include <utility>

#include "functionalitati.h"
#include <ctime>
#include<time.h>
//directorul aplicatiei
std::wstring project_dir;


//initializare director aplicatie
void init_project_directory(wstring path) {
    project_dir = std::move(path);
}


void scaleGUI(tgui::Gui& gui, float scale_x, float scale_y) {
    for (const auto& widget : gui.getWidgets()) {
        // Ajustează dimensiunea text box
        widget->setSize(widget->getSize().x * scale_x, widget->getSize().y * scale_y);
    }
}


void convert_x_to_y(bool &id_fis, bool &id_dir, const tgui::TextArea::Ptr& editBox1, const tgui::TextArea::Ptr& editBox2, const wchar_t* x_1, const wchar_t* y_1)
{

    std::wstring x=(x_1), y(y_1);

    // Obținem timpul curent
    auto t = std::time(nullptr);
    
    struct tm tm={}; // Structura pentru timpul local

    // Folosim localtime_r (thread-safe)

localtime_s(&tm, &t);

    // Formatăm timpul ca șir de caractere (ora_minut_secunda)
    std::wostringstream  woss;
    woss << std::put_time(&tm, L"_%H%M%S_");
    std::wstring conversion_time = woss.str();

    // Variabile pentru validarea fișierului și a directorului
    std::wstring file_path = editBox1->getText().toWideString();
    std::wstring output_dir = editBox2->getText().toWideString();
    output_dir += L"\\";

    // Verificare corectitudine fișier (dacă este de tip x)
    id_fis = fs::exists(file_path) && fs::is_regular_file(file_path) && file_path.substr(file_path.find_last_of('.')) == x;

    // Verificarea existenței directorului
    id_dir = fs::exists(output_dir) && fs::is_directory(output_dir) && output_dir != L"/";

    // Dacă directorul și fișierul sunt valide, începem conversia
    if (id_dir && id_fis) {

        // Construim numele fișierului de ieșire
        std::wstring output_file = output_dir + fs::path(file_path).stem().wstring() + L"_" + conversion_time + y;

        // Comanda ffmpeg pentru conversie

        std::wstring ffmpeg_path = project_dir + L"/bin/ffmpeg/ffmpeg";
        std::wstring command = L"\"" + ffmpeg_path + L"\" -i \"" + file_path + L"\" \"" + output_file + L"\"";

        // Pregătim structura STARTUPINFO și PROCESS_INFORMATION
        STARTUPINFO si;
        PROCESS_INFORMATION pi;
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);

        // Folosim acest flag pentru a controla vizibilitatea
        si.dwFlags = STARTF_USESHOWWINDOW;
        si.wShowWindow = SW_HIDE;
        ZeroMemory(&pi, sizeof(pi));

        // Creăm un buffer modificabil pentru comanda de proces
        std::vector<wchar_t> cmd(command.begin(), command.end());
        cmd.push_back(0);  // Terminator nullptr pentru șirul de caractere

        // Creăm și executăm procesul
        if (!CreateProcessW(
                nullptr,                 // lpApplicationName
                cmd.data(),           // lpCommandLine (vector modificabil de wchar_t)
                nullptr,                 // lpProcessAttributes
                nullptr,                 // lpThreadAttributes
                FALSE,                // bInheritHandles
                CREATE_NO_WINDOW,                    // dwCreationFlags
                nullptr,                 // lpEnvironment
                nullptr,                 // lpCurrentDirectory
                reinterpret_cast<LPSTARTUPINFOW>(&si),                  // lpStartupInfo
                &pi                   // lpProcessInformation
        )) {


            std::wcerr << L"Eroare la crearea procesului: " << GetLastError() << std::endl;
            id_fis = false; // Conversia a eșuat
            id_dir = false;
            return;
        }

        // Așteptăm terminarea procesului
        WaitForSingleObject(pi.hProcess, INFINITE);

        // Închidem handle-urile
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}


void descarcare_video(bool &id_link,bool &id_dir,const tgui::TextArea::Ptr& editBox1,const tgui::TextArea::Ptr& editBox2)
{

    // Obținem timpul curent
    auto t = std::time(nullptr);

    // Structura pentru timpul local
    struct tm tm={};

    // Folosim localtime_r (thread-safe)
    localtime_s(&tm, &t);
    // Formatăm timpul ca șir de caractere (an_luna_zi_ora_minut_secunda)
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d_%H%M%S");
    std::string download_time = oss.str();

    //variabile pentru validarea link-ului si a directorului
    std::string url=editBox1->getText().toStdString();
    std::string dir=editBox2->getText().toStdString();
    dir+="/";

    //verificare corectitudine link
    id_link=(url.find("https://www.youtube.com/") == 0 || url.find("https://www.youtube.com/") == 0);

    //verificarea existentei videoclipului
    if (fs::exists(dir) && fs::is_directory(dir)&&dir!="/") {

        id_dir = true;  // Directorul există și este valid
    } else {
        id_dir = false; // Directorul nu există sau nu este valid
    }

    //daca link-ul si directorul sunt valide si exista se incepe descarcarea
    if(id_dir==1&&id_link==1) {
        size_t pos = 0;
        while ((pos = url.find('&', pos)) != std::string::npos) {
            url.replace(pos, 1, "^&"); // Escapăm & în Windows
            pos += 2; // Skip ^&
        }
        std::wstring ffmpeg_path = project_dir + L"/bin/ffmpeg/ffmpeg";

        // Comanda yt-dlp cu specificarea locației de salvare
        //std::string command = "C:/youtube-dl/yt-dlp -o \"" + dir + "%(title)s_" + download_time + ".%(ext)s\" \"" + url + "\"";
        std::string dlp_path = (project_dir + R"(\bin\yt-dlp\yt-dlp)");
       std::string command = dlp_path + " -o \"" + dir + "%(title)s_" + download_time + ".webm\" \"" + url + "\"";


        // Execută comanda, si verifica aparitia unei erori
        STARTUPINFO si;
        PROCESS_INFORMATION pi;
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);

        si.dwFlags = STARTF_USESHOWWINDOW; // Folosim acest flag pentru a controla vizibilitatea
        si.wShowWindow = SW_HIDE;
        ZeroMemory(&pi, sizeof(pi));

        // Creăm un buffer modificabil pentru comanda de proces
        std::vector<wchar_t> cmd(command.begin(), command.end());
        cmd.push_back(0);  // Terminator nullptr pentru șirul de caractere

        // Creăm și executăm procesul
        if (!CreateProcessW(
                nullptr,                 // lpApplicationName
                cmd.data(),           // lpCommandLine (vector modificabil de wchar_t)
                nullptr,                 // lpProcessAttributes
                nullptr,                 // lpThreadAttributes
                FALSE,                // bInheritHandles
                CREATE_NO_WINDOW,                    // dwCreationFlags
                nullptr,                 // lpEnvironment
                nullptr,                 // lpCurrentDirectory
                reinterpret_cast<LPSTARTUPINFOW>(&si),                  // lpStartupInfo
                &pi                   // lpProcessInformation
        )) {
            std::wcerr << L"Eroare la crearea procesului: " << GetLastError() << std::endl;
            id_link = false; // Conversia a eșuat
            id_dir = false;
            return;
        }

        // Așteptăm terminarea procesului
        WaitForSingleObject(pi.hProcess, INFINITE);

        // Închidem handle-urile
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}


void descarcare_audio(bool &id_link, bool &id_dir, const tgui::TextArea::Ptr& editBox1, const tgui::TextArea::Ptr& editBox2)
{

    // Obținem timpul curent
    auto t = std::time(nullptr);
    struct tm tm={}; // Structura pentru timpul local

    // Folosim localtime_r (thread-safe)
    localtime_s(&tm, &t);

    // Formatăm timpul ca șir de caractere (an_luna_zi_ora_minut_secunda)
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d_%H%M%S");
    std::string download_time = oss.str();

    // Variabile pentru validarea link-ului și a directorului
    std::string url = editBox1->getText().toStdString();
    std::string dir = editBox2->getText().toStdString();
    dir += "/";

    // Verificare corectitudine link
    id_link = (url.find("https://www.youtube.com/") == 0);

    // Verificarea existenței directorului
    if (fs::exists(dir) && fs::is_directory(dir) && dir != "/") {
        id_dir = true;  // Directorul există și este valid
    } else {
        id_dir = false; // Directorul nu există sau nu este valid
    }

    // Dacă link-ul și directorul sunt valide și există, se începe descărcarea
    if (id_dir == 1 && id_link == 1) {
        size_t pos = 0;
        while ((pos = url.find('&', pos)) != std::string::npos) {
            url.replace(pos, 1, "^&"); // Escapăm & în Windows
            pos += 2; // Skip ^&
        }
        std::wstring ffmpeg_path = project_dir + L"\\bin\\ffmpeg";

        // Comanda yt-dlp pentru descărcarea directă a audio-ului în format MP3
        std::string dlp_path = project_dir + R"(\bin\yt-dlp\yt-dlp)";
        std::string command = dlp_path + " -x --audio-format mp3 --ffmpeg-location \"" + std::string(ffmpeg_path.begin(), ffmpeg_path.end()) + "\" -o \"" + dir + "%(title)s_" + download_time + ".%(ext)s\" \"" + url + "\"";

        STARTUPINFO si;
        PROCESS_INFORMATION pi;
        ZeroMemory(&si, sizeof(si));
        si.cb = sizeof(si);
        si.dwFlags = STARTF_USESHOWWINDOW; // Folosim acest flag pentru a controla vizibilitatea
        si.wShowWindow = SW_HIDE;
        ZeroMemory(&pi, sizeof(pi));

        // Creăm un buffer modificabil pentru comanda de proces
        std::vector<wchar_t> cmd(command.begin(), command.end());
        cmd.push_back(0);  // Terminator nullptr pentru șirul de caractere

        // Creăm și executăm procesul
        if (!CreateProcessW(
                nullptr,                 // lpApplicationName
                cmd.data(),           // lpCommandLine (vector modificabil de wchar_t)
                nullptr,                 // lpProcessAttributes
                nullptr,                 // lpThreadAttributes
                FALSE,                // bInheritHandles
                CREATE_NO_WINDOW,                    // dwCreationFlags
                nullptr,                 // lpEnvironment
                nullptr,                 // lpCurrentDirectory
                reinterpret_cast<LPSTARTUPINFOW>(&si),                  // lpStartupInfo
                &pi                   // lpProcessInformation
        )) {
            std::wcerr << L"Eroare la crearea procesului: " << GetLastError() << std::endl;
            id_link = false; // Conversia a eșuat
            id_dir = false;
            return;
        }

        // Așteptăm terminarea procesului
        WaitForSingleObject(pi.hProcess, INFINITE);

    // Închidem handle-urile
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
}


//fereastra pentru alegerea unui director
std::string selecteazaDirector() {

    // Buffer pentru stocarea căii
    char path[MAX_PATH];

    BROWSEINFO bi = {  };

    bi.lpszTitle = "Selecteaza un director";

    LPITEMIDLIST pidl = SHBrowseForFolder(&bi);

    if (pidl != nullptr) {

        // Convertim de la PIDL la calea completă
        SHGetPathFromIDList(pidl, path);
        IMalloc* imalloc = nullptr;

        if (SUCCEEDED(SHGetMalloc(&imalloc))) {
            imalloc->Free(pidl);
            imalloc->Release();
        }

        // Returnăm calea selectată ca string
        return static_cast<string>(path);
    }

    // Dacă nu a fost selectat nimic, returnăm un string gol
    return "";
}


// Funcție pentru deschiderea ferestrei de selectare a unui fișier

std::wstring selecteazaFisier(const std::string& fileExtension) {

    OPENFILENAMEW ofn;

    wchar_t  szFile[260];

    // owner window
    HWND hwnd = nullptr;

    // Initialize OPENFILENAME
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwnd;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile);

    wchar_t filter[256]=L"Fisiere \""; // Buffer pentru filtre, trebuie să fie suficient de mare

    int i;

    unsigned long long int n=wcslen(filter);

    for( i=0;i<fileExtension.size();i++)
        filter[n+i]=fileExtension[i];

    filter[n+fileExtension.size()]='\"';
    filter[n+fileExtension.size()+1]='\0';
    filter[n+fileExtension.size()+2]='*';

    for( i=0;i<fileExtension.size();i++)
        filter[wcslen(filter)+2]=fileExtension[i];


    ofn.lpstrFilter = filter;
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = nullptr;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = nullptr;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    // Display the Open dialog box
    if (GetOpenFileNameW(&ofn)) {
        // Returnează calea completă a fișierului
        return static_cast<wstring>(ofn.lpstrFile);
    }

    return L"";
}