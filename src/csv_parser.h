/*****************************************************************************/
/**                      Parser simple de CSV                               **/
/*****************************************************************************/
#ifndef __CSV_PARSER_H_
#define __CSV_PARSER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

GMXint parseCsvFileInt8(FILE* file, GMXint8* ptr, GMXint maxSize);
GMXint parseCsvFileUInt8(FILE* file, GMXuint8* ptr, GMXint maxSize);
GMXint parseCsvFileInt16(FILE* file, GMXint16* ptr, GMXint maxSize);
GMXint parseCsvFileUInt16(FILE* file, GMXuint16* ptr, GMXint maxSize);
GMXint parseCsvFileInt32(FILE* file, GMXint32* ptr, GMXint maxSize);
GMXint parseCsvFileUInt32(FILE* file, GMXuint32* ptr, GMXint maxSize);
GMXint parseCsvFileInt64(FILE* file, GMXint64* ptr, GMXint maxSize);
GMXint parseCsvFileUInt64(FILE* file, GMXuint64* ptr, GMXint maxSize);
// GMXint parseCsvFileInt(FILE* file, GMXint* ptr, GMXint maxSize);
// GMXint parseCsvFileUInt(FILE* file, GMXuint* ptr, GMXint maxSize);
// GMXint parseCsvFileLong(FILE* file, GMXlong* ptr, GMXint maxSize);
// GMXint parseCsvFileULong(FILE* file, GMXulong* ptr, GMXint maxSize);
GMXint parseCsvFileFloat(FILE* file, GMXfloat* ptr, GMXint maxSize);
GMXint parseCsvFileDouble(FILE* file, GMXdouble* ptr, GMXint maxSize);

#ifdef __cplusplus
}
#endif

#endif //__CSV_PARSER_H_

/* vim: set ts=2 sw=2 tw=0 et fileencoding=utf-8 :*/
