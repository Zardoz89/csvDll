/*****************************************************************************/
/**                 Lector de ficheros CSV para DIV2                        **/
/**                                                                         **/
/**              Metodos y macros auxiliares sobre div.h                    **/
/*****************************************************************************/

#ifndef __DIV_AUX_H_
#define __DIV_AUX_H_

#define GLOBALS
#include "div.h"

/**
 * Devuelve el puntero a una cadena de DIV a partir de su offset
 */
#define getDivString(offset) ((char *)&mem[text_offset + offset])


#endif

/* vim: set ts=2 sw=2 tw=0 et fileencoding=cp858 :*/
