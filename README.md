# Robot Movil Sensorizado controlado y monitorizado mediante IoT
Sensorized Mobile Robot controlled an monitorized through IoT

## Descripción del proyecto
Se ha desarrollado un software que aplica “internet de las cosas” (IOT) como trabajo final de la asignatura de Informática Industrial. Se implementan diferentes tecnologías estudiadas durante el curso. Entre ellas cabe destacar el uso de comunicaciones MQTT, el diseño de flujos Node-RED y la programación en Arduino. 

This IoT software has been developed as the final project for the subject "Informática Industrial". Some technologies studied during the semester work in this project, for example MQTT, Node-RED or Arduino.

## Prerrequisitos Software
Este proyecto necesita para funcionar la ejecución simultánea de código en los siguientes servicios:
  - Node-RED
  - Arduino
  - Matlab2020 (Simulink)

## Prerrequisios Hardware
Existe la posibilidad de ejecutar el código como si solo tuviera la funcionalidad de enviar datos de un sensor de temperatura y humedad (sin robot); en cuyo caso, el hardware mínimo necesarion será:
  - DHT11
  - ESP8266
  
Para ejecutar también la parte del robot, este deberá tener como mínimo las siguientes características:
  - Dos sensores de distancia. Nosotros hemos utilizado dos configuraciones distintas, una con dos sensores láser y otra que añade además, un sensor láser más y dos sensores de ultrasonidos
  - Una placa Arduino MEGA 2560
  - Motores que permitan que el robot se mueva

## Organizacion Proyecto
Se incluye todo el software necesario para hacer funcionar el proyecto. Existen dos versiones del programa Simulink, dependiendo de la cantidad de sensores utilizados
  - Documentos y manuales: Contiene la guía del susuario, la memoria del proyecto, el esquema de conexionado y un par de turoriales.
  - ESP8266/Global_G1 : Contiene el código Arduino. Descargar todo en la misma carpeta y ejecutar Global_G1.ino
  - Node-Red: Contiene los flujos en formato Json. Importar cada uno individualmente
  - PIERO_X_Sensores: Programas Simulink en función del número X de sensores del robot.


## Autores
  - Pablo Roldán Pérez            - https://github.com/Pablo-R-P-G1
  - Manuel Valle Delgado          - https://github.com/ManuelVD
  - Antonio Jesús Pérez Bazuelo   - https://github.com/AntonioJPerez87
  - Pablo Vera Soto               - https://github.com/Pabloski587
  - Mathias Lofeudo Clinckspoor   - https://github.com/m4ttnice
  
  ## Galería
  
![Robot Móvil](/Galería/IMG_20210204_125405.jpg)
![Robot Móvil desde arriba](/Galería/IMG_20210204_130153.jpg)
