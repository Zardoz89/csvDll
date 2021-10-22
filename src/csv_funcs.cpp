/*****************************************************************************/
/**                      Funciones visibles por Gemix                       **/
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "csv.h"

// csv_readToIntArray(S, IP, I) , "I"
GMXvoid GMXEXT_CSV_readToIntArray() {
  GMXint numberOfElements = GMXAPI_ParamGetInt();
  GMXint* arrayPtr = GMXAPI_ParamGetIntPtr();
  GMXuint8* fileName = GMXAPI_ParamGetString();

  fprintf(stderr, "CSV: fileName = %s\n", fileName);
  fprintf(stderr, "CSV: nElem = %d\n", numberOfElements);
  fprintf(stderr, "CSV: offset = %p\n", arrayPtr);

  //LPRINTF("CSV: nElem = %d\n", numberOfElements);
  //LPRINTF("CSV: offset = %d\n", (int)offset);
  //LPRINTF("CSV: fileName = %s\n", fileName);

  char buf[BUFFER_SIZE];
  memset(buf, 0, BUFFER_SIZE * sizeof(char));

  //GMXFile* gmxFile = GMXAPI_System_FileOpen(fileName, GMXAPI_OPEN_READ, GMXAPI_OPENMODE_TEXT, nullptr);
	//GMXFile file =*(*OpenFile            )(const GMXchar *file, GMXint mode, GMXint openmode, const GMXchar *password);

  //GMXAPI_System_FileClose(gmxFile);
  GMXAPI_ReturnInt(0);
}


/* vim: set ts=2 sw=2 tw=0 et fileencoding=utf-8 :*/
