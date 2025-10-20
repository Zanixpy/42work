# Template de Checklist de Tests

## Instructions d'Utilisation

Cette checklist vous assure que tous les aspects de votre projet C sont correctement testés avant la soumission. Utilisez-la systématiquement pour chaque projet.

---

## Informations du Projet

**Nom du projet :** [nom]
**Date de test :** [date]
**Auteur :** [votre nom]
**Version :** [version]

---

## 1. Tests de Compilation

### Compilation de Base
- [ ] `gcc -Wall -Wextra -Werror` compile sans erreurs
- [ ] `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1` compile sans erreurs
- [ ] `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42` compile sans erreurs
- [ ] `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1000` compile sans erreurs
- [ ] `gcc -Wall -Wextra -Werror -D BUFFER_SIZE=10000000` compile sans erreurs

### Compilation avec Makefile
- [ ] `make` fonctionne correctement
- [ ] `make clean` supprime les fichiers temporaires
- [ ] `make fclean` supprime tous les fichiers générés
- [ ] `make re` recompile proprement

### Warnings et Erreurs
- [ ] Aucun warning affiché
- [ ] Aucune erreur de compilation
- [ ] Code respecte la norme 42 (si applicable)

---

## 2. Tests Fonctionnels

### Cas Normaux
- [ ] **Test 1 :** [description] - Résultat : [attendu]
- [ ] **Test 2 :** [description] - Résultat : [attendu]
- [ ] **Test 3 :** [description] - Résultat : [attendu]

### Cas Limites
- [ ] **Test limite 1 :** [description] - Résultat : [attendu]
- [ ] **Test limite 2 :** [description] - Résultat : [attendu]
- [ ] **Test limite 3 :** [description] - Résultat : [attendu]

### Cas d'Erreur
- [ ] **Test erreur 1 :** [description] - Résultat : [attendu]
- [ ] **Test erreur 2 :** [description] - Résultat : [attendu]
- [ ] **Test erreur 3 :** [description] - Résultat : [attendu]

### Cas Particuliers
- [ ] **Fichier vide** - Résultat : [attendu]
- [ ] **Ligne vide** - Résultat : [attendu]
- [ ] **Fichier sans '\n' final** - Résultat : [attendu]
- [ ] **Ligne très longue** - Résultat : [attendu]
- [ ] **FD invalide** - Résultat : [attendu]

---

## 3. Tests de Mémoire

### Valgrind - Fuites Mémoire
```bash
valgrind --leak-check=full --show-leak-kinds=all ./programme
```
- [ ] **Definitely lost :** 0 bytes
- [ ] **Indirectly lost :** 0 bytes
- [ ] **Possibly lost :** 0 bytes
- [ ] **Still reachable :** 0 bytes (ou acceptable)
- [ ] **Suppressed :** 0 bytes

### Valgrind - Erreurs Mémoire
- [ ] **Invalid read :** 0 erreurs
- [ ] **Invalid write :** 0 erreurs
- [ ] **Use after free :** 0 erreurs
- [ ] **Double free :** 0 erreurs
- [ ] **Memory leak :** 0 erreurs

### Tests Spécifiques Mémoire
- [ ] Test avec gros fichier (vérifier pas de fuite)
- [ ] Test avec plusieurs FD simultanés
- [ ] Test avec interruption brutale du programme

---

## 4. Tests de Performance

### Temps d'Exécution
```bash
time ./programme < fichier_test
```
- [ ] **Petit fichier (< 1KB) :** Temps acceptable
- [ ] **Fichier moyen (1-100KB) :** Temps acceptable
- [ ] **Gros fichier (> 1MB) :** Temps acceptable

### Utilisation Mémoire
```bash
valgrind --tool=massif ./programme
```
- [ ] Utilisation mémoire raisonnable
- [ ] Pas de croissance mémoire excessive
- [ ] Libération mémoire correcte

---

## 5. Tests de Robustesse

### Gestion d'Erreurs
- [ ] **FD négatif :** Gestion correcte
- [ ] **FD fermé :** Gestion correcte
- [ ] **Fichier inexistant :** Gestion correcte
- [ ] **Permissions insuffisantes :** Gestion correcte
- [ ] **Disque plein :** Gestion correcte

### Stress Tests
- [ ] **Lecture continue :** Fonctionne sans crash
- [ ] **FD multiples :** Gestion correcte
- [ ] **Interruption :** Pas de fuite mémoire
- [ ] **Ressources limitées :** Gestion correcte

---

## 6. Tests de Compatibilité

### Différentes Tailles de Buffer
- [ ] **BUFFER_SIZE=1 :** Fonctionne correctement
- [ ] **BUFFER_SIZE=42 :** Fonctionne correctement
- [ ] **BUFFER_SIZE=1000 :** Fonctionne correctement
- [ ] **BUFFER_SIZE=10000000 :** Fonctionne correctement

### Différents Types de Fichiers
- [ ] **Fichier texte simple :** Fonctionne
- [ ] **Fichier avec caractères spéciaux :** Fonctionne
- [ ] **Fichier binaire :** Gestion correcte
- [ ] **Fichier très long :** Fonctionne

---

## 7. Tests d'Intégration

### Fonctionnement Global
- [ ] **Workflow complet :** Fonctionne de bout en bout
- [ ] **Interactions entre fonctions :** Correctes
- [ ] **État global :** Maintenu correctement
- [ ] **Nettoyage final :** Effectué correctement

### Tests avec Outils Externes
- [ ] **Comparaison avec commandes système :** Résultats identiques
- [ ] **Tests avec différents shells :** Compatible
- [ ] **Tests sur différents OS :** Compatible (si applicable)

---

## 8. Tests de Documentation

### Code Documentation
- [ ] **Commentaires de fonctions :** Présents et clairs
- [ ] **Documentation des paramètres :** Complète
- [ ] **Exemples d'utilisation :** Fournis
- [ ] **Notes importantes :** Mentionnées

### README et Documentation
- [ ] **Instructions de compilation :** Claires
- [ ] **Instructions d'utilisation :** Complètes
- [ ] **Exemples d'utilisation :** Fournis
- [ ] **Cas d'erreur documentés :** Mentionnés

---

## 9. Tests de Norme et Style

### Norme 42 (si applicable)
- [ ] **Nommage des fonctions :** Conforme
- [ ] **Nommage des variables :** Conforme
- [ ] **Longueur des lignes :** Respectée
- [ ] **Indentation :** Correcte
- [ ] **Headers :** Conformes
- [ ] **Prototypes :** Conformes

### Style de Code
- [ ] **Lisibilité :** Code facile à lire
- [ ] **Cohérence :** Style uniforme
- [ ] **Simplicité :** Pas de complexité inutile
- [ ] **Modularité :** Fonctions bien séparées

---

## 10. Tests Finaux

### Checklist Pré-Soumission
- [ ] **Tous les tests précédents :** Passés
- [ ] **Code finalisé :** Plus de modifications prévues
- [ ] **Documentation complète :** README et commentaires
- [ ] **Backup effectué :** Code sauvegardé
- [ ] **Version finale :** Tagée ou marquée

### Validation Finale
- [ ] **Relecture du code :** Effectuée
- [ ] **Tests sur environnement propre :** Effectués
- [ ] **Validation par un pair :** Effectuée (si possible)
- [ ] **Prêt pour soumission :** Confirmé

---

## Résumé des Tests

### Résultats Globaux
- **Tests de compilation :** [ ] Passés | [ ] Échecs
- **Tests fonctionnels :** [ ] Passés | [ ] Échecs
- **Tests de mémoire :** [ ] Passés | [ ] Échecs
- **Tests de performance :** [ ] Passés | [ ] Échecs
- **Tests de robustesse :** [ ] Passés | [ ] Échecs

### Problèmes Identifiés
```
[Liste des problèmes rencontrés et leurs solutions]
```

### Améliorations Apportées
```
[Liste des améliorations effectuées pendant les tests]
```

---

## Notes Supplémentaires

```
[Espace pour notes, observations, ou recommandations]
```

---

**Statut final :** [ ] Prêt pour soumission | [ ] Nécessite des corrections
**Date de validation :** [date]
**Validateur :** [nom]
