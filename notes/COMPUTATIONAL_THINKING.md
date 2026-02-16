# Guide de Pensée Computationnelle en C

## Introduction

La pensée computationnelle est une approche méthodologique pour résoudre des problèmes complexes en les décomposant en étapes logiques que l'ordinateur peut exécuter. Ce guide vous apprendra à structurer votre réflexion pour créer du code C efficace et maintenable.

## Les 4 Piliers de la Pensée Computationnelle

### 1. Décomposition (Decomposition)
**Principe :** Diviser un problème complexe en sous-problèmes plus simples et gérables.

**Exemple pratique :**
```
Problème : Créer une fonction qui lit un fichier ligne par ligne
↓
Sous-problèmes :
- Ouvrir le fichier
- Lire des chunks de données
- Chercher les caractères de fin de ligne
- Construire les lignes complètes
- Gérer la mémoire
- Fermer le fichier
```

### 2. Reconnaissance de Patterns (Pattern Recognition)
**Principe :** Identifier les similarités et les répétitions dans le problème.

**Exemple pratique :**
```
Pattern identifié : Lecture répétitive de données
Solution : Utiliser une boucle avec read() jusqu'à EOF
Pattern identifié : Recherche de caractères
Solution : Fonction générique ft_strchr()
```

### 3. Abstraction (Abstraction)
**Principe :** Ignorer les détails non-essentiels et se concentrer sur l'essentiel.

**Exemple pratique :**
```
Détail non-essentiel : Le type de fichier (texte, binaire)
Essentiel : Le flux de données (stream)
Abstraction : Traiter tout comme un flux d'octets
```

### 4. Algorithmes (Algorithm Design)
**Principe :** Créer des instructions étape par étape pour résoudre le problème.

**Exemple pratique :**
```
Algorithme pour lire une ligne :
1. Lire un chunk de données
2. Chercher '\n' dans le chunk
3. Si trouvé : extraire la ligne
4. Si pas trouvé : lire le chunk suivant
5. Répéter jusqu'à trouver '\n' ou EOF
```

## Workflow en 7 Étapes pour Tout Projet C

### Étape 1 : Comprendre le Problème
**Questions à se poser :**
- Que doit faire exactement le programme ?
- Quelles sont les contraintes ?
- Y a-t-il des cas particuliers à gérer ?

**Actions :**
- Lire attentivement le sujet
- Reformuler le problème avec vos propres mots
- Identifier les cas limites (erreurs, valeurs nulles, etc.)

**Template :**
```
Problème : [Description claire]
Contraintes : [Limites techniques]
Cas limites : [Situations particulières]
```

### Étape 2 : Identifier les Entrées/Sorties
**Questions à se poser :**
- Quelles données le programme reçoit-il ?
- Quel format de données attendu ?
- Que doit-il retourner exactement ?

**Actions :**
- Lister toutes les entrées (paramètres, fichiers, stdin)
- Définir précisément les sorties (types, formats)
- Identifier les codes d'erreur possibles

**Template :**
```
Entrées :
- Type : [int, char*, FILE*, etc.]
- Description : [ce que représente cette entrée]
- Validation : [comment vérifier si c'est valide]

Sorties :
- Type : [int, char*, void, etc.]
- Description : [ce que retourne la fonction]
- Codes d'erreur : [valeurs de retour en cas d'erreur]
```

### Étape 3 : Décomposer en Sous-Problèmes
**Questions à se poser :**
- Quelles sont les tâches principales ?
- Quelles tâches peuvent être faites indépendamment ?
- Y a-t-il des dépendances entre les tâches ?

**Actions :**
- Créer une hiérarchie de problèmes
- Identifier les fonctions utilitaires nécessaires
- Définir l'ordre d'exécution

**Template :**
```
Problème principal : [Nom du projet]
├── Sous-problème 1 : [Tâche principale]
│   ├── Fonction utilitaire A
│   └── Fonction utilitaire B
├── Sous-problème 2 : [Tâche principale]
│   └── Fonction utilitaire C
└── Sous-problème 3 : [Tâche principale]
```

### Étape 4 : Définir les Structures de Données
**Questions à se poser :**
- Quelles données doivent être stockées ?
- Comment organiser ces données efficacement ?
- Quelles structures C utiliser ?

**Actions :**
- Identifier les variables nécessaires
- Choisir les types appropriés
- Définir les structures si nécessaire

**Template :**
```
Variables globales/statiques :
- [type] [nom] : [description]

Variables locales :
- [type] [nom] : [description]

Structures :
typedef struct s_[nom] {
    [type] [champ] : [description]
    [type] [champ] : [description]
} t_[nom];
```

### Étape 5 : Concevoir les Algorithmes (Pseudo-Code)
**Questions à se poser :**
- Quel est l'ordre logique des opérations ?
- Quelles conditions doivent être vérifiées ?
- Comment gérer les cas d'erreur ?

**Actions :**
- Écrire le pseudo-code pour chaque fonction
- Définir les conditions et boucles
- Prévoir la gestion d'erreurs

**Template :**
```
Fonction [nom_fonction] :
SI [condition d'erreur] :
    RETOURNER [code d'erreur]

TANT QUE [condition] :
    [action principale]
    SI [condition] :
        [action si vrai]
    SINON :
        [action si faux]

RETOURNER [valeur de succès]
```

### Étape 6 : Implémenter Fonction par Fonction
**Questions à se poser :**
- Par quelle fonction commencer ?
- Comment tester chaque fonction individuellement ?
- Comment gérer la mémoire ?

**Actions :**
- Commencer par les fonctions utilitaires
- Implémenter une fonction à la fois
- Tester chaque fonction avant de passer à la suivante

**Template :**
```
Ordre d'implémentation :
1. Fonctions utilitaires simples (ft_strlen, ft_strchr)
2. Fonctions utilitaires complexes (ft_strjoin, ft_strdup)
3. Fonction principale
4. Fonction main() pour les tests
```

### Étape 7 : Tester et Déboguer Systématiquement
**Questions à se poser :**
- Comment tester chaque cas possible ?
- Comment identifier les fuites mémoire ?
- Comment vérifier la performance ?

**Actions :**
- Créer des tests pour chaque cas limite
- Utiliser valgrind pour détecter les fuites
- Tester avec différents fichiers d'entrée

**Template :**
```
Tests à effectuer :
- Cas normal : [description]
- Cas limite : [description]
- Cas d'erreur : [description]
- Test mémoire : valgrind --leak-check=full
- Test performance : time ./programme
```

## Exemple Concret : Analyse d'une Fonction Simple

### Problème : Créer ft_strlen()

**Étape 1 - Comprendre :**
- Fonction qui calcule la longueur d'une chaîne
- Retourne le nombre de caractères avant '\0'
- Ne compte pas le '\0' terminal

**Étape 2 - Entrées/Sorties :**
```
Entrée : const char *s (chaîne à mesurer)
Sortie : size_t (longueur de la chaîne)
Erreur : Aucune (retourne 0 si s == NULL)
```

**Étape 3 - Décomposition :**
```
Problème principal : Calculer la longueur
├── Vérifier si s est NULL
├── Parcourir la chaîne caractère par caractère
└── Compter jusqu'à '\0'
```

**Étape 4 - Structures de données :**
```
Variables locales :
- size_t len : compteur de longueur
- const char *ptr : pointeur pour parcourir
```

**Étape 5 - Algorithme :**
```
ft_strlen(s) :
SI s == NULL :
    RETOURNER 0

len = 0
ptr = s
TANT QUE *ptr != '\0' :
    len++
    ptr++

RETOURNER len
```

**Étape 6 - Implémentation :**
```c
size_t ft_strlen(const char *s)
{
    size_t len;
    const char *ptr;
    
    if (!s)
        return (0);
    
    len = 0;
    ptr = s;
    while (*ptr)
    {
        len++;
        ptr++;
    }
    return (len);
}
```

**Étape 7 - Tests :**
```c
// Tests à effectuer
assert(ft_strlen("hello") == 5);
assert(ft_strlen("") == 0);
assert(ft_strlen(NULL) == 0);
assert(ft_strlen("a") == 1);
```

## Checklist de Validation

Avant de considérer votre projet terminé, vérifiez :

- [ ] Toutes les fonctions ont un nom descriptif
- [ ] Chaque fonction a un seul objectif clair
- [ ] La gestion d'erreurs est complète
- [ ] La mémoire est correctement gérée (malloc/free)
- [ ] Les cas limites sont testés
- [ ] Le code compile sans warnings
- [ ] Valgrind ne détecte aucune fuite mémoire
- [ ] Les tests passent avec différents inputs
- [ ] Le code respecte la norme 42

## Conseils Pratiques

### Nommage des Variables
```c
// ❌ Mauvais
int i, j, k;
char *str, *s, *tmp;

// ✅ Bon
int fd, read_bytes, line_length;
char *buffer, *line, *temp_string;
```

### Gestion de la Mémoire
```c
// ❌ Mauvais
char *str = malloc(100);
// ... utilisation ...
// Oubli du free()

// ✅ Bon
char *str = malloc(100);
if (!str)
    return (NULL);
// ... utilisation ...
free(str);
str = NULL;
```

### Structure des Fonctions
```c
// ✅ Structure recommandée
t_type function_name(t_param param)
{
    // 1. Vérifications d'entrée
    if (!param)
        return (NULL);
    
    // 2. Déclaration des variables
    t_type result;
    
    // 3. Allocation mémoire si nécessaire
    result = malloc(sizeof(t_type));
    if (!result)
        return (NULL);
    
    // 4. Logique principale
    // ...
    
    // 5. Retour du résultat
    return (result);
}
```

## Conclusion

Cette méthodologie vous permettra d'aborder tout projet C avec confiance. La clé est de ne jamais commencer à coder sans avoir d'abord bien compris et décomposé le problème. Prenez le temps de planifier, et le code sera plus facile à écrire, déboguer et maintenir.

**Rappel important :** La pensée computationnelle est un processus itératif. N'hésitez pas à revenir aux étapes précédentes si vous découvrez de nouveaux aspects du problème pendant l'implémentation.
