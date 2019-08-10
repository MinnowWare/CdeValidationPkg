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

@file isalnum.c

@brief C Development Environment (CDE)\n
    Validation of the <em>isalnum()</em>-function from the standard C library
    

@details 

@todo

@mainpage
    isalnum() validation driver for PEI

@section intro_sec Introduction
    Validation of the <em>clock()</em>-function from the standard C library.

@subsection ref_sec References
    <a href="https://www.pdf-archive.com/2014/10/02/ansi-iso-9899-1990-1/ansi-iso-9899-1990-1.pdf">ANSI C Specification</a>\n
    <a href="https://github.com/JoaquinConoBolillo/torito-C-Library/blob/master/implemented.md">functions supported in CdeLib</a>\n
    <a href="https://docs.microsoft.com/en-us/cpp/c-language/c-language-reference?view=vs-2019">Microsoft C Language Reference</a>\n
    <a href="https://minnowboard.org/compare-boards/">MinnowBoard</a>\n
    @image html StdCLibCover.jpg

@subsection Parm_sec Command line parameters
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <CDE.h>

#define COUNT 0x100

//#include <uefi.h>

int main(int argc, char** argv) {
    int i,c,result;
    static char buffer[512];
    int count = COUNT;                  // default 0x100
#ifdef WIN64BUILD
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
#endif// WIN64BUILD
    CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "##################################################################\n"));
    CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "########################## Test isalnum() in DXE #################\n"));
    CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "##################################################################\n"));
//
// get command line parameter
//
    for (i = 0; i < argc; i++) {

        if (0 == strncmp("/count", argv[i], strlen("/count"))) {
            count = atoi(argv[i + 1]);
        }

    }

    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "argc = %d, ", argc);
    for (i = 0; i < argc; i++) {
        sprintf(&buffer[strlen(buffer)], "argv[%d] = %s, ", i, argv[i]);
    }

    buffer[strlen(buffer) - 2] = '\0';          // kill last ', '


    CDEMOFINE((MFNINF(1) "%s\n", buffer));

    for (c = 0; c < count; c++) {

        result = isalnum(c);

        sprintf(buffer, "%s%s%s%s%s%s%s%s",
            (result & _UPPER) ? "_UPPER " : "",
            (result & _LOWER) ? "_LOWER " : "",
            (result & _DIGIT) ? "_DIGIT " : "",
            (result & _SPACE) ? "_SPACE " : "",
            (result & _PUNCT) ? "_PUNCT " : "",
            (result & _CONTROL) ? "_CONTROL " : "",
            (result & _BLANK) ? "_BLANK " : "",
            (result & _HEX) ? "_HEX " : "");

        CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "isalnum(0x%04X) -> %s\n",c,buffer));

    }
    CDEMOFINE/*MOduleFIleliNE*/((MFNBAR(1) "\n"));

}