# Codigo-Proyecto
CODIGO HERE

anton@DESKTOP-IQA2H53 MINGW64 ~
$ ls
PCBENV/  cdssetup/

anton@DESKTOP-IQA2H53 MINGW64 ~
$ cd PCBENV

anton@DESKTOP-IQA2H53 MINGW64 ~/PCBENV
$ ls
allegro.ini  license_cache_allegro_17.2-2016.txt

anton@DESKTOP-IQA2H53 MINGW64 ~/PCBENV
$ cd:
bash: cd:: command not found

anton@DESKTOP-IQA2H53 MINGW64 ~/PCBENV
$ cd ::
bash: cd: ::: No such file or directory

anton@DESKTOP-IQA2H53 MINGW64 ~/PCBENV
$ cd c:

anton@DESKTOP-IQA2H53 MINGW64 /c
$ ls
'$Recycle.Bin'/                                PerfLogs/                     devlist.txt     install.res.1028.dll*
 ActiveHDL_SE_x32Setup.log                     Powersim/                     eSupport/       install.res.1031.dll*
 Aldec/                                       'Program Files'/               eula.1028.txt   install.res.1033.dll*
'Archivos de programa'@                       'Program Files (x86)'/         eula.1031.txt   install.res.1036.dll*
 Autodesk/                                     ProgramData/                  eula.1033.txt   install.res.1040.dll*
 BOOTNXT                                       Recovery/                     eula.1036.txt   install.res.1041.dll*
 Boot/                                        'Riot Games'/                  eula.1040.txt   install.res.1042.dll*
 Cadence/                                      SPB_Data/                     eula.1041.txt   install.res.2052.dll*
'DIAL Communication Framework Setup Log.txt'  'System Volume Information'/   eula.1042.txt   install.res.3082.dll*
 Data/                                         Users/                        eula.2052.txt   pagefile.sys
'Documents and Settings'@                      VC_RED.MSI                    eula.3082.txt   rads/
 EES32/                                        VC_RED.cab                    globdata.ini    swapfile.sys
 Finish.log                                    Windows/                      hiberfil.sys    vcredist.bmp
 Intel/                                        Windows.old/                  inetpub/
 MoveGames/                                    Xilinx/                       install.exe*
 My_Designs/                                   bootmgr                       install.ini

anton@DESKTOP-IQA2H53 MINGW64 /c
$ cd Users/

anton@DESKTOP-IQA2H53 MINGW64 /c/Users
$ ls
'All Users'@   Default/  'Default User'@   Public/   anton/   defaultuser0/   desktop.ini

anton@DESKTOP-IQA2H53 MINGW64 /c/Users
$ cd anton/

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton
$ ls
'3D Objects'/                  Music/
 AppData/                      NTUSER.DAT
'Cisco Packet Tracer 6.2sv'/   NTUSER.DAT{fd9a35db-49fe-11e9-aa2c-248a07783950}.TM.blf
'Configuración local'@         NTUSER.DAT{fd9a35db-49fe-11e9-aa2c-248a07783950}.TMContainer00000000000000000001.regtrans-ms
 Contacts/                     NTUSER.DAT{fd9a35db-49fe-11e9-aa2c-248a07783950}.TMContainer00000000000000000002.regtrans-ms
 Cookies@                      OneDrive/
'Datos de programa'@           Pictures/
 Desktop/                      Plantillas@
 Documents/                    Reciente@
 Downloads/                   'Saved Games'/
 Dropbox/                      Searches/
'Entorno de red'@              SendTo@
 EurekaLog/                    Videos/
 Favorites/                   'VirtualBox VMs'/
 Impresoras@                   Xilinx/
 Intel/                        ansel/
 IntelGraphicsProfiles/        java
 Links/                        ntuser.dat.LOG1
'Menú Inicio'@                 ntuser.dat.LOG2
 MicrosoftEdgeBackups/         ntuser.ini
'Mis documentos'@              prueba/

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton
$ cd Desktop/

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop
$ mkdir "Prueba"

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop
$ cd Prueba

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop/Prueba
$ git clone https://github.com/INFORMATICA-INDUSTRIAL-GRUPO-1/Codigo-Proyecto.git
Cloning into 'Codigo-Proyecto'...
remote: Enumerating objects: 3, done.
remote: Counting objects: 100% (3/3), done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
Receiving objects: 100% (3/3), done.

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop/Prueba
$ ls
Codigo-Proyecto/

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop/Prueba
$ cd Codigo-Proyecto

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop/Prueba/Codigo-Proyecto (main)
$ ls
Prueba

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop/Prueba/Codigo-Proyecto (main)
$ vi Prueba2

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop/Prueba/Codigo-Proyecto (main)
$ git add .
warning: LF will be replaced by CRLF in Prueba2.
The file will have its original line endings in your working directory

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop/Prueba/Codigo-Proyecto (main)
$ git commit -m "Esto es una prueba"
Author identity unknown

*** Please tell me who you are.

Run

  git config --global user.email "you@example.com"
  git config --global user.name "Your Name"

to set your account's default identity.
Omit --global to set the identity only in this repository.

fatal: unable to auto-detect email address (got 'anton@DESKTOP-IQA2H53.(none)')

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop/Prueba/Codigo-Proyecto (main)
$ git config --global user.email baddsnake878@gmail.com

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop/Prueba/Codigo-Proyecto (main)
$ git config --global user.name Baddsnake

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop/Prueba/Codigo-Proyecto (main)
$ git commit -m "Esto es una prueba"
[main 80d7774] Esto es una prueba
 1 file changed, 1 insertion(+)
 create mode 100644 Prueba2

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop/Prueba/Codigo-Proyecto (main)
$ git push origin master
error: src refspec master does not match any
error: failed to push some refs to 'https://github.com/INFORMATICA-INDUSTRIAL-GRUPO-1/Codigo-Proyecto.git'

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop/Prueba/Codigo-Proyecto (main)
$ git push origin main
Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Delta compression using up to 4 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 272 bytes | 272.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/INFORMATICA-INDUSTRIAL-GRUPO-1/Codigo-Proyecto.git
   592f133..80d7774  main -> main

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop/Prueba/Codigo-Proyecto (main)
$ git pull origin main
From https://github.com/INFORMATICA-INDUSTRIAL-GRUPO-1/Codigo-Proyecto
 * branch            main       -> FETCH_HEAD
Already up to date.

anton@DESKTOP-IQA2H53 MINGW64 /c/Users/anton/Desktop/Prueba/Codigo-Proyecto (main)
