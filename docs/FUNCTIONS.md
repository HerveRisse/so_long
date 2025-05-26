# So Long - Documentation des fonctions

Ce document décrit toutes les fonctions présentes dans les fichiers sources du projet So Long, ainsi que leur ordre d'exécution.

## Ordre d'exécution principal

1. `main()` - Point d'entrée du programme
2. `validate_args()` - Vérifie les arguments
3. `check_file_extension()` - Vérifie l'extension .ber
4. `initialize_map()` - Initialise la structure de la carte
   - `count_lines()` - Compte les lignes du fichier
   - `read_map()` - Lit le contenu de la carte
   - `validate_map()` - Valide la structure de la carte
5. `init_game()` - Initialise le jeu
   - `find_player_pos()` - Trouve la position du joueur
   - `init_window()` - Crée la fenêtre
   - `load_images()` - Charge les textures
   - `draw_map()` - Dessine la carte initiale
6. Configuration des hooks
   - `handle_key()` - Pour les touches
   - `close_game()` - Pour la fermeture
7. `mlx_loop()` - Boucle principale du jeu

## Boucle de jeu
1. `handle_key()` - Reçoit l'input
2. `process_movement()` - Traite le mouvement
3. `update_position()` - Calcule la nouvelle position
4. `move_player()` - Déplace le joueur
5. `draw_map()` - Met à jour l'affichage

## Fonctions par fichier

## display.c
1. `draw_tile(t_game *game, void *img, int x, int y)`: Fonction de base pour dessiner une tuile
2. `display_message(t_game *game, char *message)`: Affiche un message à l'écran (utilisé pour les victoires/défaites)
3. `draw_map(t_game *game)`: Dessine la carte complète en utilisant draw_tile

## display_utils.c
1. `load_xpm_image(void *mlx, char *path, int *width, int *height)`: Fonction de base pour charger une image
2. `load_images(t_game *game)`: Utilise load_xpm_image pour charger toutes les textures du jeu

## game.c
1. `handle_key(int keycode, t_game *game)`: Fonction principale de gestion des touches
2. `process_movement(t_game *game, int keycode)`: Appelée par handle_key pour traiter les mouvements
3. `close_game(t_game *game)`: Gère la fermeture propre du jeu
4. `destroy_images(t_game *game)`: Appelée par close_game pour libérer les ressources

## game_init.c
1. `init_game(t_game *game)`: Fonction principale d'initialisation
2. `init_window(t_game *game)`: Appelée par init_game pour créer la fenêtre

## game_utils.c
1. `update_position(int keycode, int *x, int *y)`: Calcule les nouvelles coordonnées selon la touche
2. `move_player(t_game *game, int new_x, int new_y)`: Applique le mouvement si valide

## main.c
1. `main(int argc, char **argv)`: Point d'entrée du programme
2. `validate_args(int argc, char **argv)`: Première validation des arguments
3. `check_file_extension(char *file)`: Vérifie l'extension .ber
4. `initialize_map(t_map *map, char *map_file)`: Initialise et valide la carte

## map.c
1. `validate_map(t_map *map)`: Fonction principale de validation de carte
2. `check_walls(t_map *map)`: Vérifie l'intégrité des murs

## map_checks.c
1. `check_map_chars(t_map *map)`: Vérifie la validité des caractères
2. `check_map_counts(t_map *map)`: Vérifie les quantités d'éléments (P,E,C)

## map_path.c
1. `validate_path(t_map *map)`: Fonction principale de validation du chemin
2. `find_path(t_map *map, int x, int y)`: Algorithme récursif de pathfinding

## map_read.c
1. `read_map(t_map *map, int fd)`: Fonction principale de lecture de carte
2. `process_line(t_map *map, char *line, int i)`: Traite chaque ligne lue

## map_utils.c
1. `count_lines(char *file)`: Compte les lignes pour l'allocation
2. `free_map(t_map *map)`: Libère la mémoire de la carte

## map_validation.c
1. `check_path_to_exit(t_map *map)`: Vérifie l'accessibilité de la sortie
2. `create_visited_map(t_map *map)`: Crée la carte de pathfinding

## movement.c
1. `find_player_pos(t_game *game)`: Trouve la position initiale du joueur
2. `handle_movement(t_game *game, int new_x, int new_y)`: Gère la logique de mouvement

## utils.c
1. `error_exit(char *message)`: Gestion des erreurs fatales
2. `free_game(t_game *game)`: Nettoyage final des ressources
