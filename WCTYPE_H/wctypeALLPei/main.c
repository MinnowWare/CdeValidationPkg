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
    Validation of all <em>Wctype.h</em>-function from the standard C library


@details

@todo

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wctype.h>
#include <CDE.h>

#define COUNT 0x2000

//#include <uefi.h>


int main(int argc, char** argv) {
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
            int (*isfunc)(win_t);
            char* szIsName;
        }isfunc[] = {
                {iswalnum, "iswalnum" },
                {iswalpha, "iswalpha" },
                {iswcntrl, "iswcntrl" },
                {iswdigit, "iswdigit" },
                {iswgraph, "iswgraph" },
                {iswlower, "iswlower" },
                {iswprint, "iswprint" },
                {iswpunct, "iswpunct" },
                {iswspace, "iswspace" },
                {iswupper, "iswupper" },
                {iswxdigit,"iswxdigit"}
        };

        for (i = 0; i < sizeof(isfunc) / sizeof(isfunc[0]); i++) {
            CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "##################################################################\n"));
            CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "########################## Test %s() in PEI #################\n", isfunc[i].szIsName));
            CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "##################################################################\n"));

            for (c = 0; c < count; c++) {

                result = isfunc[i].isfunc(c);
                if (0 != result) {
                    sprintf(pBuffer, "%s%s%s%s%s%s%s%s%s",
                        (result & _UPPER) ? "_UPPER " : "",
                        (result & _LOWER) ? "_LOWER " : "",
                        (result & _DIGIT) ? "_DIGIT " : "",
                        (result & _SPACE) ? "_SPACE " : "",
                        (result & _PUNCT) ? "_PUNCT " : "",
                        (result & _CONTROL) ? "_CONTROL " : "",
                        (result & _BLANK) ? "_BLANK " : "",
                        (result & _ALPHA) ? "_ALPHA " : "",
                        (result & _HEX) ? "_HEX " : "");

                    CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "%s(0x%04X) -> %s\n", isfunc[i].szIsName, c, pBuffer));
                }
            }
            CDEMOFINE/*MOduleFIleliNE*/((MFNBAR(1) "\n"));

        }
    }

    if (1/*TOfunctions*/) {
        static struct {
            wint_t (*tofunc)(win_t);
            char* szToName;
        }tofunc[] = {
                {towlower, "towlower" },
                {towupper, "towupper" }
        };

        for (i = 0; i < sizeof(tofunc) / sizeof(tofunc[0]); i++) {
            CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "##################################################################\n"));
            CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "########################## Test %s() in PEI\n", tofunc[i].szToName));
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

    if (1/*ISWCTYPE() and WCTYPE() function*/) {
        wint_t t;
        char* wctype_table[] = { "alpha","alnum","alpha","blank","cntrl","digit","graph","lower","print","punct","space","upper","xdigit","Xdigit" };

        CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "##################################################################\n"));
        CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "########################## Test iswctype() and wctype() in PEI\n"));
        CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "##################################################################\n"));

        CDEMOFINE((MFNINF(1)"%04X %04X %s\n", 0x0157, _ALPHA | _BLANK | _PUNCT | _DIGIT | _LOWER | _UPPER, "print"));
        CDEMOFINE((MFNINF(1)"%04X %04X %s\n", 0x0117, _ALPHA | _PUNCT | _DIGIT | _LOWER | _UPPER, "graph"));
        CDEMOFINE((MFNINF(1)"%04X %04X %s\n", 0x0107, _ALPHA | _DIGIT | _LOWER | _UPPER, "alnum"));
        CDEMOFINE((MFNINF(1)"%04X %04X %s\n", 0x0103, _ALPHA | _LOWER | _UPPER, "alpha"));
        CDEMOFINE((MFNINF(1)"%04X %04X %s\n", 0x0001, _UPPER, "upper"));
        CDEMOFINE((MFNINF(1)"%04X %04X %s\n", 0x0002, _LOWER, "lower"));
        CDEMOFINE((MFNINF(1)"%04X %04X %s\n", 0x0004, _DIGIT, "digit"));
        CDEMOFINE((MFNINF(1)"%04X %04X %s\n", 0x0008, _SPACE, "space"));
        CDEMOFINE((MFNINF(1)"%04X %04X %s\n", 0x0010, _PUNCT, "punct"));
        CDEMOFINE((MFNINF(1)"%04X %04X %s\n", 0x0020, _CONTROL, "cntrl"));
        CDEMOFINE((MFNINF(1)"%04X %04X %s\n", 0x0040, _BLANK, "blank"));
        CDEMOFINE((MFNINF(1)"%04X %04X %s\n", 0x0080, _HEX, "xdigit"));


        for (t = 0; t < sizeof(wctype_table) / sizeof(wctype_table[0]); t++) {
            CDEMOFINE/*MOduleFIleliNE*/((MFNINF(1) "########################## Testing \"%s\"\n", wctype_table[t]));
            for (c = 0; c < count; c++) {
                int nRet;

                nRet = iswctype((wint_t)c, wctype(wctype_table[t]));

//                CDEMOFINE((MFNINF(0 != nRet) /* <<< no comma >>> */ "Character 0x%04X is %s / %04X\n", c, wctype_table[t], nRet));
                CDEMOFINE((MFNINF(0 != nRet) /* <<< no comma >>> */ "iswctype(%04X, wctype(%s)) -> %04X\n", c, wctype_table[t], nRet));

            }
        }
    }
    if (1/*WCTRANS and TOWCTRANS function*/) {
        wint_t t, wc;
        int c;
        static char* property_table[] = { { "toupper" },{"tolower" },{ "towupper" },{ "towlower" },{ "INVALID" } };

        for (i = 0, t = 0; i < sizeof(property_table) / sizeof(property_table[0]); i++) {

            t = wctrans(property_table[i]);

            CDEMOFINE((MFNINF(1) " %s -> t == %X\n", property_table[i], t));

            for (c = 0; c < count; c++) {

                wc = towctrans((wint_t)c, t);

                CDEMOFINE((MFNINF(wc != (wint_t)c) /* <<< no comma >>> */ "Character 0x%04X is converted to 0x%04X\n", c, wc));
            }
        }
    }
}