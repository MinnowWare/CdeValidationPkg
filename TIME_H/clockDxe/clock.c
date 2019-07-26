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

@file clockDxe.c

@brief C Development Environment (CDE)\n
    Validation of the <em>clock()</em>-function from the standard C library
    

@details 

@todo

@mainpage
    clock() validation driver for DXE

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
#include <string.h>
#include <time.h>
#include <CDE.h>

//#include <uefi.h>

int main() {
    clock_t clk;
    int i;
    
    //__debugbreak();

    CDEMOFINE((MFNINF(1) "##################################################################\n"));
    CDEMOFINE((MFNINF(1) "########################## Test clock() ##########################\n"));
    CDEMOFINE((MFNINF(1) "##################################################################\n"));
    CDEMOFINE((MFNINF(1) "print 10 \".\". Each 1000ms a new one:"));

    for (i = 0; i < 10; i++) {

        clk = CLOCKS_PER_SEC / 1 /*frequency*/ + clock();
        CDEMOFINE((MFNBAR(1) "."));
        while (clk > clock())
            ;

    }
    CDEMOFINE((MFNBAR(1) "."));

}