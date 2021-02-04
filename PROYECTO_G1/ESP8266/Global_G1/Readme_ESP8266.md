Programa Asignatura INFORMATICA INDUSTRIAL Grupo1
 Codigo ESP8266
 Version V.0.0.01a
 Fecha de creacion: 28/11/2020
 



Version 0.0.01alpha del código perteneciente al ESP8266

Changelog:
*0.0.0.02alpha:
             
            07- Configuracion de LW en formato correcto 
            06- Formateo de datos en Json "correcto"
            05- Conexion mqtt al servidor designado iot.uma...
            04- Solucionado bug 00, ahora utiliza la libreria ArduinoJson para todo el proyecto
            03- Añadida configuracion de wifi desde un terminal (ej. movil) 

*0.0.0.01alpha:
             
             
             02-Añadidas las nuevas funciones para la estructura datos (chipId, SwitchState)
             01-Código repartido en .cpp en clasificado por funcionalidades (Global, Config, Datos, Fota, Mqtt, Wifi)
             00-Código perteneciente al ejercicio TAREA GRUPAL CON FOTA

KnowBugs:

    *0.0.0.01alpha:
                 00-Utiliza las dos librerias json (Cambiar la funcion SerializaDatosJSON_2 => Para que haga uso de la libreria "ArduinoJson" en lugar de "Arduino_JSON")
    
    *0.0.0.02alpha:
                 01-Hacer los topics configurables desde la pestaña "config.cpp"             
                 
                 
                              
