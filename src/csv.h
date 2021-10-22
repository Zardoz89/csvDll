/*****************************************************************************/
/**                 Lector de ficheros CSV para GEMIX                       **/
/*****************************************************************************/

#ifndef __CSV_H_
#define __CSV_H_

#define GMXUSE_GRAPHICSENGINE_HARDWARE 0
#include "GemixSDK.h"

#include "csv_funcs.h"
#include "csv_parser.h"

#define BUFFER_SIZE 256
#define EOL "\r\n"


// Macros para la generación del log de CSV
#ifdef CSV_DEBUG

#include <stdio.h>

#define LOG(STR) \
  fprintf(stderr, STR)

#define LOGF(STR, VAL) \
  fprintf(stderr, STR, VAL)

#else

#define LOG(STR)
#define LOGF(STR, VAL)

#endif

#endif /* __CSV_H_ */
/* vim: set ts=2 sw=2 tw=0 et fileencoding=utf-8 :*/
