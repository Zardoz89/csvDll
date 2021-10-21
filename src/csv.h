/*****************************************************************************/
/**                 Lector de ficheros CSV para DIV2                        **/
/**                                                                         **/
/**              Macros para la generación del log de CSV                   **/
/*****************************************************************************/

#ifndef __CSV_H_
#define __CSV_H_

#ifdef CSV_DEBUG

#define CSV_LOG_FILE "csv.log"

#define INIT_LOG()  \
  GMXFile* ferr = NULL

#define OPEN_LOG \
  ferr = GMXAPI_System_OpenFile(CSV_LOG_FILE, GMXAPI_OPEN_APPEND, GMXAPI_OPENMODE_TEXT, null);

#define LPRINT(STR) \
  if (ferr != NULL) { \
    fprintf(ferr->f, STR); \
  }

#define LPRINTF(STR, VAL) \
  if (ferr != NULL) { \
    fprintf(ferr->f, STR, VAL); \
  }

#define CLOSE_LOG \
  if (ferr != NULL) { \
    GMXAPI_System_CloseFile(ferr) \
  }

#else

#define INIT_LOG
#define OPEN_LOG
#define LPRINT(STR)
#define LPRINTF(STR, VAL)
#define CLOSE_LOG
#endif


#endif
/* vim: set ts=2 sw=2 tw=0 et fileencoding=utf-8 :*/
