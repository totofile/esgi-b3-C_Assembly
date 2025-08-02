# TP Assembleur - Multiplication de 3 nombres

## Description
Deux programmes assembleur x86_64 qui multiplient 3 nombres (2, 3, 4) et retournent le résultat (24) comme code de sortie.

## Programmes

### Version 1: multiply_registers.S
- **Méthode**: Arguments passés via registres (rdi, rsi, rdx)
- **Compilation**: `as -o multiply_registers.o multiply_registers.S && ld -o multiply_registers multiply_registers.o`
- **Exécution**: `./multiply_registers; echo $?`

### Version 2: multiply_stack.S  
- **Méthode**: Arguments passés via la stack
- **Compilation**: `as -o multiply_stack.o multiply_stack.S && ld -o multiply_stack multiply_stack.o`
- **Exécution**: `./multiply_stack; echo $?`

## Résultat attendu
Code de retour: **24** (2 × 3 × 4)

## Points techniques
- Syntaxe Intel utilisée
- Syscall exit (60) pour retourner le résultat
- Gestion correcte de la stack dans la version 2
- Stack frame avec rbp dans la fonction multiply (version stack)