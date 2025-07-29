# Documentație Proiect Video Convertor

## Contribuitor
- [COSTELINOO](https://github.com/COSTELINOO)

## Cerința problemei

Să se dezvolte o aplicație desktop care facilitează descărcarea și conversia formatelor media. Aplicația trebuie să permită utilizatorilor să descarce conținut video și audio de pe platforme precum YouTube și să realizeze conversii între diverse formate media populare (WebM, MP4, MP3, WAV) folosind un proces simplificat și o interfață intuitivă. Sistemul trebuie să integreze biblioteci open-source pentru procesarea media și să ofere feedback vizual utilizatorului privind starea operațiunilor.

## Restricții și precizări

- Proiectul va fi evaluat în funcție de complexitatea și utilitatea funcționalităților implementate
- Interfața grafică trebuie să fie intuitivă și prietenoasă, permițând utilizarea aplicației fără cunoștințe tehnice avansate
- Aplicația trebuie să gestioneze erorile și să ofere feedback relevant utilizatorului
- Implementarea trebuie să asigure compatibilitatea cu sistemul de operare Windows

## Build and run

Pentru a rula aplicația, urmați pașii de mai jos:

1. Clonați repository-ul folosind comanda:
   ```
   git clone https://github.com/COSTELINOO/Video-Convertor.git
   ```

2. Navigați în directorul proiectului:
   ```
   cd Video-Convertor
   ```

3. Rulați scriptul `run.bat` făcând dublu-click pe acesta sau folosind comanda:
   ```
   run.bat
   ```


## Videoclip de prezentare

Un videoclip demonstrativ al aplicației este disponibil la următorul link:
[Videoclip de prezentare](https://drive.google.com/file/d/1aQOkc9EcFrQRPZYxmZTGYbTnjTZo2x8p/view?usp=drive_link)

## Capturi de ecran
<img width="1291" height="885" alt="Screenshot 2024-09-21 201404" src="https://github.com/user-attachments/assets/1426a087-c52d-4ee9-9703-233af3383c4c" />
<img width="1290" height="872" alt="Screenshot 2024-09-21 201438" src="https://github.com/user-attachments/assets/4c7a131c-d715-4cb7-bb49-59dbc617a45c" />
<img width="1291" height="887" alt="Screenshot 2024-09-21 201459" src="https://github.com/user-attachments/assets/761f494e-1c68-4d80-baf9-a71d9501ee6d" />
<img width="1290" height="883" alt="Screenshot 2024-09-21 201519" src="https://github.com/user-attachments/assets/92bd8d06-a988-4ebf-b2a6-28b37fd0a007" />
<img width="1288" height="882" alt="Screenshot 2024-09-21 201538" src="https://github.com/user-attachments/assets/7d7cca5f-57f0-4f75-a8d2-f2d318df2f04" />
<img width="1292" height="883" alt="Screenshot 2024-09-21 201600" src="https://github.com/user-attachments/assets/b9946643-2f58-490e-9155-26260e71163d" />

## Descrierea aplicației

Video Convertor este o aplicație desktop dezvoltată în limbajul de programare C++, utilizând compilatorul MinGW (64bit) pentru executarea codului. Aplicația beneficiază de integrarea bibliotecilor SFML și TGUI, asigurând o interfață grafică interactivă și o experiență plăcută pentru utilizatori.

### Tehnologii utilizate

- **C++**: Limbajul principal de programare utilizat pentru dezvoltarea aplicației
- **SFML (Simple and Fast Multimedia Library)**: Bibliotecă grafică multiplatformă pentru C++, ce oferă funcționalități de bază pentru crearea de aplicații multimedia. Aceasta facilitează manipularea graficii 2D și a intrărilor de la utilizator.
- **TGUI (Texus' Graphical User Interface)**: Extensie a bibliotecii SFML, concepută pentru a simplifica crearea interfețelor grafice. Permite gestionarea și afișarea elementelor de interacțiune cu utilizatorul.
- **FFmpeg**: Instrument folosit pentru procesarea, convertirea și manipularea fișierelor audio și video.
- **yt-dlp**: Bibliotecă utilizată pentru descărcarea conținutului de pe platforme video precum YouTube.

### Interfața și navigarea

Aplicația prezintă o interfață principală hexagonală, intuitivă, cu cinci opțiuni diferite de conversie și descărcare, reprezentate prin butoane distincte. Designul este modern, cu elemente interactive care răspund la acțiunile utilizatorului. Navigarea între diferitele secțiuni ale aplicației se face prin selectarea hexagoanelor corespunzătoare funcționalității dorite.

### Funcționalități principale

#### 1. Descărcare video de pe YouTube

Această funcționalitate permite utilizatorilor să descarce videoclipuri de pe YouTube în format WebM.
- Utilizatorul introduce URL-ul videoclipului YouTube în prima casetă de text
- Selectează directorul de destinație pentru videoclipul descărcat folosind butonul "Alege director"
- Inițiază descărcarea apăsând butonul "Descarcă"
- Aplicația oferă feedback vizual privind validitatea link-ului și a directorului de destinație
- După finalizarea descărcării, utilizatorul primește o notificare de succes

#### 2. Descărcare audio de pe YouTube

Permite extragerea și descărcarea doar a componentei audio din videoclipurile YouTube, în format MP3.
- Utilizatorul introduce URL-ul videoclipului YouTube în prima casetă de text
- Selectează directorul de destinație pentru fișierul audio folosind butonul "Alege director"
- Inițiază descărcarea apăsând butonul "Descarcă"
- Aplicația utilizează yt-dlp și FFmpeg pentru a extrage și converti automat componenta audio în format MP3
- Fișierul rezultat include timestamp-ul descărcării în denumire pentru o organizare mai ușoară

#### 3. Conversie WebM la MP4

Această funcționalitate permite conversia fișierelor video din formatul WebM (utilizat frecvent de YouTube) în formatul MP4, mai compatibil cu majoritatea playerelor și dispozitivelor.
- Utilizatorul selectează fișierul WebM sursă folosind butonul "Alege fișier"
- Selectează directorul de destinație pentru fișierul MP4 rezultat
- Inițiază conversia apăsând butonul "Convertește"
- Aplicația validează existența și formatul fișierului sursă
- Utilizează FFmpeg pentru a realiza conversia între formatele video
- Fișierul rezultat primește un sufix cu timestamp pentru identificare facilă

#### 4. Conversie MP4 la MP3

Permite extragerea componentei audio dintr-un fișier video MP4 și salvarea acesteia ca fișier MP3 separat.
- Utilizatorul selectează fișierul MP4 sursă
- Alege directorul de destinație pentru fișierul MP3
- Inițiază extracția apăsând butonul "Convertește"
- Aplicația verifică validitatea fișierului sursă și a directorului de destinație
- Utilizează FFmpeg pentru a extrage și converti componenta audio
- Oferă feedback vizual privind progresul și finalizarea operațiunii

#### 5. Conversie MP3 la WAV

Această funcționalitate permite conversia fișierelor audio din formatul MP3 (comprimat) în formatul WAV (necomprimat), util pentru proiecte de editare audio care necesită calitate maximă.
- Utilizatorul selectează fișierul MP3 sursă
- Alege directorul de destinație pentru fișierul WAV
- Inițiază conversia apăsând butonul "Convertește"
- Aplicația validează fișierul sursă și directorul destinație
- Efectuează conversia folosind FFmpeg
- Afișează mesaje de confirmare sau eroare după finalizarea operațiunii

### Caracteristici suplimentare

#### Scalabilitate automată

Aplicația detectează automat rezoluția ecranului și ajustează dimensiunea interfeței pentru a se adapta optim la dispozitivul utilizatorului, asigurând o experiență consistentă pe orice configurație.

#### Feedback vizual

Interfața oferă feedback vizual pentru toate acțiunile:
- Butonele își schimbă aspectul la hover și click
- Mesaje de eroare sau confirmare afișate direct în interfață
- Indicatori pentru validitatea input-urilor utilizatorului
- Animație pentru butoanele interactive

#### Tratarea erorilor

Aplicația include mecanisme robuste de tratare a erorilor:
- Verificarea validității link-urilor YouTube
- Validarea existenței și permisiunilor directoarelor de destinație
- Verificarea formatelor fișierelor pentru conversie
- Mesaje de eroare detaliate și sugestii pentru rezolvarea problemelor

#### Optimizări pentru performanță

- Operațiile de conversie și descărcare rulează în thread-uri separate pentru a menține interfața responsivă
- Utilizarea eficientă a resurselor sistemului în timpul operațiunilor de procesare media
- Implementarea de mecanisme pentru prevenirea blocării interfeței în timpul operațiunilor de lungă durată

### Structura aplicației

Aplicația este organizată modular, cu pagini dedicate pentru fiecare funcționalitate:
- **Pagina principală**: Interfața hexagonală cu toate opțiunile disponibile
- **Pagina de descărcare video**: Interfață pentru descărcarea videoclipurilor de pe YouTube
- **Pagina de descărcare audio**: Interfață pentru descărcarea componentei audio din videoclipuri YouTube
- **Pagina de conversie WebM la MP4**: Interfață pentru conversia formatelor video
- **Pagina de conversie MP4 la MP3**: Interfață pentru extragerea audio din fișiere video
- **Pagina de conversie MP3 la WAV**: Interfață pentru conversia între formate audio

Fiecare pagină urmează un design consistent, cu:
- Câmpuri de text pentru introducerea input-urilor necesare
- Butoane pentru selectarea fișierelor și directoarelor
- Buton principal pentru inițierea operațiunii
- Buton de revenire la pagina principală
- Zonă de feedback pentru afișarea stării operațiunii

### Concluzii

Video Convertor este o aplicație desktop completă care oferă o soluție intuitivă și eficientă pentru descărcarea și conversia conținutului media. Cu o interfață grafică atractivă și funcționalități bine implementate, aplicația satisface nevoile utilizatorilor care doresc să manipuleze fișiere media fără a necesita cunoștințe tehnice avansate sau utilizarea mai multor programe diferite.

Combinația dintre bibliotecile SFML și TGUI pentru interfața grafică, împreună cu instrumentele FFmpeg și yt-dlp pentru procesarea media, rezultă într-o aplicație robustă și versatilă, capabilă să gestioneze diverse scenarii de conversie și descărcare a conținutului media.
