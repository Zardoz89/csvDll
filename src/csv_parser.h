/*****************************************************************************/
/**                      Parser simple de CSV                               **/
/*****************************************************************************/
#ifndef __CSV_PARSER_H_
#define __CSV_PARSER_H_

#ifdef __cplusplus
extern "C" {
#endif

GMXint parseCsvFile(const GMXFile* file, GMXint32* ptr, GMXint maxSize);

#ifdef __cplusplus
}
#endif

#endif //__CSV_PARSER_H_

/* vim: set ts=2 sw=2 tw=0 et fileencoding=utf-8 :*/
