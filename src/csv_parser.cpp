/*****************************************************************************/
/**                      Parser simple de CSV                               **/
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "csv.h"


/**
 * Elimina del buf todo el contenido posterior a un caracter si este está presente
 * @param buf Ptr. al buf
 * @param dropCharacter Caracter a buscar el punto desde donde eliminar
 */
void dropBufferFrom(char *buf, char dropCharacter);


/**
 * Tokeniza el buf usando el separador ';' y procesa cada token
 * @param dataSize Tama?o del tipo de dato
 * @param buf Ptr. al buf
 * @param offset Offset del array de Ints de DIV
 * @param numberOfElements N? maximo de elementos del array
 * @param *index Indice del elemento del array a guardar
 */
void tokenizeLine(char *buf, GMXint32* ptr, GMXint maxSize, uint32_t *index);

/**
 * Mete un valor int 32bits en la memoria de DIV
 */
void putValueInt32(const char* token, GMXint32* ptr, uint32_t index);

GMXint parseCsvFile(const GMXFile* file, GMXint32* ptr, GMXint maxSize)
{
  char buf[BUFFER_SIZE];
  uint32_t index = 0;
  memset(buf, 0, BUFFER_SIZE * sizeof(char));

  /*
  for (GMXint i = 0; i < maxSize; i++) {
    ptr[i] = i+1;
  }
  */

  if (file != NULL && file->f != NULL) {
    LOG("CSV: file is opened.\n");
    while (index < maxSize && fgets(buf, BUFFER_SIZE-1, file->f ) != NULL) {
      dropBufferFrom(buf, '\r');
      dropBufferFrom(buf, '\n'); // Purgar fin de linea CRLF o LF
      dropBufferFrom(buf, '#'); // Comentarios
      LOGF("CSV: buf=%s\n", buf);
      tokenizeLine(buf, ptr, maxSize, &index);
    }
  } else {
    LOG("CSV: file not found.\n");
  }
  return index;
}

/**
 * Tamaño del tipo de dato
 *
typedef enum {
  DBYTE,
  DWORD,
  DINT
} DataSize;
*/

/*
uint8_t isValueSeparatorWithEOLFilled = 0; // Flag para saber si ya hemos rellenado valueSeparatorWithEOL
*/
const char* valueSeparator = ",";
const char* valueSeparatorWithEOL = ",\r\n"; // El elemento separador concatenado con EOL

void dropBufferFrom(char *buf,char dropCharacter)
{
  char* position = strchr(buf, dropCharacter);
  if (position != NULL) {
    // Insertamos un caracter nulo en dicha posición para "cortar" la cadena por ahi
    *position = 0;
  }
}

void tokenizeLine(char *buf, GMXint32* ptr, GMXint maxSize, uint32_t *index)
{
  const char* token = strtok(buf, valueSeparator);
  while (*index < maxSize && token != NULL && *token != 0) {

    // Recorremos todos los tokens/valores de la linea
    if (ptr != 0) {
      putValueInt32(token, ptr, *index);
    }
    token = strtok(NULL, valueSeparatorWithEOL);
    // El indice lo aumentamos desde aqui para contar solo los tokens validos
    *index = *index + 1;
  }
}

void putValueInt32(const char* token, GMXint32* ptr, uint32_t index)
{
  if (token != NULL) {
    GMXint32 val = (GMXint32) strtol(token, NULL, 0);
    ptr[index] = val;
  }
}

/**
 * Mete un valor word 16bit en la memoria de DIV
 *
void putValueWord(const char *token, uint_32_t offset, uint_32_t index)
{
  int_16_t val = 0;
  int_16_t* ptr = (int_16_t*) &mem[offset];
  if (token != NULL) {
    val = (int_16_t) strtol(token, NULL, 0);
    ptr[index] = val;
  }
}

**
 * Mete un valor byte en la memoria de DIV
 *
void putValueByte(const char *token, uint_32_t offset, uint_32_t index)
{
  int_8_t val = 0;
  int_8_t* ptr = (int_8_t*) &mem[offset];
  if (token != NULL) {
    val = (int_8_t) strtol(token, NULL, 0);
    ptr[index] = val;
  }
}
*/

/* vim: set ts=2 sw=2 tw=0 et fileencoding=utf-8 :*/
