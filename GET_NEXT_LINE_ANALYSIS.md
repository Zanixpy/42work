# Application de la Pensée Computationnelle : Analyse de get_next_line

## Introduction

Ce document applique la méthodologie de pensée computationnelle au projet `get_next_line` pour démontrer comment décomposer un problème complexe en tâches logiques et gérables.

## Étape 1 : Comprendre le Problème

### Analyse du Sujet
**Problème :** Créer une fonction qui lit un fichier ligne par ligne, en retournant une ligne à chaque appel.

**Contraintes identifiées :**
- Fonction doit gérer plusieurs file descriptors simultanément
- BUFFER_SIZE peut être défini différemment (1, 42, 1000, etc.)
- Doit retourner la ligne avec le `\n` inclus
- Retourne `NULL` en cas de fin de fichier ou d'erreur
- Gestion mémoire stricte (pas de fuites)

**Cas limites à considérer :**
- Fichier vide
- Ligne vide (`\n` seul)
- Ligne très longue (plus grande que BUFFER_SIZE)
- Fichier avec seulement `\n` à la fin
- File descriptor invalide
- Erreur de lecture

## Étape 2 : Identifier les Entrées/Sorties

### Entrées
```
Type : int fd
Description : File descriptor du fichier à lire
Validation : fd >= 0 (pas de vérification explicite requise par le sujet)
```

### Sorties
```
Type : char *
Description : Ligne lue avec '\n' inclus, ou NULL si fin/erreur
Codes d'erreur : 
- NULL si EOF atteint
- NULL si erreur de lecture
- NULL si allocation mémoire échoue
```

## Étape 3 : Décomposer en Sous-Problèmes

### Analyse de l'État Actuel
Votre code actuel présente plusieurs problèmes :

```c
// ❌ Problèmes identifiés dans le code actuel
void firstT(int fd, int *read_bytes, char **buf, int *newline, int *n)
{
    // - Nom de fonction non-descriptif
    // - Trop de paramètres (violation du principe de responsabilité unique)
    // - Utilisation de write() au lieu de construire la string
    // - Logique complexe et difficile à suivre
}
```

### Décomposition Recommandée

```
Problème principal : get_next_line
├── Sous-problème 1 : Gestion du buffer statique par fd
│   ├── Fonction : get_buffer_for_fd()
│   └── Fonction : create_new_buffer()
├── Sous-problème 2 : Lecture et recherche de '\n'
│   ├── Fonction : read_until_newline()
│   └── Fonction : find_newline_in_buffer()
├── Sous-problème 3 : Construction de la ligne
│   ├── Fonction : extract_line_from_buffer()
│   └── Fonction : update_buffer_after_line()
└── Sous-problème 4 : Fonctions utilitaires
    ├── ft_strlen()
    ├── ft_strchr()
    ├── ft_strjoin()
    └── ft_strdup()
```

## Étape 4 : Définir les Structures de Données

### Variables Statiques Nécessaires
```c
// Structure pour gérer un buffer par fd
typedef struct s_buffer {
    char *data;        // Données lues
    int size;          // Taille des données dans le buffer
    int position;      // Position actuelle dans le buffer
    int fd;            // File descriptor associé
} t_buffer;

// Liste chaînée pour gérer plusieurs fd
typedef struct s_buffer_list {
    t_buffer buffer;
    struct s_buffer_list *next;
} t_buffer_list;
```

### Variables Locales dans get_next_line
```c
char *line;           // Ligne à retourner
t_buffer *current;   // Buffer pour le fd actuel
int newline_pos;      // Position du '\n' trouvé
```

## Étape 5 : Concevoir les Algorithmes (Pseudo-Code)

### Algorithme Principal
```
get_next_line(fd) :
    current = get_buffer_for_fd(fd)
    SI current == NULL :
        RETOURNER NULL
    
    line = NULL
    
    TANT QUE TRUE :
        SI current->position >= current->size :
            SI read_more_data(fd, current) == 0 :
                RETOURNER line (ou NULL si line vide)
        
        newline_pos = find_newline_in_buffer(current)
        
        SI newline_pos >= 0 :
            line = extract_line_from_buffer(current, newline_pos)
            update_buffer_after_line(current, newline_pos)
            RETOURNER line
        SINON :
            line = append_buffer_to_line(line, current)
            current->position = current->size
```

### Fonctions Utilitaires
```
get_buffer_for_fd(fd) :
    POUR CHAQUE buffer dans la liste statique :
        SI buffer->fd == fd :
            RETOURNER buffer
    
    buffer = create_new_buffer(fd)
    ajouter buffer à la liste statique
    RETOURNER buffer

read_more_data(fd, buffer) :
    bytes_read = read(fd, buffer->data, BUFFER_SIZE)
    SI bytes_read <= 0 :
        RETOURNER 0
    
    buffer->size = bytes_read
    buffer->position = 0
    RETOURNER bytes_read

find_newline_in_buffer(buffer) :
    POUR i = buffer->position À buffer->size :
        SI buffer->data[i] == '\n' :
            RETOURNER i
    RETOURNER -1

extract_line_from_buffer(buffer, newline_pos) :
    line_length = newline_pos - buffer->position + 1
    line = malloc(line_length + 1)
    SI line == NULL :
        RETOURNER NULL
    
    copier buffer->data[buffer->position] à buffer->data[newline_pos] dans line
    line[line_length] = '\0'
    RETOURNER line
```

## Étape 6 : Plan d'Implémentation

### Ordre d'Implémentation Recommandé

1. **Fonctions utilitaires de base** (dans `get_next_line_utils.c`)
   ```c
   size_t ft_strlen(const char *s);
   char *ft_strchr(const char *s, int c);
   char *ft_strjoin(char const *s1, char const *s2);
   char *ft_strdup(const char *s);
   ```

2. **Fonctions de gestion de buffer**
   ```c
   t_buffer *get_buffer_for_fd(int fd);
   t_buffer *create_new_buffer(int fd);
   void free_buffer_for_fd(int fd);
   ```

3. **Fonctions de lecture et traitement**
   ```c
   int read_more_data(int fd, t_buffer *buffer);
   int find_newline_in_buffer(t_buffer *buffer);
   char *extract_line_from_buffer(t_buffer *buffer, int newline_pos);
   void update_buffer_after_line(t_buffer *buffer, int newline_pos);
   ```

4. **Fonction principale**
   ```c
   char *get_next_line(int fd);
   ```

### Structure des Fichiers Recommandée

```
get_next_line/
├── get_next_line.h          # Prototypes et définitions
├── get_next_line.c          # Fonction principale
├── get_next_line_utils.c    # Fonctions utilitaires
└── test_main.c             # Programme de test
```

## Étape 7 : Tests Systématiques

### Cas de Test à Implémenter

1. **Cas normaux**
   ```c
   // Fichier avec plusieurs lignes
   "Hello\nWorld\nTest\n"
   
   // Résultat attendu :
   // Appel 1: "Hello\n"
   // Appel 2: "World\n" 
   // Appel 3: "Test\n"
   // Appel 4: NULL
   ```

2. **Cas limites**
   ```c
   // Fichier vide
   ""
   
   // Ligne vide
   "\n"
   
   // Fichier sans '\n' final
   "Hello World"
   
   // Ligne très longue
   "A" répété 10000 fois + "\n"
   ```

3. **Tests de mémoire**
   ```bash
   valgrind --leak-check=full --show-leak-kinds=all ./a.out
   ```

4. **Tests de performance**
   ```bash
   time ./a.out < gros_fichier.txt
   ```

### Programme de Test Complet

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    int line_count = 0;
    
    // Test avec fichier normal
    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        printf("Erreur: impossible d'ouvrir test.txt\n");
        return (1);
    }
    
    printf("=== Test lecture ligne par ligne ===\n");
    while ((line = get_next_line(fd)) != NULL)
    {
        line_count++;
        printf("Ligne %d: %s", line_count, line);
        free(line);
    }
    
    printf("Total: %d lignes lues\n", line_count);
    close(fd);
    
    // Test avec fd invalide
    printf("\n=== Test fd invalide ===\n");
    line = get_next_line(-1);
    if (line == NULL)
        printf("✓ Gestion correcte du fd invalide\n");
    else
        printf("✗ Erreur: devrait retourner NULL\n");
    
    return (0);
}
```

## Comparaison : Avant vs Après

### Code Actuel (Problématique)
```c
// ❌ Problèmes identifiés
void firstT(int fd, int *read_bytes, char **buf, int *newline, int *n)
{
    // - Nom non-descriptif
    // - Trop de responsabilités
    // - Utilise write() au lieu de construire string
    // - Logique difficile à suivre
    // - Gestion mémoire problématique
}
```

### Code Refactorisé (Recommandé)
```c
// ✅ Solution claire et modulaire
char *get_next_line(int fd)
{
    static t_buffer_list *buffers = NULL;
    t_buffer *current;
    char *line;
    int newline_pos;
    
    if (fd < 0)
        return (NULL);
    
    current = get_buffer_for_fd(fd, &buffers);
    if (!current)
        return (NULL);
    
    line = NULL;
    while (1)
    {
        if (current->position >= current->size)
        {
            if (read_more_data(fd, current) <= 0)
                return (line);
        }
        
        newline_pos = find_newline_in_buffer(current);
        if (newline_pos >= 0)
        {
            line = extract_line_from_buffer(current, newline_pos);
            update_buffer_after_line(current, newline_pos);
            return (line);
        }
        else
        {
            line = append_buffer_to_line(line, current);
            current->position = current->size;
        }
    }
}
```

## Bénéfices de cette Approche

1. **Lisibilité** : Chaque fonction a un nom descriptif et un objectif clair
2. **Maintenabilité** : Code modulaire facile à déboguer et modifier
3. **Testabilité** : Chaque fonction peut être testée individuellement
4. **Réutilisabilité** : Les fonctions utilitaires peuvent être réutilisées
5. **Performance** : Gestion mémoire optimisée
6. **Robustesse** : Gestion complète des cas d'erreur

## Prochaines Étapes

1. Implémenter les fonctions utilitaires dans `get_next_line_utils.c`
2. Créer la structure de données pour gérer les buffers
3. Implémenter les fonctions de gestion de buffer
4. Refactoriser `get_next_line()` avec la nouvelle approche
5. Créer un programme de test complet
6. Valider avec valgrind et différents cas de test

Cette approche méthodologique vous permettra de créer un code plus robuste, maintenable et conforme aux bonnes pratiques de programmation en C.
