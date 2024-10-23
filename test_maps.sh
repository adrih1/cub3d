#!/bin/bash

# Dossier contenant les maps à tester
MAP_DIR_GOOD="maps/good"

# Exécutable à tester
EXEC="./cub3d"

# Codes de couleur
GREEN="\033[0;32m"  # Vert
RESET="\033[0m"     # Réinitialise la couleur
BOLD="\033[1m"      # Gras

# Fonction pour tester les fichiers de map dans le dossier des maps "good"
test_maps_in_directory() {
    local map_dir=$1
    local dir_label=$2
    local success_count=0
    local total_count=0

    # Afficher le titre en grand et avec un saut de ligne
    echo -e "${BOLD}\n\n===== Testing Maps in $dir_label =====${RESET}\n"

    # Parcourt tous les fichiers .cub dans le dossier spécifié
    for map_file in "$map_dir"/*.cub; do
        echo "Testing: $map_file"
        ((total_count++)) # Incrémente le compteur total

        # Exécute le programme sans Valgrind
        "$EXEC" "$map_file" &
        PID=$!

        # Attendre que l'utilisateur ferme l'application (par exemple, via Échap)
        wait $PID

    done
}

# Tester les maps dans le dossier "maps/good"
test_maps_in_directory "$MAP_DIR_GOOD" "Good"
