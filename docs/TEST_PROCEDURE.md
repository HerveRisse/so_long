# Procédure de test So_long

## 0. Préparation de l'environnement
```bash

## 1. Tests de compilation
```bash
# Nettoyage et compilation
make fclean
make

# Vérification du relink
make
```

## 2. Tests de conformité
```bash
# Vérification de la norme
norminette src/*.c includes/*.h
norminette libft/src/**/*.c libft/includes/*.h

# Vérification des fichiers requis
ls -la Makefile src/ includes/ libft/
```

## 3. Tests fonctionnels

### 3.1 Tests de validation des cartes
```bash

# Test avec carte valide
./so_long maps/small.ber

# Test avec carte invalide (pas d'extension .ber)
echo "1111\n1PE1\n1111" > maps/invalid.txt
./so_long maps/invalid.txt
# Doit afficher : Invalid file extension (must be .ber)
./so_long maps/invalid.txt

# Test avec carte invalide (pas rectangulaire)
echo "1111\n1PE1\n11111" > maps/not_rectangular.ber
./so_long maps/not_rectangular.ber
# Doit afficher : Map must be rectangular

# Test avec carte invalide (pas de sortie)
echo "1111\n1P01\n1111" > maps/no_exit.ber
./so_long maps/no_exit.ber
# Doit afficher : Map must have exactly one exit

# Test avec carte invalide (pas de collectible)
echo "1111\n1PE1\n1111" > maps/no_collectible.ber
./so_long maps/no_collectible.ber
# Doit afficher : Map must have at least one collectible

# Test avec carte invalide (pas de joueur)
echo "1111\n1EC1\n1111" > maps/no_player.ber
./so_long maps/no_player.ber
# Doit afficher : Map must have exactly one player position

# Test avec carte invalide (plusieurs joueurs)
echo "1111\n1PEP1\n1111" > maps/multiple_players.ber
./so_long maps/multiple_players.ber
# Doit afficher : Map must have exactly one player position

# Test avec carte invalide (murs non fermés)
echo "1111\n0PE1\n1111" > maps/open_walls.ber
./so_long maps/open_walls.ber
# Doit afficher : Map must be surrounded by walls

# Test avec carte invalide (caractères non valides)
echo "1111\n1PX1\n1111" > maps/invalid_chars.ber
./so_long maps/invalid_chars.ber
# Doit afficher : Invalid character in map
```

### 3.2 Tests de gameplay
```bash
# Créer une carte de test complète
cat > maps/test.ber << 'EOF'
1111111
1P0C001
1000001
100C001
1000E01
1111111
EOF

# Lancer le jeu avec la carte de test
./so_long maps/test.ber

# Vérifier :
1. Déplacements
   - W : Déplacement vers le haut
   - A : Déplacement vers la gauche
   - S : Déplacement vers le bas
   - D : Déplacement vers la droite
   - Les déplacements sont bloqués par les murs (1)
   - Le compteur de mouvements s'incrémente à chaque déplacement

2. Collectibles
   - Les collectibles (C) disparaissent quand le joueur passe dessus
   - La sortie n'est pas accessible tant que tous les collectibles ne sont pas ramassés

3. Sortie
   - Le jeu se termine quand le joueur atteint la sortie (E) avec tous les collectibles
   - Un message de victoire s'affiche

4. Interface
   - Le compteur de mouvements s'affiche dans le terminal
   - La fenêtre se ferme proprement avec la touche ESC ou le bouton de fermeture
```

### 3.3 Tests de mémoire
```bash
# Vérification des fuites de mémoire
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/test.ber

# Note : La MLX peut générer des avertissements valgrind, c'est normal.
# Vérifier qu'il n'y a pas de fuites venant de notre code.
```

## 4. Vérification finale
- [ ] Le Makefile compile sans relink
- [ ] Tous les fichiers passent la norminette
- [ ] Les cartes invalides sont correctement rejetées
- [ ] Le gameplay fonctionne comme prévu
- [ ] Pas de fuites mémoire
- [ ] La fermeture du jeu est propre

## 5. Nettoyage
```bash
# Suppression des fichiers de test uniquement
rm -f maps/invalid.txt maps/*_*.ber maps/test.ber

# Nettoyage de la compilation
make fclean
```
