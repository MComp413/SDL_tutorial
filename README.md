# TESTE ENGINE SDL

ET bilu pede que busquem conhecimento

## Build e run

É necessário ter instalados MinGW, glew, SDL2 e SDL2_Image. Os arquivos .dll do glew, SDL2 e SDL2_Image, no diretório deps, precisam ser incluídos nos diretórios de destino dos executáveis, assim como os recursos estáticos res.

## Para rodar no VSCode:
- Configuração c_cpp_properties.json:
```json
{
    "configurations": [
        {
            "name": "<nome>",
            "includePath": [
                "${workspaceFolder}/include",
                "<caminho até o mingw>/mingw64/include",
                "<caminho até o glew>/glew-2.1.0/include",
                "<caminho até o SDL2>/SDL2_x86_64-w64-mingw32/include"
            ],
            "defines": [
                "_DEBUG", "UNICODE", "_UNICODE"
            ],
            "intelliSenseMode": "gcc-x64",
            "compilerPath": "<caminho até o mingw>/mingw64/bin/g++.exe",
            "cStandard": "c17",
            "cppStandard": "c++17"
        }
    ],
    "version": 4
}
```

- Configuração do launch.json:
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++ debug",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/bin/debug/main.exe",
            "args":[],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "<caminho até o mingw>/mingw64/bin/gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty printing for GDB",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "<nome da tarefa de debug>"
        }
    ]
}
```

- Configuração do tasks.json:
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "<nome da tarefa>",
            "command": "g++",
            "args": ["resto", "do", "comando"],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": [
                "$gcc"
            ]
        }
    ]
}
```

### Comandos para debug:

Compilação de objetos:
```sh
 g++ -c src/*.cpp -std=c++17 -g -Wall -m64 -I include -I <caminho até o glew>/glew-2.1.0/include -I <caminho até o SDL2>/SDL2_x86_64-w64-mingw32/include && \
    move *.o obj/debug
```

Compilação de executáveis:
```sh
g++ -g obj/debug/*.o -o main.exe -L <caminho até o SDL2>/SDL2_x86_64-w64-mingw32/lib -L <caminho até o glew>glew-2.1.0/lib/Release/x64 -lmingw32 -lglew32 -lopengl32 -lSDL2main lSDL2 lSDL2_image && \
    move *.exe bin/debug
```

### Comandos para debug:

Compilação de objetos:
```sh
 g++ -c -O3 src/*.cpp -std=c++17 -Wall -m64 -I include -I <caminho até o glew>/glew-2.1.0/include -I <caminho até o SDL2>/SDL2_x86_64-w64-mingw32/include && \
    move *.o obj/release
```

Compilação de executáveis:
```sh
g++ obj/release/*.o -o main.exe -s -L <caminho até o SDL2>/SDL2_x86_64-w64-mingw32/lib -L <caminho até o glew>glew-2.1.0/lib/Release/x64 -lmingw32 -lglew32 -lopengl32 -lSDL2main lSDL2 lSDL2_image && \
    move *.exe bin/release
```



