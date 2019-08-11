/*!
@copyright

    Copyright (c) 2019, MinnowWare. All rights reserved.
    This program and the accompanying materials are licensed and made
    available under the terms and conditions of the BSD License
    which accompanies this distribution.  The full text of the license
    may be found at

    http://opensource.org/licenses/bsd-license.php

    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
    WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

@file main.c

@brief C Development Environment (CDE)\n
    Validation of all <em>ctype.h</em>-function from the standard C library


@details

@todo

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <CDE.h>

#define COUNT 0x100

//#include <uefi.h>

static char* gszCdeDriverName;

int main(int argc, char** argv) {
    gszCdeDriverName = argv[0];
    int i, c, result;
#define SIZE 2000
    char* pBuffer = malloc(SIZE);
    int count = COUNT;                  // default 0x100

#ifdef WIN64DEBUGBUILD
    for (i = 0; i < argc; i++) {
        int fDebug = 0;

        fDebug = 0 == strcmp("/debug", argv[i]);

        if (1 == fDebug) {
            printf("1. Start Visual Studio\n");
            printf("2. Select MENU->DEBUG->ATTACH TO PROCESS or ALT+CTRL+P\n");
            printf("3. Select the process to be debugged (this particular executable)\n");
            printf("4. go back to the processes command line window and:\n");
            printf("press any key...");
            getchar();
            __debugbreak();
        }
    }
#endif// WIN64DEBUGBUILD
    //
    // get command line parameter
    //
    for (i = 0; i < argc; i++) {

        if (0 == strncmp("/count", argv[i], strlen("/count"))) {
            count = atoi(argv[i + 1]);
        }

    }

    memset(pBuffer, 0, SIZE);
    sprintf(pBuffer, "argc = %d, ", argc);
    for (i = 0; i < argc; i++) {
        sprintf(&pBuffer[strlen(pBuffer)], "argv[%d] = %s, ", i, argv[i]);
    }

    pBuffer[strlen(pBuffer) - 2] = '\0';          // kill last ', '

    CDEMOFINE((MFNINF(1) "%s\n", pBuffer));
    if (1/*ISfunctions*/) {
        static struct {
            int (*isfunc)(int);
            char* szIsName;
        }isfunc[] = {
                {isalnum, "isalnum" },
                {isalpha, "isalpha" },
                {iscntrl, "iscntrl" },
                {isdigit, "isdigit" },
                {isgraph, "isgraph" },
                {islower, "islower" },
                {isprint, "isprint" },
                {ispunct, "ispunct" },
                {isspace, "isspace" },
                {isupper, "isupper" },
                {isxdigit,"isxdigit"}
        };

        for (i = 0; i < sizeof(isfunc) / sizeof(isfunc[0]); i++) {
            CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "##################################################################\n"));
            CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "########################## Test %s() in PEI #################\n", isfunc[i].szIsName));
            CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "##################################################################\n"));

            for (c = 0; c < count; c++) {

                result = isfunc[i].isfunc(c);
                if (0 != result) {
                    sprintf(pBuffer, "%s%s%s%s%s%s%s%s",
                        (result & _UPPER) ? "_UPPER " : "",
                        (result & _LOWER) ? "_LOWER " : "",
                        (result & _DIGIT) ? "_DIGIT " : "",
                        (result & _SPACE) ? "_SPACE " : "",
                        (result & _PUNCT) ? "_PUNCT " : "",
                        (result & _CONTROL) ? "_CONTROL " : "",
                        (result & _BLANK) ? "_BLANK " : "",
                        (result & _HEX) ? "_HEX " : "");

                    CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "%s(0x%04X) -> %s\n", isfunc[i].szIsName, c, pBuffer));
                }
            }
            CDEMOFINE/*MOduleFIleliNE*/((MFNBAR(1) "\n"));

        }
    }

    if (1/*TOfunctions*/) {
        static struct {
            int (*tofunc)(int);
            char* szToName;
        }tofunc[] = {
                {tolower, "tolower" },
                {toupper, "toupper" }
        };

        for (i = 0; i < sizeof(tofunc) / sizeof(tofunc[0]); i++) {
            CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "##################################################################\n"));
            CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "########################## Test %s() in PEI #################\n", tofunc[i].szToName));
            CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "##################################################################\n"));

            for (c = 0; c < count; c++) {

                result = tofunc[i].tofunc(c);
                if (c != result) {
                    sprintf(pBuffer, "%s(0x%04X / %c) -> 0x%04X / %c", tofunc[i].szToName, c, c, result, result);


                    CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "%s\n", pBuffer));
                }
            }
            CDEMOFINE/*MOduleFIleliNE*/((MFNBAR(1) "\n"));

        }
    }
}