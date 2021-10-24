/*****************************************************************************/
/**                      Funciones visibles por Gemix                       **/
/*****************************************************************************/


#include "csv.h"

GMXint getArrayMaxSizeInBytes() {
  /* INT unit_size   (= 4)
   * - values:
   *   byte_unit (1)
   *   int_unit  (4)
   */
  GMXint maxSize = GMXAPI_ParamGetInt();
  maxSize *= GMXAPI_System_GetSizeOfBase(); // Adapta el valor de maxSize en función si SIZEOF es cstyle o div style
  return maxSize;
}

#if GMX_BUILD_32BIT
#define LOG_SIZEOF()      LOGF("CSV: sizeof = %d\n", GMXAPI_System_GetSizeOfBase())
#define LOG_MAX_SIZE()    LOGF("CSV: maxSize = %d\n", maxSize)
#define LOG_N_ELEMENTS()  LOGF("CSV: elementsInFile = %d\n", numberOfElements);
#else
#define LOG_SIZEOF()      LOGF("CSV: sizeof = %ld\n", GMXAPI_System_GetSizeOfBase())
#define LOG_MAX_SIZE()    LOGF("CSV: maxSize = %ld\n", maxSize)
#define LOG_N_ELEMENTS()  LOGF("CSV: elementsInFile = %ld\n", numberOfElements);
#endif

// csv_readToArray(S, I8P, I) , "I"
GMXvoid GMXEXT_CSV_readToInt8Array() {
  GMXint maxSizeBytes = getArrayMaxSizeInBytes();
  GMXint maxSize = maxSizeBytes / sizeof(GMXint8);

  GMXint8* arrayPtr = GMXAPI_ParamGetInt8Ptr();
  GMXuint8* fileName = GMXAPI_ParamGetString();

  LOG("CSV\n");
  LOGF("CSV: fileName = %s\n", fileName);
  LOG_SIZEOF();
  LOG_MAX_SIZE();
  LOGF("CSV: ptr = %p\n", arrayPtr);

  char buf[BUFFER_SIZE];
  memset(buf, 0, BUFFER_SIZE * sizeof(char));

  GMXFile* gmxFile = GMXAPI_System_FileOpen(fileName, GMXAPI_OPEN_READ, GMXAPI_OPENMODE_TEXT, nullptr);
  //GMXFile file =*(*OpenFile            )(const GMXchar *file, GMXint mode, GMXint openmode, const GMXchar *password);

  GMXint numberOfElements = 0;
  if (gmxFile != NULL && gmxFile->f != NULL) {
    LOG("CSV: file is opened.\n");
    numberOfElements = parseCsvFileInt8(gmxFile->f, arrayPtr, maxSize);
  } else {
    LOG("CSV: file not found.\n");
    numberOfElements = -1;
  }

  LOG_N_ELEMENTS();

  GMXAPI_System_FileClose(gmxFile);
  GMXAPI_ReturnInt(numberOfElements);
}

/*
GMXvoid GMXEXT_CSV_readToUInt8Array() {
  GMXint maxSizeBytes = getArrayMaxSizeInBytes();
  GMXint maxSize = maxSizeBytes / sizeof(GMXuint8);

  GMXuint8* arrayPtr = GMXAPI_ParamGetUInt8Ptr();
  GMXuint8* fileName = GMXAPI_ParamGetString();

  LOG("CSV\n");
  LOGF("CSV: fileName = %s\n", fileName);
  LOG_SIZEOF();
  LOG_MAX_SIZE();
  LOGF("CSV: ptr = %p\n", arrayPtr);

  char buf[BUFFER_SIZE];
  memset(buf, 0, BUFFER_SIZE * sizeof(char));

  GMXFile* gmxFile = GMXAPI_System_FileOpen(fileName, GMXAPI_OPEN_READ, GMXAPI_OPENMODE_TEXT, nullptr);

  GMXint numberOfElements = 0;
  if (gmxFile != NULL && gmxFile->f != NULL) {
    LOG("CSV: file is opened.\n");
    numberOfElements = parseCsvFileUInt8(gmxFile->f, arrayPtr, maxSize);
  } else {
    LOG("CSV: file not found.\n");
    numberOfElements = -1;
  }

  LOG_N_ELEMENTS();

  GMXAPI_System_FileClose(gmxFile);
  GMXAPI_ReturnInt(numberOfElements);
}
*/

// csv_readToArray(S, I32P, I) , "I"
GMXvoid GMXEXT_CSV_readToInt32Array() {
  GMXint maxSizeBytes = getArrayMaxSizeInBytes();
  GMXint maxSize = maxSizeBytes / sizeof(GMXint32);

  GMXint32* arrayPtr = GMXAPI_ParamGetInt32Ptr();
  GMXuint8* fileName = GMXAPI_ParamGetString();

  LOG("CSV\n");
  LOGF("CSV: fileName = %s\n", fileName);
  LOG_SIZEOF();
  LOG_MAX_SIZE();
  LOGF("CSV: ptr = %p\n", arrayPtr);

  char buf[BUFFER_SIZE];
  memset(buf, 0, BUFFER_SIZE * sizeof(char));

  GMXFile* gmxFile = GMXAPI_System_FileOpen(fileName, GMXAPI_OPEN_READ, GMXAPI_OPENMODE_TEXT, nullptr);

  GMXint numberOfElements = 0;
  if (gmxFile != NULL && gmxFile->f != NULL) {
    LOG("CSV: file is opened.\n");
    numberOfElements = parseCsvFileInt32(gmxFile->f, arrayPtr, maxSize);
  } else {
    LOG("CSV: file not found.\n");
    numberOfElements = -1;
  }

  LOG_N_ELEMENTS();

  GMXAPI_System_FileClose(gmxFile);
  GMXAPI_ReturnInt(numberOfElements);
}

// csv_readToArray(S, U32P, I) , "I"
GMXvoid GMXEXT_CSV_readToUInt32Array() {
  GMXint maxSizeBytes = getArrayMaxSizeInBytes();
  GMXint maxSize = maxSizeBytes / sizeof(GMXuint32);

  GMXuint32* arrayPtr = GMXAPI_ParamGetUInt32Ptr();
  GMXuint8* fileName = GMXAPI_ParamGetString();

  LOG("CSV\n");
  LOGF("CSV: fileName = %s\n", fileName);
  LOG_SIZEOF();
  LOG_MAX_SIZE();
  LOGF("CSV: ptr = %p\n", arrayPtr);

  char buf[BUFFER_SIZE];
  memset(buf, 0, BUFFER_SIZE * sizeof(char));

  GMXFile* gmxFile = GMXAPI_System_FileOpen(fileName, GMXAPI_OPEN_READ, GMXAPI_OPENMODE_TEXT, nullptr);

  GMXint numberOfElements = 0;
  if (gmxFile != NULL && gmxFile->f != NULL) {
    LOG("CSV: file is opened.\n");
    numberOfElements = parseCsvFileUInt32(gmxFile->f, arrayPtr, maxSize);
  } else {
    LOG("CSV: file not found.\n");
    numberOfElements = -1;
  }

  LOG_N_ELEMENTS();

  GMXAPI_System_FileClose(gmxFile);
  GMXAPI_ReturnInt(numberOfElements);
}

/* vim: set ts=2 sw=2 tw=0 et fileencoding=utf-8 :*/
