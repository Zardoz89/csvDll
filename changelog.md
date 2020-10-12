v0.3.1
 * Se agrega al repositorio, un directorio `dist` con los compilados generados
 * Se pasa a soportar DIV DX.
 * Se usa `extern "C"` para poder compilar una libreria dinamica para DIV DX

v0.3.0

 * Se cambia al carácter `,` como elemento separador.
 * Se agrega la función `setCSVSeparator(string)` para poder cambiar el elemento
     separador desde DIV.
 * Se pasa a usar strtol en vez de atoi. Lo que añade soporte de números en
     base octal y hexadecimal.

v0.2.0

 * Agregada funciones para escribir en arrays de bytes y words de DIV.
     `readCSVToWordArray` y `readCSVToByteArray`

v0.1.0

 * Versión inicial
