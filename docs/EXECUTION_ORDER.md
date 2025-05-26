# Ordre d'exécution des fonctions So_long

## 1. Initialisation du programme
1. `main(int argc, char **argv)` [main.c]
   - Point d'entrée du programme
   - Gère les arguments de la ligne de commande

2. `validate_args(int argc, char **argv)` [main.c]
   - Vérifie le nombre d'arguments
   - Appelle check_file_extension

3. `check_file_extension(char *file)` [main.c]
   - Vérifie que le fichier se termine par .ber

## 2. Chargement et validation de la carte
1. `initialize_map(t_map *map, char *map_file)` [main.c]
   - Initialise la structure de la carte
   - Coordonne le chargement et la validation

2. `count_lines(char *file)` [map_utils.c]
   - Compte le nombre de lignes dans le fichier
   - Utilisé pour l'allocation de mémoire

3. `read_map(t_map *map, int fd)` [map_read.c]
   - Lit le fichier ligne par ligne
   - Appelle process_line pour chaque ligne

4. `process_line(t_map *map, char *line, int i)` [map_read.c]
   - Traite chaque ligne de la carte
   - Stocke les caractères dans map->grid

5. `validate_map(t_map *map)` [map.c]
   - Vérifie que la carte est valide
   - Appelle les fonctions de vérification

6. `check_map_chars(t_map *map)` [map_checks.c]
   - Vérifie que tous les caractères sont valides (0,1,P,E,C)

7. `check_map_counts(t_map *map)` [map_checks.c]
   - Vérifie le nombre de P, E et C

8. `check_walls(t_map *map)` [map.c]
   - Vérifie que la carte est entourée de murs

9. `validate_path(t_map *map)` [map_path.c]
   - Vérifie qu'il existe un chemin valide
   - Utilise find_path pour la vérification

10. `find_path(t_map *map, int x, int y)` [map_path.c]
    - Algorithme récursif de pathfinding
    - Vérifie l'accessibilité des collectibles et de la sortie

## 3. Initialisation du jeu
1. `init_game(t_game *game)` [game_init.c]
   - Initialise la structure du jeu
   - Coordonne l'initialisation graphique

2. `init_window(t_game *game)` [game_init.c]
   - Initialise la fenêtre MLX
   - Configure la taille de la fenêtre

3. `find_player_pos(t_game *game)` [movement.c]
   - Trouve la position initiale du joueur

4. `load_images(t_game *game)` [display_utils.c]
   - Charge toutes les textures du jeu
   - Utilise load_xpm_image pour chaque texture

5. `load_xpm_image(void *mlx, char *path, int *width, int *height)` [display_utils.c]
   - Charge une image XPM individuelle

6. `draw_map(t_game *game)` [display.c]
   - Dessine la carte initiale
   - Utilise draw_tile pour chaque case

## 4. Boucle de jeu
1. `handle_key(int keycode, t_game *game)` [game.c]
   - Gère les événements clavier
   - Appelle process_movement pour WASD

2. `process_movement(t_game *game, int keycode)` [game.c]
   - Traite les touches de mouvement
   - Appelle update_position et move_player

3. `update_position(int keycode, int *x, int *y)` [game_utils.c]
   - Calcule la nouvelle position selon la touche

4. `move_player(t_game *game, int new_x, int new_y)` [game_utils.c]
   - Vérifie si le mouvement est valide
   - Met à jour la position du joueur
   - Gère la collecte d'items

5. `draw_tile(t_game *game, void *img, int x, int y)` [display.c]
   - Dessine une tuile à la position spécifiée
   - Utilisé pour mettre à jour l'affichage

6. `display_message(t_game *game, char *message)` [display.c]
   - Affiche les messages (victoire, etc.)

## 5. Nettoyage et fermeture
1. `close_game(t_game *game)` [game.c]
   - Gère la fermeture propre du jeu
   - Appelle destroy_images et free_game

2. `destroy_images(t_game *game)` [game.c]
   - Libère la mémoire des images

3. `free_game(t_game *game)` [utils.c]
   - Libère toutes les ressources du jeu

4. `free_map(t_map *map)` [map_utils.c]
   - Libère la mémoire de la carte
