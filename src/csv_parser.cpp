/*****************************************************************************/
/**                      Parser simple de CSV                               **/
/*****************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "csv.h"

const char* VALUE_SEPARATOR = ",";
const char* VALUE_SEPARATOR_WITH_EOL = ",\r\n"; // El elemento separador concatenado con EOL

/**
 * Elimina del buf todo el contenido posterior a un caracter si este está presente
 * @param buf Ptr. al buffer de texto. Si es NULL(0), no escribe en él
 * @param dropCharacter Caracter a buscar el punto desde donde eliminar
 */
void dropBufferFrom(char* buf, char dropCharacter);

GMXint parseCsvFileInt32(FILE* file, GMXint32* ptr, GMXint maxSize)
{
  assert(file != NULL);

  char buf[BUFFER_SIZE];
  GMXint index = 0;
  memset(buf, 0, BUFFER_SIZE * sizeof(char));
  while (index < maxSize && fgets(buf, BUFFER_SIZE-1, file) != NULL) {
    dropBufferFrom(buf, '\r');
    dropBufferFrom(buf, '\n'); // Purgar fin de linea CRLF o LF
    dropBufferFrom(buf, '#'); // Comentarios
    LOGF("CSV: buf=%s\n", buf);
    const char* token = strtok(buf, VALUE_SEPARATOR);
    while (index < maxSize && token != NULL && *token != 0) {

      // Recorremos todos los tokens/valores de la linea
      if (ptr != 0) {
        if (token != NULL) {
          GMXint32 val = (GMXint32) strtol(token, NULL, 0);
          ptr[index] = val;
        }
      }
      token = strtok(NULL, VALUE_SEPARATOR_WITH_EOL);
      // El indice lo aumentamos desde aqui para contar solo los tokens validos
      index++;
    }

  }
  return index;
}

GMXint parseCsvFileUInt32(FILE* file, GMXuint32* ptr, GMXint maxSize)
{
  assert(file != NULL);

  char buf[BUFFER_SIZE];
  GMXint index = 0;
  memset(buf, 0, BUFFER_SIZE * sizeof(char));
  while (index < maxSize && fgets(buf, BUFFER_SIZE-1, file) != NULL) {
    dropBufferFrom(buf, '\r');
    dropBufferFrom(buf, '\n'); // Purgar fin de linea CRLF o LF
    dropBufferFrom(buf, '#'); // Comentarios
    LOGF("CSV: buf=%s\n", buf);
    const char* token = strtok(buf, VALUE_SEPARATOR);
    while (index < maxSize && token != NULL && *token != 0) {

      // Recorremos todos los tokens/valores de la linea
      if (ptr != 0) {
        if (token != NULL) {
          GMXuint32 val = (GMXuint32) strtoul(token, NULL, 0);
          ptr[index] = val;
        }
      }
      token = strtok(NULL, VALUE_SEPARATOR_WITH_EOL);
      // El indice lo aumentamos desde aqui para contar solo los tokens validos
      index++;
    }

  }
  return index;
}

void dropBufferFrom(char *buf,char dropCharacter)
{
  char* position = strchr(buf, dropCharacter);
  if (position != NULL) {
    // Insertamos un caracter nulo en dicha posición para "cortar" la cadena por ahi
    *position = 0;
  }
}

/* vim: set ts=2 sw=2 tw=0 et fileencoding=utf-8 :*/
