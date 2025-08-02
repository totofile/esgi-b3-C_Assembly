.intel_syntax noprefix
.text
.global _start

# Fonction de multiplication qui récupère 3 arguments depuis la stack
# Arguments empilés dans l'ordre: arg3, arg2, arg1 (arg1 au sommet)
# Retour: rax (résultat)
multiply:
    # Sauvegarder rbp et configurer le stack frame
    push rbp
    mov rbp, rsp
    
    # Récupérer les arguments depuis la stack
    # rbp+16 = arg1, rbp+24 = arg2, rbp+32 = arg3
    mov rax, [rbp+16]   # Charger arg1 dans rax
    imul rax, [rbp+24]  # Multiplier par arg2
    imul rax, [rbp+32]  # Multiplier par arg3
    
    # Restaurer rbp et retourner
    pop rbp
    ret

_start:
    # Empiler les arguments sur la stack (dans l'ordre inverse)
    push 4              # Troisième argument: 4
    push 3              # Deuxième argument: 3  
    push 2              # Premier argument: 2
    
    # Appeler la fonction de multiplication
    call multiply
    
    # Nettoyer la stack (retirer les 3 arguments)
    add rsp, 24         # 3 arguments * 8 bytes = 24 bytes
    
    # Le résultat est dans rax (2*3*4 = 24)
    # Utiliser syscall exit pour retourner le résultat
    mov rdi, rax        # Code de retour dans rdi
    mov rax, 60         # Numéro du syscall exit
    syscall             # Appel système