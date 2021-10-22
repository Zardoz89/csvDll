/*****************************************************************************/
/**                      Funciones visibles por Gemix                       **/
/*****************************************************************************/


#include "csv.h"

// csv_readToInt32Array(S, I32P, I) , "I"
GMXvoid GMXEXT_CSV_readToInt32Array() {
  GMXint maxSize = GMXAPI_ParamGetInt32();
  maxSize *= GMXAPI_System_GetSizeOfBase(); // Adapta el valor de maxSize en función si SIZEOF es cstyle o div style
  maxSize = maxSize > 0 ? maxSize -1 : 0;

  GMXint32* arrayPtr = GMXAPI_ParamGetInt32Ptr();
  GMXuint8* fileName = GMXAPI_ParamGetString();

  LOG("CSV\n");
  LOGF("CSV: fileName = %s\n", fileName);
  LOGF("CSV: maxElements = %ld\n", maxSize);
  LOGF("CSV: ptr = %p\n", arrayPtr);

  char buf[BUFFER_SIZE];
  memset(buf, 0, BUFFER_SIZE * sizeof(char));

  GMXFile* gmxFile = GMXAPI_System_FileOpen(fileName, GMXAPI_OPEN_READ, GMXAPI_OPENMODE_TEXT, nullptr);
  //GMXFile file =*(*OpenFile            )(const GMXchar *file, GMXint mode, GMXint openmode, const GMXchar *password);

  GMXint numberOfElements = parseCsvFile(gmxFile, arrayPtr, maxSize);

  LOGF("CSV: elementsInFile = %ld\n", numberOfElements);

  GMXAPI_System_FileClose(gmxFile);
  GMXAPI_ReturnInt(numberOfElements);
}


/* vim: set ts=2 sw=2 tw=0 et fileencoding=utf-8 :*/
