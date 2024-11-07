#!/bin/bash

# Dossiers contenant les maps à tester
MAP_DIR_GOOD="maps/good"
MAP_DIR_BAD="maps/bad"

# Chercher dynamiquement l'exécutable dans le dossier parent
EXEC=$(find .. -maxdepth 1 -type f -iname "cub3d*" | head -n 1)

# Si aucun exécutable n'est trouvé
if [ -z "$EXEC" ]; then
  echo -e "Error: No executable named 'cub3d', 'Cub3D', or similar found in the parent directory."
  exit 1
fi

# Codes de couleur
GREEN="\033[0;32m"  # Vert
RED="\033[0;31m"    # Rouge
RESET="\033[0m"     # Réinitialise la couleur
BOLD="\033[1m"      # Gras

# Fonction pour tester les fichiers de map dans un répertoire donné
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

        # Exécute valgrind avec --track-fds=yes pour traquer les fuites de descripteurs de fichiers
        valgrind --leak-check=full --track-fds=yes "$EXEC" "$map_file" 2> valgrind_output.txt &
        PID=$!

        # Attendre que l'utilisateur ferme l'application (par exemple, via Échap)
        wait $PID

        # Lire la sortie de Valgrind une fois l'exécutable terminé
        valgrind_output=$(cat valgrind_output.txt)


        # Vérifie si Valgrind détecte des descripteurs de fichiers ouverts
        if echo "$valgrind_output" | grep -q "Open file descriptor"; then
            echo -e "${RED}$map_file : Error - Open file descriptor detected${RESET}"
        # Vérifie si Valgrind retourne 0 erreurs ET que tous les blocs de mémoire sont libérés
        elif echo "$valgrind_output" | grep -q "ERROR SUMMARY: 0 errors from 0 contexts" && \
           echo "$valgrind_output" | grep -q "All heap blocks were freed -- no leaks are possible"; then
            echo -e "${GREEN}Success${RESET}"
            ((success_count++)) # Incrémente le compteur de succès
        else
            echo -e "${RED}$map_file : Error${RESET}"
            echo "$valgrind_output"  # Optionnel, pour afficher les détails des erreurs Valgrind
        fi

        echo "--------------------------------------"

        # Nettoyer le fichier temporaire
        rm -f valgrind_output.txt
    done

    # Afficher le récapitulatif des succès
    echo -e "\n${BOLD}$success_count/$total_count Success for $dir_label maps${RESET}\n"
}

# Tester les maps dans le dossier "maps/bad"
test_maps_in_directory "$MAP_DIR_BAD" "Bad"

read -p "Appuyer sur Enter pour lancer les tests sur les maps valides..."

# Tester les maps dans le dossier "maps/good"
test_maps_in_directory "$MAP_DIR_GOOD" "Good"
