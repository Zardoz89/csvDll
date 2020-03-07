/*****************************************************************************/
/**                 Lector de ficheros CSV para DIV2                        **/
/**                                                                         **/
/**              Diccionario simple (no hash) DivString-> int_32_t          **/
/*****************************************************************************/

#ifndef __SDICC_H_
#define __SDICC_H_

#include <stdlib.h>

/* Tipos de tama¤o predeterminado */
#if __STDC_VERSION__ >= 199901L
#include <stdint.h>
#else
#include "myint.h"
#endif

/**
 * Entrada del diccionario, con el par offset String -> valor
 *
 * Equivalente en DIV a :
 * struct
 *  string key;
 *  int value;
 * end
 */
typedef struct {
  int_32_t stringOffset;
  int_32_t value;
} SDiccEntry;

/**
 * Estructura de diccionario simple, usando un array y busqueda lineal
 */
typedef struct {
  const SDiccEntry* entries;
  int_32_t nElements;
} SDicc;

/**
 * Inicializa la estructura de diccionario simple
 *
 * @param sdicc Ptr. a la estructura
 * @param entries Ptr. al array de pares clave->valor provenientes desde DIV
 * @param nElements N§ de elementos en el array
 */
void initSDicc(SDicc* sdicc, const SDiccEntry* entries, const int_32_t nElements);

/**
 * Busca una clave en el diccionario
 * Si el valor no existe, devuelve 0
 *
 * @param sdicc Ptr. a la estructura
 * @param key Cadena clave a buscar
 */
int_32_t sDiccGet(const SDicc* sdicc,const char* const key);

#endif

/* vim: set ts=2 sw=2 tw=0 et fileencoding=cp858 :*/
