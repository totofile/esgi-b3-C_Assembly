# Exercice 2 : Bypass du Canary

## Description
Exploitation d'un canary implémenté manuellement (valeur hardcodée dans le code).

## Analyse du binaire
```bash
file canary          # ELF 64-bit x86_64
objdump -d canary    # Désassemblage
strings canary       # Chaînes de caractères
```

## Vulnérabilité
- Buffer de 80 bytes mais canary manuel vulnérable
- Canary = `0x3bdcf` (hardcodé dans le code)
- Variable `is_admin` doit être égale à 5

## Layout de la stack
```
rbp-0x50: buffer[80 bytes]
rbp-0x8:  canary (0x3bdcf)
rbp-0x4:  is_admin (doit être 5)
```

## Exploit
```bash
python3 exploit_canary.py
```

**Résultat attendu :** "Well played!"

## Points clés
- Bypass du canary en connaissant sa valeur
- Contrôle précis des variables sur la stack
- Importance de l'analyse statique du binaire