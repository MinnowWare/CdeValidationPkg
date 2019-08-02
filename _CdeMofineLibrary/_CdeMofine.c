/*++

Copyright (c) 2018-2019  Kilian Kegel, kilian_kegel@hotmail.com

Module Name:

    _CdeMofine.c

Abstract:

    MOduleFIleliNE trace code

Author:

    Kilian Kegel (kilik) 16-Oct-2017

Environment:

    UEFI Shell

Revision History:
        KILIK20190115_1     modified/extended funcionality for FAT (fatal) -> exit program,
                            and ASS (assert) -> dead loop

--*/
#define  _CRT_SECURE_NO_WARNINGS
#ifndef NMOFINE
#define OS_EFI
#include <CDE.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <limits.h>

int  _gCdeCfgMofine = 0  +MOFINE_NDRIVER/*+MOFINE_NFILE*//*+MOFINE_NLINE*//*+MOFINE_NFUNCTION*//*+MOFINE_NCLOCK*//*+MOFINE_NSTDOUT*//*+*MOFINE_NCLASS*//*+MOFINE_RAWFORMAT*/;
char _gCdeCfgMofineRawSeparator[] = "`";


char **gpszCdeDriverName = NULL;

int _CdeMofine (char** pszDriver, char* pszFile, int nLine, char* pszFunction, char* pszClass, int fTraceEn, char* pszFormat, ...);
int _CdeVMofine(char** pszDriver, char* pszFile, int nLine, char* pszFunction, char* pszClass, int fTraceEn, char* pszFormat, va_list ap);

int _CdeVMofine(char** pszDriver, char* pszFile, int nLine, char* pszFunction, char* pszClass, int fTraceEn, char* pszFormat, va_list ap) {
    int nRet = 0;
    char szLine[16];

    if ((fTraceEn & 1) == 1) {

        char* pszNullClass = pszClass == NULL ? "" : pszClass;

        if (NULL != pszFile) {

            if (1 /*CDE_REMOVEPATHFROMFILENAME*/)
            {
                char* p = pszFile;

                while (*p != '\0')
                {
                    if (*p++ == '\\')
                    {
                        pszFile = p;
                    }
                }

            }

            sprintf(szLine, "%d", nLine);

            if (_gCdeCfgMofine & MOFINE_RAWFORMAT) {
                nRet = _CdeMofine(NULL, NULL, 0, NULL, NULL, 1, "%s%s%s%s%s%s%s%s%010d%s%s%s", *pszDriver, &_gCdeCfgMofineRawSeparator[0],
                    pszFile, &_gCdeCfgMofineRawSeparator[0],
                    szLine, &_gCdeCfgMofineRawSeparator[0],
                    pszFunction, &_gCdeCfgMofineRawSeparator[0],
                    clock(), &_gCdeCfgMofineRawSeparator[0],
                    pszNullClass, &_gCdeCfgMofineRawSeparator[0],
                    &_gCdeCfgMofineRawSeparator[0]
                );
            }
            else {
                if (_gCdeCfgMofine & MOFINE_NCLOCK) {
                    nRet = _CdeMofine(NULL, NULL, 0, NULL, NULL, 1, "%s%s%s%s%s%s%s%s%s", _gCdeCfgMofine & MOFINE_NDRIVER ? "" : *pszDriver,
                        _gCdeCfgMofine & MOFINE_NDRIVER ? "" : " ",
                        _gCdeCfgMofine & MOFINE_NFILE ? "" : pszFile,
                        _gCdeCfgMofine & MOFINE_NLINE ? "" : "(",
                        _gCdeCfgMofine & MOFINE_NLINE ? "" : szLine,
                        _gCdeCfgMofine & MOFINE_NLINE ? "" : ")",
                        _gCdeCfgMofine & MOFINE_NDRIVER ? "" : pszFunction,
                        _gCdeCfgMofine & MOFINE_NDRIVER ? "" : "()",
                        _gCdeCfgMofine & MOFINE_NCLASS ? "" : pszNullClass
                    );
                }
                else {
                    nRet = _CdeMofine(NULL, NULL, 0, NULL, NULL, 1, "%s%s%s%s%s%s%s%s%010d%s%s", _gCdeCfgMofine & MOFINE_NDRIVER ? "" : *pszDriver,
                        _gCdeCfgMofine & MOFINE_NDRIVER ? "" : " ",
                        _gCdeCfgMofine & MOFINE_NFILE ? "" : pszFile,
                        _gCdeCfgMofine & MOFINE_NLINE ? "" : "(",
                        _gCdeCfgMofine & MOFINE_NLINE ? "" : szLine,
                        _gCdeCfgMofine & MOFINE_NLINE ? "" : ")",
                        _gCdeCfgMofine & MOFINE_NDRIVER ? "" : pszFunction,
                        _gCdeCfgMofine & MOFINE_NDRIVER ? "" : "()",
                        //clock(),
                        _gCdeCfgMofine & MOFINE_NCLASS ? "" : " ",
                        _gCdeCfgMofine & MOFINE_NCLASS ? "" : pszNullClass
                    );
                }
            }
        }

        nRet += (int) vfprintf( stderr, pszFormat, ap );

    }//if(fTraceEn == 1;

    if (fTraceEn & MOFINE_EXITONCOND)
        exit(128);

    if (fTraceEn & MOFINE_DEADONCOND) {
        volatile int x = 0;
        while (0 == x)
            ;
    }
    return nRet;

}

int _CdeMofine(char** pszDriver, char* pszFile, int nLine, char* pszFunction, char* pszClass, int fTraceEn, char* pszFormat, ...) {
    int nRet = 0;

    if ((fTraceEn & 1) == 1) {
        va_list ap;

        va_start(ap, pszFormat);

        nRet = _CdeVMofine(pszDriver, pszFile, nLine, pszFunction, pszClass, fTraceEn, pszFormat, ap);

        va_end(ap);

    }//if(fTraceEn == 1;
    return nRet;
}
#endif//ndef NMOFINE
