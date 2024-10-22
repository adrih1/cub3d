#!/bin/bash

# Dossier contenant les maps à tester
MAP_DIR="maps/bad"

# Exécutable à tester
EXEC="./cub3d"

# Codes de couleur
GREEN="\033[0;32m"  # Vert
RED="\033[0;31m"    # Rouge
RESET="\033[0m"     # Réinitialise la couleur

# Parcourt tous les fichiers .cub dans le dossier maps/good
for map_file in "$MAP_DIR"/*.cub; do
    echo "Testing: $map_file"

    # Exécute valgrind en arrière-plan avec redirection de la sortie dans un fichier temporaire
    valgrind --leak-check=full "$EXEC" "$map_file" 2> valgrind_output.txt &
    PID=$!

    # Attendre que l'utilisateur ferme l'application (par exemple, via Échap)
    wait $PID

    # Lire la sortie de Valgrind une fois l'exécutable terminé
    valgrind_output=$(cat valgrind_output.txt)

    # Vérifie si Valgrind retourne 0 erreurs ET que tous les blocs de mémoire sont libérés
    if echo "$valgrind_output" | grep -q "ERROR SUMMARY: 0 errors from 0 contexts" && \
       echo "$valgrind_output" | grep -q "All heap blocks were freed -- no leaks are possible"; then
        echo -e "${GREEN}Success${RESET}"
    else
        echo "$map_file : Error"
        echo "$valgrind_output"  # Optionnel, pour afficher les détails des erreurs Valgrind
    fi

    echo "--------------------------------------"

    # Nettoyer le fichier temporaire
    rm -f valgrind_output.txt
done
