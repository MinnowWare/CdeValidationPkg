    Hallo welt
    <table>
        <tr>
            <td></td>
            <td><h1>NT(Msft C<br>Library)</h1></td>
            <td><h1>NT(Torito C<br>Library)</h1></td>
            <td><h1>UEFI<br>DXE</h1></td>
            <td><h1>UEFI<br>PEI</h1></td>
            <td><h1>UEFI<br>SHELL</h1></td>
        </tr>
        <tr><td><th align="center" colspan="5"> <h2>Configuration Properties </h2></th> </td></tr>
        <tr><td><th align="center" colspan="5"> <h3>General</h3></th> </td></tr>
        <tr><td>Output directory</td><td align="center" colspan="5"> $(SolutionDir)Edk2\CdeValidationPkg\build\$(Platform)\$(Configuration)</td></tr>

        <tr><td>Target Name</td><td align="center" colspan="5"> $(ProjectName)</td></tr>
        <tr><td>Target Extention</td><td>.exe</td><td>.exe</td><td>.efi</td><td>.efi</td><td>.efi</td>

        <tr>
            <td>Platform Toolset</td>
            <td align="center" colspan="5"> Visual Studio 2017 (v141)</td>
        </tr>
        <tr><td><th align="center" colspan="5"> <h3>Project Defaults</h3></th> </td></tr>
        <tr>
            <td>Configuration Type</td>
            <td align="center" colspan="5">   Application (.exe)</td>
        </tr>


        <tr><td><th align="center" colspan="5"> <h2>C/C++</h2></th> </td></tr>
        <tr><td><th align="center" colspan="5"> <h3>General</h3></th> </td></tr>
        <tr>
            <td>Additional Include Directive</td>
            <td align="center" colspan="5">$(SolutionDir)Edk2\CdePkg\include;</td>
        </tr>
        <tr>
            <td>Debug Format</td>
            <td align="center" colspan="5">None</td>
        </tr>

        <tr>
            <td>Optimization</td>
            <td align="center" colspan="5">/O1</td>
        </tr>
        <tr>
            <td>Preprocessor Definitions</td>
            <td align="center" colspan="5">_NO_CRT_STDIO_INLINE;<br>CDE_DRIVER_NAME="$(TargetName)";</td>
        </tr>
        <tr><td><th align="center" colspan="5"> <h3>Code Generation</h3></th> </td></tr>
        <tr><td>Enable String Pooling</td><td align="center" colspan="5">Yes /GF</td></tr>
        <tr><td>Enable C++ Exceptions</td><td align="center" colspan="5">No</td></tr>
        <tr><td>Runtime Library</td><td align="center" colspan="5">Multi-threaded /MT</td></tr>
        <tr><td>Struct Alignment</td><td align="center" colspan="5">default</td></tr>
        <tr></tr>
        <tr><td>Security Check</td><td align="center" colspan="5">Disable /GS-</td></tr>

        <tr><td><th align="center" colspan="5"> <h3>Language</h3></th> </td></tr>
        <tr><td>Treat WChar_t as buildin type</td><td align="center" colspan="5">No</td></tr>

        <tr><td><th align="center" colspan="5"> <h3>Precompiled Headers</h3></th> </td></tr>
        <tr><td>Precompiled Headers</td><td align="center" colspan="5">No</td></tr>

        <tr><td><th align="center" colspan="5"> <h3>Advanced</h3></th> </td></tr>
        <tr><td>calling conventions</td><td align="center" colspan="5">__cdecl(/Gd)</td></tr>

        <tr><td>compile as</td><td align="center" colspan="5">/TC</td></tr>


        <tr><td><th align="center" colspan="5"> <h2>Linker</h2></th> </td></tr>
        <tr><td><th align="center" colspan="5"> <h3>General</h3></th> </td></tr>
        <tr><td>Output File</td><td align="center" colspan="5">$(OutDir)$(TargetName)$(TargetExt)</td></td></tr>

        <tr><td>Additional Library Directory</td><td align="center" colspan="5">$(SolutionDir)Edk2\CdeValidationPkg\Library\;<br>$(SolutionDir)Edk2\CdePkg\CdeLib\x64\;</td></tr>

    </table>
