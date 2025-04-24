make re

# Vérifier qu'il n'y a pas de relink
make

# Vérifier le nettoyage
make clean
make fclean
make re

## 2. Test des cartes valides
# Carte de base
./so_long maps/map_large.ber

# Vérifier les déplacements avec WASD
# Vérifier que le compteur de mouvements s'affiche
# Vérifier que les collectibles disparaissent quand on les prend
# Vérifier que les ennemis se déplacent
# Vérifier que la sortie n'est utilisable qu'après avoir tous les collectibles

## 3. Test des cartes invalides

mkdir -p test_maps

# Carte sans collectible
echo "111\n1P1\n111" > test_maps/no_collectible.ber
./so_long test_maps/no_collectible.ber

# Carte sans sortie
echo "111\n1PC\n111" > test_maps/no_exit.ber
./so_long test_maps/no_exit.ber

# Carte non rectangulaire
echo "111\n1P\n111" > test_maps/not_rectangle.ber
./so_long test_maps/not_rectangle.ber

# Carte non fermée
echo "111\n1P0\n111" > test_maps/not_closed.ber
./so_long test_maps/not_closed.ber

# Carte avec caractères invalides
echo "111\n1PZ\n111" > test_maps/invalid_char.ber
./so_long test_maps/invalid_char.ber

# Carte vide
touch test_maps/empty.ber
./so_long test_maps/empty.ber

# Fichier non .ber
echo "111\n1P1\n111" > test_maps/invalid.txt
./so_long test_maps/invalid.txt

## 4. Test de la gestion de la mémoire
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map_large.ber

## 5. Test des événements
./so_long maps/map_large.ber

# 1. Fermeture avec ESC
# 2. Fermeture avec la croix de la fenêtre
# 3. Collision avec un ennemi -> Game Over
# 4. Collecte de tous les objets puis sortie -> Victoire
# 5. Tentative de sortie sans tous les objets -> Pas possible

## 6. Test des graphismes
./so_long maps/map_large.ber

# 1. Murs (texture de briques)
# 2. Sol (texture grise)
# 3. Joueur (chevalier en armure bleue)
# 4. Collectibles (pièces/trésors)
# 5. Sortie (porte du château)
# 6. Ennemis (gobelins)

# 1. Les ennemis se déplacent aléatoirement
# 2. Les ennemis ne traversent pas les murs
# 3. Contact avec un ennemi = Game Over

# Norminette du projet principal
norminette src/*.c includes/*.h

# Norminette de la libft
norminette libft/src/**/*.c libft/includes/*.h

# Nettoyage
rm -rf test_maps/
make fclean
