/*****************************************************************************/
/**                 Lector de ficheros CSV para DIV2                        **/
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Tipos de tamaØo predeterminado */
#if __STDC_VERSION__ >= 199901L
#include <stdint.h>
#else
#include "myint.h"
#endif

#include "csv.h"
#include "divAux.h"

INIT_LOG();

#define BUFFER_SIZE 256
#define EOL "\r\n"

/**
 * Tama¤o del tipo de dato
 */
typedef enum {
  BYTE,
  WORD,
  INT
} DataSize;


uint_8_t isValueSeparatorWithEOLFilled = 0; // Flag para saber si ya hemos rellenado valueSeparatorWithEOL
char* valueSeparator = ",";
char valueSeparatorWithEOL[BUFFER_SIZE]; // El elemento separador concatenado con EOL

void dropBufferFrom(char *buf,char dropCharacter);
void tokenizeLine(DataSize dataSize, char *buf, uint_32_t offset, uint_32_t numberOfElements, uint_32_t *index);
void putValueInt(const char *token, uint_32_t offset, uint_32_t index);
void putValueWord(const char *token, uint_32_t offset, uint_32_t index);
void putValueByte(const char *token, uint_32_t offset, uint_32_t index);

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
    // Insertamos un caracter nulo en dicha posici®n para "cortar" la cadena por ahi
    *position = 0;
  }
}

/**
 * Tokeniza el buf usando el separador ';' y procesa cada token
 * @param dataSize Tama¤o del tipo de dato
 * @param buf Ptr. al buf
 * @param offset Offset del array de Ints de DIV
 * @param numberOfElements N? maximo de elementos del array
 * @param *index Indice del elemento del array a guardar
 */
void tokenizeLine(DataSize dataSize, char *buf, uint_32_t offset, uint_32_t numberOfElements, uint_32_t *index)
{
  const char* token = strtok(buf, valueSeparator);
  while (*index < numberOfElements && token != NULL && *token != 0) {
    if (offset != 0) {
      switch (dataSize) {
        case BYTE:
          putValueByte(token, offset, *index);
          break;

        case WORD:
          putValueWord(token, offset, *index);
          break;

        case INT:
        default:
          putValueInt(token, offset, *index);
      }
    }
    token = strtok(NULL, valueSeparatorWithEOL);
    // El indice lo aumentamos desde aqui para contar solo los tokens validos
    *index = *index + 1;
  }
}

/**
 * Mete un valor int 32bits en la memoria de DIV
 */
void putValueInt(const char *token, uint_32_t offset, uint_32_t index)
{
  int_32_t val = 0;
  int_32_t* ptr = &mem[offset];
  if (token != NULL) {
    val = atoi(token);

    // mem es un array de int_32_t con toda la memoria del programa DIV
    // si DIV2 esta compactando cuando el tipo del array es byte o word, entonces
    // habra que hacer magia con punteros
    ptr[index] = val;
  }
}

/**
 * Mete un valor word 16bit en la memoria de DIV
 */
void putValueWord(const char *token, uint_32_t offset, uint_32_t index)
{
  int_16_t val = 0;
  int_16_t* ptr = (int_16_t*) &mem[offset];
  if (token != NULL) {
    val = atoi(token);
    ptr[index] = val;
  }
}

/**
 * Mete un valor byte en la memoria de DIV
 */
void putValueByte(const char *token, uint_32_t offset, uint_32_t index)
{
  int_8_t val = 0;
  int_8_t* ptr = (int_8_t*) &mem[offset];
  if (token != NULL) {
    val = atoi(token);
    ptr[index] = val;
  }
}
// Importante: Para cada funci¢n se debe indicar el retval(int), y hacer
// siempre un getparm() por cada par metro de llamada (el retval() es
// imprescindible incluso si la funci¢n no necesita devolver un valor).

inline void readCSVToArray(DataSize dataSize) {
  char* fileName = NULL;
  FILE *file = NULL;
  char buf[BUFFER_SIZE];
  int error = 0;
  uint_32_t index = 0;

  // Rellenamos valueSeparatorWithEOL de forma lazy
  if (!isValueSeparatorWithEOLFilled) {
    sprintf(valueSeparatorWithEOL, "%s%s", valueSeparator, EOL);
    isValueSeparatorWithEOLFilled = 1;
  }

  OPEN_LOG();

  // Los par metros se leen en el orden inverso en que se declaran, al
  // provenir del stack del interprete de DIV
  int numberOfElements = getparm();
  int offset = getparm();
  int offsetFileName = getparm();

  // Obtenermos el texto en el array, a partir del bloque de textos + el offset que nos pasa DIV
  fileName = getDivString(offsetFileName);

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
      tokenizeLine(dataSize, buf, offset, numberOfElements, &index);
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

// Funci¢n DIV readCSVToIntArray(string fileName ,offset array, numberOfElements)
void readCSVToIntArray() {
  readCSVToArray(INT);
}

// Funci¢n DIV readCSVToWordArray(string fileName ,offset array, numberOfElements)
void readCSVToWordArray() {
  readCSVToArray(WORD);
}

// Funci¢n DIV readCSVToByteArray(string fileName ,offset array, numberOfElements)
void readCSVToByteArray() {
  readCSVToArray(BYTE);
}

// Funci¢n DIV setCSVSeparator(string separator)
void setCSVSeparator() {
  int offsetSeparator = getparm();
  char* divString = getDivString(offsetSeparator);
  size_t stringLenght = strlen(divString);

  if (stringLenght <= 0) {
    retval(-1); // No se ha pasado una cadena valida
    return;
  }

  valueSeparator = divString;
  sprintf(valueSeparatorWithEOL, "%s%s", valueSeparator, EOL);
  isValueSeparatorWithEOLFilled = 1;

  retval(0);
}

void __export divlibrary(LIBRARY_PARAMS) {
  //          Nombre en DIV,      ptr a funci¢n,     n§ de par metros
  COM_export("readCSVToIntArray", readCSVToIntArray, 3);
  COM_export("readCSVToWordArray", readCSVToWordArray, 3);
  COM_export("readCSVToByteArray", readCSVToByteArray, 3);
  COM_export("setCSVSeparator", setCSVSeparator, 1);
}

void __export divmain(COMMON_PARAMS) {
  GLOBAL_IMPORT();
}
/* vim: set ts=2 sw=2 tw=0 et fileencoding=cp858 :*/
