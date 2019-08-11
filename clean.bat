@echo off
echo clean up "echo %~p0"...

if exist build rd /s /q build

for /F  %%d in ('dir /b /AD') do if exist %%d\doxygen.tmp rd /s /q %%d\doxygen.tmp
for /F  %%d in ('dir /s /b /AD x64') do  rd /s /q %%d

ping 127.0.0.0 > nul