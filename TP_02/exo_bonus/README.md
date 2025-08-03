# Exercice Bonus : Canary + ret2win

## Description
Combinaison de bypass du canary ET ret2win pour obtenir un shell.

## Analyse
Le même binaire que l'exercice 2 contient aussi la fonction `win()` !
- Fonction `win()` à `0x401166` qui exécute `execve("/bin/sh", NULL, NULL)`
- Canary manuel à bypass (`0x3bdcf`)

## Stratégie
1. Bypass le canary comme dans l'exercice 2
2. Écraser l'adresse de retour pour pointer vers `win()`

## Layout de la stack étendu
```
rbp-0x50: buffer[80 bytes]
rbp-0x8:  canary (0x3bdcf) ← à préserver
rbp-0x4:  is_admin (n'importe quoi)
rbp:      saved rbp (8 bytes)
rbp+8:    return address (8 bytes) ← vers win()
```

## Exploit
```bash
python3 exploit_bonus_shell.py
```

**Résultat attendu :** Shell interactif

## Points clés
- Combinaison de deux techniques d'exploitation
- Bypass de protection + redirection d'exécution
- Analyse complète du binaire pour trouver toutes les fonctions