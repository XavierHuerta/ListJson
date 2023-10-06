# ListJson
ListJason es un pequeño software que al darle la dirección de un directorio por parametro, este revisa los ficheros que se encuentren dentro y los muestra con un formato de tipo Json.

->  Uso : 
  Para poder ejecutar ListJson debes abrir una terminal en la carpeta donde se encuentra el ejecutable.
Deberas ejecutarlo de la siguiente manera:

    ListJson.exe URlDirecotrio

Ejemplo

    ListJson.exe c:\User\Directory

->  Salida : 
  Al ejecutarlo veras una salida de la siguiente forma: 

    { "files": [
      {"name":"texto1.txt","size":450},
      {"name":"texto2.txt","size":950}]
    }
