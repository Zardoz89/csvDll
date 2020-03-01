/*****************************************************************************/
/**                 Lector de ficheros CSV para DIV2                        **/
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Tipos de tama�o predeterminado */
#if __STDC_VERSION__ >= 199901L
#include <stdint.h>
#else
#include "myint.h"
#endif

#include "csv.h"

#define GLOBALS
#include "div.h"

INIT_LOG();

#define BUFFER_SIZE 256
#define VALUE_SEPARATOR ";"
#define VALUE_SEPARATOR_WITH_EOL ";\r\n"

void dropBufferFrom(char *buf,char dropCharacter);
void tokenizeLine(char *buf, uint_32_t offset, uint_32_t numberOfElements, uint_32_t *index);
void putValue(const char *token, uint_32_t offset, uint_32_t index);

/**
 * Elimina del buf todo el contenido posterior a un caracter si este est?
 * presente
 * @param buf Ptr. al buf
 * @param dropCharacter Caracter a buscar el punto desde donde eliminar
 */
void dropBufferFrom(char *buf,char dropCharacter)
{
  char* position = strchr(buf, dropCharacter);
  if (position != NULL) {
    // Insertamos un caracter nulo en dicha posici�n para "cortar" la cadena por ahi
    *position = 0;
  }
}

/**
 * Tokeniza el buf usando el separador ';' y procesa cada token
 * @param buf Ptr. al buf
 * @param offset Offset del array de Ints de DIV
 * @param numberOfElements N? maximo de elementos del array
 * @param *index Indice del elemento del array a guardar
 */
void tokenizeLine(char *buf, uint_32_t offset, uint_32_t numberOfElements, uint_32_t *index)
{
  const char* token = strtok(buf, VALUE_SEPARATOR);
  while (*index < numberOfElements && token != NULL && *token != 0) {
    putValue(token, offset, *index);
    token = strtok(NULL, VALUE_SEPARATOR_WITH_EOL);
    // El indice lo aumentamos desde aqui para contar solo los tokens validos
    *index = *index + 1;
  }
}

/**
 * Mete un valor int 32 en la memoria de DIV
 */
void putValue(const char *token, uint_32_t offset, uint_32_t index)
{
  int_32_t val = 0;
  if (token != NULL) {
    val = atoi(token);

    // mem es un array de int_32_t con toda la memoria del programa DIV
    // si DIV2 esta compactando cuando el tipo del array es byte o word, entonces
    // habra que hacer magia con punteros
    mem[offset + index] = val;
  }
}

// Importante: Para cada funci�n se debe indicar el retval(int), y hacer
// siempre un getparm() por cada par metro de llamada (el retval() es
// imprescindible incluso si la funci?n no necesita devolver un valor).

// Funci�n DIV readCSVToArray(fileName ,offset array, numberOfElements)
void readCSVToIntArray() {
  char* fileName = NULL;
  FILE *file = NULL;
  char buf[BUFFER_SIZE];
  int error = 0;
  uint_32_t index = 0;

  OPEN_LOG();

  // Los par�metros se leen en el orden inverso en que se declaran, al
  // provenir del stack del interprete de DIV
  int numberOfElements = getparm();
  int offset = getparm();
  int offsetFileName = getparm();

  // Obtenermos el texto en el array, a partir del bloque de textos + el offset que nos pasa DIV
  fileName = (char *)&mem[text_offset + offsetFileName];

  LPRINTF("CSV: nElem = %d\n", numberOfElements);
  LPRINTF("CSV: offset = %d\n", offset);
  LPRINTF("CSV: fileName = %s\n", fileName);

  memset(buf, 0, BUFFER_SIZE * sizeof(char));

  file = div_fopen(fileName, "r");
  if (file != NULL) {
    LPRINT("CSV: fopen\n");
    while (index < numberOfElements && fgets(buf, BUFFER_SIZE-1, file ) != NULL) {
      dropBufferFrom(buf, '\r');
      dropBufferFrom(buf, '\n'); // Purgar fin de linea CRLF o LF
      dropBufferFrom(buf, '#'); // Comentarios
      LPRINTF("CSV: buf=%s\n", buf);
      tokenizeLine(buf, offset, numberOfElements, &index);
    }
    div_fclose(file);
  } else {
    LPRINT("CSV: file not opened or found\n");
    retval(-1);
    return;
  }

  LPRINTF("CSV: index=%d\n", index);
  CLOSE_LOG();

  retval(index);
}

void __export divlibrary(LIBRARY_PARAMS) {
  //          Nombre en DIV,      ptr a funci�n,     n� de par�metros
  COM_export("readCSVToIntArray", readCSVToIntArray, 3);
}

void __export divmain(COMMON_PARAMS) {
  GLOBAL_IMPORT();
}
/* vim: set ts=2 sw=2 tw=0 et fileencoding=cp858 :*/