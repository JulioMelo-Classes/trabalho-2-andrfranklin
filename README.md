# Entrega final do trabalho 2 de LP1:

## Para compilar

Com makefiles:
```console
mkdir build
make
```

Com cmake:
```console
mkdir build
cd build
cmake ..
cmake --build .
```

Escolha uma das duas formas de build e ignore a outra.

## Para executar
Você pode rodar o sistema e em logo depois digitar os comandos seguidos de ENTER
```console
./concordo
```

Ou pode criar um arquivo de texto com uma lista de comandos (um por linha) e executar o sistema redirecionando esse arquivo como entrada padrão:
```console
./concordo < ../script_teste.txt
```
