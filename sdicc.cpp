/*****************************************************************************/
/**                 Lector de ficheros CSV para DIV2                        **/
/**                                                                         **/
/**              Diccionario simple (no hash) DivString-> int_32_t          **/
/*****************************************************************************/

#include <string.h>

#include "divAux.h"
#include "sdicc.h"

void initSDicc(SDicc* sdicc, const SDiccEntry* entries, const int_32_t nElements)
{
  sdicc->entries = entries;
  sdicc->nElements = nElements;
}

int_32_t sDiccGet(const SDicc* sdicc, const char* const key)
{
  if (key == NULL || sdicc == NULL) {
    return 0;
  }

  // Busqueda lineal clasica
  for (int_32_t i = 0; i < sdicc->nElements ; i++) {
    const char* entryKey = getDivString(sdicc->entries[i].stringOffset);
    if (strcmp(key, entryKey) == 0) {
      return sdicc->entries[i].value;
    }
  }

  return 0;
}


/* vim: set ts=2 sw=2 tw=0 et fileencoding=cp858 :*/
