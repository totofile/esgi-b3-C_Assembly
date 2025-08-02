.intel_syntax noprefix
.text
.global _start

# Fonction de multiplication qui prend 3 arguments via registres
# Arguments: rdi (arg1), rsi (arg2), rdx (arg3)
# Retour: rax (résultat)
multiply:
    mov rax, rdi        # Charge le premier argument dans rax
    imul rax, rsi       # Multiplie rax par le deuxième argument
    imul rax, rdx       # Multiplie rax par le troisième argument
    ret                 # Retourne le résultat dans rax

_start:
    # Placer les arguments dans les registres
    mov rdi, 2          # Premier argument: 2
    mov rsi, 3          # Deuxième argument: 3
    mov rdx, 4          # Troisième argument: 4
    
    # Appeler la fonction de multiplication
    call multiply
    
    # Le résultat est maintenant dans rax (2*3*4 = 24)
    # Utiliser syscall exit pour retourner le résultat
    mov rdi, rax        # Code de retour dans rdi
    mov rax, 60         # Numéro du syscall exit
    syscall             # Appel système