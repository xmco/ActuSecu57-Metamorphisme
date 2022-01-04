# Metamorphic program

This project aims at implementing a metamorphic program in modern C++ that changes his signature every times he makes a copy of himself.

## How to use

First, compile the program :

```sh
make
```

Then run it :

```sh
./metamorphic
```

It will create a child executable that you can run too :

```sh
./metamorphic_child_XXXXXX
```

After creating multiple children, you can check that the signature is different for each one :

```sh
sha256sum metamorphic*
```

You can clean all executables with the commande :

```sh
make clean
```
