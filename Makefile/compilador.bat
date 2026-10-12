@echo off

cd ..

echo Compilando...



gcc src\*.c -Iinclude -Ilib -Llib -lraylib -lopengl32 -lgdi32 -lwinmm -o jogo.exe



if %errorlevel% neq 0 (

    echo Erro na compilacao.

) else (

    echo Compilado com sucesso!

    jogo.exe

)



pause