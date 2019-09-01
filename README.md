# CdeValidationPkg
C Development Environment Validation Package for EDK2

## Introduction
**CdeValidationPkg** is the environment for unit tests  of each single ANSI C library function
implemented and provided to other POST drivers in the [**CdePkg**](https://github.com/MinnowWare/CdePkg/blob/master/README.md)

The [completion list ](https://github.com/MinnowWare/CdePkg/blob/master/implemented.md) is updated
by the results of those unit tests.

Furthermore the concept of passing the `EFI_PEI_FILE_HANDLE*` and `EFI_PEI_SERVICES**` parameter to PEI
modules `main()` entry point respective `EFI_HANDLE` and EFI_SYSTEM_TABLE*` for DXE modules `main()` entry point is
demonstrated.

## Intention
The concept for this validation suite is to:

1.  Create test programs that can be build for Windows NT (with Microsofts libcmt.lib), UEFI DXE, SMM, PEI (with CdePkg CdeLib) and 
        SHELL (with Torito C Library) out of the same source code.

2.  Test status messages are written using a commonly used trace interface `CDEMOFINE` to 
        `stdout` (WinNT and UEFI SHELL) or to the StatusCode interface / COM1 at 115200,n,8,1 baud.
    
3.  Capture the trace messages for POST drivers (terminal program or log window of the emulator). 
        Capture the trace messages from the same source module compiled as Windows NT executable (linked against libcmt.lib)
        by redirecting to `stdout` as reference traces.
        Compare both trace logs to verify equality of the **CdeLib** / **Torito C** functions and the 
        original Microsoft implementation.

The tests are kept simple and quick. A comprehensive validation can not be done in POST, since the
transmission rate of the trace messages is too slow.

## Implementation
Each single VS2019 projects / EDK2 components can be build in:

1. Visual Studio 2019 using the Platform Toolset v141 (VS2017)

2. in the EDK2 Emulation Build (NT32Pkg)

3. in the EDK2 MinnowBoard Build (Vlv2TbltDevicePkg)

## Known bugs
* Torito C Library based programs can not build in 32Bit mode because Torito C is for x86-64
  mode only

### 20190822
* reoranization of build strategy: use CDE_CONFIGURATION_STRING=SOLUTIONCONIG and 
  CDE_PLATFORM_STRING=PLATFORM preprocessor settings passed by the compiler
  to differentiate executables. Reduce number of projects to one single project
  for all platforms (NT(Microsoft C Library), NT(Torito C Library), UEFI DXE(CdeLib)
  UEFI PEI(CdeLib), UEFI SHELL(Torito C Library)). Same for EDK2 builds.
* place CDE*.SLN solution files into EDK2 directory, to be able to use Visual Studio solutions
  EDK2 directory without MinnowBoard build environment

### 20190811
* add validation driver/executables for all `ctype.h`- and `wctype.h`-related functions:
    (ctypeALLPei, ctypeALLDxe, wctypeALLPei, wctypeALLDxe)
* remove previously used single function test drivers

### 20190802/1
* WinNTx86-64 (Microsoft C Library)
* WinNTx86-64 (Torito C Library)

### 20190730
* add all *CTYPE.H*-functions to PEI post phase

### 20190728
* add all *CTYPE.H*-functions to DXE post phase

### 20190727
* add *clockPei*

###	20190726/initial revision
* add clock() demonstration for DXE phase
