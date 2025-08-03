# Exercice 3 : ret2win

## Description
Buffer overflow classique pour rediriger l'exécution vers une fonction cachée.

## Analyse du binaire
```bash
file ret2win         # ELF 64-bit x86_64
objdump -d ret2win   # Désassemblage
strings ret2win      # Chaînes de caractères
```

## Vulnérabilité
- Buffer de 32 bytes
- Lecture de 100 bytes avec `fgets()` → Buffer overflow
- Fonction `win()` à l'adresse `0x401146` qui exécute `/bin/sh`

## Layout de la stack
```
rbp-0x20: buffer[32 bytes]
rbp:      saved rbp (8 bytes)
rbp+8:    return address (8 bytes) ← cible
```

## Exploit
```bash
python3 exploit_ret2win.py
```

**Résultat attendu :** Shell interactif

## Points clés
- ret2win basique sans protections
- Calcul d'offset pour atteindre l'adresse de retour
- Redirection vers fonction cachée