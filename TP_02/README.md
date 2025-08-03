# TP - Exploitation binaire - Partie 2

## Structure du TP

### Exercice 2 : Bypass du Canary (`exo_2/`)
- **Binaire :** `canary`
- **Objectif :** Bypass d'un canary manuel hardcodé
- **Technique :** Analyse statique + réécriture de variables

### Exercice 3 : ret2win (`exo_3/`)
- **Binaire :** `ret2win` 
- **Objectif :** Buffer overflow classique vers fonction cachée
- **Technique :** ret2win basique

### Exercice Bonus (`exo_bonus/`)
- **Binaire :** `canary` (même que exercice 2)
- **Objectif :** Combinaison bypass canary + ret2win pour shell
- **Technique :** Exploitation avancée multi-étapes

## Outils utilisés
- `objdump` : Désassemblage
- `strings` : Extraction de chaînes
- `gdb` + `gef` : Debugging dynamique
- `pwntools` : Framework d'exploitation

## Concepts importants
- Buffer overflow
- Stack layout et manipulation
- Canary bypass (implémentation manuelle)
- Return address hijacking
- Analyse statique vs dynamique

## Tests et validation

### Exercice 2 ✅
```bash
cd exo_2/
python3 exploit_canary.py
# Résultat : "Well played!"
```

### Exercice 3 ✅  
```bash
cd exo_3/
python3 exploit_ret2win.py
# Résultat : Shell interactif
```

### Exercice Bonus ✅
```bash
cd exo_bonus/
python3 exploit_bonus_shell.py
# Résultat : "Well played!" + exécution de win() → /bin/sh
```

## Utilisation
Chaque dossier contient :
- Le binaire à exploiter
- L'exploit Python avec pwntools
- Un README détaillé avec l'analyse
- Tests validés et fonctionnels